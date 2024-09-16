#include <stdio.h>
#include <stdlib.h>
#define SIZE 8

void print_binary(int number)
{
	printf("0b");

	int *rez, i = 0;
	rez = (int *)malloc(8 * sizeof(int));
	*rez = 0;

	while (number > 0) {
		*(rez + i) = number % 2;
		number /= 2;
		++i;
	}

	for (i = 7; i >= 0; --i)
		printf("%d", *(rez + i));

	printf("\n");
	free(rez);
}

void print_hexa(int number)
{
	printf("0x");

	char rez[8];
	int i = 0;

	while (number > 0) {
		if ((number % 16) < 10)
		*(rez + i) = number % 16 + 48;
		else
		*(rez + i) = number % 16 + 55;

		number /= 16;
		++i;
	}

	for (int j = i; j <= 7; ++j)
		printf("0");
	for (int j = i - 1; j >= 0; --j)
		printf("%c", *(rez + j));

	printf("\n");
}

void check_parity(int *numbers, int n)
{
	for (int i = 0; i < n; ++i)
		if (*(numbers + i) & 1)
			print_hexa(*(numbers + i));
		else
			print_binary(*(numbers + i));
}

int main()
{
	int n, v[100];
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	scanf("%d", &v[i]);

	check_parity(v, n);
	return 0;
}