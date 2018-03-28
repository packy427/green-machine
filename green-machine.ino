/*! \file main.ino \brief green-machine main file. */
//-----------------------------------------------------------------------------
//  Filename   : main.ino
//  Title      : Main code for ME463 group The Masters for green-machine
//  Author     : Patrick Kennedy (kennedyp@purdue.edu)
//  Created    : 02/20/2018
//  Modified   : 02/28/2018
//  Version    : 0.1
//  Description:
//     Contains all functionality for green-machine
//     NOTE: Version is below v1.0, all functions not realized
//-----------------------------------------------------------------------------

#include <Stepper.h>
#include "MD07A.h"

// == PROGRAM OPTIONS == //
#define RUN_INIT_ROUTINE  1

// == CONSTANTS == //
#define DIR_LOAD_SPRING   1
#define DIR_RELEASE       0

// == PIN DECLARATIONS == //
#define RCV01   A0    // IR comp are numbered clockwise starting directly forward, from top view
#define RCV02   A1
#define RCV03   A2
#define RCV04   A3
#define RCV05   A4
#define RCV06   A5

#define EMIT_FRONT  4
#define EMIT_SIDE  3
#define EMIT_REAR  2

#define DCMOTOR_DIR   10
#define DCMOTOR_PWMH  11
#define DCMOTOR_RESET 12

#define STEPPER_IN1   6
#define STEPPER_IN2   7
#define STEPPER_IN3   8
#define STEPPER_IN4   9

// == GLOBAL VARIABLES == //
const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
const int stepSmall = 50;
const int stepMed = 100;
const int stepLarge = 200;


// == OBJECTS == //
Stepper stepperMotor(stepsPerRevolution, STEPPER_IN1, STEPPER_IN2, STEPPER_IN3, STEPPER_IN4);
MD07A launchMotor(DCMOTOR_DIR, DCMOTOR_PWMH, DCMOTOR_STBY);

void setup(){
  // Define all output pins
  pinMode(EMIT_FRONT, OUTPUT);
  pinMode(EMIT_SIDE, OUTPUT);
  pinMode(EMIT_REAR, OUTPUT);
  pinMode(DCMOTOR_STBY, OUTPUT);
  pinMode(DCMOTOR_IN1, OUTPUT);
  pinMode(DCMOTOR_IN2, OUTPUT);
  pinMode(DCMOTOR_PWM, OUTPUT);
  pinMode(STEPPER_IN1, OUTPUT);
  pinMode(STEPPER_IN2, OUTPUT);
  pinMode(STEPPER_IN3, OUTPUT);
  pinMode(STEPPER_IN4, OUTPUT);

  // Initialize obj
  stepperMotor.setSpeed(5);   // Set stepper speed to 5 rpm
  launchMotor.Sleep(false);

  // Init routine
#if RUN_INIT_ROUTINE
  digitalWrite(EMIT_FRONT, HIGH);
  delay(300);
  digitalWrite(EMIT_SIDE, HIGH);
  delay(300);
  digitalWrite(EMIT_REAR, HIGH);
  delay(300);

  stepperMotor.step(stepSmall);
  stepperMotor.step(-stepSmall);

  launchMotor.Rotate(DIR_LOAD_SPRING, 45);
  launchMotor.Rotate(DIR_RELEASE, 10);

  digitalWrite(EMIT_FRONT, LOW);
  digitalWrite(EMIT_SIDE, LOW);
  digitalWrite(EMIT_REAR, LOW);
#endif
}

void loop(){
  // Todo
}

