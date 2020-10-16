


#include <LiquidCrystal.h>
#include <stdio.h>
#include <SoftwareSerial.h>
LiquidCrystal lcd(4,5,6,7,8,9);
unsigned char rcv,count,gchr,gchr1,robos='s';
 //char pastnumber[11]="";
 


String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

int light1 = 10;
int light2= 11;
int light3=12;
int light4=13;


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

//    serialEvent();
  pinMode(light1, OUTPUT);
  pinMode(light2, OUTPUT);
  pinMode(light3, OUTPUT);
  pinMode(light4, OUTPUT); 

  
  digitalWrite(light1, LOW); 
   digitalWrite(light2, LOW);  digitalWrite(light3, LOW);  digitalWrite(light4, LOW); 
  
  //cli();
  //serialEvent();
  
   
   // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Bluetooth Home Automation");

  delay(1000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("L1:");
  lcd.setCursor(8, 0);
  lcd.print("L2:");
  lcd.setCursor(0, 1);
  lcd.print("L3:");
  lcd.setCursor(8, 1);
  lcd.print("L4:");
  
  
  //serialEvent();
}

void loop() 
{

 //Serial.write("AT\r\n");
 while(Serial.available())
   {
     char inChar1 = (char)Serial.read();
    
     Serial.write(inChar1);
     Serial.write("\r\n");
      delay(10);
     if(inChar1 == '1')
       {lcd.setCursor(3, 0);
        lcd.print("ON ");
         digitalWrite(light1, HIGH); 
         
                  
       }
     if(inChar1 == '2')
       {
         lcd.setCursor(3, 0);
        lcd.print("OFF");digitalWrite(light1, LOW);
                 
                  
       }
     if(inChar1 == '3')
       {lcd.setCursor(11, 0);
        lcd.print("ON ");
         digitalWrite(light2, HIGH);
                   
       }
     if(inChar1 == '4')
       {lcd.setCursor(11, 0);
        lcd.print("OFF");
         digitalWrite(light2, LOW);
                  
          
      if(inChar1 == '5')
       {lcd.setCursor(3, 1);
        lcd.print("ON ");
         digitalWrite(light3, HIGH);
                   
       }
     if(inChar1 == '6')
       {lcd.setCursor(3, 1);
        lcd.print("OFF");
         digitalWrite(light3, LOW);
                  
                  
       }
 if(inChar1 == '7')
       {lcd.setCursor(11, 0);
        lcd.print("ON ");
         digitalWrite(light4, HIGH);
                   
       }
     if(inChar1 == '8')
       {lcd.setCursor(11, 1);
        lcd.print("OFF");
         digitalWrite(light4, LOW);
                  
                  
       }       
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
              Serial.write(gchr);
              Serial.write("\r\n");
               if(gchr == '1')
                 { lcd.clear();
                   lcd.print("Front");
                   
                   }
               if(gchr == '2')
                 {  lcd.clear();
                   lcd.print("Back");                
                 
                 }
               if(gchr == '3')
                 {     lcd.clear();
                   lcd.print("left");              
                   
                  
                 }
               if(gchr == '4')
                 {  lcd.clear();
                   lcd.print("Right");                 
                  
        
                 }
                 if(gchr == '5')
                 {  lcd.clear();
                   lcd.print("Right");                 
                  
        
                 }
                 if(gchr == '6')
                 {  lcd.clear();
                   lcd.print("Right");                 
                  
        
                 }
                 if(gchr == '7')
                 {  lcd.clear();
                   lcd.print("Right");                 
                  
        
                 }
                 if(gchr == '8')
                 {  lcd.clear();
                   lcd.print("Right");                 
                  
        
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
