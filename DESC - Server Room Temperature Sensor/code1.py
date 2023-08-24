#!/usr/bin/python
from flask import Flask, render_template
import sys
import Adafruit_DHT			# usually used in temperature, humidity projects
app = Flask(__name__)
sensor = Adafruit_DHT.DHT22 # defines the sensor object used
pin = 4						# defines the gpio pin we are using

@app.route("/")
def main():
    humidity, temperature = Adafruit_DHT.read_retry(sensor, pin)  # grabs the h + s sensor readings upto 15 times
    templateData = {
            'temperature' : round(temperature, 1),				  # returns rounded floating point number to 1 dp
            'humidity' : round(humidity)						  # returns rounded floating point number to 0 dp (int)
    }
    return render_template('main.html', **templateData)			  # links the information to the html code

if __name__ == "__main__":
    app.run(host='0.0.0.0', port=80, debug=True)
