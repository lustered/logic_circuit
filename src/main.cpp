#include <Arduino.h>
// 1
#define button1Pin  13
#define button2Pin  12
#define button3Pin  11
// 2 
#define led1Pin 6
#define led2Pin 5
#define led3Pin 4
#define led4Pin 3
// 3
int button1_state = 0;
int button2_state = 0;
int button3_state = 0;

void setup() {
  Serial.begin(9600);
  // leds
  pinMode(led1Pin,OUTPUT);
  pinMode(led2Pin,OUTPUT);
  pinMode(led3Pin,OUTPUT);
  pinMode(led4Pin,OUTPUT);
  // button pins
  pinMode(button3Pin,INPUT);
  pinMode(button2Pin,INPUT);
  pinMode(button1Pin,INPUT);

}

void loop() {
  button3_state = digitalRead(button3Pin);
  button2_state = digitalRead(button2Pin);
  button1_state = digitalRead(button1Pin);

  Serial.println(button1_state);
  Serial.println(button2_state);
  Serial.println(button3_state);
  delay(1000);

  if(button3_state == HIGH){
    digitalWrite(led1Pin, HIGH);
  }
  else{
    digitalWrite(led1Pin, LOW);
  }
  if(button2_state == HIGH){
    digitalWrite(led2Pin, HIGH);
  }
  else{
    digitalWrite(led2Pin, LOW);
  }

}

int logic_gate(int gate, int a, int b)
{
  int ret = 0;
  switch (gate)
  {
  /* and */
  case 1:
    if (a == b)
    {
      ret = a;
    }
    break;
  /* not */
  case 3:
    if (a == 1)
    {
      ret = 0;
    }
    else if (a == 0)
      ret = 1;

    break;

  }
  return ret;
  /* end of switch */
}