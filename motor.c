#include "motor.h"

static float motor_speed = 0;

float update_motor(float voltage)
{
    float K = 0.1;       // Motor constant
    float inertia = 0.9; // Smooth response

    motor_speed = inertia * motor_speed + K * voltage;

    return motor_speed;
}