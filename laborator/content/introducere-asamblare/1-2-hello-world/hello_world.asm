%include "printf32.asm"

section .data
    myString: db "Hello, World!", 0
    my_String: db "Goodbye, World!", 0

section .text
    global main
    extern printf

main:
    mov ecx, 6                      ; N = valoarea registrului ecx
    mov eax, 2
    mov ebx, 1
    cmp eax, ebx
    jns print                        ; TODO1: eax > ebx?
    ret

print:
    PRINTF32 `%s\n\x0`, myString
    sub ecx,1                       ; TODO2.2: afisati "Hello, World!" de N ori
    jnz print
    PRINTF32 `%s\n\x0`, my_String   ; TODO2.1: afisati "Goodbye, World!"

    ret
