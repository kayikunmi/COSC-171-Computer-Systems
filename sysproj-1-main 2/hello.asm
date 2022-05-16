; ------------------------------------------------------------------------------
; Writes "Hello, World" to the console and then exits.
; To assemble and run:
;
;     $ nasm -felf64 -gdwarf hello.asm
;     $ ld -o hello hello.o
;     $ ./hello
; ------------------------------------------------------------------------------

; ------------------------------------------------------------------------------
        global    _start
; ------------------------------------------------------------------------------

; ------------------------------------------------------------------------------
        section   .text	              ; The start of the code portion of the program.
	
_start:				      ; Labels the entry point to the program.
	sectionl.text
_main:
	push message
	call _printf
	add esp, 4
	ret
message:
	db 'This is a new message', 10,0
	

; ------------------------------------------------------------------------------

; ------------------------------------------------------------------------------
        section   .data		      ; The start of the data portion of the program.

greetings:			      ; Labels the string of bytes to be written.
	db        "This is a new line", 10  ; The message, with the byte values for "newline" appended.
; ------------------------------------------------------------------------------
