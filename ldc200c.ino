//============================================================================//
// Neurophos Inc.                                                             //
// K.P.Trofatter                                                              //
// August 2022                                                                //
//============================================================================//
// arduino program for Thorlabs LDC200C series laser diode controller
// designed for arduino uno and arduino mega

//============================================================================//
// definitions                                                                //
//============================================================================//
#define PIN_LD_REM 13

//============================================================================//
// code                                                                       //
//============================================================================//
void setup(void)
{
	// set pinout
	pinMode(PIN_LD_REM, OUTPUT);
	
	// initalize serial
	Serial.begin(9600);
}

void loop(void)
{
	// wait for command
	if (Serial.available()) {
		
		// get command
		int c = Serial.read();
		
		// process command
		switch(c) {
		case '0':
			digitalWrite(PIN_LD_REM, LOW);
			Serial.print("laser off\n");
			break;
		case '1':
			digitalWrite(PIN_LD_REM, HIGH);
			Serial.print("laser on\n");
			break;
		default:
			Serial.print("bad command 0x");
			Serial.println(c & 0x00FF, HEX);
		}
	}
}

//============================================================================//
//                                                                            //
//                                                                            //
//                                                                            //
//============================================================================//
