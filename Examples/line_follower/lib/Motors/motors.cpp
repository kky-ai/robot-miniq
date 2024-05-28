#include <Arduino.h>
#include <motors.h>

Motors::Motors(uint8_t pwmn1, uint8_t pwmn2, uint8_t drn1, uint8_t drn2) : pwm1(pwmn1), pwm2(pwmn2), direction1(drn1), direction2(drn2){}

void Motors::begin(){
    //Setup motor pins
    pinMode(pwm1, OUTPUT);
    pinMode(pwm2, OUTPUT);
    pinMode(direction1, OUTPUT);
    pinMode(direction2, OUTPUT);
}

void Motors::drive(int16_t speed1, int16_t speed2){
    //Set backwards if speed is lower than 0
    digitalWrite(direction1, speed1 < 0);
    digitalWrite(direction2, speed2 < 0);

    //Throw away the signs and clamp the value
    speed1 = abs(speed1);
    speed2 = abs(speed2);
    speed1 = speed1 > 255 ? 255 : speed1;
    speed2 = speed2 > 255 ? 255 : speed2;

    //Set motor speed
    analogWrite(pwm1, speed1);
    analogWrite(pwm2, speed2);
}

void Motors::stop(){
    //Stop motors
    analogWrite(pwm1, 0);
    analogWrite(pwm2, 0);
}