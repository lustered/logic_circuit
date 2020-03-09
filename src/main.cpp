#include <Arduino.h>
const int button3Pin = 11; // the number of the pushbutton pin
const int button2Pin = 12;
const int button1Pin = 13;

const int led1_Pin = 6; // the number of the LED pin
const int led2_Pin = 5;
const int led3_Pin = 4;
const int led4_Pin = 3;

// variables will change:
int button1State = 0;
int button2State = 0;
int button3State = 0;
// prototypes
void manage_led(int button, int led);
int logic_gate(int gate, int a, int b);

void setup()
{
  // initialize the LED pin as an output:
  pinMode(led1_Pin, OUTPUT);
  pinMode(led2_Pin, OUTPUT);
  pinMode(led3_Pin, OUTPUT);
  pinMode(led4_Pin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
}

void loop()
{
  // read the state of the pushbutton value:
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);
  button3State = digitalRead(button3Pin);


  manage_led(button3State,led3_Pin);
  manage_led(button2State,led2_Pin);
  manage_led(button1State,led1_Pin);

  int get_state = logic_gate(1,button1State, button2State);
  if(button3State == HIGH){
    get_state = 1 - get_state;
  }
  manage_led(get_state,led4_Pin);
}

// turn led on/off function because we don't like bad code
void manage_led(int button, int led){
  if(button == HIGH){
    digitalWrite(led,HIGH);
  }
  else{
      digitalWrite(led,LOW);
  }

}

// logic gate function
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