%include "../utils/printf32.asm"

%define NUM 5
   
section .text

extern printf
global main
main:
    mov ebp, esp

    ; TODO 1: replace every push by an equivalent sequence of commands (use direct addressing of memory. Hint: esp)
    mov ecx, NUM
push_nums:
    ; push ecx
    sub esp, 4
    mov [esp], ecx
    loop push_nums

    ; push 0
    sub esp, 4
    mov [esp], dword 0
    ; push "mere"
    sub esp,4 
    mov [esp], dword "mere"
    ; push "are "
    sub esp,4 
    mov [esp], dword "are "
    ; push "Ana "
    sub esp,4 
    mov [esp], dword "Ana "

    lea esi, [esp]
    PRINTF32 `%s\n\x0`, esi

    ; TODO 2: print the stack in "address: value" format in the range of [ESP:EBP]
    ; use PRINTF32 macro - see format above
    mov ecx, esp
loop1:
    PRINTF32 `%p: %hhd\n\x0`, ecx, [ecx]
    add ecx, 1
    cmp ecx, ebp
    jne loop1

    ; TODO 3: print the string
    lea esi, [esp]
    PRINTF32 `%s\n\x0`, esi

    ; TODO 4: print the array on the stack, element by element.
    mov ecx, NUM
    mov ebx, 0
loop2:
    mov eax, [esp + 16 + 4 * ebx]
    PRINTF32 `%d \x0`, eax
    inc ebx
    cmp ebx, ecx
    jne loop2

    PRINTF32 `\n\x0`

    ; restore the previous value of the EBP (Base Pointer)
    mov esp, ebp

    ; exit without errors
    xor eax, eax
    ret
