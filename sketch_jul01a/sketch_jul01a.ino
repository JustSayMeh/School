#include "/home/oleg/C/protocol.h"
#include "/home/oleg/C/UART.h"
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  package pkg;
  receive(&pkg);
}
