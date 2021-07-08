#include "../include/drivers/vga.h"

int kmain(void)
{
	vga_write_char('W', 0x1);
	return 0;
}
