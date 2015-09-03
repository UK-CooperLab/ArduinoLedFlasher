/***************************************
This code is meant for an Arduino Uno
(or equivalent). It is set up to work
with the LED driver board created by
Dr. Cooper's lab at Univ. of KY. 
The latest version of this code 
can be found at:
https://github.com/UK-CooperLab
**************************************/


//Input/Output pin declarations
int buttonPin = 10;
int ledPin = 6;
int boardLedPin =13;

// - Variables for Button Debounce -
int buttonState = 0;             
int lastButtonState = LOW;
long lastDebounceTime = 0;  
long debounceDelay = 50;

// - Variables for on/off toggling
int ledState = HIGH;  

// - Function Prototypes -
void delayMinutes(int num_minutes);
void delaySeconds(int num_seconds);
void ledOn();
void ledOff();
void ledUpdate();

//Module 3 Variables
boolean mod3_shouldRun = false; 
long 	mod3_start = 0;
//Don't edit code above this line
//******************************



void setup() {
	
	//Declare pin modes 
	pinMode(buttonPin, INPUT);
	pinMode(ledPin, OUTPUT);
	pinMode(boardLedPin, OUTPUT);
	digitalWrite(ledPin, ledState);
	
	Serial.begin(115200);
}



void loop()
{
//******* HOW TO USE THIS CODE ********
/* Below you will find several 'modules'.
These modules may be updated or added to.
Check the github link (above) for the
latest version of code. Each module 
gives a brief description of its
operation. After the description you 
will see the following:

//BEGIN MODULE x
/*
<code>
*/
//END MODULE x

/*To 'enable' this module, remove the
following symbols before and after <code>:
/*
*/

/* This will enable the module. To disable 
a module, replace those symbols. More than
one module may NOT be enabled at the same
time. Always disable the current module
before enabling another one. 




//*****MODULE 1 (Button on/off) *****

/* This module toggles the lED on and off.
Pressing the button will turn the LED on. 
Pressing the button a second time will
turn the LED off. Pressing the button a 
third time will turn it on again...
*/

//BEGIN Module 1
/*
	int reading = digitalRead(buttonPin);
	if (reading != lastButtonState) 
		lastDebounceTime = millis();
   
  
	if ((millis() - lastDebounceTime) > debounceDelay) 
	{
		if (reading != buttonState) 
		{	buttonState = reading;
			
			if (buttonState == HIGH) 
			{
				//Serial.println("hello");
				ledState = !ledState;     
				ledUpdate();
			}
		}
    }
	lastButtonState = reading;
	//Serial.println(lastDebounceTime);
*/
//END Module 1
	
	
	
	
//*****MODULE 2 (timer on/off) *****

/* This module automatically turns the 
LED on and off. The line ledOn(); will
turn the LED on. The line ledOff(); will
turn the lED off. Use the 
delayMinutes(x); and delaySeconds(y); 
functions to add a pause before the next line.
For example, delayMinutes(3); will wait
3 minutes before the next line. 
Likewise, delaySeconds(14); will wait
14 seconds before the next line. 

The following example will turn on for 
2 minutes and then be off for 3 minutes
and 15 seconds. This (on, off) will repeat
forever.

ledOn();
delayMinutes(2);
ledOff();
delayMinutes(3);
delaySeconds(15);	
*/

//BEGIN MODULE 2
/*
ledOn();
delayMinutes(5);
ledOff();
delayMinutes(5);
*/
//END MODULE 2



//*****MODULE 3 (timer on/off) *****
/* This module will repeat the steps below
and stop once it reaches a certain number of
hours. For example, it is currently set to:

30 seconds on
5 minutes off
(repeat this for 24 hours, then stop)

Once the time limit has expired, and the 
flashing has stopped, pressing the button
will start it again. Pressing the button
while the flashing is running will
reset the timer. 
*/


//BEGIN MODULE 3

//Change the following line to reflect
//many hours should run for. Make sure
//to put a capital L after the number. 
long	mod3_numHours = 24L;
if(digitalRead(buttonPin))
{
		//don't edit this code 
		mod3_shouldRun = true;
		mod3_start = millis();
		
}
while(mod3_shouldRun)
{
		//Edit this code to be the flashing
		//pattern that is desired. 
		ledOn();
		delaySeconds(30);
		ledOff();
		delayMinutes(5);
		
		//don't edit this code
		if((millis() - mod3_start) > mod3_numHours * 3600 * 1000)
			mod3_shouldRun = false;
}

//END MODULE 3

}







//******************************
//Don't edit code below this line 
void ledUpdate()
{
	if(ledState)
		ledOff();
	else
		ledOn();
}

void ledOn()
{
	ledState = 0;
	digitalWrite(ledPin, ledState);
	digitalWrite(boardLedPin, HIGH);
}

void ledOff()
{
	ledState = 1;
	digitalWrite(ledPin, ledState);
	digitalWrite(boardLedPin, LOW);
}

void delayMinutes(int num_minutes)
{
  for(int i = 0; i < num_minutes; i++)
      delaySeconds(60);  
}

void delaySeconds(int num_seconds)
{
  for(int i = 0; i < num_seconds; i++)
    delay(1000);
}



