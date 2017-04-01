#include <SoftwareSerial.h>// import the serial library
#include <Servo.h>
SoftwareSerial Bluetooth(2, 3); // RX, TX
int BluetoothData; // the data given from Computer
Servo ESC;
int conPin = 7;

#define DEBUG

void setup() {
  // put your setup code here, to run once:
  Bluetooth.begin(115200);
  #ifdef DEBUG
  Serial.begin(9600);
  Serial.println("Bluetooth On");
  #endif
  ESC.attach(9);
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
      sendThrottle(0);
   }
}

void sendThrottle(int gaz)
{
    ESC.write(gaz);
    #ifdef DEBUG
    Serial.println(gaz);
    #endif
}

