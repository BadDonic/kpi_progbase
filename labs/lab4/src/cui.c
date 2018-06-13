#include <cui.h>

static void line(int x) {
    int i = 0;
    conMove(x,2);
    conSetAttr(FG_GREEN);
    for (i = 2; i <= 99; i++) {
        printf("=");
    }
    conSetAttr(FG_DEFAULT);
    printf("\n");
}

static void parallel_Lines(void) {
    conSetAttr(FG_GREEN);
    for (int i = 2; i <= MAX_ROW; i++) {
        conMove(i, 1);
        printf("|");
        conMove(i,MAX_COL + 1);
        printf("|");
    }
    conSetAttr(FG_DEFAULT);
}

void Cui_standOut(char *str, int x, int y, int attr) {
	conMove(x,y);
	conSetAttr(attr);
	printf("%s", str);
	conSetAttr(FG_DEFAULT);
}

void Cui_clearField(int startRow, int finishRow, int startCol, int finishCol) {
	for (int j = startRow; j <= finishRow; j++) {
		for (int i = startCol; i <= finishCol; i++) {
			conMove(j, i);
			printf(" ");
		}
	}
}

void Cui_showMainMenu(void) {
    conHideCursor();
    conResize(MAX_ROW + 2, MAX_COL + 1);
    conClear();
    parallel_Lines();
    line(1);
	Cui_standOut("Main", 2, 48, FG_INTENSITY_CYAN);
    line(3);
	Cui_standOut("1) Create a new data set", 10, 37, FG_INTENSITY_YELLOW);
    line(18);
    line(22);
	Cui_standOut("2) Read array of data from file", 30, 34, FG_INTENSITY_YELLOW);
    line(39);
}

void Cui_showCreationMenu(int countProviders) {
	conShowCursor();
	Cui_clearField(MIN_ROW, MAX_ROW, MIN_COL, MAX_COL);
	Cui_standOut("Creation Menu", 2, 50 - (int) strlen("Creation Menu") / 2, FG_INTENSITY_CYAN);
	line(3);
	conMove(5,45);
	printf("Provider №%i", countProviders);
	line(27);
	Cui_standOut("Provider's Name, Owner's Name, Owner's Surname - 0nly the alphabetic characters", 30, 12, FG_YELLOW);
	Cui_standOut("Year of birth - within [1800 - 2017]", 32, 12, FG_YELLOW);
	Cui_standOut("Annual Profit(UAH) - Only positive float numbers", 34, 12, FG_YELLOW);
	Cui_standOut("Owner's Age - within [1 - 147]", 36, 12, FG_YELLOW);
	Cui_standOut("Provider's Name :", 7, 36, FG_GREEN);
	Cui_standOut("Year of birth:", 10, 36, FG_GREEN);
	Cui_standOut("Annual Profit(UAH) :", 13, 36, FG_GREEN);
	Cui_standOut("Owner's Name :", 16, 36, FG_GREEN);
	Cui_standOut("Owner's Surname :", 19, 36, FG_GREEN);
	Cui_standOut("Owner's Age :", 22, 36, FG_GREEN);
	conSetAttr(FG_DEFAULT);
}

void Cui_showChoiceMenu(void) {
	Cui_clearField(4, MAX_ROW, MIN_COL, MAX_COL);
	conHideCursor();
	Cui_standOut("1) Add New Provider", 10, 27, FG_INTENSITY_YELLOW);
	Cui_standOut("2) Return to Main menu and save Providers in file ", 20, 27, FG_INTENSITY_YELLOW);
	Cui_standOut("3) Return to Main menu without saving", 30, 27, FG_INTENSITY_YELLOW);
}

void Cui_showEditMenu() {
	Cui_clearField(MIN_ROW, MAX_ROW, MIN_COL, MAX_COL);
	Cui_standOut("Edit Menu", 2, 50 - (int) strlen("Edit Menu") / 2, FG_INTENSITY_CYAN);
	line(3);
	Cui_standOut("'1' Delete specified Provider", 6, 60, FG_YELLOW);
	Cui_standOut("'2' Rewrite data in specified position", 12, 60, FG_YELLOW);
	Cui_standOut("'3' Add new Provider", 18, 60, FG_YELLOW);
	Cui_standOut("'4' Find 'N' Prov with best AnnuProfit", 24, 60, FG_YELLOW);
	Cui_standOut("'s' Save changes and return to Main", 30, 60, FG_YELLOW);
	Cui_standOut("'r' Return to Main without saving", 36, 60, FG_YELLOW);
	conSetAttr(FG_GREEN);
	for (int i = 0; i < 35; i++) {
		conMove(4 + i,58);
		printf("|");
	}
	conSetAttr(FG_DEFAULT);
}

void Cui_printList(Provider * self) {
	Cui_standOut("№ | 0)ProvName 1)Year 2)Profit 3)Name 4)Surname 5)Age", 5, 3, FG_DEFAULT);
	conSetAttr(FG_CYAN);
	for (int i = 0; i < Provider_countList(self); ++i) {
		conMove(7 + 2 * i, 3);
		Provider * current = Provider_getStructure(self, i);
		char result[STR_SIZE];
		printf("%i | %s", i, Convert_structureToString(result, current));
	}
	conSetAttr(FG_DEFAULT);
}


