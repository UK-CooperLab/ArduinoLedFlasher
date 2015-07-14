int led1 = 5;
int led2 = 6;
int led3 = 3;
int led4 = 10;
int led5 = 11;
int led6 = 9;

int on_time = 5;  //minutes
int off_time = 10; //minutes

void delayMinutes(int num_minutes);
void delaySeconds(int num_seconds);
void allLed(bool state);

void setup()
{
  Serial.begin(9600);
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  
  Serial.println("Hello Cooper Lab");
}


//*********************CHANGE THE CODE BELOW THIS LINE
void loop()
{

//Examples
// allLed(1) turns all leds ON
// allLed(0) turns all leds off
// delaySeconds(x) waits x seconds before doing the next thing
// delayMinutes(y) waits y minutes before doing the next thing


//TOP OF LOOP
  
  allLed(1);
  delaySeconds(20);
  
  allLed(0);
  delayMinutes(5);
  
  
  
  //WHEN THE CODE GETS HERE IT WILL GO BACK TO "TOP OF LOOP" AND REPEAT FOREVER
}

//****************CHANGE THE CODE ABOVE THIS LINE



void allLed(bool state)
{
  if(state)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);  
  }
  else
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
  }
}


void delayMinutes(int num_minutes)
{
  for(int i = 0; i < num_minutes; i++)
  {
    delaySeconds(60);
  }
  
}

void delaySeconds(int num_seconds)
{
  for(int i = 0; i < num_seconds)
  {
    delay(1000);
  }
}



