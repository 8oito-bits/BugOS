#include "../include/drivers/io.h"

void io_out_byte(unsigned short port, unsigned char value)
{
	__asm__ __volatile__(
			"outb %%al, %%dx"
			: : "r" (value), "r" (port));
}
