int pins[] = {3, 5, 6, 9, 10, 11};
int LenPins = sizeof(pins);
int states[] = {LOW, LOW, LOW, LOW, LOW, LOW};
unsigned long prevMillis[] = {0, 0, 0, 0, 0, 0};
long intervals[] = {10, 1000, 2000, 3000, 4000, 5000};

unsigned long crnMillis;

void loop() {
  crnMillis = micros();
  for (int i = 0; i < LenPins; i++)
	{    
    if (crnMillis - prevMillis[i] >= intervals[i]) 
	{
      prevMillis[i] = crnMillis;
  
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
