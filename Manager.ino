const int NUMBER_OF_PINS = 6;

unsigned long* microsArr = new unsigned long[NUMBER_OF_PINS];
unsigned long intervalsArr[NUMBER_OF_PINS] = {160000,50000,800000,400000,200000,100000};
int* states = new int[NUMBER_OF_PINS];
int pins[NUMBER_OF_PINS] = {3, 5, 6, 9, 10, 11};

void setup() 
{
  for (int i = 0; i < NUMBER_OF_PINS; ++i) 
  {
    microsArr[i] = 0;
    states[i] = LOW;
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  unsigned long micros_val = micros();

  if (micros_val - microsArr[0] >= intervalsArr[0]) 
  {
    microsArr[0] = micros_val;

    if (states[0] == LOW) 
    {
      states[0] = HIGH;
    }
    else 
    {
      states[0] = LOW;
    }

    digitalWrite(pins[0], states[0]);
  }

  if (micros_val - microsArr[1] >= intervalsArr[1]) 
  {
    microsArr[1] = micros_val;

    if (states[1] == LOW) 
    {
      states[1] = HIGH;
    }
    else 
    {
      states[1] = LOW;
    }

    digitalWrite(pins[1], states[1]);
  }
  
  if (micros_val - microsArr[2] >= intervalsArr[2]) 
  {
    microsArr[2] = micros_val;

    if (states[2] == LOW) 
    {
      states[2] = HIGH;
    }
    else {
      states[2] = LOW;
    }

    digitalWrite(pins[2], states[2]);
  }

  if (micros_val - microsArr[3] >= intervalsArr[3]) 
  {
    microsArr[3] = micros_val;

    if (states[3] == LOW) {
      states[3] = HIGH;
    }
    else {
      states[3] = LOW;
    }

    digitalWrite(pins[3], states[3]);
  }

  if (micros_val - microsArr[4] >= intervalsArr[4]) 
  {
    microsArr[4] = micros_val;

    if (states[4] == LOW) 
    {
      states[4] = HIGH;
    }
    else 
    {
      states[4] = LOW;
    }

    digitalWrite(pins[4], states[4]);
  }
}