
#ifndef ROBOT
#define ROBOT

#include "Motor_Controller.h"
#include "Sensor.h"

const float memory_factor = 0.6;
const float recovery_speed = 0.5;
const uint32_t recovery_time = 1000;
struct Robot{
    MotorController* motor;
    SensorArray* sensor;
    float accumilated_error = 0.0f;
    Robot(MotorController* motor,SensorArray* sensor)
        :motor(motor),sensor(sensor)
    {
        accumilated_error = 0.0f;
    }

    void P_Control(){
        bool found = false;
        float reading = 0.0f;
        for(;;){
            reading = sensor->calculate_digital(found);
            motor->control(0.5-0.5*reading,0.5+0.5*reading);
            while(!found){
                if(accumilated_error < 0){
                    motor->control(recovery_speed,0);
                }
                else{
                    motor->control(0,recovery_speed);
                }
                reading = sensor->calculate_digital(found);
            }
            accumilated_error = (memory_factor*accumilated_error+reading);

        }
    }
};

#endif
