
#include "Sensor.h"

Sensor::Sensor(void)
{


}
void Sensor::setup()
{
  if(!lsm.begin())
{
  /* There was a problem detecting the LSM9DS0 ... check your connections */
  Serial.print(F("Ooops, no LSM9DS0 detected ... Check your wiring or I2C ADDR!"));
  while(1);
}

  // 1.) Set the accelerometer range
    lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_2G);
    //lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_4G);
    //lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_6G);
    //lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_8G);
    //lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_16G);

    // 2.) Set the magnetometer sensitivity
    lsm.setupMag(lsm.LSM9DS0_MAGGAIN_2GAUSS);
    //lsm.setupMag(lsm.LSM9DS0_MAGGAIN_4GAUSS);
    //lsm.setupMag(lsm.LSM9DS0_MAGGAIN_8GAUSS);
    //lsm.setupMag(lsm.LSM9DS0_MAGGAIN_12GAUSS);

    // 3.) Setup the gyroscope
    lsm.setupGyro(lsm.LSM9DS0_GYROSCALE_245DPS);
    //lsm.setupGyro(lsm.LSM9DS0_GYROSCALE_500DPS);
    //lsm.setupGyro(lsm.LSM9DS0_GYROSCALE_2000DPS);
}

/*
TODO:
//http://ozzmaker.com/berryimu/
*/
void Sensor::loop()
{
    /* Get a new sensor event */
  sensors_event_t accel, mag, gyro, temp;
  lsm.getEvent(&accel, &mag, &gyro, &temp);
  zAxis = gyro.gyro.z;




}
float Sensor::getAngle(){
  return angle;
}

int Sensor::getZAxis(){
  return zAxis;
}
