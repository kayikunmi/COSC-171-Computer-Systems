; ------------------------------------------------------------------------------
; Counts down from 9 to 0, printing each.
; To assemble and run:
;
;     $ nasm -felf64 -gdwarf countdown.asm
;     $ ld -o countdown countdown.o
;     $ ./countdown	
; ------------------------------------------------------------------------------

; ------------------------------------------------------------------------------
        global    _start
; ------------------------------------------------------------------------------

; ------------------------------------------------------------------------------
        section   .text
_start:
	mov r8, 9
	mov r9, 0
	mov rsi, digit_str

top:	cmp r8,0
	jl end
	
	mov rax,1
	mov rdi, 1
	mov rdx, 4
	syscall
	
	dec r8
	sub byte[digit_str], 1
	jmp top

end:    mov       rax, 60                 ; system call for exit
        xor       rdi, rdi                ; exit code 0
        syscall                           ; invoke operating system to exit
; ------------------------------

	
; ------------------------------------------------------------------------------
        section   .data
digit_str:
	db        "9", 10                 ; The integer 10 is a newline char
; ------------------------------------------------------------------------------
