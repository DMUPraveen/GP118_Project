#line 1 "c:\\Users\\dell\\Desktop\\University\\Semester2\\Elec Project\\Line_Follow_Code\\Robot.h"

#ifndef ROBOT
#define ROBOT

#include "Motor_Controller.h"
#include "Sensor.h"


struct Robot{
    MotorController* motor;
    SensorArray* sensor;
    Robot(MotorController* motor,SensorArray* sensor)
        :motor(motor),sensor(sensor)
    {
        
    }

    void P_Control(){
        bool found = false;
        for(;;){
            auto reading = sensor->calculate_digital(found);
            motor->control(0.5+0.5*reading,0.5-0.5*reading);
        }
    }
};

#endif