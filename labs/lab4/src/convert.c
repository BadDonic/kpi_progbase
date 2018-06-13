#include <convert.h>

Provider * Convert_GetNHigherAnnualProfit(Provider *self, int N_number) {
	char string[STR_SIZE * STR_SIZE] = "";
	for (int i = 0; i < Provider_countList(self); ++i) {
		char buffer[STR_SIZE] = "";
		strcat(string, Convert_structureToString(buffer, Provider_getStructure(self, i)));
		strcat(string, " ");
	}
	string[strlen(string) - 1] = '\0';
	Provider * list = Convert_stringToList(string);
	int size = Provider_countList(list);
	for (int i = 0; i < size - N_number; ++i) {
		int indexMin = 0;
		for (int j = 0; j < Provider_countList(list); ++j) {
			if (*Provider_getAnnualProfit(Provider_getStructure(list, indexMin)) > *Provider_getAnnualProfit(Provider_getStructure(list, j))) {
				indexMin = j;
			}
		}
		Provider_deleteStructure(&list, indexMin);
	}
	return list;
}

void Convert_changeFieldInList(Provider *self, int indexProvider, int indexField, char *data) {
	Provider * current = Provider_getStructure(self, indexProvider);
	if (indexField == 0) strcpy(Provider_getProvName(current), data);
	if (indexField == 1) *Provider_getYear(current) = atoi(data);
	if (indexField == 2) *Provider_getAnnualProfit(current) = atof(data);
	if (indexField == 3) strcpy(Provider_getOwnerName(current), data);
	if (indexField == 4) strcpy(Provider_getOwnerSurname(current),data);
	if (indexField == 5) *Provider_getAge(current) = atoi(data);
}


Provider * Convert_stringToList(char *string) {
	char provName[STR_SIZE];
	int year;
	long double annualProfit;
	char ownerName[STR_SIZE];
	char ownerSurname[STR_SIZE];
	int age;
	Provider * list = NULL;
	for (int i = 0; string != NULL; ++i) {
		sscanf(string, "%s %i %Lf %s %s %i", provName, &year, &annualProfit, ownerName, ownerSurname, &age);
		Provider_addLast(&list, Provider_newStructure(provName, year, annualProfit, ownerName, ownerSurname, age));
		for (int j = 0; j < 6; ++j) {
			if (strchr(string, ' ') == NULL) {
				string = NULL;
				break;
			}
			string = strchr(string, ' ') + 1;
		}
	}
	return list;
}

char * Convert_structureToString(char *result, Provider *self) {
	if (self == NULL) {
		strcpy(result, "");
		return result;
	}
	char provName[STR_SIZE] = "";
	strcpy(provName, Provider_getProvName(self));
	int year = *Provider_getYear(self);
	long double annualProfit = *Provider_getAnnualProfit(self);
	char ownerName[STR_SIZE] = "";
	strcpy(ownerName, Provider_getOwnerName(self));
	char ownerSurname[STR_SIZE] = "";
	strcpy(ownerSurname, Provider_getOwnerSurname(self));
	int age = *Provider_getAge(self);
	sprintf(result,"%s %i %Lg %s %s %i", provName, year, annualProfit, ownerName, ownerSurname, age);
	return result;
}

bool correctName(char * string) {
	if (!strcmp(string, "")) return false;
	if (!isupper(string[0])) return false;
	for (int i = 1; i < strlen(string); i++) {
		if (!isalpha(string[i])) return false;
	}
	return true;
}

bool correctYear(char * string) {
	if (!strcmp(string, "")) return false;
	for (int i = 0; i < strlen(string); i++) {
		if (!isdigit(string[i])) return false;
	}
	int year = atoi(string);
	if (year > 2017 || year <= 1800) return false;
	return true;
}

bool correctAnnualProfit(char *string) {
	if (!strcmp(string, "")) return false;
	for (int i = 0; i < strlen(string); i++) {
		if (!isdigit(string[i]) && !(string[i] == '.' && i != 0 && i != strlen(string) - 1 && strlen(string) - i <= 3)) return false;
	}
	return true;
}

bool correctAge(char * string) {
	if (!strcmp(string, "")) return false;
	for (int i = 0; i < strlen(string); i++) {
		if (!isdigit(string[i])) return false;
	}
	int age = atoi(string);
	if (age > 147 || age < 1) return false;
	return true;
}

bool correctIndex(char * string, int maxIndex) {
	if (!strcmp(string, "")) return true;
	for (int i = 0; i < strlen(string); ++i) {
		if (!isdigit(string[i]))return false;
	}
	if (atoi(string) >= maxIndex) return false;
	return true;
}

bool correctFileName(char * string) {
	if (!strcmp(string, "")) return false;
	if (strstr(string, ".txt") == NULL && strstr(string, ".txt") + 4 != '\0') return false;
	for (int i = 0; i < strlen(string) - 4 ; i++) {
		if (!isalpha(string[i]) && !isdigit(string[i])) return false;
	}
	return true;
}
