#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int m = 0;
    int n = 0;
    int i = 0;
    int j = 0;
    double x = 0;

    printf("Please, Enter integer n\n");
    scanf("%i", &n);

    printf("Please, Enter integer m\n");
    scanf("%i", &m);

    for (i = 1; i <= n ; i++)
    {
        for (j = 1; j < m; j++)
        {
            x += sqrt(i + j * 2);
        }
    }
    printf("x = %g\n", x);

    return 0;
}
