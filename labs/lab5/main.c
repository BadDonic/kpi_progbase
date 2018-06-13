#include <cui.h>
#include <convert.h>
#include <storage.h>
#include <test.h>

void getCorrectInputData(char * result, char * message, int row, int col, int attr, bool (*correctData)(char *));
void getCorrectIndex(char * result, char * message, int row, int col, int attr, int max);




int main(void) {
	test();
	char button = '\0';
	char * message[STRUCTURE_SIZE] = {
			"Provider's Name : ",
			"Year of birth: ",
			"Annual Profit(UAH) : ",
			"Owner's Name : ",
			"Owner's Surname : ",
			"Owner's Age : ",
	};
	bool (*correctData[STRUCTURE_SIZE])(char *) = {
			correctName,
			correctYear,
			correctAnnualProfit,
			correctName,
			correctName,
			correctAge,
	};
	while (button != 'q') {
		Cui_showMainMenu();
		button = conGetChar();
		switch (button) {
			case '1' : {
				int countProviders = 0;
				char string[STR_SIZE * STR_SIZE] = "";
				while (strchr("23", button) == NULL) {
					button = '0';
					countProviders++;
					Cui_showCreationMenu(countProviders);
					for (int i = 0; i < STRUCTURE_SIZE; ++i) {
						getCorrectInputData(string, message[i], 7 + 3 * i, 36, FG_GREEN, correctData[i]);
						strcat(string, " ");
					}
					string[strlen(string) - 1] = '\0';

					while (strchr("123", button) == NULL) {
						Cui_showChoiceMenu();
						button = conGetChar();
					}
				}
				if (button == '3') {
					break;
				}
				Provider * result = Convert_stringToList(string);

				char filename[STR_SIZE] = "";
				getCorrectInputData(filename, "Input FILENAME: ", 25, 31, FG_DEFAULT, correctFileName);
				if (strstr(filename, ".txt") != NULL) Storage_writeResult(filename, result);
				if (strstr(filename, ".xml") != NULL) Storage_writeAsXml(filename, result);
				if (strstr(filename, ".json") != NULL) Storage_writeAsJson(filename, result);
				Provider_freeList(&result);
				break;
			}
			case '2' : {
				char filename[STR_SIZE] = "";
				getCorrectInputData(filename, "Input FILENAME: ", 20, 35, FG_DEFAULT, isExistingFile);
				Provider * list = NULL;
				if (strstr(filename, ".txt") != NULL) list = Storage_readText(filename);
				if (strstr(filename, ".xml") != NULL) list = Storage_readAsXml(filename);
				if (strstr(filename, ".json") != NULL) list = Storage_readAsJson(filename);
				while (button != 'r') {
					Cui_showEditMenu();
					Cui_printList(list);
					button = conGetChar();
					switch (button) {
						case '1': {
							char index[STR_SIZE] = "";
							getCorrectIndex(index, "Provider № ", 9, 75, FG_YELLOW, Provider_countList(list));
							if (!strcmp(index, "")) {
								break;
							}
							Provider_deleteStructure(&list, atoi(index));
							break;
						}
						case '2': {
							char indexProvider[STR_SIZE] = "";
							getCorrectIndex(indexProvider, "Provider № ", 15, 75, FG_YELLOW, Provider_countList(list));
							if (!strcmp(indexProvider, "")) {
								break;
							}
							char indexField[STR_SIZE] = "";
							getCorrectIndex(indexField, "Field № ", 15, 75, FG_YELLOW, 7);

							if (!strcmp(indexField, "")) {
								strcpy(indexField, "012345");
							}
							for (int i = 0; i < strlen(indexField); ++i) {
								int index = indexField[i] - 48;
								char result[STR_SIZE] = "";
								getCorrectInputData(result, message[index], 15, 60, FG_YELLOW, correctData[index]);
								Cui_clearField(15, 15, 60 ,MAX_COL);
								Convert_changeFieldInList(list, atoi(indexProvider), index, result);
							}
							break;
						}
						case '3': {
							char index[STR_SIZE] = "";
							getCorrectIndex(index, "Position № ", 21, 75, FG_YELLOW, Provider_countList(list) + 1);
							if (!strcmp(index, "")) {
								break;
							}
							Cui_showCreationMenu(atoi(index));
							char string[STR_SIZE] = "";
							for (int i = 0; i < STRUCTURE_SIZE; ++i) {
								getCorrectInputData(string, message[i], 7 + 3 * i, 36, FG_GREEN, correctData[i]);
								strcat(string, " ");
							}
							string[strlen(string) - 1] = '\0';
							Provider * newNode = Convert_stringToList(string);
							Provider_insert(&list, newNode, atoi(index));
							break;
						}
						case '4': {
							char index[STR_SIZE] = "";
							getCorrectIndex(index, "N = ", 27, 75, FG_YELLOW, Provider_countList(list) + 1);
							if (!strcmp(index, "")) {
								break;
							}
							Provider * sortList = Convert_GetNHigherAnnualProfit(list, atoi(index));
							Cui_clearField(3, MAX_ROW, MIN_COL, MAX_COL);
							Cui_printList(sortList);
							conGetChar();
							Provider_freeList(&sortList);
							break;
						}
						case 's': {
							char newFilename[STR_SIZE] = "";
							getCorrectInputData(newFilename, "Input FILENAME: ", 33, 75, FG_YELLOW, correctFileName);
							if (strstr(newFilename, ".txt") != NULL) Storage_writeResult(newFilename, list);
							if (strstr(newFilename, ".xml") != NULL) Storage_writeAsXml(newFilename, list);
							if (strstr(newFilename, ".json") != NULL) Storage_writeAsJson(newFilename, list);							button = 'r';
							break;
						}
						default: {
							break;
						};
					}
				}
				Provider_freeList(&list);
				break;
			}
			default: {
				break;
			}
		}
	}
	return EXIT_SUCCESS;
}

void getCorrectInputData(char * result, char * message, int row, int col, int attr, bool (*correctData)(char *)) {
	conShowCursor();
	char buffer[STR_SIZE] = "";
	Cui_standOut(message, row, col, attr);
	fgets(buffer, STR_SIZE, stdin);
	buffer[strlen(buffer) - 1] = '\0';
	while (correctData != NULL && !correctData(buffer)) {
		buffer[0] = '\0';
		Cui_clearField(row, row, col, MAX_COL);
		Cui_standOut(message, row, col, FG_RED);
		fgets(buffer, STR_SIZE, stdin);
		buffer[strlen(buffer) - 1] = '\0';
	}
	Cui_standOut(message, row, col, attr);
	strcat(result, buffer);
	conHideCursor();
}

void getCorrectIndex(char *result, char *message, int row, int col, int attr, int max) {
	conShowCursor();
	char buffer[STR_SIZE] = "";
	Cui_standOut(message, row, col, attr);
	fgets(buffer, STR_SIZE, stdin);
	buffer[strlen(buffer) - 1] = '\0';
	while (!correctIndex(buffer, max)) {
		buffer[0] = '\0';
		Cui_clearField(row, row, col, MAX_COL);
		Cui_standOut(message, row, col, FG_RED);
		fgets(buffer, STR_SIZE, stdin);
		buffer[strlen(buffer) - 1] = '\0';
	}
	Cui_clearField(row, row, col, MAX_COL);
	strcat(result, buffer);
	conHideCursor();
}

