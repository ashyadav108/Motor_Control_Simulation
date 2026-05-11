#include <stdio.h>
#include "motor.h"
#include "pid.h"

int main()
{
    float setpoint = 100;
    float speed = 0;

    FILE *file = fopen("output.csv", "w");

    if (file == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(file, "Step,Speed\n");

    for (int i = 0; i < 100; i++)
    {
        float control = pid_control(setpoint, speed);

        // Limit PWM (0–255)
        if (control > 255)
            control = 255;
        if (control < 0)
            control = 0;

        speed = update_motor(control);

        printf("Step %d: Speed = %.2f\n", i, speed);

        fprintf(file, "%d,%.2f\n", i, speed);
    }

    fclose(file);

    printf("Data saved to output.csv\n");

    return 0;
}