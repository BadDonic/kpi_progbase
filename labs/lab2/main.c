#include <progbase.h>
#include <pbconsole.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

void line(int x);
void clear_line(int line, int numbers);
void enter_string(char string[]);
void cover(char name[], char help[], int start_name, int start_help);
void print(char str1[], char str2[], char str3[], char str4[], char str5[], char str6[], char str7[], char str8[]);
void center(char str[],int x, int y);
void stand_out(char str[],int x, int y);
void clear_table(int x1, int number1, int x2, int number2);
void array_init(int array[], int size);
int searchMax(int some_array[], int size);
int searchMin(int some_array[], int size);
void swap (int array[], int posMin, int posMax);
void print_array(int array[], int size);
void cover_help(char name[], int start_name);
void array_initd(double array[], int size);
void print_arrayD(double array[], int size);
void array_init2(int size_i, int size_j, int (*array)[size_j], int x, int y);
void print_array2(int size_i, int size_j, int (*array)[size_j], int x, int y);
int scan(int number,char str[], int x, int y);

int main()
{
    conHideCursor();
    conResize(40,100);
    char n = '\0';
    srand(time(0));
    while ( n != 'q')
    {
        conHideCursor();
        conResize(40,100);
        conClear();
        line(1);
        center("Main",2,48);
        line(3);
        line(37);
        center("If you need help, press button 'h'",38,33);
        line(39);
        conSetAttr(FG_GREEN);
        for (int i = 0; i < 37  ; i++)
        {
            conMove(2 + i, 1);
            printf("|");
            conMove(2 + i,100);
            printf("|");
        }
        conSetAttr(FG_DEFAULT);
        stand_out("Exercises!",5,9);
        print("1. Univariate array!",
        "2. Two univariate arrays!",
        "3. Two-dimensional array!", 
        "4. Processing of lines of C!","","","","");
        line(11);
        center("Please Enter number of your exercises",12,31);
        line(13);

        n = conGetChar();

        switch(n)
        {
            case '1':
            {
                conClear();
                stand_out("Array: ",11,3);
                int array[10];
                array_init(array, 10);
                while (n != 'r')
                {
                    cover("Exercise № 1","If you need help for Exercise № 1, press button 'h'",44,24);

                    n = conGetChar();
                    clear_table(4,17,27,1);

                    switch(n)
                    {
                        case '1':
                        {
                            clear_line(4,17);
                            stand_out("Array: ",11,3);
                            for (int i = 0; i < 10; i++)
                            {
                                array[i] = rand() % 201 -100;
                                printf("%3i ", array[i]);
                            }
                            break;
                        }
                        case '2':
                        {
                            clear_line(4,17);
                            stand_out("Array: ",11,3);
                            array_init(array, 10);
                            break;
                        }
                        case '3':
                        {
                            stand_out("Array: ",11,3);
                            print_array(array, 10);
                            int posMax = searchMax(array,10);
                            conMove(27,39);
                            printf("PosMax = %i, Max = %i", posMax, array[posMax]);

                            break;
                        }
                        case '4':
                        {
                            stand_out("Array: ",11,3);
                            print_array(array, 10);
                            int sum = 0;
                            for (int i = 0; i < 10; i++)
                            {
                                sum += array[i];
                            }
                            conMove(27,45);
                            printf("Sum = %i", sum);
                            break;
                        }
                        case '5':
                        {
                            stand_out("Array: ",11,3);
                            print_array(array, 10);
                            int sumPositive = 0;
                            for (int i = 0; i < 10; i++)
                            {
                                if (array[i] > 0)
                                {
                                    sumPositive += array[i];
                                }
                            }
                            conMove(27,41);
                            printf("SumPositive = %i", sumPositive);
                            break;
                        }
                        case '6':
                        {
                            stand_out("Array: ",11,3);
                            print_array(array, 10);
                            int temp[10] = {0,0,0,0,0,0,0,0,0,0};
                            for (int i = 0; i < 10; i++)
                            {
                                for (int j = i + 1; j < 10; j++)
                                {
                                    if (array[i] == array[j])
                                    {
                                        temp[i] += 1;
                                    }
                                }
                            }
                            int posMax = searchMax(temp,10);
                            conMove(27,21);
                            printf("The first element that repeated most of the time[%i] = %i", posMax, array[posMax]);
                            break;
                        }
                        case '7':
                        {
                            clear_line(4,17);
                            stand_out("Previos Array: ",9,3);
                            print_array(array, 10);
                            int posMax = searchMax(array,10);
                            int posMin = searchMin(array,10);
                            swap(array, posMin, posMax);
                            stand_out("Array: ",14,3);
                            print_array(array, 10);
                            break;
                        }
                        case '8':
                        {
                            clear_line(4,17);
                            stand_out("Previos_Array: ",9,3);
                            print_array(array, 10);
                            int k = 0;
                            k = scan(k,"Enter some number: ",34,39);
                            clear_line(33,2);
                            stand_out("Array: ",14,3);
                            for (int i = 0; i < 10; i++)
                            {
                                array[i] -= k;
                            }
                            print_array(array, 10);
                            break;
                        }
                        case 'h':
                        {
                            conClear();
                            cover_help("Help for Exercise № 1", 39);
                            print("1.Заповнити масив випадковими числами від -100 до 100.",
                            "2.Обнулити всі елементи масиву.","3.Знайти максимальний елемент та його індекс.",
                            "4.Знайти суму елементів масиву.",
                            "5.Вивести суму додатніх елементів масиву.",
                            "6.Знайти перший елемент, що повторюється найбільшу кількість раз.",
                            "7.Поміняти місцями максимальний і мінімальний елементи масиву.",
                            "8.Зменшити всі елементи масиву на введене число.");
                            n = conGetChar();
                            conClear();
                            stand_out("Array: ",11,3);
                            print_array(array,10);
                            break;
                        }
                        case 'q':
                        {
                            conClear();
                            conShowCursor();
                            return 0;
                        }
                        default:
                        {
                            stand_out("Array: ",11,3);
                            print_array(array,10);
                            break;
                        }
                    }
                }
                break;
            }
            case '2':
            {
                conClear();
                double array1[10];
                double array2[10];
                stand_out("Array1: ",9,3);
                array_initd(array1, 10);
                stand_out("Array2: ",14,3);
                array_initd(array2, 10);
                while (n != 'r')
                {
                    cover("Exercise № 2","If you need helper for Exercise № 2, press button 'h'",44,23);

                    n = conGetChar();
                    clear_table(4,17,27,1);

                    switch(n)
                    {
                        case '1':
                        {
                            stand_out("Array1: ",9,3);
                            for (int i = 0; i < 10; i++)
                            {
                                array1[i] = (rand() % 4100 - 2000) * 0.01;
                            }
                            print_arrayD(array1, 10);
                            stand_out("Array2: ",14,3);
                            for (int i = 0; i < 10; i++)
                            {
                                array2[i] = (rand() % 4100 - 2000) * 0.01;
                            }
                            print_arrayD(array2, 10);
                            break;
                        }
                        case '2':
                        {
                            stand_out("Array1: ",9,3);
                            array_initd(array1, 10);
                            stand_out("Array2: ",14,3);
                            array_initd(array2, 10);
                            break;
                        }
                        case '3':
                        {
                            stand_out("Array1: ",7,3);
                            print_arrayD(array1, 10);
                            stand_out("Array2: ",15,3);
                            print_arrayD(array2, 10);
                            double array3[10];
                            stand_out("Sum of Arrays: ",11,8);
                            for (int i = 0; i < 10; i++)
                            {
                                array3[i] = array1[i] + array2[i];
                            }
                            print_arrayD(array3, 10);
                            break;
                        }
                        case '4':
                        {
                            stand_out("Array1: ",9,3);
                            print_arrayD(array1, 10);
                            stand_out("Array2: ",14,3);
                            print_arrayD(array2, 10);
                            double sum = 0;
                            for (int i = 0; i < 10; i++)
                            {
                                sum += array1[i];
                                sum -= array2[i];
                            }
                            conMove(27,39);
                            if (sum > 0)
                            {
                                printf("Sum_Array1 > Sum_Array2");
                            }else if (sum < 0)
                            {
                                printf("Sum_Array1 < Sum_Array2");
                            }else
                            {
                                printf("Sum_Array1 = Sum_Array2");
                            }
                            break;
                        }
                        case '5':
                        {
                            int posMax = 0;
                            int posMin = 0;
                            for (int i = 0; i < 10; i++)
                            {
                                if (array1[i] > array1[posMax])
                                {
                                    posMax = i;
                                }
                                if (array2[i] < array2[posMin])
                                {
                                    posMin = i;
                                }
                            }
                            double swap = array1[posMax];
                            array1[posMax] = array2[posMin];
                            array2[posMin] = swap;
                            stand_out("Array1: ",9,3);
                            print_arrayD(array1, 10);
                            stand_out("Array2: ",14,3);
                            print_arrayD(array2, 10);
                            break;
                        }
                        case 'h':
                        {
                            conClear();
                            cover_help("Help for Exercise № 2", 39);
                            print("1.Заповнити масиви випадковими дробовими числами від -20.0 до 20.0.",
                             "2.Обнулити всі елементи масивів.",
                             "3.Знайти суму відповідних елементів першого і другого масиву.",
                             "4.Вивести номер масиву, у якому максимальна сума елементів.",
                             "5.Поміняти місцями максимальний елемент першого масиву і мінімальний елемент другого масиву."
                             ,"","","");
                            n = conGetChar();
                            conClear();
                            stand_out("Array1: ",9,3);
                            print_arrayD(array1, 10);
                            stand_out("Array2: ",14,3);
                            print_arrayD(array2, 10);
                            break;
                        }
                        case 'q':
                        {
                            conClear();
                            conShowCursor();
                            return 0;
                        }
                        default:
                        {
                            stand_out("Array1: ",9,3);
                            print_arrayD(array1, 10);
                            stand_out("Array2: ",14,3);
                            print_arrayD(array2, 10);
                            break;
                        }
                    }
                }
                break;
            }
            case '3':
            {
                conClear();
                stand_out("Array:",4, 47);
                int array[8][8];
                array_init2(8,8,array, 6, 33);
                while (n != 'r')
                {
                    cover("Exercise № 3","If you need help for Exercise № 3, press button 'h'",44,24);

                    n = conGetChar();
                    clear_table(4,18,27,1);
                    switch(n)
                    {
                        case '1':
                        {
                            stand_out("Array:",4, 47);
                            for (int i = 0; i < 8; i++)
                            {
                                for (int j = 0; j < 8; j++)
                                {
                                    array[i][j] = rand() % 21 - 10 ;
                                }
                            }
                            print_array2(8, 8, array, 6, 33);
                            break;

                        }
                        case '2':
                        {
                            stand_out("Array:",4, 47);
                            array_init2(8,8,array, 6, 33);
                            break;
                        }
                        case '3':
                        {
                            stand_out("Array:",4, 47);
                            print_array2(8, 8, array, 6, 33);
                            int posMin_i = 0;
                            int posMin_j = 0;
                            for (int i = 0; i < 8; i++)
                            {
                                for (int j = 0; j < 8; j++)
                                {
                                    if (array[i][j] < array[posMin_i][posMin_j])
                                    {
                                        posMin_i = i;
                                        posMin_j = j;

                                    }
                                }
                            }
                            conMove(27,43);
                            printf("Min[%i][%i] = %i", posMin_i, posMin_j, array[posMin_i][posMin_j]);
                            break;
                        }
                        case '4':
                        {
                            stand_out("Array:",4, 47);
                            print_array2(8, 8, array, 6, 33);
                            int sum = 0;
                            for (int i = 0; i < 8; i++)
                            {
                                sum += array[i][i];
                            }
                            conMove(27,35);
                            printf("Sum of the main diagonal = %i", sum);
                            break;
                        }
                        case '5':
                        {
                            stand_out("Array:",4, 47);
                            print_array2(8, 8, array, 6, 33);
                            int sum = 0;
                            int x = 0;
                            stand_out("Please Enter indexes X within [0;7]",33,32);
                            x = scan(x,"X: ",34,48);
                            while (x > 7)
                            {
                                    clear_line(33,2);
                                    stand_out("Error! Please Enter indexes X within [0;7]", 33,29);
                                    x = scan(x,"X: ",34,48);
                            }
                            for (int j = 0; j < 8; j++)
                            {
                                sum += array[x][j];
                            }
                            clear_line(33,2);

                            conMove(27,41);
                            printf("Sum of line[%i] = %i", x,  sum);
                            break;
                        }
                        case '6':
                        {
                            stand_out("Array:",4, 47);
                            print_array2(8, 8, array, 6, 33);
                            int posMin_i = 0;
                            int posMin_j = 0;
                            int posMax_i = 0;
                            int posMax_j = 0;
                            for (int i = 0; i < 8; i++)
                            {
                                for (int j = 0; j < 8; j++)
                                {
                                    if (array[i][j] < array[posMin_i][posMin_j])
                                    {
                                        posMin_i = i;
                                        posMin_j = j;
                                    }
                                    if (array[i][j] > array[posMax_i][posMax_j])
                                    {
                                        posMax_i = i;
                                        posMax_j = j;
                                    }
                                }
                            }
                            int swap = array[posMax_i][posMax_j];
                            array[posMax_i][posMax_j] = array[posMin_i][posMin_j];
                            array[posMin_i][posMin_j] = swap;
                            print_array2(8, 8, array, 6, 33);
                            break;
                        }
                        case '7':
                        {
                            stand_out("Array:",4, 47);
                            print_array2(8, 8, array, 6, 33);
                            int x = 0;
                            int y = 0;
                            int number = 0;
                            stand_out("Please Enter indexes X and Y within [0;7]",33,29);
                            x = scan(x,"X: ",34,48);
                            y = scan(y,"Y: ",35,48);
                            while (x > 7 || y > 7 || x < 0 || y < 0)
                            {
                                clear_line(33,3);
                                stand_out("Error! Please Enter indexes X and Y within [0;7]", 33,26);
                                x = scan(x,"X: ",34,48);
                                y = scan(y,"Y: ",35,48);
                            }
                            number = scan(number,"Number: ",36,46);
                            array[x][y] = number;
                            clear_line(33,4);
                            print_array2(8, 8, array, 6, 33);
                            break;
                        }
                        case 'h':
                        {
                            conClear();
                            cover_help("Help for Exercise № 3", 39);
                            print("1.Заповнити масив випадковими числами від -10 до 10.",
                            "2.Обнулити всі елементи масиву.",
                            "3.Знайти суму відповідних елементів першого і другого масиву.",
                            "4.Знайти суму головної діагоналі масиву.",
                            "5.Знайти суму рядка за заданим індексом.",
                            "6.Поміняти місцями максимальний і мінімальний елементи масиву.",
                            "7.Змінити значення елементу за вказаними індексами на задане.","");
                            n = conGetChar();
                            conClear();
                            stand_out("Array:",4, 47);
                            print_array2(8, 8, array, 6, 33);
                            break;
                        }
                        case 'q':
                        {
                            conClear();
                            conShowCursor();
                            return 0;
                        }
                        default:
                        {
                            stand_out("Array:",4, 47);
                            print_array2(8, 8, array, 6, 33);
                        }

                    }
                }
                break;
            }
            case '4':
            {
                conClear();
                stand_out("String: ",11, 6);
<<<<<<< HEAD
                char string[] = "That’s what you said about me.\0";
=======
                char string[] = "That’s what you said about me. ";
>>>>>>> 11beecde7adbc8970511f507968a351604cdee31
                puts(string);
                while (n != 'r')
                {
                    cover("Exercise № 4","If you need help for Exercise № 4, press button 'h'",44,24);

                    n = conGetChar();
                    clear_table(4,18,27,1);
                    switch(n)
                    {
                        case '1':
                        {
                            stand_out("String: ",11, 6);
                            stand_out("Enter New String: ",34,3);
                            conShowCursor();
                            fgets(string, 81, stdin);
                            conHideCursor();
                            clear_table(11,1,33,4);
                            stand_out("String: ",11, 6);
                            puts(string);
                            break;
                        }
                        case '2':
                        {
                            string[0] = '\0';
                            stand_out("String: ",11, 6);
                            puts(string);
                            break;
                        }
                        case '3':
                        {
                            stand_out("String: ",11, 6);
                            puts(string);
                            conMove(27,45);
                            printf("Length = %i", (int)strlen(string));
                            break;
                        }
                        case '4':
                        {
                            stand_out("String: ",11, 6);
                            puts(string);
                            stand_out("Please Enter position  and length of string within [0..Length]",33,17);
                            int length = 0;
                            int pos = 0;
                            pos = scan(pos,"Position: ", 34,45);
                            length = scan(length,"Length: ",35,46);
                            clear_line(33,3);
                            while ( length < 0 || pos > (int)strlen(string) || pos < 0)
                            {
                                stand_out("Error! Please Enter position  and length of string within [0..80]",33,15);
                                pos = scan(pos,"Position: ", 34,45);
                                length = scan(length,"Length: ",35,46);
                                clear_line(33,3);
                            }
                            if (pos < (int)strlen(string))
                            {
                                stand_out("Substring: ",27,4);
<<<<<<< HEAD
                                for (int i = pos; i < length + pos + 2; i++)
=======
                                for (int i = pos; i < length + pos && i < strlen(string); i++)
>>>>>>> 11beecde7adbc8970511f507968a351604cdee31
                                {
                                    printf("%c", string[i]);
                                }
                            }else
                            {
                                stand_out("Substring: Not Exist",27,40);
                            }
                            break;
                        }
                        case '5':
                        {
                            stand_out("String: ",5, 6);
                            puts(string);
                            line(7);
                            line(8);
                            center("Result",10,47);
                            line(12);
                            clear_table(13,14,0,0);
                            char chr = '\0';
                            stand_out("Enter some character: ",34,36);
                            scanf("%c", &chr);
                            clear_line(34,1);
                            int pos = 0;
                            int x = 13;
                            for (int i = 0; i < strlen(string); i++)
                            {
                                if (string[i] == chr || i == strlen(string) - 1)
                                {
                                    conMove(x, 3);
                                    for (int j = pos; j < i; j++)
                                    {
                                        printf("%c", string[j]);
                                    }
                                    x ++;
                                    pos = i + 1;
                                }
                            }
                            if (string[strlen(string) - 1] != chr)
                            {
                                printf("%c", string[strlen(string) - 1]);
                            }
                            chr = conGetChar();
                            clear_table(4,35,0,0);
                            stand_out("String: ",11, 6);
                            puts(string);
                            break;
                        }
                        case '6':
                        {
                            stand_out("String: ",11, 6);
                            puts(string);
                            int start1 = 0;
                            int length = 0;
                            int length1 = 0;
                            for (int i = 0; i < strlen(string); i++)
                            {
                                if (!isalpha(string[i]))
                                {
                                    if (length > length1)
                                    {
                                        length1 = length;
                                        start1 = i - length1;
                                    }
                                    length = -1;
                                    
                                }
                                length++;
                            }
                            stand_out("The Largest word: ",27, 3);
                            
                            for (int i = start1; i < length1 + start1 ; i++)
                            {
                                printf("%c",string[i]);
                            }
                            break;
                        }
                        case '7':
                        {
                            stand_out("String: ",11, 6);
                            puts(string);
                            int index = 0;
                            stand_out("Numbers: ",27,3);
                            for (index = 0; index < strlen(string); index++)
                            {
                                char ch = string[index];
                                char nextCh = string[index + 1];
                                if (isdigit(ch) || ('-' == ch && isdigit(nextCh)))
                                {
                                    int number = atoi(string + index);
                                    int count = printf("%d ", number);
                                    index += count - 2;
                                }
                            }
                            break;
                        }
                        case '8':
                        {
                            stand_out("String: ",11, 6);
                            puts(string);
                            int index = 0;
                            double sum = 0;
                            int entrance = 0;
                            conMove(27,3);
                            for (index = 0; index < strlen(string); index++)
                            {
                                char ch = string[index];
                                char nextCh = string[index + 1];
                                if (isdigit(ch) || ('-' == ch && isdigit(nextCh)))
                                {
                                    double number = atof(string + index);
<<<<<<< HEAD
                                    int count = printf("%g", number);
                                    index += count - 1;
                                    sum += number;
                                    clear_line(27,1);
                                    entrance = 1;
=======
                                    if (number - (int)(number) != 0)
                                    {
                                        int count = printf("%g", number);
                                        index += count - 1;
                                        sum += number;
                                        entrance = 1;
                                    }
                                    clear_line(27,1);
                                    
>>>>>>> 11beecde7adbc8970511f507968a351604cdee31
                                }
                            }
                            if (entrance == 1)
                            {
                                stand_out("Sum: ",27,45);
                                printf("%g", sum);
                            }else
                            {
                                stand_out("Sum: ",27,45);
                            }
                            break;
                        }
                        case 'h':
                        {
                            conClear();
                            cover_help("Help for Exercise № 4", 39);
                            print("1.Заповнити строку вводом із консолі.",
                            "2.Очистити строку.",
                            "3.Вивести довжину строки.",
                            "4.Вивести підстроку із заданої позиції і заданої довжини.",
                            "5.Вивести список підстрок, розділених заданим символом.",
                            "6.Вивести найдовше слово (слова - непуста послідовність буквенних символів).",
                            "7.Знайти та вивести всі цілі числа, що містяться у строці.",
                            "8.Знайти та вивести суму всіх дробових чисел, що містяться у строці.");
                            n = conGetChar();
                            conClear();
                            stand_out("String: ",11, 6);
                            puts(string);
                            break;
                        }
                        case 'q':
                        {
                            conClear();
                            conShowCursor();
                            return 0;
                        }
                        default:
                        {
                            stand_out("String: ",11, 6);
                            puts(string);
                        }
                    }
                }
                break;
            }
            case 'h':
            {
                conClear();
                cover_help("Help for Programm", 39);
                print("Button '1...4' - Choose some Exercises in Main Menu",
                "Button '1....8' - Choose some Actions in Exercises",
                "Button 'q' - Exit ",
                "Button 'r' - Return to Main Menu",
                "",
                "",
                "",
                "");
                n = conGetChar();
                break;
            }
        }
    }
    conClear();
    conShowCursor();
    return 0;
}


