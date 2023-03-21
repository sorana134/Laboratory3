#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include "complex_test.h"


int main(int argc, char** argv) {
	{
		run_complex_tests(true);
		//check for memory leaks

		Complex c1 = complex_create(1, 2);

		printf("complex_mag: %f\n", complex_mag(c1));
		printf("complex_phase: %f\n", complex_phase(c1));
		float r, theta;
		complex_to_polar(c1, &r, &theta);


		printf("complex_to_polar: %f(cos(%f)+isin(%f))\n", r, theta, theta);
		Complex c1_conjugate = complex_conjugate(c1);
		printf("conjugate:  ");
		complex_display(c1_conjugate);
		printf("\n");
		complex_scalar_mult(&c1, 2);
		printf("complex_scalar_mult:  ");
		complex_display(c1);
		printf("\n");
		Complex* c2 = (Complex*)malloc(sizeof(Complex));
		*c2 = complex_create(3, 4);
		//Call the functions complex_mag, phase, complex_to_polar, complex_conjugate and complex_scalar_mult (with a scalar) for this variable.
		printf("\ncomplex_mag: %f\n", complex_mag(*c2));
		printf("complex_phase: %f\n", complex_phase(*c2));
		complex_to_polar(*c2, &r, &theta);
		printf("complex_to_polar: %f(cos(%f)+isin(%f))\n", r, theta, theta);
		Complex c2_conjugate = complex_conjugate(*c2);
		printf("conjugate:  ");
		complex_display(c2_conjugate);
		printf("\n");
		complex_scalar_mult(c2, 2);
		printf("complex_scalar_mult:  ");
		complex_display(*c2);
		printf("\n");

		Complex c3 = complex_add(c1, *c2);
		printf("addition:  ");
		complex_display(c3);
		printf("\n");
		Complex c4 = complex_subtract(c1, *c2);
		printf("subtraction:  ");
		complex_display(c4);
		printf("\n");
		Complex c5 = complex_multiply(c1, *c2);
		printf("multiplication:  ");
		complex_display(c5);
		printf("\n");

		free(c2);
	}_CrtDumpMemoryLeaks();
	

	return 0;
}