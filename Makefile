.PHONY: kernel/kernel.elf
kernel/kernel.elf:
	-make -C kernel/

BugOS.iso:
	cp kernel/kernel.elf iso/boot/
	grub-mkrescue -o BugOS.iso iso


.PHONY: clean run

clean:
	-rm BugOS.iso
	-make clean -C kernel/

run:
	qemu-system-i386 -cdrom BugOS.iso
