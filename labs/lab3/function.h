#ifndef FUNCTION_H
#define FUNCTION_H
#define STR_SIZE 100

struct Provider {
  char Name[STR_SIZE];
  int Year;
  int Speed;
  float MonthlyFee;
};

struct Provider * RewriteData(struct Provider * Users, int index);
struct Provider * DeleteStructure(struct Provider * Users, int * size , int index);
void PrintUsers(struct Provider * Users, int * size);
int GetStructuresFromConsole(struct Provider * users);
char * GetName(char string[]);
int GetYear(char string[]);
int GetSpeed(char string[]);
float GetMonthlyFee(char string[]);
int GetIndex(char string[]);
struct Provider * GetStructure(struct Provider * Users, int count, int entrance);
void PrintStructure(struct Provider * Users, int index, int x, int y);
void GetNhigherSpeed(struct Provider * Users, int number, int length);

#endif
