#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char* string_dup2(const char* str)
{
	size_t len = strlen(str);
	char* dup = (char*)malloc(len + 1);
	if (dup)
		strcpy(dup, str);
	return str;
}

// http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1969.htm
char* string_dup(const char* str)
{
	char* dup = (char*)malloc(strlen(str) + 1);
	if (dup)
		strcpy(dup, str);
	return str;
}

char* copy(char* buf) {
	char p[20];
	auto size = strlen(buf);
	memcpy(p, buf, size);
	return p;
}

int main(int argc, char** argv)
{
	char* dup = string_dup2("What");
	char* buf = malloc(44);
	buf = copy(argv[0]);
	printf("%s", buf);
	free(buf);
	return 0;
}