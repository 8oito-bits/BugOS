#include "../../include/drivers/vga.h"

static short *video_memory = (short *) 0xb8000;
static int cursor_position_x = 0;
static int cursor_position_y = 0;

void vga_write_char(unsigned char c, unsigned char a)
{
	video_memory[cursor_position_x] = a << 8 | c;
	cursor_position_x++;
}
