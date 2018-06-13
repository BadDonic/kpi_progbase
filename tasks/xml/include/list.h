#ifndef XML_LIST_H
#define XML_LIST_H

#include <stdlib.h>
#include <string.h>

enum {STR_SIZE = 100000};
typedef struct TaxiDriver TaxiDriver;
typedef struct Client Client;

struct Client{
	char name[STR_SIZE];
	double pay;
};

struct TaxiDriver{
	char name[STR_SIZE];
	int age;
	double salary;
	Client topClients[3];
	TaxiDriver * next;
};

TaxiDriver * TaxiDriver_new(char * driverName, int age, double salary, char * clientName[], double pay[]);
void TaxiDriver_addLast(TaxiDriver ** self, TaxiDriver * node);
void TaxiDriver_free(TaxiDriver ** self);

#endif //XML_LIST_H
