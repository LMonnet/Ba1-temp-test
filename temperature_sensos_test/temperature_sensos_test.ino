#include <math.h>
int a;
float temperature;
int B=3975;                  //B value of the thermistor
float resistance;


#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;
int colorR = 0;
int colorG = 0;
int colorB = 0;

void setup()
{
    // Configure the serial communication line at 9600 baud (bits per second.)
    Serial.begin(9600);

     // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);

    lcd.setRGB(colorR, colorG, colorB) ;
    
   
}

void loop()
{
    a=analogRead(0);
    resistance=(float)(1023-a)*10000/a; //get the resistance of the sensor;
    temperature=1/(log(resistance/10000)/B+1/298.15)-273.15;//convert to temperature via datasheet ;
   
   
   lcd.print(temperature);

 
    // Wait one second between measurements.
    delay(1000);
    lcd.clear();

    if (temperature < 10){
      //if temp below 10 degrees, set color blue
      colorB = 255;
      lcd.setRGB(colorR, colorG, colorB);
    }
    else {
      //set color green
      int colorG = 255;
      lcd.setRGB(colorR, colorG, colorB);
      }
}
