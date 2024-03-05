#!/bin/python3

# titre : Écrire et pousser du code à l'aide de la fonctionnalité Flasher

from microbit import *

while True:
    if button_a.is_pressed():
        display.scroll('A PRESSED')
    if button_b.is_pressed():
        display.scroll('B PRESSED')