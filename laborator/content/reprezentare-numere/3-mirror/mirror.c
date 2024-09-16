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

void mirror(char *s)
{
	int l = my_strlen(s);
	int i = 0;

	while (i ^ (l/2))
	{
		char p = *(s + i);
		*(s + i) = *(s + l - i - 1);
		*(s + l - i - 1) = p;

		++i;
	}
}

int main()
{
	char str[255];
	scanf("%s", str);

	mirror(str);
	printf("%s\n", str);
	return 0;
}