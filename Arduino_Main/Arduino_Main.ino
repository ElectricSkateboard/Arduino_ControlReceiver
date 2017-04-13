#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial Bluetooth(10, 11); // RX, TX
int BluetoothData; // the data given from Computer
Servo ESC;
int conPin = 2;


//#define DEBUG

void setup() {
  // put your setup code here, to run once:
  Bluetooth.begin(115200);
  #ifdef DEBUG
  Serial.begin(115200);
  Serial.println("Bluetooth On");
  #endif
  ESC.attach(12);
  pinMode(conPin,INPUT);
  
}

void loop() {
   if (Bluetooth.available()){
    BluetoothData=Bluetooth.read();
    if(digitalRead(conPin) == 1)
    {
      sendThrottle(BluetoothData);
    }
   }
   if (digitalRead(conPin) == 0)
   {
      sendThrottle(85);
   }
}

void sendThrottle(int gaz)
{
    ESC.write(gaz);
    #ifdef DEBUG
    Serial.println(gaz);
    #endif
}
