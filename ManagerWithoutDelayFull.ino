int pins[] = {3, 5, 6, 9, 10, 11};
int LenPins = sizeof(pins);
int states[] = {LOW, LOW, LOW, LOW, LOW, LOW};
unsigned long prevMillis[] = {0, 0, 0, 0, 0, 0};
long intervals[] = {60, 900, 1200, 15000, 80000, 210000};

unsigned long millis;

void loop() {
  millis = micros();
  for (int i = 0; i < LenPins; i++)
	{    
    if (millis - prevMillis[i] >= intervals[i]) 
	{
      prevMillis[i] = millis;
  
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
  for (int i = 0; i < LenPins; i++)
	{
    pinMode(pins[i], OUTPUT);
  }
}
