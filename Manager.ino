#include <TaskManager.h>

int pins[] = {3, 5, 6, 9, 10, 11};
int ledPinsLen = sizeof(ledPins);
int states[] = {LOW, LOW, LOW, LOW, LOW, LOW};
long intervals[] = {60, 900, 1200, 15000, 80000, 210000};

void loop() {
  taskManager.runLoop();
}

void led(int &ledState, int led)
{
  if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
  digitalWrite(led, ledState);
}

void setup() {
  for (int i = 0; i < ledPinsLen; i++) 
	{
    pinMode(ledPins[i], OUTPUT);
  }

  taskManager.scheduleFixedRate(intervals[0], [] 
	{
    led(states[0], pins[0]);
  }, TIME_MICROS);
      
  taskManager.scheduleFixedRate(intervals[1], [] 
	{
    led(states[1], pins[1]);
  }, TIME_MICROS);
      
  taskManager.scheduleFixedRate(intervals[2], [] 
	{
    led(states[2], pins[2]);
  }, TIME_MICROS);
      
  taskManager.scheduleFixedRate(intervals[3], [] 
	{
    led(states[3], pins[3]);
  }, TIME_MICROS);
      
  taskManager.scheduleFixedRate(intervals[4], [] 
	{
    led(states[4], pins[4]);
  }, TIME_MICROS);
      
  taskManager.scheduleFixedRate(intervals[5], [] 
	{
    led(states[5], pins[5]);
  }, TIME_MICROS);
}
