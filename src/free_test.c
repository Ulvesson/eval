#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define MAX_STR	100

typedef struct data_t {
	char* str1;
	char* str2;
	char* str3;
} data;

data* create_data() {
	data *p = malloc(sizeof(data));
	if (p) {
		p->str1 = malloc(MAX_STR);
		if (!p->str1) {
			free(p);
			return 0;
		}
		p->str2 = malloc(MAX_STR);
		if (!p->str2) {
			free(p->str1);
			free(p);
			return 0;
		}
		p->str3 = malloc(MAX_STR);
		if (!p->str3) {
			free(p->str1);
			free(p->str2);
			free(p);
			return 0;
		}
		strncpy(p->str1, "str1", 3);
		strncpy(p->str2, "str2", 3);
		strncpy(p->str3, "str3", 3);
		p->str1[3] = '\0';
		p->str2[3] = '\0';
		p->str3[3] = '\0';
	}

	return p;
}

void free_data(data *p) {
	free(p->str1);
	free(p->str2);
	free(p->str3);
	free(p);
}

int main() {
	data* p = create_data();
	printf("str1: %s str2: %s str3: %s", p->str1, p->str2, p->str3);
	free_data(p);
	return 0;
}