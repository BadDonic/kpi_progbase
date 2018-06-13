#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    int count = 0;
    int modmin = 0;
    int sum2 = 0;
    int max = 0;
    int min = 0;
    short int limit = 32767;

    printf("Please, Enter integer a\n");
    scanf("%i", &a);

    printf("Please, Enter integer b\n");
    scanf("%i", &b);

    printf("Please, Enter integer c\n");
    scanf("%i", &c);
    if (a < 0)
    {
        count += 1;
    }

    if (b < 0)
    {
        count += 1;
    }

    if (c < 0)
    {
        count += 1;
    }

    if (count == 3)
    {
        modmin = abs(fmin(fmin(a,b),c));
        sum2 = a + b + c + modmin;
        if (sum2 > -256 && modmin != 0 && !(modmin & (modmin - 1)))
        {
            printf("True\n");
        }else if(abs(sum2) > modmin && sum2 > -256)
        {
            printf("False\n");
        }
    }else if (count == 1 && fmin(fmin(a,b),c) > -256)
    {
        printf("True\n");
    }else if (count == 1 && fmin(fmin(a,b),c) <= -256)
    {
        printf("False\n");
    }else if (count == 2 && (a + b + c - fmax(fmax(a,b),c))*4 > -256)
    {
        printf("True\n");
    }else if (count == 2 && (a + b + c - fmax(fmax(a,b),c))*4 <= -256)
    {
        printf("False\n");
    }else
    {
        max = fmax(fmax(a,b),c);
        min = fmin(fmin(a,b),c);
        if (pow(max,min) <= limit)
        {
            printf("True\n");
        }else
        {
            printf("False\n");
        }
    }

    return 0;
}
