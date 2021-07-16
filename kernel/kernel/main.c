#include "../include/drivers/vga.h"

int kmain(void)
{
	char *text = "Bem-vindo ao BugOS\nCriando por Willian S. Oliveira e Lucio Lospresti\n";

	vga_write_string(text);
	return 0;
}
