/*
  Serial Event example

 When new serial data arrives, this sketch adds it to a String.
 When a newline is received, the loop prints the string and
 clears it.

 A good test for this is to try it with a GPS receiver
 that sends out NMEA 0183 sentences.

 Created 9 May 2011
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/SerialEvent

 */


#include <LiquidCrystal.h>
#include <stdio.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(8, 9);

LiquidCrystal lcd(6, 7, 5, 4, 3, 2);
 unsigned char rcv,count,gchr,gchr1,robos='s';
 //char pastnumber[11]="";
 


String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

int motor1a = 10;
int motor1b= 11;
int motor2a=6;
int motor2b=5;


int val1 = 0,val2 = 0;

void okcheck()
{
  unsigned char rcr;
  do{
      rcr = Serial.read();
    }while(rcr != 'K');
}
void setup() 
{
  // initialize serial:
  Serial.begin(9600);serialEvent();
  mySerial.begin(9600);
  
//    serialEvent();
  pinMode(motor1a, OUTPUT);
  pinMode(motor1b, OUTPUT);
  pinMode(motor2a, OUTPUT);
  pinMode(motor2b, OUTPUT); 

  
  digitalWrite(motor1a, LOW); 
   digitalWrite(motor1b, LOW);  digitalWrite(motor2a, LOW);  digitalWrite(motor2b, LOW); 
  
  //cli();
  //serialEvent();
  
   
   // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Bluetooth Home Automation");

  delay(1000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("L1:"); //3,0
  lcd.setCursor(8, 0);  
  lcd.print("L2:"); //11,0

  //serialEvent();
}

void loop() 
{

// Serial.write("AT\r\n");//
 if(mySerial.available() > 0)
   {
     char inChar1 = (char)mySerial.read();delay(10);
     if(inChar1 == 'f')
       {
                   digitalWrite(motor1a, HIGH);
                   digitalWrite(motor1b, LOW);
                    digitalWrite(motor2a, HIGH);
                   digitalWrite(motor2b, LOW);
                  
       }
     if(inChar1 == 'b')
       {
                   digitalWrite(motor1a, LOW);
                   digitalWrite(motor1b, HIGH);
                    digitalWrite(motor2a, LOW);
                   digitalWrite(motor2b, HIGH);
                  
       }
     if(inChar1 == 'l')
       {
                   digitalWrite(motor1a, HIGH);
                   digitalWrite(motor1b, LOW);
                    digitalWrite(motor2a, LOW);
                   digitalWrite(motor2b, LOW);
                  
       }
     if(inChar1 == 'r')
       {
                   digitalWrite(motor1a, LOW);
                   digitalWrite(motor1b, LOW);
                    digitalWrite(motor2a, HIGH);
                   digitalWrite(motor2b, LOW);
                  
       }
                       
   }

delay(1000);

}




void serialEvent() 
{
  while (Serial.available()) 
        {
         
         char inChar = (char)Serial.read();
           if(inChar == '*')
             {
              gchr = Serial.read();
               if(gchr == 'f')
                 { digitalWrite(motor1a, HIGH);
                   digitalWrite(motor1b, LOW);
                    digitalWrite(motor2a, HIGH);
                   digitalWrite(motor2b, LOW);
                   }
               if(gchr == 'b')
                 {                  
                 digitalWrite(motor1a, LOW);
                   digitalWrite(motor1b, HIGH);
                    digitalWrite(motor2a, LOW);
                   digitalWrite(motor2b, HIGH);
                 }
               if(gchr == 'l')
                 {                  
                    digitalWrite(motor1a, HIGH);
                   digitalWrite(motor1b, LOW);
                    digitalWrite(motor2a, LOW);
                   digitalWrite(motor2b, LOW);
                  
                 }
               if(gchr == 'r')
                 {                  
                   digitalWrite(motor1a, LOW);
                   digitalWrite(motor1b, LOW);
                    digitalWrite(motor2a, HIGH);
                   digitalWrite(motor2b, LOW);
        
                 }
             }
        }
}



/*
   sensorValue = analogRead(analogInPin);
   sensorValue = (sensorValue/9.31);
   lcd.setCursor(1,1); //rc
   lcd.print(sensorValue);
   Serial.print(sensorValue);
 */
