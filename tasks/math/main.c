#include <stdio.h>
#include <math.h>

int main (void)
{
	double x, f1, f2, sum , mult, div1, div2 = 0;

	for ( x = -10; x <= 10; x += 0.5)
	{
		f1 = pow(x,2) - 5;
		f2 = cos(pow(x,2)) + pow(sin(2 * x),2) + 1;
		sum = f1 + f2;
		mult = f1 * f2;
		printf("x = %g\nF1(x) = %g\nF2(x) = %g\nF1(x) + F2(x) = %g\nF1(x) * F2(x) = %g\n", x, f1, f2, sum, mult);
		if (0 != f2)
		{
			div1 = f1 / f2;
			printf("F1(x) / F2(x) = %g\n", div1);
		}else
		{
			printf("F1(x) / F2(x) Division by zero");
		}
		if (0 != f1)
		{
			div2 = f2 / f1;
			printf("F2(x) / F1(x) = %g\n", div2);
		}else
		{
			printf("F2(x) / F1(x) Division by zero");
		}
	}
	return 0;
}
