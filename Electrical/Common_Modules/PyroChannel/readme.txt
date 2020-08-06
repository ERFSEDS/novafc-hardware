This circuit is broken up into 2 sheets, an arming sheet, which each board
only needs one, then a pyro channel, which can have as many as desired
This circuit also allows for the pyro channel to be checked

The maximum voltage that this circuit can take is 12V, at which point the
transistors will break down. THe maximum current the transistors can
sustain is 5 amps continuous or 25 for a pulse

to fire a channel n
	digitalWrite(armPin, HIGH)
	digitalWite(channelNPin, HIGH)

to check if channel n is armed
	digitalRead(channelNPyro)

