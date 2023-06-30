#include<Arduino.h>
#include"LED.h"

struct Semaforo
{
  enum class State {
    None,
    Red,
    Yellow,
    Green
  };
  void Setup(int redpin,int yellowpin,int greenpin)
  {
    red.Setup(redpin);
    yellow.Setup(yellowpin);
    green.Setup(greenpin);
  }
  
  void SetState(State state)
  {
    
    if (state == State::Red)
    {
      red.EnableWithDuration(redduration);
    } else if (state == State::Yellow)
    {
      yellow.EnableWithDuration(yellowduration);
    } else if (state == State::Green)
    {
      green.EnableWithDuration(greenduration);
    }

  }
  LED red;
  LED yellow;
  LED green;
  static const int redduration = 12000;
  static const int yellowduration = 2000;
  static const int greenduration = 10000;

};

Semaforo semaforo;
void setup() {
  Serial.begin(9600);
  semaforo.Setup(13,12,11);
}

void loop() {
  // put your main code here, to run repeatedly:
  semaforo.SetState(Semaforo::State::Green);
  semaforo.SetState(Semaforo::State::Yellow);
  semaforo.SetState(Semaforo::State::Red);
}
