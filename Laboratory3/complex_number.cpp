#include <math.h>
#include <stdio.h>
#include "complex_number.h"

#define PI 3.14159265
Complex complex_create(float real, float imag)
{
	Complex c;
	c.real = real;
	c.imag = imag;
	return c;

}
float get_real(Complex c)
{
	return c.real;
}
float get_imag(Complex c)
{
	return c.imag;
}
void set_real(Complex* c, float real)
{
	c->real = real;
}
void set_imag(Complex* c, float imag)
{
	c->imag = imag;
}
Complex complex_conjugate(Complex c)
{
	Complex cc;
	cc.real = c.real;
	cc.imag = -c.imag;
	return cc;
}
Complex complex_add(Complex c1, Complex c2)
{
	Complex sum;
	sum.real = c1.real + c2.real;
	sum.imag = c1.imag + c2.imag;
	return sum;
}
Complex complex_subtract(Complex cl, Complex c2)
{
	Complex diff;
	diff.real = cl.real - c2.real;
	diff.imag = cl.imag - c2.imag;
	return diff;
}
Complex complex_multiply(Complex c1, Complex c2)
{
	Complex product;
	product.real = c1.real * c2.real - c1.imag * c2.imag;
	product.imag = c1.real * c2.imag + c1.imag * c2.real;
	return product;
}
void complex_scalar_mult(Complex* c, float s)
{
	c->real = c->real * s;
	c->imag = c->imag * s;
}
bool complex_equals(Complex c1, Complex c2)
{
	if (c1.real == c2.real && c1.imag == c2.imag)
		return true;
	else
		return false;
}
float complex_mag(Complex c)
{
	float mag;
	mag = sqrt(c.real * c.real + c.imag * c.imag);
	return mag;
}
float complex_phase(Complex c)
{
	double phase, r, tetha;
	
	tetha = atan2(c.imag,  c.real);
	phase = tetha;
	

	return phase;
}
void complex_to_polar(Complex c, float* r, float* theta)
{
	*r = complex_mag(c);
	*theta = complex_phase(c);
}

void complex_display(Complex c)
{
	printf("%f + %fi", c.real, c.imag);
}
