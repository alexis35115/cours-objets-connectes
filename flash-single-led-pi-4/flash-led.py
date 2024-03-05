import RPi.GPIO as GPIO
import time

# On précise qu'on utilise la numérotation des pins sur le BOARD au lieu de BCM
GPIO.setmode(GPIO.BOARD)
# Supprimer les avertissements
GPIO.setwarnings(False)

GPIO.setup(11, GPIO.OUT)

while True:
    GPIO.output(11, True) # True / 1 / HIGH
    time.sleep(1)
    GPIO.output(11, False) # False / 0 / LOW
    time.sleep(1)

GPIO.cleanup()