GLOBAL syscallReceiver
EXTERN sysCall

section .text

syscallReceiver:
	;64-bit stack frame
	push rbp
	push rsp
	push rbx
	push r12
	push r13
	push r15

	call sysCall

	pop r15
	pop r13
	pop r12
	pop rbx
	pop rsp
	pop rbp
	ret