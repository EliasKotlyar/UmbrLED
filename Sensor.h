
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM9DS0.h>

class Sensor
{
  public:

    Sensor(void);
    void setup(void);
    void loop(void);
    int getZAxis(void);
    float getAngle(void);

  private:
    Adafruit_LSM9DS0 lsm = Adafruit_LSM9DS0(1000);  // Use I2C, ID #1000
    int zAxis;
    unsigned char gyroValue = 0;
    unsigned char offset = 136;
    float angle = 0;
    float gyroRate;
    

};
