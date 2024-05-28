#include <Arduino.h>
#include <motors.h>

//Left motor pins
#define PWM1 5 //PWM
#define DIR1 12 //Direction

//Right motor pins
#define PWM2 6 //PWM
#define DIR2 7 //Direction

#define SETPOINT 450 // Maximum (1023) / 2; shifted a little bit to one side because of an inbalance

#define MAX_SPEED 100 // Maximum motor speed, anything above 255 will be clamped

// PD controller coefficients
#define Kp 0.001
#define Kd 0.01

float last_e = 0;
int value = 0;
float e, P, D, PD;

Motors motors(PWM1,PWM2,DIR1,DIR2);

void setup() {
  motors.begin();

  while (analogRead(6)>900); // Wait for a button press
}

void loop() {
  value = analogRead(5);
  
  //PD Controller
  e = (value-SETPOINT);
  P = e*Kp;
  D = (e - last_e)*Kd;
  last_e = e;
  PD = P + D;
  
  //Calculate speed of individial motors
  int speed1 = int(MAX_SPEED*(1+PD));
  int speed2 = int(MAX_SPEED*(1-PD));

  motors.drive(speed1, speed2);
}