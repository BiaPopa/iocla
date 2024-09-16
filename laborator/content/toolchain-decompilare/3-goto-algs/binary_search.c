#include <stdio.h>

int main(void)
{
	int v[] =  {1, 2, 15, 51, 53, 66, 202, 7000};
	int dest = v[2]; /* 15 */
	int start = 0;
	int end = sizeof(v) / sizeof(int) - 1;
	int mij;
	/* TODO: Implement binary search */
label:
	mij = (end + start) / 2;
	if (v[mij] == dest)
		goto close;
	if (v[mij] > dest)
		goto right;
	goto left;

right:
	end = mij - 1;
	goto label;

left:
	start = mij + 1;
	goto label;

close:
	printf("Find key %d\n", v[mij]);
	return 0;
}
