# esp8266-water-heater
Program for the water heater for Arduino esp8266.

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