#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>

// http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1969.htm
char* string_dup(const char* str)
{
	char* dup = (char*)malloc(strlen(str) + 1);
	if (dup)
		strcpy(dup, str);
	return str;
}

// Fixed string_dup
char* string_dup2(const char* str)
{
	char* dup = (char*)malloc(strlen(str) + 1);
	if (dup)
		strcpy(dup, str);
	return dup;
}

char* copy(char* buf) {
	char p[20];
	auto size = strlen(buf);
	memcpy(p, buf, size);
	return p;
}

int main(int argc, char** argv)
{
	const char* msg = "Big bug! string_dup is broken.";
	char* dup = string_dup2(msg);
	printf(dup);
	free(dup);
	char* buf = malloc(44);
	buf = copy(argv[0]);
	printf("%s", buf);
	free(buf);
	return 0;
}