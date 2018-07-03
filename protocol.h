#ifndef PROTOCOL_H
#define PROTOCOL_H
typedef char pbyte;
typedef short int pword;
static const pword MAGIC = 0x0102;
static const pword CURRENT_VERSION = 0x0;
#pragma pack(push, 1)
typedef struct _package{
	pword magic;
	pword version;
	pbyte opcode;
	pbyte dsize;
	pbyte crc;
	pbyte *data;
} package;
#pragma pack(pop)
void init_package_header(package *pkg);
void init_command_package (package *, pbyte , pbyte *);
void init_data_package(package *, pbyte *, int);
#endif