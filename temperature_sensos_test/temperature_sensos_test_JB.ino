
//libraries
#include <math.h>
#include <Wire.h>
#include "rgb_lcd.h"

//temp sensor connected to analog input A0
#define TEMP_SENSOR 0

//global variables
int a;
float temperature;
int B = 3975;                  //B value of the thermistor
float resistance;

//creation de un nouveau ecran nommé lcd
rgb_lcd lcd;

//les variables pour les couleurs de l'écran LCD en global !
int colorR = 0;
int colorG = 0;
int colorB = 0;

void setup()
{
    // Configure the serial communication line at 9600 baud (bits per second.)
    // nous outiliseron plutot le LCD 
    // Serial.begin(9600);

    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    lcd.setRGB(colorR, colorG, colorB) ;
    
   
}

void loop()
{
    a = analogRead(TEMP_SENSOR);
    resistance = (float)(1023 - a) * 10000 / a; //get the resistance of the sensor;
    temperature = 1/(log(resistance/10000)/B+1/298.15) - 273.15;//convert to temperature via datasheet ;
   
   
   lcd.print(temperature);
   delay(1000); // Wait one second between measurements.
   lcd.clear();

    if (temperature < 10){
      //if temp below 10 degrees, set color blue
      colorB = 255;
      colorG = 0;
      lcd.setRGB(colorR, colorG, colorB);
    } else {
      //set color green
   	  colorB = 0;
      colorG = 255;
      lcd.setRGB(colorR, colorG, colorB);
      }
}
