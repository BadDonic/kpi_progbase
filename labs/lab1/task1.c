#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double x, y, z, a, a0, a1, a2 = 0;
    printf("Please, Enter double x\n");
    scanf("%lf", &x);
    printf("Please, Enter double y\n");
    scanf("%lf", &y);
    printf("Please, Enter double z\n");
    scanf("%lf", &z);

    if ( x == y || 0 == z || x == 0 || sin(y) == 0)
    {
        puts("Can't be computed");
    }else
    {
    a0 = pow(x, y + 1) / pow(x - y, 1 / z);
    a1 = 4 * x + z / x;
    a2 = pow((x + 0), 1 / fabs(sin(y)));

    a = a0 + a1 +a2;
    printf("a = %.10g\n", a);
    }
    return 0 ;
}
