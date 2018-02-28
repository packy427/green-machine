/*! \file main.ino \brief green-machine main file. */
//-----------------------------------------------------------------------------
//  Filename   : main.ino
//  Title      : Main code for ME463 group The Masters for green-machine
//  Author     : Patrick Kennedy (kennedyp@purdue.edu)
//  Created    : 02/20/2018
//  Modified   : 02/28/2018
//  Version    : 0.1
//  Description:
//     Contains all functionalty for green-machine
//     NOTE: Version is below v1.0, all functions not realized
//-----------------------------------------------------------------------------

//== PIN DECLARATIONS ==//
// IR comp are numbered clockwise starting directly forward, from top view
// TODO: Inlcude ULN2003 to provide current for emitters, 20mA max/GPIO 
#define EMIT01  13
#define EMIT02  12
#define EMIT03  11
#define EMIT04  10
#define EMIT05  9

#define RCV01   A0
#define RCV02   A1
#define RCV03   A2
#define RCV04   A3
#define RCV05   A4
#define RCV06   A5

#define DCMOTOR_STBY  7
#define DCMOTOR_IN1   6
#define DCMOTOR_IN2   5
#define DCMOTOR_PWM   4

#define STEPPER_IN1   3
#define STEPPER_IN2   2
#define STEPPER_IN3   1
#define STEPPER_IN4   0

void setup(){
  // Define all output pins
  pinMode(EMIT01, OUTPUT);
  pinMode(EMIT02, OUTPUT);
  pinMode(EMIT03, OUTPUT);
  pinMode(EMIT04, OUTPUT);
  pinMode(EMIT05, OUTPUT);
  pinMode(DCMOTOR_STBY, OUTPUT);
  pinMode(DCMOTOR_IN1, OUTPUT);
  pinMode(DCMOTOR_IN2, OUTPUT);
  pinMode(DCMOTOR_PWM, OUTPUT);
  pinMode(STEPPER_IN1, OUTPUT);
  pinMode(STEPPER_IN2, OUTPUT);
  pinMode(STEPPER_IN3, OUTPUT);
  pinMode(STEPPER_IN4, OUTPUT);
  
  // Set default values for pins
  digitalWrite(DCMOTOR_STBY, LOW);
}

void loop(){
  // Todo
}
