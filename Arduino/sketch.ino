#include "hackair.h"
#include <Wire.h>
#include <Thinary_AHT10.h>

#define LOOP_COUNT 5

// Specify your sensor
hackAIR sensor(SENSOR_SDS011);

AHT10Class AHT10;

void setup() {
  // Initialize the sensor
  sensor.begin();

  // Open serial port
  Serial.begin(9600);

  Wire.begin();
  if (AHT10.begin(eAHT10Address_Low))
  {
    Serial.println("Init AHT10 Sucess.");
  }
  else
  {
    Serial.println("Init AHT10 Failure.");
  }
}

void loop() {
  sensor.turnOn();
  
  delay(5000);

  struct hackAirData data;
  sensor.readAverageData(data, LOOP_COUNT);

  //Serial.print("PM2.5: ");
  //Serial.println(data.pm25);
  //Serial.print("PM10: ");
  //Serial.println(data.pm10);
  //Serial.println("---");

  sensor.turnOff();

  for (int i = 0; i < 300; i++) {
    //Serial.print("Humidity: ");
    //Serial.println(AHT10.GetHumidity());
    //Serial.print("Temp: ");
    //Serial.println(AHT10.GetTemperature());

    Serial.print(data.pm25);
    Serial.print(",");
    Serial.print(data.pm10);
    Serial.print(",");
    Serial.print(AHT10.GetTemperature());
    Serial.print(",");
    Serial.println(AHT10.GetHumidity());
    
    delay(1000);
  }
}
