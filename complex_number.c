#include <stdio.h>
#include <stdlib.h>

struct Complex {
	double numA;
	double numB;
};

void sum(struct Complex *z1, struct Complex *z2) {
    double sumA = z1->numA + z2->numA;
    double sumB = z1->numB + z2->numB;
    printf("Sum = %2.2f %2.2f\n", sumA, sumB);
};

int main() {
    struct Complex* num1 = malloc(sizeof(struct Complex));
    struct Complex* num2 = malloc(sizeof(struct Complex));

    num1->numA = 4.0;
    num1->numB = 7.0;
    num2->numA = 3.1;
    num2->numB = 2.8;

    printf("Num1 = %2.2f %2.2f, Num2 = %2.2f %2.2f\n", num1->numA, num1->numB, num2->numA, num2->numB);
    
    sum(num1, num2);

    // printf("Num1 = %2.2f %2.2f, Num2 = %2.2f %2.2f\n", num1->numA, num1->numB, num2->numA, num2->numB);

    free(num1);
    free(num2);

	return 0;
};
