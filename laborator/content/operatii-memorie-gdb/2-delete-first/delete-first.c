#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* delete_first(char *s, char *pattern)
{
	char *str = strdup(s);
	int l = strlen(pattern);

	if (strstr(str, pattern) != NULL) {
		char *ptr = strstr(str, pattern);
		strcpy(ptr, ptr + l);
	}

	return str;
}

int main(){
	char *s = "Ana are mere";
	char *pattern = "re";

	printf("%s\n", delete_first(s, pattern));

	return 0;
}
