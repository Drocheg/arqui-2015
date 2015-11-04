GLOBAL _int

_int:
	push rbp
	push rsp
	push rbx
	push r12
	push r13
	push r15
	pushf

	int rdi
	
	popf
	pop r15
	pop r13
	pop r12
	pop rbx
	pop rsp
	pop rbp
	iretq