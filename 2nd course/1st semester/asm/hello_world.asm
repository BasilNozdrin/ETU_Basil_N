; hello_world.asm
;
; Author: Basil Nozdrin
; Date: 16-sep-2020

global _start

section .text:

_start:
    moc eax, 0x4             ; use the write syscall
    mov ebx, 1               ; use stdout as the fd
    mov ecx, message         ; use the message as the buffer
    mov edx, message_length  ; and supply the length
    int 0x80                 ; invoke the syscall

    ; now gracefully exit

    mov eax, 0x1
    mov ebx, 0
    int 0x80

section .data:
    message: db "Hello Wordl!", 0xA
    message_length equ $-message
