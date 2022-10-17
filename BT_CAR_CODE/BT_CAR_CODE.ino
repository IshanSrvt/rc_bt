

#include <SoftwareSerial.h>
SoftwareSerial BlueTooth(0, 1);    
char BT_input;                    
int motorPin1 = 8;                
int motorPin2 = 9;                


void setup()  
{
  BlueTooth.begin(9600);  
  Serial.begin(9600);
  Serial.println("Started");
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);                                                                                                              
}

void loop() 
{
  if (BlueTooth.available())
  {
    BlueTooth.println("Connection Established...");
   BT_input=BlueTooth.read();
    if (BT_input=='s')
    {
      digitalWrite(motorPin1, LOW);   
      digitalWrite(motorPin2, LOW);
      delay(1000);   
         
      Serial.println("Motors are Off");
      BlueTooth.println("s");
    }
    else if (BT_input=='l')
    {
      digitalWrite(motorPin1, LOW);   
      digitalWrite(motorPin2, HIGH);
      delay(1000);  
       
      Serial.println("Motors are rotating left");
      BlueTooth.println("Motors are rotating left");
    }
    else if (BT_input=='r')
    {
      digitalWrite(motorPin1, HIGH); 
      digitalWrite(motorPin2, LOW); 
      delay(1000);
      
      Serial.println("Motors are rotating right");
      BlueTooth.println("Motors are rotating right");
    }
   else if (BT_input=='f')
    {
      digitalWrite(motorPin1, HIGH); 
      digitalWrite(motorPin2, HIGH);
      delay(1000); 
       
      Serial.println("MOTORS FORWARD");
      BlueTooth.println("MOTORS FORWARD");
    }
    
  }
 
}
