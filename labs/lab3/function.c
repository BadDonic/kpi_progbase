#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#include <pbconsole.h>
#include "menu.h"
#include <ctype.h>
#include <string.h>

int GetStructuresFromConsole(struct Provider * users) {
  int count = 1;
  char n = 0;
  char space = 0;
  while (n != '2' && n != '3') {
    users = (struct Provider *)realloc(users, (size_t)count * sizeof(struct Provider));
    GetStructure(users, count, space);
    space = 1;
    clear_line(4, 34);
    stand_out("1) Add New User", 10, 27, FG_INTENSITY_YELLOW);
    stand_out("2) Return to Main menu and save Users in file ", 20, 27, FG_INTENSITY_YELLOW);
    stand_out("3) Return to Main menu without saving", 30, 27, FG_INTENSITY_YELLOW);
    n = conGetChar();
    count++;
    if (n == '3') {
      count = 0;
    }else if (n == '2') {
      count--;
    }
  }
  return count;
}

char * GetName(char string[]) {
  char * str = NULL;
  str = string;
  if (!strcmp(string, "")) {
    str = "0";
    return str;
  }
  for (int i = 0; *(str + i) != '\0'; i++) {
    if (!isalpha(*(str + i))) {
      str = "0";
      return str;
    }
  }
  return str;
}

int GetYear(char string[]) {
  int Year = 0;
  int i = 0;
  if (!strcmp(string, "")) {
    return 0;
  }
  while (string[i] != '\0') {
    if (!isdigit(string[i])) {
      return -1;
    }
    i++;
  }
  Year = atoi(string);
  if (Year > 2017 || Year <= 1900) {
    return -1;
  }
  return Year;
}

int GetSpeed(char string[]) {
  int Speed = 0;
  int i = 0;
  int Mb[14] = {1, 2, 4, 8, 16, 32, 50, 64, 80, 100, 128, 256, 512, 1000};
  while (string[i] != '\0') {
    if (!isdigit(string[i])) {
      return 0;
    }
    i++;
  }
  Speed = atoi(string);
  for (int i = 0; i < 14; i++) {
    if(Speed == Mb[i]) {
      return Speed;
    }
  }
  return 0;
}

int GetIndex(char string[]) {
  int index = 0;
  int i = 0;
  if (!strcmp(string, "")) {
    return 0;
  }
  while (string[i] != '\0') {
    if (!isdigit(string[i])) {
      return 0;
    }
    i++;
  }
  index = atoi(string);
  if (index <= 0) {
    return 0;
  }
  return index;
}

float GetMonthlyFee(char string[]) {
  int i = 0;
  float DoubNumber = 0.0;
  while (string[i] != '\0') {
    if (!isdigit(string[i]) && !(string[i] == '.' && i != 0 && i != strlen(string) && strlen(string) - i <= 3)) {
      return DoubNumber;
    }
    i++;
  }
  DoubNumber = atof(string);
  return DoubNumber;
}



void PrintUsers(struct Provider * Users, int * size) {
  int shiftX = 0;
  conSetAttr(FG_GREEN);
  for (int i = 2; i < 37; i++) {
      conMove(2 + i, 56);
      printf("|");
  }
  conSetAttr(FG_DEFAULT);
  for (int i = 0; i < *size; i += 2) {
    conMove(5 + shiftX, 10);
    printf("User №%i", i + 1);
    conMove(6 + shiftX, 3);
    printf("%i) Name: %s", i * 4 + 1, Users[i].Name);
    conMove(7 + shiftX, 3);
    if ( Users[i].Year != 0) {
      printf("%i) Year of birth: %i", i * 4 + 2, Users[i].Year);
    }else {
      printf("%i) Year of birth: ", i * 4 + 2);
    }
    conMove(8 + shiftX, 3);
    printf("%i) Speed: %i", i * 4 + 3, Users[i].Speed);
    conMove(9 + shiftX, 3);
    printf("%i) Monthly Fee: %g", i * 4 + 4, Users[i].MonthlyFee);
    shiftX += 6;
  }
  shiftX = 0;
  for (int i = 1; i < *size; i += 2) {
    conMove(5 + shiftX, 37);
    printf("User №%i", i + 1);
    conMove(6 + shiftX, 30);
    printf("%i) Name: %s", i * 4 + 1, Users[i].Name);
    conMove(7 + shiftX, 30);
    if ( Users[i].Year != 0) {
      printf("%i) Year of birth: %i", i * 4 + 2, Users[i].Year);
    }else {
      printf("%i) Year of birth: ", i * 4 + 2);
    }
    conMove(8 + shiftX, 30);
    printf("%i) Speed: %i", i * 4 + 3, Users[i].Speed);
    conMove(9 + shiftX, 30);
    printf("%i) Monthly Fee: %g", i * 4 + 4, Users[i].MonthlyFee);
    shiftX += 6;
  }
  return;
}

