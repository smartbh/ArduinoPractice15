#include <SoftwareSerial.h>

// 2, 3번 핀을 이용
SoftwareSerial BTSerial(3, 2); // 2<-->BT의 TX, 3<-->BT의 RX
int ledPin = 9;

void setup( ) 
{
  BTSerial.begin(9600); // 반드시 필요함
  pinMode(ledPin, OUTPUT);
};

void loop() 
{
   if (BTSerial.available()){
    byte read = BTSerial.read(); 
    Serial.println(read);
    if (read == 1)
      digitalWrite(ledPin, HIGH);
    else if (read == 2) 
      digitalWrite(ledPin, LOW);
  }
}

