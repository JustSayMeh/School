#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "protocol.h"
void send(package *, int);
pword bytes_to_word(pbyte , pbyte );
package *receive(int);
void init_uart(int fd, int bound)
{
	struct termios options;
	tcgetattr(fd, &options);
	cfsetispeed(&options, bound);
	cfsetospeed(&options, bound);
	tcsetattr(fd, TCSANOW, &options); 
}

int main()
{
	int fd = open("/dev/ttyACM0", O_RDWR), g;
	init_uart(fd, 9600);
	char bf[100];
	while (1)
	{
		package pkg, *rec;
		scanf("%s", bf);
		init_package_header(&pkg);
		init_data_package(&pkg, bf, strlen(bf));
		send(&pkg, fd);
		rec = receive(fd);
		for (int i = 0; i < rec->dsize; i++)
		{
			printf("%c", rec->data[i]);
		} 
		printf("\n");
	}	
	return 0;
}