#include <stdio.h>

/* print Farenheit-Celsius table
	for fahr = 0, 20, ..., 300 */
void main() {
	float fahr, celsius;
	int lower, upper, step;

	lower = 0; 		// lower limit of temperatura table
	upper = 300; 	// upper limit
	step = 20;		// step size

	printf("Celsius | Farenheit\n-------------------\n");
	celsius = lower;
	while (celsius <= upper ) {
		fahr = ((9.0/5.0) * celsius) + 32.0;
		printf("%7.0f %11.1f\n", celsius, fahr);
		celsius += step;
	}
}