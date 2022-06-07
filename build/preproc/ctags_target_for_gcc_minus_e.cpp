# 1 "c:\\Users\\dell\\Desktop\\University\\Semester2\\Elec Project\\Line_Follow_Code\\Line_Follow.ino"

# 3 "c:\\Users\\dell\\Desktop\\University\\Semester2\\Elec Project\\Line_Follow_Code\\Line_Follow.ino" 2
# 4 "c:\\Users\\dell\\Desktop\\University\\Semester2\\Elec Project\\Line_Follow_Code\\Line_Follow.ino" 2

const uint8_t MA_IN1 = 2;
const uint8_t MA_IN2 = 3;
const uint8_t MB_IN1 = 4;
const uint8_t MB_IN2 = 5;
const uint8_t ENA = 9;
const uint8_t ENB = 10;

const uint32_t dtime = 5000;

const uint8_t sensor_array_pins[8] = {A0,A1,A2,A3,A4,A5,A6,A7};







void setup()
{
Serial.begin(9600);
// auto motors = MotorController(
//     MA_IN1,
//     MA_IN2,
//     MB_IN1,
//     MB_IN2,
//     ENA,
//     ENB
// );

auto sensors = SensorArray(sensor_array_pins,8,900);
bool found = false;
while (true)
{

    Serial.println(10*sensors.calculate_digital(found));


}



}
void loop()
{

}
