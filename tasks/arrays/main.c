#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pbconsole.h>
#include <math.h>

int main()
{
    int A[10];
    int i = 0;
    int count = 0;
    int sum = 0;
    int min = 0;
    int max = 0;
    char s[10] = "\0";
    srand(time(0));

    puts("1. Random array of integers in the range [-99..199].");
    for (; i <= 9; i++)
    {
        A[i] = rand() % 299 - 99 ;
        printf("%i\t", A[i]);
    }

    puts("\n2. Blue background for all numbers in the range [-99..127].");
    for (i = 0; i <= 9; i++)
    {
        if (A[i] <= 127)
        {
            conSetAttr(BG_BLUE);
            printf("%i", A[i]);
            conSetAttr(BG_DEFAULT);
            printf("\t");
            conReset();
        }else
        {
            printf("%i\t", A[i]);
        }
    }

    puts("\n3. Green background for all numbers that are less than 50.");
    for (i = 0; i <= 9; i++)
    {
        if (A[i] <= 50)
        {
            count += 1;
            sum += A[i];
            conSetAttr(BG_GREEN);
            printf("%i", A[i]);
            conSetAttr(BG_DEFAULT);
            printf("\t");
            conReset();
        }else
        {
            printf("%i\t", A[i]);
        }
    }
    printf("\nCount:  %i\n", count);
    printf("Sum:  %i\n", sum);
    if (count == 0)
    {
        count = 1;
    }
    printf("Average:  %g\n", (double)sum / count);

    puts("\n4. The first MIN between [-50..50].");
    for (min = 200, i = 0; i <= 9; i++)
    {
        if ( min > A[i] && A[i] <= 50 && A[i] >= -50)
        {
            min = A[i];
            count = i;
        }
    }
    if (min == 200)
    {
        puts("MIN: Not exist");
    }else
    {
        printf("MIN: A[%i] = %i\n", count, min);
    }
    puts("\n5. The first MAX.");
    for (max = -100, i = 0; i <= 9; i++)
    {
        if ( max < A[i])
        {
            max = A[i];
            count = i;
        }
    }
    printf("MAX: A[%i] = %i\n", count, max);

    puts("\n6. A separate array of characters S.");
    for (i = 0; i <= 9; i++)
    {
        s[i] = (abs(A[i]) % 95) + 32;
    }
    s[9] = '\0';
    puts(s);

    puts("\n7. All numbers that more than -25 in the array A replaced by zero.");
    for (i = 0; i <= 9; i++)
    {
        if (A[i] > -25)
        {
            A[i] = 0;
            conSetAttr(BG_MAGENTA);
            printf("%i", A[i]);
            conSetAttr(BG_DEFAULT);
            printf("\t");
            conReset();
        }else
        {
            printf("%i\t", A[i]);
        }
    }
    puts("");
    return 0;
}
