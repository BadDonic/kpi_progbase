#include <list.h>


struct Provider {
	char provName[STR_SIZE];
	int year;
	long double annualProfit;
	Owner * owner;
	Provider * next;
};

struct Owner {
	char ownerName[STR_SIZE];
	char ownerSurname[STR_SIZE];
	int age;
};





Provider * Provider_newStructure(char * provName, int year, long double annualProfit, char * ownerName, char * ownerSurname, int age) {
	Provider * provider = (Provider *)malloc(sizeof(Provider));
	strcpy(provider->provName, provName);
	provider->year = year;
	provider->annualProfit = annualProfit;
	provider->owner = Owner_newStructure(ownerName, ownerSurname, age);
	provider->next = NULL;
	return provider;
}

int Provider_countList(Provider * self) {
	int count = 0;
	while (self != NULL) {
		self = self->next;
		count++;
	}
	return count;
}

Provider * Provider_getStructure(Provider * self, int index) {
	if (index >= Provider_countList(self) || index < 0) {
		return NULL;
	}
	while (self != NULL && index != 0) {
		self = self->next;
		index--;
	}
	return self;
}



void Provider_freeList(Provider ** self) {
	for (int i = Provider_countList(*self) - 1; i >= 0 ; --i) {
		Provider_deleteStructure(self, i);
	}
}

void Provider_deleteStructure(Provider ** self, int index) {
	if (index >= Provider_countList(*self) || index < 0) {
		return ;
	}
	Provider * current = *self;
	if (index == 0) {
		*self = (*self)->next;
		Provider_freeStructure(&current);
		return ;
	}
	while (index - 1 != 0) {
		current = current->next;
		index--;
	}
	Provider * temp = current->next;
	current->next = current->next->next;
	Provider_freeStructure(&temp);
}


void Provider_freeStructure(Provider ** self) {
	Owner_freeStructure(&(*self)->owner);
	free(*self);
	*self = NULL;
}

void Provider_addLast(Provider ** self, Provider * node) {
	if (*self == NULL) {
		*self = node;
		return;
	}
	Provider * current = *self;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = node;
	node->next = NULL;
}

char * Provider_getProvName(Provider * self) {
	return self->provName;
}

int * Provider_getYear(Provider * self) {
	return &(self->year);
}

long double * Provider_getAnnualProfit(Provider * self) {
	return &(self->annualProfit);
}

char * Provider_getOwnerName(Provider * self) {
	return self->owner->ownerName;
}

char * Provider_getOwnerSurname(Provider * self) {
	return self->owner->ownerSurname;
}

int * Provider_getAge(Provider * self) {
	return &(self->owner->age);
}

void Provider_insert(Provider ** self, Provider * node, int index) {
	if (index > Provider_countList(*self) || index < 0) {
		return ;
	}else if (*self == NULL) {
		*self = node;
		return;
	}else if (index == 0) {
		node->next = *self;
		*self = node;
		return;
	}

	Provider * current = *self;
	while (index - 1 != 0) {
		current = current->next;
		index--;
	}
	node->next = current->next;
	current->next = node;
}




Owner * Owner_newStructure(char * ownerName, char * ownerSurname, int age) {
	Owner * owner = (Owner *)malloc(sizeof(Owner));
	strcpy(owner->ownerName, ownerName);
	strcpy(owner->ownerSurname, ownerSurname);
	owner->age = age;
	return owner;
}

void Owner_freeStructure(Owner ** self) {
	free(*self);
	*self = NULL;
}







