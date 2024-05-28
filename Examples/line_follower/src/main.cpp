#include <Arduino.h>
#include <motors.h>

//Left motor pins
#define PWM1 5 //PWM
#define DIR1 12 //Direction

//Right motor pins
#define PWM2 6 //PWM
#define DIR2 7 //Direction

#define MULTIPLIER 100 // Multiplier for better final precision after conversion to int
#define NUM_OF_SENSORS 5

#define TRIAG_NUMBER ((NUM_OF_SENSORS-1)*NUM_OF_SENSORS)/2
#define SETPOINT (MULTIPLIER*(TRIAG_NUMBER/NUM_OF_SENSORS))

#define MAX_SPEED 100 // Maximum motor speed, anything above 255 will be clamped

// PD controller coefficients - not final, should be tuned
#define Kp 0.03
#define Kd 0.01

float last_e = 0;
int value = 0;

Motors motors(PWM1,PWM2,DIR1,DIR2);

void setup() {
  Serial.begin(9600);
  motors.begin();
}

void loop() {
  uint32_t sensors_average = 0;
  uint32_t sensors_sum = 0;
  float PD, P, D, e;

  for(int i=0; i<5; i++){
    value = analogRead(i);
    sensors_average += uint32_t(value * i) * MULTIPLIER;  
    sensors_sum += value;
  }
  
  e = (int(sensors_average/sensors_sum)-SETPOINT);
  P = e*Kp;
  D = (e - last_e)*Kd;
  last_e = e;
  PD = P + D;
  
  int speed1 = int(MAX_SPEED*(1+PD));
  int speed2 = int(MAX_SPEED*(1-PD));

  if (sensors_sum < 3500){
    motors.drive(speed1, speed2);
  }
  else{
    motors.stop();
  }
}