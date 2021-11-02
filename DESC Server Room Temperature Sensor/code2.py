#!/usr/bin/python
import sys
import csv
import time
import smtplib
import Adafruit_DHT         
sensor = Adafruit_DHT.DHT22     # defines the sensor object used
pin = 4                         # defines the gpio pin we are using

humidity, temperature = Adafruit_DHT.read_retry(sensor,pin)

with open ('/home/pi/email_alert/log.csv', 'a') as f:

    if humidity is not None and temperature is not None:
        row = [time.strftime('%m/%d/%y'), time.strftime('%H:%M:%S'),"{:.2f}".format(temperature),"{:.2f}".format(humidity)]
        w = csv.writer(f)
        w.writerow(row)
    else:
        print ('Failed to get reading. Try again!')   # if the above script doesn't work, this message is produced
            
    f.close()

if (temperature > 28):          # if the temperature exceeds 28 degrees, an emergency email is sent out
    print(temperature)
        
    smtpUser = "desscitservices@gmail.com"
    smtpPass = "*********"
    toAdd = "it@dessc.sch.ae"
    fromAdd = "MDF-Alarm"

    subject = "DESC MDF Temperature exceeding critical limit" 
    header = "To: " + toAdd + "\n" + "From:" + fromAdd + "\n" + "Subject:" + subject
    body = ("warning: DESC Campus F Block MDF Temp: {0:0.1f} C".format(temperature))

    
    
    print(header + "\n" + body) 

    s = smtplib.SMTP("smtp.gmail.com", 587)

    s.ehlo()
    s.starttls()
    s.ehlo()

    s.login(smtpUser, smtpPass) 
    s.sendmail(fromAdd, toAdd, header + "\n\n" + body)
    s.quit()
