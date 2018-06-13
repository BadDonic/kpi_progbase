#ifndef LAB4_CUI_H
#define LAB4_CUI_H

#include <pbconsole.h>
#include <string.h>
#include <list.h>

enum {MAX_ROW = 38, MAX_COL = 99, MIN_ROW = 2, MIN_COL = 2};

void Cui_showMainMenu(void);
void Cui_showCreationMenu(int countProviders);
void Cui_showChoiceMenu(void);
void Cui_showEditMenu();
void Cui_printList(Provider * self);

void Cui_standOut(char *str, int x, int y, int attr);
void Cui_clearField(int startRow, int finishRow, int startCol, int finishCol);

#endif //LAB4_CUI_H
