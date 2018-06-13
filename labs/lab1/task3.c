#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int op = 0;
    int a = 0;
    int b = 0;
    int swap = 0;

    printf("Please, Enter code of operation\n");
    scanf("%i", &op);

    printf("Please, Enter integer a\n");
    scanf("%i", &a);

    printf("Please, Enter integer b\n");
    scanf("%i", &b);

    if (op < 0)
    {
        op = abs(op);
        swap = a;
        a = b;
        b = swap;
    }

    switch (op)
    {
        case 0 :
            printf("a + b = %i\n", a + b);
            break;
        case 1:
            printf("a - b = %i\n", a - b);
            break;
        case 2:
            printf("a * b = %i\n", a * b);
            break;
        case 3:
            if (b != 0)
            {
                printf("a / b = %g\n", (double)a / b);
                break;
            }else
            {
                printf("Can't be computed\n");
            }
        case 4:
            printf("abs(a) = %i\n", abs(a));
            break;
        case 5:
            printf("min (a,b) = %g\n", fmin(a,b));
            break;
        case 6:
            printf("max (a,b) = %g\n", fmax(a,b));
            break;
        case 7:
        case 13:
            printf("pow (a,b) = %g\n", pow(a,b));
            break;
        case 8 :
            if (a != 0)
            {
                printf("var (a,b) = %g\n", (double) 3 * cos(b * 3.14) / (a - 0));
                break;
            }else
            {
                printf("Can't be computed\n");
            }
        default :
            printf("def (a,b) = %i\n", op * abs(a + 1) + op * abs(b + 1));
            break;
    }
    return 0;
}
