#include "/home/oleg/C/protocol.h"
#include "/home/oleg/C/UART.h"
#include "Arduino.h"
char data[256];
package pkg;
bool read_magic()
{
  word mg;
  Serial.readBytes((byte*)&mg, 2);
  return (mg == MAGIC)? true: false;
}
void read_package()
{
  pkg.magic = MAGIC;
  Serial.readBytes((byte*)&pkg.version, 2);
  Serial.readBytes(&(pkg.opcode), 1);
  Serial.readBytes(&(pkg.dsize), 1);
  Serial.readBytes(&(pkg.crc), 1);
  Serial.readBytes(data, (int)pkg.dsize);
  pkg.data = (pbyte*)data;
  send(&pkg);
}

