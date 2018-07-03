#include "protocol.h"
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
void send(package *pkg, int fd)
{
	write(fd, (char*)pkg, sizeof(package) - sizeof(pbyte*));
	write(fd, (char*)pkg->data, ((int)pkg->dsize));
}
pword bytes_to_word(pbyte o, pbyte t)
{
	pword buf = o;
	buf << 8;
	buf |= t;
	return buf;
}
package *receive(int fd)
{
	package *pkg  = malloc(sizeof(package));
	int n2, cur = 0;
	char bf[100];
	//scanf("%d", &cur);
	while ((n2 = read(fd, bf, 100)) == 0)
		;
	cur += n2;
	while ((n2 = read(fd, bf + cur, 100)) != 0)
		cur += n2;
	printf("%d\n", n2);
	pkg->magic = bytes_to_word(bf[0], bf[1]);
	pkg->version = bytes_to_word(bf[2], bf[3]);
	pkg->opcode = bf[4];
	pkg->dsize = bf[5];
	pkg->crc = bf[6];
	pbyte *dt = calloc((int)pkg->dsize, sizeof(pbyte));
	memcpy(dt, bf + 7, (int)pkg->dsize);
	return pkg;
}