bits 32
global _start

Section .data
str: 				db "Hello", 0x0a, 0x0
strsize: 		dd 0x6
retaddr: 		resd 1

Section .text
_start:
	nop
	mov eax,0
	mov ebx,0
	
	mov esi,retaddr
	mov dword [esi],$+0x08
	jmp print

	mov esi, retaddr
	mov dword [esi],$+0x08
	jmp print

	mov esi,retaddr
	mov dword [esi],$+0x08
	jmp exit

	mov ecx,0
	mov edx,0
	nop

print:
	mov eax,0x4
	mov ebx,0x1
	mov ecx,str
	mov esi,strsize
	mov edx,[esi]
	int 0x80

	mov esi,retaddr
	jmp [esi]

exit:
	mov eax,0x1
	xor ebx,ebx
	int 0x80


