EXTERN IRQ_handler
EXTERN int80Handler
GLOBAL _int20
GLOBAL _int21
GLOBAL _int80

SECTION .text

%macro irqMacro 1
	;Stack frame
	push rbp
	push rsp
	push rbx
	push r12
	push r13
	push r15

	mov rdi, %1
	call IRQ_handler
	
	;Undo stack frame
	pop r15
	pop r13
	pop r12
	pop rbx
	pop rsp
	pop rbp
	iretq
%endmacro

_int20:
	irqMacro 0x00

_int21:
	irqMacro 0x01

_int80:
	;Stack frame
	push rbp
	push rsp
	push rbx
	push r12
	push r13
	push r15

	;Parameter registers shouldn't have been modified
	call int80Handler
	
	;Undo stack frame
	pop r15
	pop r13
	pop r12
	pop rbx
	pop rsp
	pop rbp
	;iretq
	ret