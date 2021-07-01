.code32

.set MULTIBOOT_FLAGS, 		(1 << 0) | (1 << 1)
.set MULTIBOOT_MAGIC,		0x1BADB002
.set MULTIBOOT_CHECKSUM,	-(MULTIBOOT_MAGIC + MULTIBOOT_FLAGS)

.section .multiboot
	.long MULTIBOOT_MAGIC
	.long MULTIBOOT_FLAGS
	.long MULTIBOOT_CHECKSUM
	

.section .text
.extern kmain
.global boot
boot:
	call kmain
	jmp .
