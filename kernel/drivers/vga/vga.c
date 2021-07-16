#include "../../include/drivers/vga.h"
#include "../../include/drivers/io.h"

#define MODE3_WIDTH	80
#define MODE3_HEIGHT	25

static unsigned short *video_memory = (unsigned short *) 0xB8000;
static unsigned int cursor_position_x = 0;
static unsigned int cursor_position_y = 0;
static unsigned char attribute = VGA_MODE3_WHITE;

static void write_char(unsigned char character)
{	
	if(character == '\n')
	{
		cursor_position_x = 0;
		cursor_position_y++;
		return;
	}

	if (cursor_position_y >= MODE3_HEIGHT)
		vga_scrollup();

	unsigned int position = cursor_position_y * MODE3_WIDTH + cursor_position_x;

	video_memory[position] = attribute << 8 | character;

	if(cursor_position_x < MODE3_WIDTH - 1)
		cursor_position_x++;
	else
	{
		cursor_position_x = 0;
		cursor_position_y++;
	}
}

void vga_write_char(unsigned char character)
{
	write_char(character);
	vga_set_cursor_position(cursor_position_x, cursor_position_y);
}


void vga_scrollup(void)
{
	unsigned short int *p = video_memory + MODE3_WIDTH;


	cursor_position_y = MODE3_HEIGHT - 1;
	cursor_position_x = 0;
	// Bom, eu ainda não implementei uma memmove(), então vai ter que ser isso aí por enquanto.
	unsigned int i;
	for( i = 0; i < MODE3_WIDTH*(MODE3_HEIGHT-1); i++ )
		video_memory[i] = p[i];

	p = video_memory + MODE3_WIDTH*(MODE3_HEIGHT-1);
  
	for ( i = 0; i < MODE3_WIDTH; i++ )
		*p++ = 0x20 + (attribute << 8);
}

void vga_write_string(char *string)
{
	while(*string)
		write_char(*string++);

	vga_set_cursor_position(cursor_position_x, cursor_position_y);
}

void vga_set_cursor_position(unsigned int x, unsigned int y)
{
	unsigned short position = y * MODE3_WIDTH + x;

	io_out_byte(0x3d4, 0x0F);
	io_out_byte(0x3d5, position);
	io_out_byte(0x3d4, 0x0E);
	io_out_byte(0x3d5, position >> 8);
}

void vga_set_attribute(char att)
{
	attribute = att;
}

char vga_get_attribute(void)
{
	return attribute;
}
