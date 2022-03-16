#include <stdio.h>

/**
 * Afisati adresele elementelor din vectorul "v" impreuna cu valorile
 * de la acestea.
 * Parcurgeti adresele, pe rand, din octet in octet,
 * din 2 in 2 octeti si apoi din 4 in 4.
 */

int main() {
    int v[] = {0xCAFEBABE, 0xDEADBEEF, 0x0B00B135, 0xBAADF00D, 0xDEADC0DE};

    unsigned char *char_ptr = (unsigned char *)v;

    int i = 0;
    while (i < 20) {
        printf("%p -> 0x%x\n", char_ptr + i, *(char_ptr + i));
        ++i;
    }

    printf("\n");

    unsigned short *ptr = (unsigned short *)v;
    i = 0;
    while (i < 10) {
        printf("%p -> 0x%x\n", ptr + i, *(ptr + i));
        ++i;
    }

    printf("\n");

    unsigned int *ptr2 = (unsigned int *)v;
    i = 0;
    while (i < 5) {
        printf("%p -> 0x%x\n", ptr2 + i, *(ptr2 + i));
        ++i;
    }

    return 0;
}
