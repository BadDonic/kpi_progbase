#include <stdio.h>
#include <progbase.h>
#include <pbconsole.h>

int main(void)
{
    char image[28][28] =
    {
        { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
        { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
        { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
        { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
        { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
        { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
        { 'F','F','F','F','F','F','0','0','0','0','0','0','0','0','0','0','0','0','0','0','F','F','F','F','F','F','F','F' },
        { 'F','F','F','F','0','0','4','4','4','5','4','5','4','4','4','5','5','4','4','0','0','0','F','F','F','F','F','F' },
        { 'F','F','F','F','0','5','5','4','4','5','0','0','4','4','0','0','4','5','4','4','5','0','F','F','F','F','F','F' },
        { 'F','F','F','F','0','0','5','5','4','4','5','5','0','0','5','4','5','4','4','4','0','0','F','F','F','F','F','F' },
        { 'F','F','F','F','F','0','0','0','5','4','5','0','5','4','0','5','4','4','4','0','0','F','F','F','F','F','F','F' },
        { 'F','F','F','F','F','F','F','0','0','0','0','0','0','0','0','0','0','0','0','F','F','F','F','F','F','F','F','F' },
        { 'F','F','F','F','0','0','0','0','4','4','5','4','4','4','4','4','4','5','4','0','0','0','0','F','F','F','F','F' },
        { 'F','F','F','F','0','4','4','0','4','5','5','5','5','4','5','5','5','4','4','0','4','4','0','F','F','F','F','F' },
        { 'F','F','F','0','5','4','5','0','4','4','5','5','5','4','5','4','4','4','4','0','4','5','4','0','F','F','F','F' },
        { 'F','F','F','0','4','5','4','0','4','4','5','4','4','5','5','5','5','4','4','0','4','5','4','0','F','F','F','F' },
        { 'F','F','F','0','4','4','4','0','4','5','4','4','4','5','4','5','4','5','4','0','4','5','0','F','F','F','F','F' },
        { 'F','F','F','F','0','4','4','0','4','5','4','4','5','4','4','4','4','5','4','0','5','5','0','F','F','F','F','F' },
        { 'F','F','F','F','F','0','0','0','4','4','5','4','5','5','5','5','4','4','4','0','0','0','F','F','F','F','F','F' },
        { 'F','F','F','F','F','F','F','0','4','5','4','4','4','4','4','4','5','4','4','0','F','F','F','F','F','F','F','F' },
        { 'F','F','F','F','F','F','F','0','4','5','5','4','0','0','0','4','4','5','4','0','F','F','F','F','F','F','F','F' },
        { 'F','F','F','F','F','F','F','0','0','0','0','0','F','F','F','0','0','0','0','0','F','F','F','F','F','F','F','F' },
        { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
        { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
        { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
        { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
        { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
        { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' }
    };
    int size = sizeof(image) / sizeof(image[0]);
    const char colorsTable[16][2] =
    {
        {'0', BG_BLACK},
        {'2', BG_RED},
        {'4', BG_GREEN},
        {'5', BG_YELLOW},
        {'8', BG_BLUE},
        {'A', BG_MAGENTA},
        {'C', BG_CYAN},
        {'E', BG_WHITE},
        {'1', BG_INTENSITY_BLACK},
        {'3', BG_INTENSITY_RED},
        {'7', BG_INTENSITY_GREEN},
        {'6', BG_INTENSITY_YELLOW},
        {'9', BG_INTENSITY_BLUE},
        {'B', BG_INTENSITY_MAGENTA},
        {'D', BG_INTENSITY_CYAN},
        {'F', BG_INTENSITY_WHITE}
    };

    int colorsTableLength = sizeof(colorsTable) / sizeof(colorsTable[0]);
    char colorsPalette[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    int colorsPaletteLength = sizeof(colorsPalette) / sizeof(colorsPalette[0]);
    int colorPairIndex = 0;
    int i = 0;
    int j = 0;
    int count = 0;
    int dir = 1;

    conClear();
    printf("\tTask 1\n");
    for (i = 0; i < colorsPaletteLength; i++)
    {
        char colorCode = '\0';
        char color = '\0';
        /* get current color code from colorsPalette */
        colorCode = colorsPalette[i];
        /* find corresponding color in table */
        for (colorPairIndex = 0; colorPairIndex < colorsTableLength; colorPairIndex++)
        {
            char colorPairCode = colorsTable[colorPairIndex][0];
            char colorPairColor = colorsTable[colorPairIndex][1];
            if (colorCode == colorPairCode)
            {
                color = colorPairColor;
                break;  /* we have found our color, break the loop */
            }
        }
        /* print space with founded color background */
        conSetAttr(color);
        putchar(' ');
    }
    conSetAttr(BG_DEFAULT);
    printf("\n\tTask 2\n");


    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            char colorCode = '\0';
            char color = '\0';

            colorCode = image[i][j];

            for (colorPairIndex = 0; colorPairIndex < colorsTableLength; colorPairIndex++)
            {
                char colorPairCode = colorsTable[colorPairIndex][0];
                char colorPairColor = colorsTable[colorPairIndex][1];

                if (colorCode == colorPairCode)
                {
                    color = colorPairColor;
                    break;
                }
            }
            conSetAttr(color);
            putchar(' ');
        }
        conSetAttr(BG_DEFAULT);
        puts("");
    }
    conSetAttr(BG_DEFAULT);
    conClear();

    for (count = 0, i = 0, j = 0; count < size * size; count++)
    {
        char colorCode = '\0';
        char color = '\0';
        int x = i + 1;
        int y = j + 1;

        colorCode = image[i][j];

        for (colorPairIndex = 0; colorPairIndex < colorsTableLength; colorPairIndex++)
        {
            char colorPairCode = colorsTable[colorPairIndex][0];
            char colorPairColor = colorsTable[colorPairIndex][1];

            if (colorCode == colorPairCode)
            {
                color = colorPairColor;
                break;
            }
        }
        conMove(x, y);
        conSetAttr(color);
        putchar(' ');
        fflush(stdout);
        sleepMillis(5);

        i += dir;
        if (i == size)
        {
            i--;
            j++;
            dir = -dir;
        }

        if (i == -1)
        {
            i++;
            j++;
            dir = -dir;
        }

    }

    conSetAttr(BG_DEFAULT);
    conMove(29,1);
    printf("\tTask 4\n");
    for (i = 0; i < size / 2; i++)
    {
        for (j = i + 1; j <= size - 1 - i; j++)
        {
            char tmp = image[i][j];
            image[i][j] = image[size - 1 - j][i];
            image[size - 1 - j][i] = tmp;

            tmp = image[size - 1 - j][i];
            image[size - 1 - j][i] = image[size - 1 - i][size - 1 - j];
            image[size - 1 - i][size - 1 - j] = tmp;

            tmp = image[size - 1 - i][size - 1 - j];
            image[size - 1 - i][size - 1 - j] = image[j][size - 1 - i];
            image[j][size - 1 - i] = tmp;
        }
    }

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            char colorCode = '\0';
            char color = '\0';

            colorCode = image[i][j];

            for (colorPairIndex = 0; colorPairIndex < colorsTableLength; colorPairIndex++)
            {
                char colorPairCode = colorsTable[colorPairIndex][0];
                char colorPairColor = colorsTable[colorPairIndex][1];

                if (colorCode == colorPairCode)
                {
                    color = colorPairColor;
                    break;
                }
            }
            conSetAttr(color);
            putchar(' ');
        }
        conSetAttr(BG_DEFAULT);
        puts("");
    }
    conReset();
    return 0;
}

