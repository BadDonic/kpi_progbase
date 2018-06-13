#ifndef LAB4_LIST_H
#define LAB4_LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <ctype.h>

enum {STR_SIZE = 1000, STRUCTURE_SIZE = 6};

typedef struct Provider Provider;
typedef struct Owner Owner;

Provider * Convert_stringToList(char *string);
Provider * Provider_newStructure(char * provName, int year, long double annualProfit, char * ownerName, char * ownerSurname, int age);
int Provider_countList(Provider * self);
Provider * Provider_getStructure(Provider * self, int index);
char * Convert_structureToString(char *result, Provider *self);
void Provider_freeList(Provider ** self);
void Provider_deleteStructure(Provider ** self, int index);
void Provider_freeStructure(Provider ** self);
void Provider_addLast(Provider ** self, Provider * node);
char * Provider_getProvName(Provider * self);
int * Provider_getYear(Provider * self);
long double * Provider_getAnnualProfit(Provider * self);
char * Provider_getOwnerName(Provider * self);
char * Provider_getOwnerSurname(Provider * self);
int * Provider_getAge(Provider * self);
void Provider_insert(Provider ** self, Provider * node, int index);

Owner * Owner_newStructure(char * ownerName, char * ownerSurname, int age);
void Owner_freeStructure(Owner ** self);
#endif //LAB4_LIST_H