struct Provider * DeleteStructure(struct Provider * Users, int * size , int index) {
  for (int i = index - 1; i < *size - 1; i++) {
    strcpy(Users[i].Name, Users[i + 1].Name);
    Users[i].Year = Users[i + 1].Year;
    Users[i].Speed = Users[i + 1].Speed;
    Users[i].MonthlyFee = Users[i + 1].MonthlyFee;
  }

  *size = *size - 1;
  Users = (struct Provider *)realloc(Users, *size * sizeof(struct Provider));
  return Users;
}

struct Provider * RewriteData(struct Provider * Users, int index) {

  switch (index % 4) {
    case 0: {
      index /= 4;
      Users[index].MonthlyFee = -1;
      while(Users[index].MonthlyFee == 0.0 || Users[index].MonthlyFee == -1) {
        clear_field(16, 58, 42);
        if (Users[index].MonthlyFee == -1) {
          stand_out("Monthly fee(UAN) :", 16, 62, FG_GREEN);
        }else {
          stand_out("Monthly fee(UAN) :", 16, 62, FG_INTENSITY_RED);
        }
        char buffer[STR_SIZE] = "\0";
        conMove(16, 82);
        fgets(buffer, STR_SIZE, stdin);
        buffer[strlen(buffer) - 1] = '\0';
        Users[index].MonthlyFee = GetMonthlyFee(buffer);
      }
      break;
    }
    case 1: {
      index /= 4;
      strcpy(Users[index].Name, "-1");
      while( !strcmp(Users[index].Name, "0") || !strcmp(Users[index].Name, "-1")) {
        clear_field(16, 58, 42);
        if (!strcmp(Users[index].Name, "-1")) {
          stand_out("Names :", 16, 70, FG_GREEN);
        }else {
          stand_out("Names :", 16, 70, FG_INTENSITY_RED);
        }
        char buffer[STR_SIZE] = "\0";
        conMove(16, 79);
        fgets(buffer, STR_SIZE, stdin);
        buffer[strlen(buffer) - 1] = '\0';
        strcpy(Users[index].Name, GetName(buffer));
      }
      break;
    }
    case 2: {
      index /= 4;
      Users[index].Year = -2;
      while(Users[index].Year == -1 || Users[index].Year == -2) {
        clear_field(16, 58, 42);
        if (Users[index].Year == -2) {
          stand_out("Year of birth:", 16, 62, FG_GREEN);
        }else {
          stand_out("Year of birth:", 16, 62, FG_INTENSITY_RED);
        }
        char buffer[STR_SIZE] = "\0";
        conMove(16, 78);
        fgets(buffer, STR_SIZE, stdin);
        buffer[strlen(buffer) - 1] = '\0';
        Users[index].Year = GetYear(buffer);
      }
      break;
    }
    case 3: {
      index /= 4;
      Users[index].Speed = -1;
      while(Users[index].Speed == 0 || Users[index].Speed == -1) {
        clear_field(16, 58, 42);
        if (Users[index].Speed == -1) {
          stand_out("Speed(Mb/c) :",16, 65, FG_GREEN);
        }else {
          stand_out("Speed(Mb/c) :",16, 65, FG_INTENSITY_RED);
        }
        char buffer[STR_SIZE] = "\0";
        conMove(16, 80);
        fgets(buffer, STR_SIZE, stdin);
        buffer[strlen(buffer) - 1] = '\0';
        Users[index].Speed = GetSpeed(buffer);
      }
      break;
    }
  }
  return Users;
}

struct Provider * GetStructure(struct Provider * users, int count, int entrance) {
  clear_line(4,35);
  conShowCursor();
  conMove(6, 45);
  conSetAttr(FG_YELLOW);
  printf("User №%i", count);
  conSetAttr(FG_DEFAULT);
  line(24);
  stand_out(" - Fields which must be filled", 27, 12, FG_YELLOW);
  stand_out("*", 27, 12, FG_INTENSITY_RED);
  stand_out("Name - 0nly the alphabetic characters", 29, 12, FG_YELLOW);
  stand_out("Year of birth - within [1900 - 2016] or '0' If you want to leave it empty ", 31, 12, FG_YELLOW);
  stand_out("Speed(Mb/c) - Only {1, 2, 4, 8, 16, 32, 50, 64, 80, 100, 128, 256, 512, 1000}", 33, 12, FG_YELLOW);
  stand_out("MonthlyFee(UAH) - Only positive float numbers", 35, 12, FG_YELLOW);
  stand_out("Names  :", 8, 36, FG_GREEN);
  stand_out("*", 8, 41, FG_INTENSITY_RED);
  stand_out("Year of birth:", 12, 36, FG_GREEN);
  stand_out("Speed(Mb/c)  :",16, 36, FG_GREEN);
  stand_out("*", 16, 47, FG_INTENSITY_RED);
  stand_out("Monthly fee(UAH)  :", 20, 36, FG_GREEN);
  stand_out("*", 20, 52, FG_INTENSITY_RED);

