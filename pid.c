#include "pid.h"

static float integral = 0;
static float prev_error = 0;

float pid_control(float setpoint, float measured)
{
    float Kp = 2.0;
    float Ki = 0.5;
    float Kd = 1.0;

    float error = setpoint - measured;

    // Integral update
    integral += error;

    // Anti-windup
    if (integral > 100)
        integral = 100;
    if (integral < -100)
        integral = -100;

    // Derivative
    float derivative = error - prev_error;

    float output = Kp * error + Ki * integral + Kd * derivative;

    prev_error = error;

    return output;
}