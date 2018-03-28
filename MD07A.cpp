//
// Created by PK3 on 3/8/2018.
//
#import <Arduino.h>
#include "MD07A.h"

class MD07A{
  public:
  int pin_dir;
  int pin_pwmh;
  int pin_reset;

  // Default constructor, default pins are 5,6,7
  MD07A(){
    pin_dir = 5;
    pin_pwmh = 6;
    pin_reset = 7;

    pinMode(pin_dir, OUTPUT);
    pinMode(pin_pwmh, OUTPUT);
    pinMode(pin_reset, OUTPUT);
  }

  // Constructor with necessary pin definitions
  MD07A(int DirectionPin, int PWMHPin, int ResetPin){
    pin_dir = DirectionPin;
    pin_pwmh = PWMHPin;
    pin_reset = ResetPin;

    pinMode(pin_dir, OUTPUT);
    pinMode(pin_pwmh, OUTPUT);
    pinMode(pin_reset, OUTPUT);
  }

  void Sleep(bool sleep){
    // Write opposite to reset pin (active low)
    digitalWrite(pin_reset, !sleep);
  }
  // ---------------------------------------------------------------------------
  //  Rotate (base function)
  //  PARAMS:
  //    bool  direction   Direction for the motor to spin, no reference yet
  //    float degrees     Desired angular displacement (est)
  //  Spin the motor an estimated number of degrees. Assuming that the motor
  //    spins at a constant 12 RPM as listed in datasheet and that motor is
  //    under low load, immediate response. The motor is turned on for a
  //    calculated time interval corresponding to an est. angular displacement
  //  --------------------------------------------------------------------------
  void Rotate(bool direction, float degrees){
    int timeDelay;
    // Determine direction
    digitalWrite(pin_dir, direction);

    // Determine time to spin
    delay = MS_PER_RAD * DegToRad(degrees);
    this->IndicatorLED(true);
    digitalWrite(pin_pwmh, HIGH);
    delay(timeDelay);
    digitalWrite(pin_pwmh, LOW);
    this->IndicatorLED(false);
  }

  // ---------------------------------------------------------------------------
  //  Rotate (overloaded with duty cycle)
  //  PARAMS:
  //    bool  direction   Direction for the motor to spin, no reference yet
  //    float degrees     Desired angular displacement (est)
  //    int   dutyCycle   Duty cycle to use, scaled from 0-255
  //  Supposed to allow for variable power, not sure how well the timing will
  //    work in predicting the position, needs to be tested
  //  --------------------------------------------------------------------------
  void Rotate(bool direction, float degrees, int dutyCycle){
    // Check that pin_PWMH is actually a PWM pin, otherwise call other fcn
    if(pin_pwmh != 2 || pin_pwmh != 3 || pin_pwmh != 5 || pin_pwmh != 6){
      this->Rotate(direction, degrees);
    }
    else{
      int timeDelay;
      // Determine direction
      digitalWrite(pin_dir, direction);

      // Determine time to spin
      delay = MS_PER_RAD * DegToRad(degrees);
      this->IndicatorLED(true);
      analogWrite(pin_pwmh, dutyCycle);
      delay(timeDelay);
      digitalWrite(pin_pwmh, LOW);
      this->IndicatorLED(false);
    }
  }

  void IndicatorLED(bool enable){
    digitalWrite(LED_BUILTIN, enable);
  }
};

float DegToRad(float degrees){
  return degrees/180*PI;
}

