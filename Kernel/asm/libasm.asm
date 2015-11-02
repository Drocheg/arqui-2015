GLOBAL cpuVendor
GLOBAL _sidt
GLOBAL outb
GLOBAL outw
GLOBAL outd
GLOBAL inb
GLOBAL inw
GLOBAL ind
GLOBAL int80
GLOBAL _cli
GLOBAL _sti

section .text
	
cpuVendor:
	push rbp
	mov rbp, rsp

	push rbx

	mov rax, 0
	cpuid


	mov [rdi], ebx
	mov [rdi + 4], edx
	mov [rdi + 8], ecx

	mov byte [rdi+13], 0

	mov rax, rdi

	pop rbx

	mov rsp, rbp
	pop rbp
	ret

_sidt:
	sidt [rdi]
	mov rax, [rdi]
	and rax, 0xFFFFFFFFFFFF0000
	mov [rdi], rax
	ret

; void outb(uint16_t port, uint8_t value)
outb:
	mov rdx, rdi
	mov rax, rsi
	out dx, al
	ret

; void outw(uint16_t port, uint16_t value)
outw:
	mov rdx, rdi
	mov rax, rsi
	out dx, ax
	ret

; void outd(uint16_t port, uint32_t value)
outd:
	mov rdx, rdi
	mov rax, rsi
	out dx, eax
	ret

; uint8_t inb(uint16_t port)
inb:
	mov rdx, rdi
	in al, dx
	ret

; uint16_t inw(uint16_t port)
inw:
	mov rdx, rdi
	in ax, dx
	ret

; uint32_t ind(uint16_t port)
ind:
	mov rdx, rdi
	in eax, dx
	ret

;void int80()
int80:
	int 80h
	ret

; void _cli()
_cli:
	cli
	ret

; void _sti()
_sti:
	sti
	ret