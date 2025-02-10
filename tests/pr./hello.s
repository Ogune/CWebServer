bits 32
global _start

Section .text
_start:
	mov eax,1;		1, is the nmbr for exit sys_call
	mov ebx, 5;   5, the exit status in this case
	int 0x80;     tells the kernel to exec the sys_call in eax reg,...

	; exit(5) ;

Section .data
str: db "Hello World", 0x0a, 0x00
