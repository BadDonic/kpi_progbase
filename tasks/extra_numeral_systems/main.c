#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <math.h>

char * ns_convert(char * buffer, const char * number, unsigned int sourceBase, unsigned int destBase)
{
    int i,j,n,k,l,sum,dot = 0;
    char temp[65] = "\0";
    char temp1[65] = "\0";
    char temp2[65] = "\0";
    char temp3[65] = "\0";
    char temp4[65] = "\0";
    long long int * arg;
    double * brg;
    double sum1 = 0.0;



    if (sourceBase >= 2 && sourceBase <= 36 && destBase >= 2 && destBase <= 36)
    {
        for ( i = 0, l = 0; i <= strlen(number) - 1; i++)
		{
            if (number[i] == '.')
            {
                l = l + 1;
            }
        }

        if (l == 1)
        {
            for (j = 0, n = 0, dot = 1; number[j] != '.'; j++, n++)
                {
                    dot++;
                    temp[n] = number[j];
                }

                n = strlen(temp);
                arg = (long long int*) malloc(n * sizeof(long long int));

                for (n = strlen(temp) - 1, j = 0; n >= 0; n--,j++)
                {
                    arg[j] = temp[n];
                }

                for(sum = 0, j = 0; j < strlen(temp); j++)
                {
                    if (sourceBase <= 10)
                    {
                        if (arg[j] >= 0 && arg[j] < sourceBase + 48 )
                        {
                            arg[j] = pow(sourceBase,j)*(arg[j]-48);
                            sum = sum + arg[j];
                        }else
                        {
                            buffer = "\0";
                            goto ret;
                        }
                    }else
                    {
                        if (arg[j] >= 0 && arg[j] <= 57 )
                        {
                            arg[j] = pow(sourceBase,j)*(arg[j]-48);
                            sum = sum + arg[j];
                        }else if ( arg[j] >= 65 && arg[j] <= sourceBase + 54 )
                        {
                            arg[j] = pow(sourceBase,j)*(arg[j]-55);
                            sum = sum + arg[j];
                        }else
                        {
                            buffer = "\0";
                            goto ret;
                        }
                    }
                }

                for (k = 0, j = 0; sum / (int)pow(destBase,j) > 0; j++)
                {
                    if (sum / (int)pow(destBase,j) % destBase < 10)
                    {
                        k++;
                        arg[j] = sum / (int)pow(destBase,j) % destBase + 48;
                    }else
                    {
                        k++;
                        arg[j] = sum / (int)pow(destBase,j) % destBase + 55;
                    }
                }

                for (j = k - 1, n = 0; j >= 0; j--, n++ )
                {
                    temp1[n] = arg[j];
                }
                for ( j = dot, i = 0; j <= strlen(number); j++, i++)
                {
                    temp4[i] = number[j];
                }

                n = strlen(temp4) - 1;
                brg = (double*) malloc(n * sizeof(double));

                for (i = 0, j = 0;  i <= strlen(temp4) - 1; i++,j++)
                {
                    brg[j] = temp4[i];
                }

                for(sum1 = 0, j = 0; j < strlen(temp4); j++)
                {
                    if (sourceBase <= 10)
                    {
                        if (brg[j] >= 0 && brg[j] < sourceBase + 48 )
                        {
                            brg[j] = (brg[j] - 48) / (double)pow(sourceBase,(j+1));
                            sum1 = sum1 + brg[j];
                        }else
                        {
                            buffer = "\0";
                            goto ret;
                        }
                    }else
                    {
                        if (brg[j] >= 0 && brg[j] <= 57 )
                        {
                            brg[j] = (brg[j] - 48) / (double)pow(sourceBase,(j+1));
                            sum1 = sum1 + brg[j];
                        }else if ( brg[j] >= 65 && brg[j] <= sourceBase + 54 )
                        {
                            brg[j] = (brg[j] - 55) / (double)pow(sourceBase,(j+1));
                            sum1 = sum1 + brg[j];
                        }else
                        {
                            buffer = "\0";
                            goto ret;
                        }
                    }
                }

                if ( sourceBase == destBase)
                {
                    strcpy(buffer, number);
                    goto ret;
                }else
                {
                    for (j = 0; j < 6; j++)
                    {
                        if ((int) (sum1 * destBase) < 10)
                        {
                            arg[j] = (int) (sum1 * destBase) + 48;
                            sum1 = (sum1*destBase) - arg[j] + 48;
                        }else
                        {
                            arg[j] = (int) (sum1 * destBase) + 55;
                            sum1 = (sum1*destBase) - arg[j] + 55;
                        }
                    }
                }

                for (i = 0; i <= 5; i++)
                {
                    temp2[i] =   arg[i];
                }

                for (i = 5, k = 0; i >= 0; i--)
                {
                    if (temp2[i] == '0')
                    {
                        k++;
                    }else
                    {
                        for (j = 0; j <= 5 - k; j++)
                        {
                            temp3[j] = temp2[j];
                        }
                    }
                }

                strcat(temp1, ".");
                strcat(temp1, temp3);
                strcpy(buffer,temp1);
                goto ret;


        }else if (l == 0)
        {
            for (j = 0, n = 0; j <= strlen(number) - 1; j++, n++)
                {
                    temp[n] = number[j];
                }

                n = strlen(temp);
                arg = (long long int*) malloc(n * sizeof(long long int));

                for (n = strlen(temp) - 1, j = 0, k = 0; n >= 0; n--,j++)
                {
                    k++;
                    arg[j] = temp[n];
                }

                for(sum = 0, j = 0; j < strlen(temp); j++)
                {
                    if (sourceBase <= 10)
                    {
                        if (arg[j] >= 0 && arg[j] < sourceBase + 48 )
                        {
                            arg[j] = pow(sourceBase,j)*(arg[j]-48);
                            sum = sum + arg[j];
                        }else
                        {
                            buffer = "\0";
                            goto ret;
                        }
                    }else
                    {
                        if (arg[j] >= 0 && arg[j] <= 57 )
                        {
                            arg[j] = pow(sourceBase,j)*(arg[j]-48);
                            sum = sum + arg[j];
                        }else if ( arg[j] >= 65 && arg[j] < sourceBase + 55 )
                        {
                            arg[j] = pow(sourceBase,j)*(arg[j]-55);
                            sum = sum + arg[j];
                        }else
                        {
                            buffer = "\0";
                            goto ret;
                        }
                    }
                }

                for (k = 0, j = 0; sum / (int)pow(destBase,j) > 0; j++)
                {
                    if (sum / (int)pow(destBase,j) % destBase < 10)
                    {
                        k++;
                        arg[j] = sum / (int)pow(destBase,j) % destBase + 48;
                    }else
                    {
                        k++;
                        arg[j] = sum / (int)pow(destBase,j) % destBase + 55;
                    }
                }

                for (j = k - 1, n = 0; j >= 0; j--, n++ )
                {
                    temp1[n] = arg[j];
                }

                strcpy(buffer,temp1);
                goto ret;

        }else if (l > 1)
        {
            buffer = "\0";
            goto ret;
        }
    }else
    {
        buffer = "\0";
        goto ret;
    }
ret:
    return buffer;
}

int main(void)
{
    char buf[1000] = "";
    char * x = NULL;
    x = ns_convert(buf, "1A", 16, 10);
    return 0;
}
