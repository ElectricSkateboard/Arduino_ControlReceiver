#include <SoftwareSerial.h>// import the serial library
#include <Servo.h>
SoftwareSerial Bluetooth(2, 3); // RX, TX
int BluetoothData; // the data given from Computer
Servo ESC;
int conPin = 7;


void setup() {
  // put your setup code here, to run once:
  Bluetooth.begin(115200);
  Serial.begin(9600);
  Serial.println("Bluetooth On");
  ESC.attach(9);
  pinMode(conPin,INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
   if (Bluetooth.available()){
    BluetoothData=Bluetooth.read();
    if(digitalRead(conPin) == 1)
    {
      ESC.write(BluetoothData);
      Serial.println(BluetoothData);
    }
   }
   if (digitalRead(conPin) == 0)
   {
    ESC.write(0);
    Serial.println(0);
   }
}

