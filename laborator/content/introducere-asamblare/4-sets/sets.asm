%include "printf32.asm"

section .text
    global main
    extern printf

main:
    ;cele doua multimi se gasesc in eax si ebx
    mov eax, 139
    mov ebx, 169
    PRINTF32 `%u\n\x0`, eax ; afiseaza prima multime
    PRINTF32 `%u\n\x0`, ebx ; afiseaza cea de-a doua multime

    ; TODO1: reuniunea a doua multimi
    or eax, ebx
    PRINTF32 `%u\n\x0`, eax ; afiseaza prima multime

    ; TODO2: adaugarea unui element in multime
    or eax, 64
    PRINTF32 `%u\n\x0`, eax ; afiseaza prima multime

    ; TODO3: intersectia a doua multimi
    and eax, ebx
    PRINTF32 `%u\n\x0`, eax ; afiseaza prima multime

    ; TODO4: complementul unei multimi
    not eax
    PRINTF32 `%u\n\x0`, eax ; afiseaza prima multime

    ; TODO5: eliminarea unui element
    or eax, 1
    not eax
    PRINTF32 `%u\n\x0`, eax ; afiseaza prima multime

    ; TODO6: diferenta de multimi EAX-EBX
    not ebx
    and eax, ebx
    PRINTF32 `%u\n\x0`, eax ; afiseaza prima multime

    xor eax, eax
    ret
