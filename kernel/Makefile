AS=as
CC=gcc
CFLAGS=-m32 -O2 -nostdlib -nostdinc -fno-builtin -fno-stack-protector
OBJS=kernel/start.o 	\
     kernel/main.o	\
     drivers/vga/vga.o	\
     drivers/io.o

LDFLAGS=-T kernel/kernel.ld -m elf_i386

kernel.elf: $(OBJS)
	ld $(LDFLAGS) -o $@ $^

%.o: %.s
	$(AS) --32 $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	-rm drivers/*.o drivers/vga/*.o kernel/*.o kernel.elf
