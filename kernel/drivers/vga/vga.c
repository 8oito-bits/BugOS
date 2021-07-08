#include "../../include/drivers/vga.h"
#include "../../include/drivers/io.h"

static short *video_memory = (short *) 0xb8000;
static int cursor_position_x = 0;
static int cursor_position_y = 0;

void vga_write_char(unsigned char c, unsigned char a)
{
	video_memory[cursor_position_x] = a << 8 | c;

	if(cursor_position_x < 80)
		cursor_position_x++;
	else
	{
		cursor_position_x++;
		cursor_position_y++;
	}

	vga_set_cursor_position(cursor_position_x, cursor_position_y);
}

void vga_set_cursor_position(unsigned int x, unsigned int y)
{
	unsigned short position = y * 80 + x;

	io_out_byte(0x3d4, 0x0F);
	io_out_byte(0x3d5, position & 0xFF);
	io_out_byte(0x3d4, 0x0E);
	io_out_byte(0x3d5, position >> 8 & 0xFF);
}
