#!/bin/python3

# Il faut installer la dépendance sudo pip3 install pyowm

import pyowm
from pyowm.utils import timestamps

## Copy and paste your key into the line below
KEY = '7a960ab52c3ac143c25f5e692a14031f'

## Place your location (city, country code) into the line below
location = 'Toronto,ca'

"""
owm = pyowm.OWM(KEY)
forecaster = owm.weather_manager().forecast_at_place(location, '3h')
now = timestamps.last_three_hours(timestamps.now())
weather = forecaster.get_weather_at(now)
forecast = forecaster.forecast
print('pewpew')
print(forecast.weathers[0])
icons = [weather.get_weather_icon_name() for weather in forecast.weathers]
"""
owm = pyowm.OWM('7a960ab52c3ac143c25f5e692a14031f')
mgr = owm.weather_manager()
daily_forecaster = mgr.forecast_at_place('Toronto,CA', 'daily')

tomorrow = timestamps.next_three_hours()
weather = daily_forecaster.get_weather_at(tomorrow) 
print(weather)

