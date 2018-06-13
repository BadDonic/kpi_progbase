#include <list.h>

TaxiDriver * TaxiDriver_new(char * driverName, int age, double salary, char * clientName[], double pay[]) {
	TaxiDriver * self = (TaxiDriver *)malloc(sizeof(TaxiDriver));
	strcpy(self->name, driverName);
	self->age = age;
	self->salary = salary;
	for (int i = 0; i < 3; ++i) {
		strcpy(self->topClients[i].name, clientName[i]);
		self->topClients[i].pay = pay[i];
	}
	self->next = NULL;
	return self;
}

void TaxiDriver_addLast(TaxiDriver ** self, TaxiDriver * node) {
	if (*self == NULL) {
		*self = node;
		return;
	}

	TaxiDriver * current = *self;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = node;
}


void TaxiDriver_free(TaxiDriver ** self) {
	while ((*self)->next != NULL) {
		TaxiDriver * current = *self;
		while (current->next->next != NULL) {
			current = current->next;
		}
		free(current->next);
		current->next = NULL;
	}
	free(*self);
	*self = NULL;
}