#include <BluetoothSerial.h>
#define LedPin 12
BluetoothSerial BT;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  BT.begin("LAPTOP-0EHG6RB3");//請改名
  pinMode(LedPin, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  while (BT.available()) {
    //讀取藍芽資料
    String BTdata=BT.readString();
    //顯示在序列視窗
    Serial.println(BTdata);
    if (BTdata=="a"){
    digitalWrite(12,HIGH);
    delay(1000);}
    if (BTdata=="b"){
    digitalWrite(12,LOW);
    delay(1000);}
    delay(1);
}
}
