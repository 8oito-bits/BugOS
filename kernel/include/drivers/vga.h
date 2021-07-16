#ifndef VGA_H
#define VGA_H

typedef enum {
	VGA_MODE3_BLACK,
	VGA_MODE3_BLUE,
	VGA_MODE3_GREEN,
	VGA_MODE3_CYAN,
	VGA_MODE3_RED,
	VGA_MODE3_MAGENTA,
	VGA_MODE3_BROWN,
	VGA_MODE3_LIGHT_GREY,
	VGA_MODE3_DARK_GREY,
	VGA_MODE3_LIGHT_BLUE,
	VGA_MODE3_LIGHT_GREEN,
	VGA_MODE3_LIGHT_CYAN,
	VGA_MODE3_LIGHT_RED,
	VGA_MODE3_LIGHT_MAGENTA,
	VGA_MODE3_LIGHT_BROWN,
	VGA_MODE3_WHITE
} vga_mode3_colors_e;

void vga_write_char(unsigned char);
void vga_set_cursor_position(unsigned int, unsigned int);
void vga_scrollup(void);
void vga_write_string(char *);
void vga_set_attribute(char);
char vga_get_attribute(void);

#endif
