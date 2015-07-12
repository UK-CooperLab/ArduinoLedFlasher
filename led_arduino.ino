int led1 = 5;
int led2 = 6;
int led3 = 3;
int led4 = 10;
int led5 = 11;
int led6 = 9;

int on_time = 5;  //minutes
int off_time = 10; //minutes

void delayMinutes(int num_minutes);
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


void loop()
{

  allLed(1);
  delayMinutes(on_time);
  
  allLed(0);
  delayMinutes(off_time);
  
}


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
    for(int j = 0; j < 60; j++)
    {
      delay(1000);
    }
  }
  
}




