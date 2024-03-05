import RPi.GPIO as GPIO
import time

# GPIO.BOARD versus GPIO.BCM
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

# indiquer qu'on sort au lieu d'entrer
GPIO.setup(18, GPIO.OUT)

print("LED On")
GPIO.output(18, GPIO.HIGH)

time.sleep(2)
print("LED Off")
GPIO.output(18, GPIO.LOW)

GPIO.cleanup()