EXTERN IRQ_handler

GLOBAL irq0ASM

%macro irqHandlerMaster 1
	;Stack frame
	push rbp
	push rsp
	push rbx
	push r12
	push r13
	push r15
	pushf

	mov rdi, %1
	push rdi
	call IRQ_handler	;EOI handled by IRQ_handler
	pop rdi
	
	;Undo stack frame
	popf
	pop r15
	pop r13
	pop r12
	pop rbx
	pop rsp
	pop rbp
	iretq
%endmacro

irq0ASM:
	irqHandlerMaster 0