#include <stdio.h>

char* copy(char* buf) {
	char p[20];
	auto size = strlen(buf);
	memcpy(p, buf, size);
	return p;
}

int main(int argc, char** argv)
{
	char* buf = malloc(44);
	buf = copy(argv[0]);
	printf("%s", buf);
	free(buf);
	return 0;
}