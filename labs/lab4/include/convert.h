#ifndef LAB4_CONVERT_H
#define LAB4_CONVERT_H

#include <list.h>
#include <stdbool.h>

Provider * Convert_GetNHigherAnnualProfit(Provider *self, int N_number);
void Convert_changeFieldInList(Provider *self, int indexProvider, int indexField, char *data);
Provider * Convert_stringToList(char *string);
char * Convert_structureToString(char *result, Provider *self);

bool correctName(char * string);
bool correctYear(char * string);
bool correctAnnualProfit(char *string);
bool correctAge(char * string);
bool correctIndex(char * string, int maxIndex);
bool correctFileName(char * string);

#endif //LAB4_CONVERT_H
