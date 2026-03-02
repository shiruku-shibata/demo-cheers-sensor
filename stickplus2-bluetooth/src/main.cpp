#include <M5StickCPlus2.h>
#include "BluetoothSerial.h"

byte counter;
BluetoothSerial bts;

void setup() {
  auto cfg = M5.config();
  M5.begin(cfg);

  M5.Display.clear();
  M5.Display.setTextSize(2);
  M5.Display.setCursor(0, 0);
  M5.Display.println("Bluetooth Now");

  Serial.begin(9600);
  bts.begin("M5StickCPlus2"); // PC側で表示されるBluetooth名

  counter = 0;
}

void loop() {
  bts.println(counter);
  counter++;
  delay(100);
}