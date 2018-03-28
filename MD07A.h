//
// Created by PK3 on 3/8/2018.
//

#ifndef GREEN_MACHINE_MD07A_H
#define GREEN_MACHINE_MD07A_H

// Motor constants
#define OUTPUT_RAD_PER_SEC  1.25664   // 12 RPM
#define MS_PER_RAD          796       // 796 ms for 1 rad of rotation
#define PI                  3.1415926 // For deg/rad conversion

class MD07A{
public:
  MD07A();
  MD07A(int DirectionPin, int PWMHPin, int ResetPin);
  void Rotate(bool direction, float degrees);
  void Rotate(bool direction, float degrees, int dutyCycle);
  void Sleep(bool sleep);
  void IndicatorLED(bool enable);

private:
  int pin_dir;
  int pin_pwmh;
  int pin_reset;
};

float DegToRad(float degrees);
#endif //GREEN_MACHINE_MD07A_H