void line(int x)
{
    int i = 0;
    conMove(x,2);
    conSetAttr(FG_GREEN);
    for (i = 2; i <= 99; i++)
    {
        printf("=");
    }
    conSetAttr(FG_DEFAULT);
    printf("\n");
}
void clear_line(int line, int numbers)
{
    int i = 0;

    for (int j = 0; j < numbers; j++)
    {
        for (i = 2; i <= 99; i++)
        {
            conMove(line + j,i);
            printf(" ");
        }
    }
}
void enter_string(char string[])
{
    conSetAttr(FG_BLUE);
    printf("String: ");
    conSetAttr(FG_DEFAULT);
    printf("%s\n", string);
}

void cover(char name[], char help[], int start_name, int start_help)
{
    line(1);
    center(name,2,start_name);
    line(3);
    line(37);
    center(help,38,start_help);
    line(39);
    conSetAttr(FG_GREEN);
    for (int i = 0; i < 37  ; i++)
    {
        conMove(2 + i, 1);
        printf("|");
        conMove(2 + i,100);
        printf("|");
    }
    conSetAttr(FG_DEFAULT);
    line(22);
    center("Result",24,47);
    line(26);
    line(28);
    center("Please Enter number of your operation",30,31);
    line(32);

}
void print(char str1[], char str2[], char str3[], char str4[], char str5[], char str6[], char str7[], char str8[])
{
    conMove(6,2);
    printf("%s", str1);
    conMove(7,2);
    printf("%s", str2);
    conMove(8,2);
    printf("%s", str3);
    conMove(9,2);
    printf("%s", str4);
    conMove(10,2);
    printf("%s", str5);
    conMove(11,2);
    printf("%s", str6);
    conMove(12,2);
    printf("%s", str7);
    conMove(13,2);
    printf("%s", str8);
    conMove(14,2);
}
void center(char str[],int x, int y)
{
    conMove(x,y);
    conSetAttr(FG_INTENSITY_CYAN);
    puts(str);
    conSetAttr(FG_DEFAULT);
}
void stand_out(char str[],int x, int y)
{
    conMove(x,y);
    conSetAttr(FG_INTENSITY_RED);
    printf("%s", str);
    conSetAttr(FG_DEFAULT);
}
void clear_table(int x1, int number1, int x2, int number2)
{
    clear_line(x1,number1);
    clear_line(x2,number2);
}
void array_init(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = 0;
        printf("%3i ", array[i]);
    }
}
int searchMax(int some_array[], int size)
{
    int max = some_array[0];
    int posMax = 0;
    for (int i = 0; i < size; i++)
    {
        if (some_array[i] > max)
        {
            max = some_array[i];
            posMax = i;
        }
    }
    return posMax;
}
int searchMin(int some_array[], int size)
{
    int min = some_array[0];
    int posMin = 0;
    for (int i = 0; i < size; i++)
    {
        if (some_array[i] < min)
        {
            min = some_array[i];
            posMin = i;
        }
    }
    return posMin;
}
void swap (int array[], int posMin, int posMax)
{
    int swap = array[posMax];
    array[posMax] = array[posMin];
    array[posMin] = swap;
}
void print_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%3i ", array[i]);
    }
}
void cover_help(char name[], int start_name)
{
    line(1);
    center(name,2,start_name);
    line(3);
    line(19);
    center("Press any button to return past the window",29,29);
    line(39);
    conSetAttr(FG_GREEN);
    for (int i = 0; i < 37  ; i++)
    {
        conMove(2 + i, 1);
        printf("|");
        conMove(2 + i,100);
        printf("|");
    }
    conSetAttr(FG_DEFAULT);

}
void array_initd(double array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = 0;
        printf("%g ", array[i]);
    }
}
void print_arrayD(double array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%g ", array[i]);
    }
}
void array_init2(int size_i, int size_j, int (*array)[size_j], int x, int y)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            array[i][j] = 0;
        }
    }
    print_array2(size_i, size_j, array, x, y);
}
void print_array2(int size_i, int size_j, int (*array)[size_j], int x, int y)
{

    for (int i = 0; i < size_i; i++)
    {
        conMove(x + i,y);
        for (int j = 0; j < size_j; j++)
        {
            printf("%3i ", array[i][j]);
        }
        puts("");
        puts("");
        x++;
    }
}
int scan(int number,char str[], int x, int y)
{
    stand_out(str, x, y);
    scanf("%d", &number);
    return number;
}