  strcpy(users[count - 1].Name, "-1");
  while( !strcmp(users[count - 1].Name, "0") || !strcmp(users[count - 1].Name, "-1")) {
    clear_line(8,1);
    if (!strcmp(users[count - 1].Name, "-1")) {
      stand_out("Names  :", 8, 36, FG_GREEN);
    }else {
      stand_out("Names  :", 8, 36, FG_INTENSITY_RED);
    }
    
    stand_out("*", 8, 41, FG_INTENSITY_RED);
    char buffer[STR_SIZE] = "\0";
    conMove(8, 45);
    fgets(buffer, STR_SIZE, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    strcpy(users[count - 1].Name, GetName(buffer));
  }
  stand_out("Names  :", 8, 36, FG_GREEN);
  stand_out("*", 8, 41, FG_INTENSITY_RED);

  users[count - 1].Year = -2;
  while(users[count - 1].Year == -1 || users[count - 1].Year == -2) {
    clear_line(12,1);
    if (users[count - 1].Year == -2) {
      stand_out("Year of birth:", 12, 36, FG_GREEN);
    }else {
      stand_out("Year of birth:", 12, 36, FG_INTENSITY_RED);
    }
    char buffer[STR_SIZE] = "\0";
    conMove(12, 52);
    fgets(buffer, STR_SIZE, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    users[count - 1].Year = GetYear(buffer);
  }
  stand_out("Year of birth:", 12, 36, FG_GREEN);

  users[count - 1].Speed = -1;
  while(users[count - 1].Speed == 0 || users[count - 1].Speed == -1) {
    clear_line(16,1);
    if (users[count - 1].Speed == -1) {
      stand_out("Speed(Mb/c)  :",16, 36, FG_GREEN);
    }else {
      stand_out("Speed(Mb/c)  :",16, 36, FG_INTENSITY_RED);
    }
    stand_out("*", 16, 47, FG_INTENSITY_RED);
    char buffer[STR_SIZE] = "\0";
    conMove(16, 52);
    fgets(buffer, STR_SIZE, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    users[count - 1].Speed = GetSpeed(buffer);
  }
  stand_out("Speed(Mb/c)  :",16, 36, FG_GREEN);
  stand_out("*", 16, 47, FG_INTENSITY_RED);

  users[count - 1].MonthlyFee = -1;
  while(users[count - 1].MonthlyFee == 0.0 || users[count - 1].MonthlyFee == -1) {
    clear_line(20,1);
    if (users[count - 1].MonthlyFee == -1) {
      stand_out("Monthly fee(UAN)  :", 20, 36, FG_GREEN);
    }else {
      stand_out("Monthly fee(UAN)  :", 20, 36, FG_INTENSITY_RED);
    }
    stand_out("*", 20, 52, FG_INTENSITY_RED);
    char buffer[STR_SIZE] = "\0";
    conMove(20, 56);
    fgets(buffer, STR_SIZE, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    users[count - 1].MonthlyFee = GetMonthlyFee(buffer);
  }
  stand_out("Monthly fee(UAN)  :", 20, 36, FG_GREEN);
  stand_out("*", 20, 52, FG_INTENSITY_RED);
  conHideCursor();
  return users;
}

void PrintStructure(struct Provider * Users, int index, int x, int y) {
  conMove(x, y + 7);
  printf("User №%i", index + 1);
  conMove(x + 1, y);
  printf("%i)Name: %s", index * 4 + 1, Users[index].Name);
  conMove(x + 2, y);
  if ( Users[index].Year != 0) {
    printf("%i) Year of birth: %i", index * 4 + 2, Users[index].Year);
  }else {
    printf("%i) Year of birth: ", index * 4 + 2);
  }
  conMove(x + 3, y);
  printf("%i) Speed: %i", index * 4 + 3, Users[index].Speed);
  conMove(x + 4, y);
  printf("%i) Monthly Fee: %g", index * 4 + 4, Users[index].MonthlyFee);
  return;
}

void GetNhigherSpeed(struct Provider * Users, int number, int length) {
  int shiftX = 0;
  int shiftY = 0;
  int size = length;
  int temp[size];
  for (int i = 0; i < size; i++) {
    temp[i] = Users[i].Speed;
  }
  for (int i = 0; i < number; i++) {
    int posMax = 0;
    for (int j = 0; j < size; j++) {
      if(temp[j] > temp[posMax]) {
        posMax = j;
      }
    }
    temp[posMax] = -1;
    PrintStructure(Users, posMax, 5 + shiftX, 3 + shiftY);
    shiftY += 24;
    if (shiftY == 96) {
      shiftY = 0;
      shiftX += 6;
    }
  }
}
