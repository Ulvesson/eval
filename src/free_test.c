#include <stdio.h>

#define MAX_STR	100

struct data_t {
	char* str1;
	char* str2;
	char* str3;
};

data_t* create_data() {
	data_t* p = malloc(sizeof(data_t));
	if (p) {
		p.str1 = malloc(MAX_STR);
		p.str2 = malloc(MAX_STR);
		p.str3 = malloc(MAX_STR);
		strncpy(p.str1, "str1", 3);
		strncpy(p.str2, "str2", 3);
		strncpy(p.str3, "str3", 3);
		p.str1[3] = '\0';
		p.str2[3] = '\0';
		p.str3[3] = '\0';
	}

	return p;
}

void free_data(data_t *p) {
	free(p.str1);
	free(p.str2);
	free(p.str3);
	free(p);
}

int main() {
	data_t* p = create_data();
	printf("str1: %s str2: %s str3: %s", p.str1, p.str2, p.str3);
	free_data(p);
	return 0;
}