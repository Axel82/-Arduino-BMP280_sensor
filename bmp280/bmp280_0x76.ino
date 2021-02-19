/***************************************************************************
This is a library for the BMP280 humidity, temperature & pressure sensor
 
This sensor use I2C protocol to communicate, 2 pins are required
to interface.

Adapt I2C adress in Adafruit_BMP280.h (mine 0x76)
Pressure at sea level : http://www.meteociel.fr/observations-meteo/pression.php
***************************************************************************/
 
#include <Wire.h>
#include <Adafruit_BMP280.h>
 
Adafruit_BMP280 myBmp280; // I2C
int Bmp280PressureHpa = 0;
 
void setup()
{
  Serial.begin(9600);
  Serial.println(F("BMP280 test"));
 
  if (!myBmp280.begin())
  {
    Serial.println("Could not find a valid BMP280 sensor, check wiring!");
    while (1);
    }
}
 
void loop()
{
  Serial.print("Temperature = ");
  Serial.print(myBmp280.readTemperature());
  Serial.println(" *C");

  Bmp280PressureHpa = myBmp280.readPressure() / 100;
  Serial.print("Pressure = ");
  Serial.print(Bmp280PressureHpa);
  Serial.println(" hPa");
 
  Serial.print("Approx altitude = "); 
  Serial.print(myBmp280.readAltitude(1018)); //The "1018" is the pressure(hPa) at sea level in day in your region
  Serial.println(" m");
 
  Serial.println();
  delay(2000);
}
