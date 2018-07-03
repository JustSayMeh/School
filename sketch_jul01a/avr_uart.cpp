#include "Arduino.h"
#include "/home/oleg/C/protocol.h"
bool read_magic();
void read_package();
void send(package *pkg)
{
  Serial.write((byte*)pkg, sizeof(package) - 2);
  Serial.write((byte*)(pkg->data), (int)pkg->dsize); 
}

void receive(package *pkg)
{
  while (!Serial.available())
    ;
  if (read_magic())
  {
      digitalWrite(13, HIGH);
      read_package();
  }
}

