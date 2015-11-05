EXTERN IRQ_handler

GLOBAL _int0
GLOBAL _irq0
GLOBAL _irq1


%macro irqHandlerMaster 1
	;Stack frame
	push rbp
	push rsp
	push rbx
	push r12
	push r13
	push r15

	mov rdi, %1
	push rdi
	call IRQ_handler	;EOI handled by IRQ_handler
	
	;EOI
	mov al, 20h
	out 20h, al
	
	pop rdi
	
	;Undo stack frame
	pop r15
	pop r13
	pop r12
	pop rbx
	pop rsp
	pop rbp
	iretq
%endmacro

%macro intMacro 1
	;Stack frame
	push rbp
	push rsp
	push rbx
	push r12
	push r13
	push r15

	int %1
	
	;Undo stack frame
	pop r15
	pop r13
	pop r12
	pop rbx
	pop rsp
	pop rbp
	iretq
%endmacro


_int0:
	irqHandlerMaster 0

_irq0:
	irqHandlerMaster 0

_irq1:
	irqHandlerMaster 1
