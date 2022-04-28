#include <stdio.h>

void main() {
	int c;

	while ((c = getchar()) != EOF) {
		printf("%d %d\n", (c = getchar()) != EOF, EOF);
		// putchar(c);
	}
}