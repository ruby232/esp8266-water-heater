# Esp8266 Water Heater

This Arduino project allows to automate water heater so that you always have hot water when you need it. 
You can create a schedule to turn the water heater on and off at specific times of day, and you can also control the water heater manually using a web server.

## Components
Arduino board: esp8266

## Webserver Routes
### Set schedules 
URL: http://water-heater.local/set-schedules
Pauload: 
```json
[
	{
		"hour": 23,
		"minute": 45,
		"state": 1
	},
	{
		"hour": 10,
		"minute": 0,
		"state": 0
	},
	{
		"hour": 6,
		"minute": 30,
		"state": 0
	}
]
```

### Get schedules 
URL: http://water-heater.local/get-schedules

### Get current relay state
URL: http://water-heater.local/get-state

### Set relay state on
URL: http://water-heater.local/state-on

### Set relay state off
URL: http://water-heater.local/state-off

### Update OTA
URL: http://water-heater.local/update

## Tools and docs
[Minify HTML](https://jsonformatter.org/minify-html)
[Tutoriales útil para Ambos ESP8266](https://nocheprogramacion.com/series/arduino_esp/index.html)

