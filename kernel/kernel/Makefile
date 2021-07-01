AS=as
CC=gcc
CFLAGS=-m32 -O2 -nostdlib -nostdinc -fno-builtin -fno-stack-protector
OBJS=start.o main.o
LDFLAGS=-T kernel.ld -m elf_i386

BugOS.iso: BugOS
		cp BugOS ../../iso/boot/
		grub-mkrescue -o BugOS.iso ../../iso

BugOS: $(OBJS)
	ld $(LDFLAGS) -o $@ $^

%.o: %.s
	$(AS) --32 $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $<

.PHONY: clean

clean:
	rm *.o
