#include <stdio.h>

// pwndbg> p /x a
// $1 = 0x101f
// pwndbg> p a
// $2 = 4127

// pwndbg> x int_ptr
// 0xffffd08c:     0xbb7abe00
// pwndbg> p int_ptr
// $3 = (unsigned int *) 0xffffd08c

int main() {
	unsigned int a = 4127;
	int b = -27714;
	short c = 1475;
	int v[] = {0xCAFEBABE, 0xDEADBEEF, 0x0B00B135, 0xBAADF00D, 0xDEADC0DE};

	unsigned int *int_ptr = (unsigned int *) &v;

	for (unsigned int i = 0 ; i < sizeof(v) / sizeof(*int_ptr) ; ++i) {
		++int_ptr;
	}

	(void) a;
	(void) b;
	(void) c;

	return 0;
}
