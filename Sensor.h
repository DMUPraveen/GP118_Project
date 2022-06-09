#ifndef SENSOR
#define SENSOR


struct  SensorArray
{
    const uint8_t* analog_pins = nullptr;
    uint8_t number_of_pins = 0;
    uint32_t threshold = 0;
    SensorArray(const uint8_t* analog_pins,uint8_t number_of_pins,uint32_t threshold)
        :analog_pins(analog_pins),number_of_pins(number_of_pins),threshold(threshold)
    {
        for(int i = 0;i<number_of_pins;i++){
            pinMode(analog_pins[i],INPUT);
        }
    }

    float calculate_digital(bool& found){
        /*
        calculates the error with digital filtering on the sensor
        */
        found = false;
        float pos = 0;
        uint32_t number = 0;
        for(int i =0;i<number_of_pins;i++){
            uint8_t re = analogRead(analog_pins[i]) > threshold; //Larger value for balck returns 1 indicating
            if(re){
                pos += (2/((float)number_of_pins-1)*i-1);
                number += 1;
            }
        }
        if(!number){
            return 0;
        }
        found = true;
        return pos/number;
    }
};
#endif