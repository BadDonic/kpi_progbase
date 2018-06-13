#include <stdlib.h>
#include <stdio.h>
#include "function.h"
#include <string.h>

struct Provider * GetStructuresFromFile(FILE * fileflow, struct Provider * Users, int * size) {
  int count = 0;
  while (!feof(fileflow)) {
    char buffer[STR_SIZE] = "\0";
    char Name[STR_SIZE] = "\0";
    char Year[STR_SIZE] = "\0";
    char Speed[STR_SIZE] = "\0";
    char MonthlyFee[STR_SIZE] = "\0";
    fscanf(fileflow, "%s %s %s %s", Name, Year, Speed, MonthlyFee);
    fgets(buffer, STR_SIZE, fileflow);
    if (strcmp(buffer, "")) {
      if(!strcmp("0", GetName(Name)) || GetYear(Year) == -1 || GetSpeed(Speed) == 0 || GetMonthlyFee(MonthlyFee) == 0.0) {
        *size = count;
        return 0;
      }else {
        count++;
        Users = (struct Provider *)realloc(Users, count * sizeof(struct Provider));
        strcpy(Users[count - 1].Name, Name);
        Users[count - 1].Year = GetYear(Year);
        Users[count - 1].Speed = GetSpeed(Speed);
        Users[count - 1].MonthlyFee = GetMonthlyFee(MonthlyFee);
      }
    }
  }
  *size = count;
  return Users;
}

void RecordStructure(FILE * fileflow, struct Provider * users, int * size) {
  for (int i = 0; i < *size; i++) {
    fprintf(fileflow, "%s %i %i %g\n", (users + i)->Name, (users + i)->Year, (users + i)->Speed, (users + i)->MonthlyFee);
  }
}
