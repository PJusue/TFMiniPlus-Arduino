/* File Name: TFMP_example.ino
 * Developer: Pablo Jusue
 * Date Saturday 10 of August 2019
 *
 * Description: This is the Arduino sketch for reading the distance data of a TFMini plus. This is the simplified version of the one created by Bud Ryerson
 *
 * Default settings for the TFMini Plus are a 115200 serial baud rate
 * and a 100Hz measurement frame rate. The device will begin returning
 * measurement data right away:
 *   Distance in centimeters,
 *   Signal strength in arbitrary units,
 *   and an encoded number for Temperature in degrees centigrade.
 */

#include <TFMPlus.h>  // Include TFMini Plus Library v1.3.4
TFMPlus tfmP;         // Create a TFMini Plus object

#include "printf.h"   // May not work corrrectly with Intel devices

#include <SoftwareSerial.h>       // alternative software serial library
SoftwareSerial Serial2(10, 11);  // Choose the correct RX, TX Pins

uint16_t tfDist;       // Distance measurement in centimeters (default)
uint16_t tfFlux;       // Luminous flux or intensity of return signal
uint16_t tfTemp;       // Temperature in degrees Centigrade (coded)




/*  - - -   End of useful Lidar commands   - - - -   */

void setup()
{
    Serial.begin( 115200);   // Intialize terminal serial port
    delay(20);               // Give port time to initalize
    printf_begin();          // Initialize printf.

    Serial2.begin( 115200);  // Initialize TFMPLus device serial port.
    delay(20);               // Give port time to initalize
    tfmP.begin( &Serial2);   // Initialize device library object and...
                             // pass device serial port to the object.

    tfDist = 0;            // Clear device data variables.
    tfFlux = 0;
    tfTemp = 0;

    delay(500);            // And wait for half a second.
}

// Use the 'getData' function to pass back device data.
void loop()
{
   tfmP.getData( tfDist, tfFlux, tfTemp); // Get data from the device.  
   printf( "%d\n", tfDist);           // Display the distance.
    //printf("%d",tfDist);


  // 3. Finish up and advance the loop counter
  delay(10);       // Delay to match the 100Hz data frame rate.
}
