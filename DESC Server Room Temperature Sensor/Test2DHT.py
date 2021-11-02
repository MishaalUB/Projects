import Adafruit_DHT
import time

SENSOR = Adafruit_DHT.DHT22
PIN = 4

while True:
	humidity, temperature = Adafruit_DHT.read_retry(SENSOR, PIN)
	if humidity is not None and temperature is not None:
		print("Temperature = {:.2f}c   Humidity = {:.2f}%".format(temperature, humidity))
	else:
		print("Sensor failure, please try again.");
	time.sleep(3);