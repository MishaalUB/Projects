import Adafruit_DHT
import time

DHT_SENSOR = Adafruit_DHT.DHT22			# defines the sensor object being used "DHT22"
DHT_PIN = 4								# defines the General Purpose Input/Output pin we are using

while True:																	# creates infinite loop 
	humidity, temperature = Adafruit_DHT.read_retry(DHT_SENSOR, DHT_PIN)	# create variables to store our data
	if humidity is not None and temperature is not None:					# checks whether the sensor has gained readings
		print("Temperature = {:.2f}c   Humidity = {:.2f}%".format(temperature, humidity))	# if it worked, t + h is printed to the screen
	else:
		print("Sensor failure, please try again.");							# otherwise, we get an error message
	time.sleep(3);															# sleep pauses the loop so we get readings every 3 seconds