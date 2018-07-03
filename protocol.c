#include "protocol.h"
void init_package_header(package *pkg)
{
	pkg->magic = MAGIC;
	pkg->version = CURRENT_VERSION;
}
void init_command_package (package *pkg, pbyte opc, pbyte *args)
{
	pkg->opcode = opc;
	pkg->data = args;
}
void init_data_package(package *pkg, pbyte *data, int sz)
{
	pkg->opcode = 0x0;
	pkg->data = data;
	pkg->dsize = sz;
}