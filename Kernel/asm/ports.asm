GLOBAL portWrite
GLOBAL portRead

portRead:
	mov rdx, rdi
	mov rax, 0
	in al, dx
	ret

portWrite:
	mov rdx, rdi
	mov rax, rsi
	out dx, al
	ret