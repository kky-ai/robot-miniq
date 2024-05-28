#define FORWARD 0
#define BACKWARD 1

class Motors {
public:
    uint8_t pwm1, pwm2, direction1, direction2;
 
    Motors(uint8_t pwmn1, uint8_t pwmn2, uint8_t drn1, uint8_t drn2);
    void begin();
    void drive(int16_t speed1, int16_t speed2);
    void stop();
};