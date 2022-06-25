#include <stdio.h>

void print(char * str);
char* input();

int main () {

	printf("input function:\n");
	char* str = input();
	printf("print function:");
	print(str);
	print("\n");

	return 0;
}
