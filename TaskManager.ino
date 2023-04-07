#include <TaskManager.h>

int pins[] = {3, 5, 6, 9, 10, 11};
int len = sizeof(pins);
int states[] = {LOW, LOW, LOW, LOW, LOW, LOW};
long inter[] = {60, 900, 1200, 15000, 80000, 210000};

void setup() 
{
  for (int i = 0; i < len; i++) 
  {
    pinMode(pins[i], OUTPUT);
  }

  taskManager.scheduleFixedRate(inter[0], [] 
  {
    led(states[0], pins[0]);
  }, TIME_MICROS);
      
  taskManager.scheduleFixedRate(inter[1], [] 
  {
    led(states[1], pins[1]);
  }, TIME_MICROS);
      
  taskManager.scheduleFixedRate(inter[2], [] 
  {
    led(states[2], pins[2]);
  }, TIME_MICROS);
      
  taskManager.scheduleFixedRate(inter[3], [] 
  {
    led(states[3], pins[3]);
  }, TIME_MICROS);
      
  taskManager.scheduleFixedRate(inter[4], [] 
  {
    led(states[4], pins[4]);
  }, TIME_MICROS);
      
  taskManager.scheduleFixedRate(inter[5], [] 
  {
    led(states[5], pins[5]);
  }, TIME_MICROS);
}

void loop() {
  taskManager.runLoop();
}

void led(int &ledState, int led)
{
  if (ledState == LOW) 
  {
    ledState = HIGH;
  } 
  else 
  {
    ledState = LOW;
  }
  
  digitalWrite(led, ledState);
}