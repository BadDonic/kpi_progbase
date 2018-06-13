#include <stdio.h>
#include <stdlib.h>
#include <pbconsole.h>
#include <progbase.h>

int main()
{
    int x, y, z, y1 = 1;

    conClear();

    conSetAttr(BG_WHITE);
    for (x = 1; x < 13; x++)
    {
        for (y = 0; y < 29; y++)
        {
            conMove(x, y);
            putchar(' ');
        }
    }

    conSetAttr(BG_GREEN);
    for (x = 13; x < 17; x++)
    {
        for (y = 0; y < 29; y++)
        {
            conMove(x, y);
            putchar(' ');
        }
    }

    conSetAttr(BG_YELLOW);
    for (x = 13, y = 7; y < 10 ; y++)
    {
        conMove(x, y);
        putchar(' ');
    }

    for (x = 13, y = 16; y < 19 ; y++)
    {
        conMove(x, y);
        putchar(' ');
    }

    conSetAttr(BG_RED);
    for ( x = 1, y = 14, z = 15; x <= 8; x++, y += 2, z += 2 )
    {
        if ( y <= 24 && z <= 25)
        {
            conMove(x, y);
            puts(" ");
            conMove(x, z);
            puts(" ");
        }else if (y <= 28 && z <= 29)
        {
            y = y - 1;
            z = z - 1;
            conMove(x, y);
            puts(" ");
            conMove(x, z);
            puts(" ");
            y = y + 1;
            z = z + 1;
        }
    }

    conSetAttr(BG_YELLOW);
    for ( x = 1, y = 16, z = 17; x <= 7; x++, y += 2, z += 2 )
    {
        if ( y <= 26 && z <= 27)
        {
            conMove(x, y);
            puts(" ");
            conMove(x, z);
            puts(" ");
        }else if (y <= 28 && z <= 29)
        {
            y = y - 1;
            z = z - 1;
            conMove(x, y);
            puts(" ");
            conMove(x, z);
            puts(" ");
        }
    }

    conSetAttr(BG_INTENSITY_YELLOW);
    for ( x = 1, y = 18, z = 19; x <= 6; x++, y += 2, z += 2 )
    {
        if ( y <= 26 && z <= 27)
        {
            conMove(x, y);
            puts(" ");
            conMove(x, z);
            puts(" ");
        }else
        {
            conMove(x, y);
            puts(" ");
        }
    }

    conSetAttr(BG_GREEN);
    for ( x = 1, y = 20, z = 21; x <= 5; x++, y += 2, z += 2 )
    {
        if ( y <= 26 && z <= 27)
        {
            conMove(x, y);
            puts(" ");
            conMove(x, z);
            puts(" ");
        }else
        {
            conMove(x, y);
            puts(" ");
        }
    }

    conSetAttr(BG_CYAN);
    for ( x = 1, y = 22, z = 23; x <= 4; x++, y += 2, z += 2 )
    {
        if ( y <= 26 && z <= 27)
        {
            conMove(x, y);
            puts(" ");
            conMove(x, z);
            puts(" ");
        }else
        {
            conMove(x, y);
            puts(" ");
        }
    }

    conSetAttr(BG_INTENSITY_BLUE);
    for ( x = 1, y = 24, z = 25; x <= 3; x++, y += 2, z += 2 )
    {
        if ( y <= 26 && z <= 27)
        {
            conMove(x, y);
            puts(" ");
            conMove(x, z);
            puts(" ");
        }else
        {
            conMove(x, y);
            puts(" ");
        }
    }

    conSetAttr(BG_MAGENTA);
    for ( x = 1, y = 26, z = 27; x <= 2; x++, y += 2, z += 2 )
    {
        if ( y <= 26 && z <= 27)
        {
            conMove(x, y);
            puts(" ");
            conMove(x, z);
            puts(" ");
        }else
        {
            conMove(x, y);
            puts(" ");
        }
    }

    conSetAttr(BG_INTENSITY_GREEN);
    for (x = 7; x <= 10; x++)
    {
        for (y = 7; y <= 19; y++)
        {
            conMove(x,y);
            puts(" ");
        }
    }

    for (x = 10; x <= 12; x++)
    {
        for (y = 7; y <= 18; y++)
        {
            if ( y <= 9)
            {
                conMove(x,y);
                puts(" ");
            }else if (y >= 16 && y <= 18)
            {
                conMove(x,y);
                puts(" ");
            }
        }
    }

    for (x = 3; x <= 5; x++)
    {
        for (y = 4; y <= 9; y++)
        {
            conMove(x,y);
            puts(" ");
        }
    }

    for (x = 2, y  = 6; y <= 8; y++)
    {
        conMove(x,y);
        puts(" ");
    }

    for (x = 6, y  = 7; y <= 17; y++)
    {
        if (y <= 8)
        {
            conMove(x,y);
            puts(" ");
        }else if (y >= 11 && y <= 17)
        {
            conMove(x,y);
            puts(" ");
        }
    }

    for (x = 5, y  = 13; y <= 15; y++)
    {
        conMove(x,y);
        puts(" ");
    }

    for ( x = 7, y = 18, z = 19, y1 = 20; x <= 12; x++, y++, z++, y1++)
    {
        conMove(x, y);
        puts(" ");
        conMove(x, z);
        puts(" ");
        conMove(x, y1);
        puts(" ");

    }

    conSetAttr(BG_GREEN);
    for ( x = 9, z = 9; x >= 6; x--, z++)
    {
        for (y = z, y1 = 28 - z; y <= y1; y +=2)
        {
            conMove(x, y);
            puts(" ");
        }
    }

    conSetAttr(BG_INTENSITY_GREEN);
    conMove(4, 3);
    puts(" ");

    conSetAttr(BG_WHITE);
    conMove(12, 25);
    puts(" ");

    conSetAttr(BG_BLACK);
    conMove(3, 7);
    puts(" ");


    conReset();
    conMove(17, 1);
    return 0;
}
