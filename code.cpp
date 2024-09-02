#include <BluetoothSerial.h>  // Include the Bluetooth Serial library
#include "Wire.h"
BluetoothSerial SerialBT;  // Create an instance of the BluetoothSerial class
char incomingChar;

#define PIN_IN1  23
#define PIN_IN2  19 
#define PIN_ENA  13 
#define PIN_IN3  18
#define PIN_IN4  4 

void MoveForward(void);
void BackForward(void);
void MoveRight(void);
void MoveLeft(void);
void Stop(void);

void MoveForward(void) 
{
  digitalWrite(PIN_IN1, HIGH);
  digitalWrite(PIN_IN2, LOW);
  digitalWrite(PIN_IN3, LOW);
  digitalWrite(PIN_IN4, HIGH);
  analogWrite(PIN_ENA, 255);
 // analogWrite(ENB, 150);
}
void MoveBackward(void) 
{
  digitalWrite(PIN_IN1, LOW);
  digitalWrite(PIN_IN2, HIGH);
  digitalWrite(PIN_IN3, HIGH);
  digitalWrite(PIN_IN4, LOW);
  analogWrite(PIN_ENA, 255);
 // analogWrite(ENB, 150);
}

void MoveRight(void) 
{
  digitalWrite(PIN_IN1, HIGH);
  digitalWrite(PIN_IN2, LOW);
  digitalWrite(PIN_IN3, LOW);
  digitalWrite(PIN_IN4, LOW);
  analogWrite(PIN_ENA, 255);
}

void MoveLeft(void) 
{
  digitalWrite(PIN_IN1, LOW);
  digitalWrite(PIN_IN2, LOW);
  digitalWrite(PIN_IN3, LOW);
  digitalWrite(PIN_IN4, HIGH);
  analogWrite(PIN_ENA, 255);
}

void Stop(void) 
{
  digitalWrite(PIN_IN1, LOW);
  digitalWrite(PIN_IN2, LOW);
  digitalWrite(PIN_IN3, LOW);
  digitalWrite(PIN_IN4, LOW);
  analogWrite(PIN_ENA, 0);
}

void setup() 
{
  // Start the Serial Monitor with a baud rate of 115200
  Serial.begin(115200); 

  // Initialize Bluetooth with the name "ESP32_BT"       
  SerialBT.begin("ESP32_BT");  
  Serial.println("Bluetooth device is ready to pair.");
  
  pinMode(PIN_IN1, OUTPUT);
  pinMode(PIN_IN2, OUTPUT);
  pinMode(PIN_IN3, OUTPUT);
  pinMode(PIN_IN4, OUTPUT);
  pinMode(PIN_ENA, OUTPUT);

}

void loop() 
{
  
  if (SerialBT.available()) 
  {
    // Read a character from the Bluetooth serial connection
    incomingChar = SerialBT.read();
    
    // Print the received character to the Serial Monitor
    //Serial.print("Received: ");
    Serial.println(" ");
    Serial.println(incomingChar);

    if(incomingChar == 'F')
    {
      //Serial.println("hi");
      MoveForward();
    }
    else if (incomingChar == 'B')
    {
      MoveBackward();
    }
    else if (incomingChar == 'S')
    {
      Stop();
    }
    else if (incomingChar == 'R')
    {
      MoveRight();
    }
    else if (incomingChar == 'L')
    {
      MoveLeft();
    }

  }

}
