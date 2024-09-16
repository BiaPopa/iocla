#include <stdio.h>

int main(void)
{
	int v[] = {4, 1, 2, -17, 15, 22, 6, 100};
	int max;
	int i;

	/* TODO: Implement finding the maximum value in the vector */
	max = v[0];
	i = 1;

cont:
	if (i > 7)
		goto close;
	if (v[i] > max)
		goto label;
	i++;
	goto cont;

label:
	max = v[i];
	i++;
	goto cont;
	
close:
	printf("%d\n", max);
	return 0;
}
