#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <progbase.h>
#include <pbconsole.h>

int main()
{
    char text[] = "I've watched through his eyes, I've listened through his ears, and I tell you he's the one. \
Or at least as close as we're going to get. That's what you said about the brother. \
The brother tested out impossible. For other reasons. Nothing to do with his ability. \
Same with the sister. And there are doubts about him. He's too malleable. \
Too willing to submerge himself in someone else's will. \
Not if the other person is his enemy. \
So what do we do? Surround him with enemies all the time?";
    int i = 0;
    int count = 0;
    int consonants = 0;
    int vowels = 0;
    int length_word = 0;
    char vowel_letters[] = "AaEeIiOoUu";
    conSetAttr(BG_BLUE);
    printf("Print the text and his length\n");
    conSetAttr(BG_DEFAULT);
    printf("%s\nLength = %i\n", text, (int)strlen(text));

    puts("===========================================");
    conSetAttr(BG_BLUE);
    printf("Print the text without letters in lowercase\n");
    conSetAttr(BG_DEFAULT);
    for (i = 0; i < strlen(text); i++)
    {
        if (!islower(text[i]))
        {
            printf("%c", text[i]);
            count++;
        }
    }
    printf("\nLength = %i\n", count);

    puts("===========================================");
    conSetAttr(BG_BLUE);
    printf("Print each sentence on a new line and his length \n");
    conSetAttr(BG_DEFAULT);
    for (i = 0, count = 0; i < strlen(text); i++)
    {
        putchar(text[i]);
        count++;
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            if  (text[i + 1] != '\0')
            {
                printf("\nLength = %i\n------------------------------------\n", count + 1);
                i++;
                count = 0;
            }
            else
            {
                printf("\nLength = %i\n", count);
            }
        }
    }

    puts("===========================================");
    conSetAttr(BG_BLUE);
    printf("The total number of words in the text\n");
    conSetAttr(BG_DEFAULT);
    for (i = 0, count = 1; i < strlen(text); i++)
    {
        if (isspace(text[i]))
        {
            count++;
        }

    }
    printf("The total number of words = %i\n", count);

    puts("===========================================");
    conSetAttr(BG_BLUE);
    printf("Print all words which beginning with a consonant letter\n");
    conSetAttr(BG_DEFAULT);
    for (i = 0, count = 0; i < strlen(text); i++)
    {
        if (isupper(text[i]) && text[i] != 'A' && text[i] != 'E' && text[i] != 'I' && text[i] != 'O' && text[i] != 'U')
        {
            for (; isalpha(text[i]) || ((text[i] == 39  || text[i] == '-') && isalpha(text[i + 1])); i++)
            {
                putchar(text[i]);
            }
            printf(", ");
            count++;
        }
    }
    printf("\nThe total number of words = %i\n", count);

    puts("===========================================");
    conSetAttr(BG_BLUE);
    printf("Print all the words in which consonant > vowels\n");
    conSetAttr(BG_DEFAULT);
    for (i = 0, count = 0; i < strlen(text); i++)
    {
        for (; isalpha(text[i]) || ((text[i] == 39  || text[i] == '-') && isalpha(text[i + 1])); i++)
        {
            length_word++;
            if (strchr(vowel_letters, text[i]) != 0)
            {
                vowels++;
            }
            else if (isalpha(text[i]))
            {
                consonants++;
            }
        }

        if (consonants > vowels)
        {
            for (i = i - length_word; isalpha(text[i]) || ((text[i] == 39  || text[i] == '-') && isalpha(text[i + 1])); i++)
            {
                putchar(text[i]);
            }
            printf(", ");
            count++;
        }
        length_word = 0;
        consonants = 0;
        vowels = 0;
    }
    printf("\nThe total number of words = %i\n", count);
    puts("===========================================");

    return 0;
}
