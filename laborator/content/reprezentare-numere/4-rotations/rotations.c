#include <stdio.h>
#define SIZE 8
#define LEFT 1
#define RIGHT 256

void rotate_left(int *number, int bits)
{
	for (int i = 0; i < bits; ++i) {
		int temp = (*number >> SIZE) & LEFT;
	*number = (*number << 1) | temp;
	}
}

void rotate_right(int *number, int bits)
{
	for (int i = 0; i < bits; ++i) {
		int temp = (*number << SIZE) & RIGHT;
		*number = (*number >> 1) | temp;
	}
}

int main()
{
	int number, bits;
	scanf("%d%d", &number, &bits);

	bits %= SIZE;
	rotate_left(&number, bits);
	rotate_right(&number, bits);

	printf("%d\n", number);
	return 0;
}