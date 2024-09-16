#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strlen(const char *str)
{
	int len = 0;

	while (*(str + len))
	{
		++len;
	}

	return len;
}

void equality_check(const char *str)
{
	int i = 0, len = my_strlen(str);

	while (*(str + i))
	{
		if (!(*(str + i) ^ *(str + (i + (1 << i)) % len)))
			printf("Address of %c: %p ", *(str + i), (str + i));

		++i;
	}

	printf("\n");
}

int main(void)
{
	char str[255];
	scanf("%s", str);

	int len = my_strlen(str);
	printf("length = %d ", len);

	equality_check(str);
	return 0;
}