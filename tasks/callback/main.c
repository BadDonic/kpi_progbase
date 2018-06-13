#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum {STR_SIZE = 100};

typedef struct Student Student;

struct Student {
	char name[STR_SIZE];
	int age;
};

void printText(char ** string, int size);
int stringCompare(const void * p1, const void * p2);
int countConsonant(char * word);

void printStudents(Student * self, size_t size);
int studentCompare(const void * p1, const void * p2);

void Array_foreach(int arr[], int len, void (*action)(int, int));
void Array_foreachReversed(int arr[], int len, void (*action)(int, int));
void printNegativeOddNumber(int number, int index);
void printIntegerNumbers(int number, int index);

int main() {
	//STRING SORTING
	char * string[] = {"Anyone", "who", "reads", "Old", "and", "Middle", "English", "literary", "texts" "will", "be", "familiar", "with", "the", "mid-brown", "volumes", "of", "the", "EETS", "with", "the", "symbol", "of", "Alfred's", "jewel", "embossed", "on", "the", "front", "cover"};
	int length = sizeof(string) / sizeof(char *);
	printf("TASK №1 :\n \tCортування масиву слів у порядку зростання кількості приголосних букв.\n\n");
	printf("String : \n");
	printText(string, length);
	qsort(string, (size_t)length, sizeof(char *), stringCompare);
	printf("\nSORTED String : \n");
	printText(string, length);
	puts("=====================================================");

	//TASK 2
	Student students[] = { {.name = "Ivan", .age = 12},
						   {.name = "Danya", .age = 18},
						   {.name = "Vlad", .age = 19},
						   {.name = "Lena", .age = 17},
						   {.name = "Sasha", .age = 23},
						   {.name = "Dima", .age = 17},
						   {.name = "Bodya", .age = 27} };
	size_t lengthOfStudents = sizeof(students) / sizeof(Student);
	printf("TASK №2 :\n \t Cортування масиву елементів Студент за прізвищем у алфавітному порядку \n\n");
	printf("Students : \n");
	printStudents(students, lengthOfStudents);
	qsort(students, lengthOfStudents, sizeof(Student), studentCompare);
	printf("\nSORTED Students : \n");
	printStudents(students, lengthOfStudents);
	puts("=====================================================");

	//TASK3
	int arr[] = {7, 3, 4, 1, -1, 23, 12, 43, 2, -4, 5, -7, -3, -4, -1, 1, -23, -12, -43, -2, 4, -5};
	int lengthOfInteger = sizeof(arr) / sizeof(int);
	printf("Integer Numbers : \n ");
	Array_foreach(arr, lengthOfInteger, printIntegerNumbers);
	puts("");
	puts("Array_foreach (Negative and Odd)");
	Array_foreach(arr, lengthOfInteger, printNegativeOddNumber);
	puts("");
	puts("Array_foreachReversed (Negative and Odd)");
	Array_foreachReversed(arr, lengthOfInteger, printNegativeOddNumber);
	return EXIT_SUCCESS;
}

void printText(char ** string, int size) {
	for (int i = 0; i < size; ++i)
		printf("%s ", string[i]);
	puts("");
}

int countConsonant(char * word) {
	int consonant = 0;
	for (int i = 0; i < strlen(word); ++i)
		if (isalpha(word[i]) && strchr("oeiauOEIAU", word[i]) == NULL) consonant++;
	return consonant;
}

int stringCompare(const void *p1, const void *p2) {
	return countConsonant(*(char **)p1) - countConsonant(*(char **)p2);
}

void printStudents(Student *self, size_t size) {
	for (int i = 0; i < size; ++i)
		printf("[ name: %s \t age: $%i ]\n", self[i].name, self[i].age);
	puts("");
}

int studentCompare(const void *p1, const void *p2) {
	return strcmp(((Student *)p1)->name, ((Student *)p2)->name);
}

void Array_foreach(int *arr, int len, void (*action)(int, int)) {
	for (int i = 0; i < len; ++i)
		action(arr[i], i);
}

void Array_foreachReversed(int *arr, int len, void (*action)(int, int)) {
	for (int i = len - 1; i >= 0; --i)
		action(arr[i], i);
}

void printIntegerNumbers(int number, int index) {
	printf("arr[%i] = %i\n ", index, number);
}

void printNegativeOddNumber(int number, int index) {
	if (number < 0 && (abs(number) % 2) == 1) printf("arr[%i] = %i\n", index, number);
}
