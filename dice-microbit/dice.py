#!/bin/python3

from microbit import *
import random
import time # pour défi 1

# Version initiale
while True:
    if accelerometer.was_gesture('shake'):
        display.show(random.randint(1, 6))

# Version avec la partie 1 du défi
"""
while True:
    if accelerometer.was_gesture('shake'):
        display.show(random.randint(1, 6))
        time.sleep(3)
        display.clear()
"""

# Version avec la partie 2 du défi
"""
while True:
    if accelerometer.was_gesture('shake'):
        display.show(random.randint(2, 12))
        time.sleep(3)
        display.clear()
"""