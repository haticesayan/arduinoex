
#include <LiquidCrystal.h> //add lcd library 
#include <SparkFun_ADXL345.h> // dowloand and add sparkfun adxl345 library on internet
LiquidCrystal lcd(12,11,5,4,3,2); //Choose numbers for lcd to connect with ardunio
ADXL345 adxl345 = ADXL345(); // Create an adl345 using sparkfun library

int adxlX=0; // initialize variables for adxl345
int adxlY=0;
int adxlZ=0;
long Time=0; // initialize time
#define incomeX 255 // define income variables
#define incomeY 259
#define incomeZ 257
   void setup(){
 adxl345.powerOn(); // adxl345 set using sparkfun adxl345 library
 adxl345.setRangeSetting(2);
 adxl345.setSpiBit(0);
  lcd.begin(16, 2); // begining lcd
  lcd.clear(); 
  lcd.setCursor(0,0);// set first row
  lcd.print("Hatice Sayan"); // write first row
  lcd.setCursor(0, 1); // set second row
  lcd.print("20170808035"); // write second row
  delay(5000); // write for 5 seconds
  lcd.clear(); // clear all from lcd
  }
#define setX 21 // define set variables for adxl345 x,y,z dimensions
#define setY -7
#define setZ -2
void Device(int number){ //method for designing a stopwatch device
  if(number==2){} //if number is 2 then don't do anything
    else{
    Time=millis();  // else start stopwatch device
    }
lcd.setCursor(0,1); // set second row
int minutes=(Time/60000)%60; // define minutes
if(minutes<10){lcd.print("0"); // if minutes less than 10 write second row "0"
}
lcd.print(minutes); // write minutes
lcd.print(":"); // write ":"
int seconds=(Time/1000)%60; // define seconds
if(seconds<10){ //if seconds less than 10 write second row "0"
  lcd.print("0");
}
lcd.print(seconds);/// write seconds
lcd.print(":"); // write ":"
int mseconds= Time%100; // define miliseconds
if(mseconds<10){ //if miliseconds less than 10 write second row "0"
 lcd.print("0");
  }
lcd.print(mseconds);// write miliseconds
}
void show(int x,int y,int z){ // method for showing x,y,z for adxl345 dimensions
 lcd.setCursor(0,0); // set frist row
 lcd.print(x); //write x
 lcd.print(":"); // write :
 lcd.print(y); // write y
  lcd.print(":"); // write :
  lcd.print(z); // write z
  }
  void Device_reset() // method for reset stopwatch device
{
 lcd.clear(); // clear all in lcd
 lcd.setCursor(0,1); // set second row
 lcd.print("RESET"); // write reset on lcd
 adxlX=00; // set dimensions values to 0
 adxlY=00;    
 adxlZ=00;    
 Time=millis();  // start stopwatch device
}
void loop() {int x,y,z;
lcd.clear(); // clear all in lcd
Device(2); // do not do anything on lcd for start position
if(millis()%2000){ 
 adxl345.readAccel(&x,&y,&z); //read all dimensions using sparkfun adxl345 library
 adxlX=(x-setX)/incomeX; // set all dimensions using defined variables
 adxlY=(y-setY)/incomeY;
 adxlZ=(z-setZ)/incomeZ; 
 
 if(adxlZ==1){ // if z dimension equals 1 start stopwatch device
  Device(1); 
  } 
  else if(adxlX==-1){ // if x dimension equals -1 stop the device and write stopped on lcd 
 Device(2);
 lcd.print(" Stopped");
 }
 else if(adxlY==1){ // if y dimension equals 1 reset the device
  Device_reset();
  }
else{
 Device(1); // else keep going on stopwatch
  }}
  show(adxlX,adxlY,adxlZ); // show in first row x:y:z
delay(100); // delay for 1 seconds/10
}
