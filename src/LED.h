#include <Arduino.h>
#ifndef LED_h
#define LED_h
struct LED
{
  void Setup(int pin)
  {
    pinMode(pin, OUTPUT);
    this->pin = pin;
  }
  void SetState(bool state)
  {
    digitalWrite(pin, state);
  }
  bool GetState()
  {
    return digitalRead(pin);
  }
  void Toggle()
  {
    bool oldstate = digitalRead(pin);
    digitalWrite(pin, !oldstate);
  }
  void Enable()
  {
    SetState(true);
  }
  void Disable()
  {
    SetState(false);
  }
  void EnableWithDuration(int ms)
  {
    bool oldstate = GetState();
    SetState(true);
    delay(ms);
    SetState(oldstate);
  }
  void DisableWithDuration(int ms)
  {
    bool oldstate = GetState();
    SetState(false);
    delay(ms);
    SetState(oldstate);
  }
  int pin;
};

#endif
