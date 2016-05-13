#include <Wire.h>
#include <Adafruit_LSM9DS0.h>
Adafruit_LSM9DS0 lsm;
 
// Here is where you can put in your favorite colors that will appear!
// just add new {nnn, nnn, nnn}, lines. They will be picked out randomly
//                                  R   G   B

 
// mess with this number to adjust TWINklitude :)
// lower number = more sensitive
#define MOVE_THRESHOLD 400
#define WAITFORCLICKS 3
 
void setup() 
{
  //Serial.begin(9600);
  Serial.println("init all");
  // Try to initialise and warn if we couldn't detect the chip
  if (!lsm.begin())
  {
    Serial.println("Oops ... unable to initialize the LSM303. Check your wiring!");
    while (1);
  }
  setupBluetooth();
}
 
void loop() 
{
 watchSensor();
}

int countClicks = 0;

void watchSensor() {
  lsm.read();
  double storedVector = lsm.accelData.y;

    // wait a bit
  delay(100);
  
  // get new data!
  lsm.read();
  double newVector = lsm.accelData.y;

  if (storedVector <= -11000 && newVector >= 11000) {
    countClicks++;  
  }

  // n times
  if (countClicks == WAITFORCLICKS) {
    notify();
    Serial.println("Twinkle!");
    countClicks = 0;
  }
}

/*
void watchSensor() {
  lsm.read();
  double storedVector = lsm.accelData.x*lsm.accelData.x;
  storedVector += lsm.accelData.y*lsm.accelData.y;
  storedVector += lsm.accelData.z*lsm.accelData.z;
  storedVector = sqrt(storedVector);
    
  // wait a bit
  delay(200);
  
  // get new data!
  lsm.read();
  double newVector = lsm.accelData.x*lsm.accelData.x;
  newVector += lsm.accelData.y*lsm.accelData.y;
  newVector += lsm.accelData.z*lsm.accelData.z;
  newVector = sqrt(newVector);
  
  // are we moving 
  if (abs(newVector - storedVector) > MOVE_THRESHOLD) {
    Serial.println(".");
    countClicks++;
  }

  // n times
  if (countClicks == WAITFORCLICKS) {
    Serial.println("Twinkle!");
    notify();
    countClicks = 0;
  }
}
*/
