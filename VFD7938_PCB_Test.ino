
/* 
VFD7938  test

Arduino   VFD7938
Pro Mini  PCB

Pin 10    RCK
Pin 11    SER IN
Pin 13    SRCK 
*/

#include <SPI.h>

byte ssPin = 10;
byte x;

byte DisplayArray[] = {
 0,0,0,0,0,0,0,0,0,                  // ALL_ON
 255,255,255,255,255,255,255,255,255 // ALL_OFF
};

void setup(){
 SPI.begin();
 }

void loop(){
   digitalWrite (ssPin, LOW);
   for (x=0; x<9; x=x+1){
       SPI.transfer (DisplayArray[x]);
       }
   digitalWrite (ssPin, HIGH);

   delay (750);

   digitalWrite (ssPin, LOW);
   for (x=0; x<9; x=x+1){
       SPI.transfer (DisplayArray[x+9]);
       }
   digitalWrite (ssPin, HIGH);

   delay (750);  
}
