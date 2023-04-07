int pins[] = {3, 5, 6, 9, 10, 11};
int ledPinsLen = sizeof(ledPins);
int states[] = {LOW, LOW, LOW, LOW, LOW, LOW};
unsigned long previousMillis[] = {0, 0, 0, 0, 0, 0};
long intervals[] = {60, 900, 1200, 15000, 80000, 210000};

unsigned long millis;

void loop() {
  millis = micros();
  for (int i = 0; i < 6 ; i++)
	{    
    if (millis - previousMillis[i] >= intervals[i]) 
	{
      previousMillis[i] = millis;
  
    if (states[i] == LOW) 
	{
      states[i] = HIGH;
    } else {
      states[i] = LOW;
    } 
      
    digitalWrite(pins[i], states[i]);
    }
  }
}

void setup() 
{
  for (int i = 0; i < ledPinsLen; i++)
	{
    pinMode(ledPins[i], OUTPUT);
  }
}
