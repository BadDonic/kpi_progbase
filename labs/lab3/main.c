#include <stdio.h>
#include <stdlib.h>
#include <progbase.h>
#include <pbconsole.h>
#include <string.h>
#include <ctype.h>
#include "file.h"
#include "function.h"
#include "menu.h"
#include "assert.h"
#define STR_SIZE 100
//gcc main.c menu.c function.c file.c assert.c -std=c99 -Wall -Werror -pedantic-errors -lm -lprogbase

int main(int argc, char const *argv[]) {

  if ( argc == 2 && !strcmp(argv[1], "test") ) {
    test();
  }

  conHideCursor();
  conResize(40,100);
  char n = '\0';
  while (n != 'q') {
    conHideCursor();
    conResize(40,100);
    conClear();
    parallel_Lines();
    line(1);
    stand_out("Main",2, 48, FG_INTENSITY_CYAN);
    line(3);
    stand_out("1) Create a new data set", 10, 37, FG_INTENSITY_YELLOW);
    line(18);
    line(22);
    stand_out("2) Read array of data from file", 30, 34, FG_INTENSITY_YELLOW);
    line(39);
    n = conGetChar();

    switch (n) {
      case '1': {
        stand_out("Input the name of Internet Service Provider: ", 20, 4, FG_DEFAULT);
        conShowCursor();

        char filename[STR_SIZE] = "";
        fgets(filename, STR_SIZE, stdin);
        filename[strlen(filename) - 1] = '\0';
        clear_line(20, 1);
        FILE * file = fopen(filename, "a");
        if (NULL == file) {
          conHideCursor();
          stand_out("!!!ERROR OPENNING FILE!!!", 19, 37, FG_INTENSITY_RED);
          stand_out("Enter some button to exit from programm", 21, 30, FG_INTENSITY_RED);
          conGetChar();
          conClear();
          return EXIT_FAILURE;
        }

        struct Provider * users = (struct Provider *)malloc(sizeof(struct Provider));
        if (NULL == users) {
          stand_out("!!!ERROR TO CREATE NEW STRUCTURE!!!", 19, 37, FG_INTENSITY_RED);
          stand_out("Enter some button to exit from programm", 21, 30, FG_INTENSITY_RED);
          n = conGetChar();
          conClear();
          return EXIT_FAILURE;
        }
        clear_line(2, 1);
        stand_out(filename, 2, 50 - strlen(filename) / 2, FG_INTENSITY_CYAN);
        clear_line(4, 34);
        int NumberOfUsers = GetStructuresFromConsole(users);

        if (NumberOfUsers != 0) {
          RecordStructure(file, users, &NumberOfUsers);
        }

        free(users);
        fclose(file);
        break;
      }
      case '2': {
        int check = -2;

        struct Provider * Users = (struct Provider *)malloc(1 * sizeof(struct Provider));
        if (NULL == Users) {
          stand_out("!!!ERROR TO CREATE NEW STRUCTURE!!!", 19, 37, FG_INTENSITY_RED);
          stand_out("Enter some button to exit from programm", 21, 30, FG_INTENSITY_RED);
          n = conGetChar();
          conClear();
          return EXIT_FAILURE;
        }
        char filename[STR_SIZE] = "\0";

        while (check == 0 || check == -2) {

          if (check == -2) {
            stand_out("Input the name of Internet Service Provider: ", 20, 4, FG_DEFAULT);
          }else {
            stand_out("Input the name of Internet Service Provider: ", 20, 4, FG_INTENSITY_RED);
          }

          conShowCursor();
          fgets(filename, STR_SIZE, stdin);
          filename[strlen(filename) - 1] = '\0';
          clear_line(20, 1);
          FILE * file = fopen(filename, "r");
          if (NULL == file) {
            conHideCursor();
            stand_out("!!!ERROR OPENNING FILE!!!", 19, 37, FG_INTENSITY_RED);
            stand_out("Enter some button to exit from programm", 21, 30, FG_INTENSITY_RED);
            n = conGetChar();
            conClear();
            return EXIT_FAILURE;
          }

          Users = GetStructuresFromFile(file, Users, &check);
          clear_line(20, 1);
          fclose(file);
        }
        stand_out(filename, 2, 50 - strlen(filename) / 2, FG_INTENSITY_CYAN);
        n = '\0';
        int eror = 0;

        while (n != 'r') {
          clear_line(4, 32);
          PrintUsers(Users, &check);
          stand_out("'1' Delete specified User", 7, 66, FG_YELLOW);
          stand_out("'2' Rewrite data in specified position", 13, 59, FG_YELLOW);
          stand_out("'3' Rewrite specified User", 19, 65, FG_YELLOW);
          stand_out("'4' Find 'N' users with the best Speed ", 25, 59, FG_YELLOW);
          stand_out("'s' Save changes", 31, 71, FG_YELLOW);
          stand_out("'r' Return to Main Menu", 37, 67, FG_YELLOW);
          conHideCursor();
          n = conGetChar();
          switch (n) {
            case '1': {
              int index = -1;

              while( index == 0 || index == -1) {
                clear_field(10, 69, 30);
                if (index == -1) {
                  stand_out("User :", 10, 72, FG_GREEN);
                }else {
                  stand_out("User :", 10, 72, FG_INTENSITY_RED);
                }
                if (eror == 0) {
                  char buffer[STR_SIZE] = "\0";
                  fgets(buffer, STR_SIZE, stdin);
                  eror = 1;
                }
                char buffer[STR_SIZE] = "\0";
                conMove(10, 80);
                fgets(buffer, STR_SIZE, stdin);
                buffer[strlen(buffer) - 1] = '\0';
                index = GetIndex(buffer);
                if (index > check) {
                  index = 0;
                }
              }
              Users = DeleteStructure(Users, &check, index);
              break;
            }
            case '2': {
              int index = -1;
              while( index == 0 || index == -1) {
                clear_field(16, 57, 42);
                if (index == -1) {
                  stand_out("Index :", 16, 72, FG_GREEN);
                }else {
                  stand_out("Index :", 16, 72, FG_INTENSITY_RED);
                }
                if (eror == 0) {
                  char buffer[STR_SIZE] = "\0";
                  fgets(buffer, STR_SIZE, stdin);
                  eror = 1;
                }
                char buffer[STR_SIZE] = "\0";
                conMove(16, 80);
                fgets(buffer, STR_SIZE, stdin);
                buffer[strlen(buffer) - 1] = '\0';
                index = GetIndex(buffer);
                if (index > check * 4) {
                  index = 0;
                }
              }
              Users = RewriteData(Users, index);
              break;
            }
            case '3': {
              int index = -1;

              while( index == 0 || index == -1) {
                clear_field(10, 69, 30);
                if (index == -1) {
                  stand_out("User :", 22, 72, FG_GREEN);
                }else {
                  stand_out("User :", 22, 72, FG_INTENSITY_RED);
                }
                if (eror == 0) {
                  char buffer[STR_SIZE] = "\0";
                  fgets(buffer, STR_SIZE, stdin);
                  eror = 1;
                }
                char buffer[STR_SIZE] = "\0";
                conMove(22, 80);
                fgets(buffer, STR_SIZE, stdin);
                buffer[strlen(buffer) - 1] = '\0';
                index = GetIndex(buffer);
                if (index > check) {
                  index = 0;
                }
              }
              Users = GetStructure(Users, index, 1);
              break;
            }
            case '4': {
              int number = -1;
              while( number == 0 || number == -1) {
                clear_field(28, 57, 42);
                if (number == -1) {
                  stand_out("Number :", 28, 72, FG_GREEN);
                }else {
                  stand_out("Number :", 28, 72, FG_INTENSITY_RED);
                }
                if (eror == 0) {
                  char buffer[STR_SIZE] = "\0";
                  fgets(buffer, STR_SIZE, stdin);
                  eror = 1;
                }
                char buffer[STR_SIZE] = "\0";
                conMove(28, 81);
                fgets(buffer, STR_SIZE, stdin);
                buffer[strlen(buffer) - 1] = '\0';
                number = GetIndex(buffer);
                if (number > check ) {
                  number = 0;
                }
              }
              clear_line(4, 35);
              GetNhigherSpeed(Users, number, check);
              conGetChar();
              break;
            }
            case 's': {
              remove(filename);
              FILE * save = fopen(filename, "w");
              if (NULL == save) {
                conHideCursor();
                stand_out("!!!ERROR SAVING FILE!!!", 34, 74, FG_INTENSITY_RED);
                n = conGetChar();
                break;
              }else {
                stand_out("!!!SUCCESS!!!", 34, 74, FG_GREEN);
                RecordStructure(save, Users, &check);
                fclose(save);
                conGetChar();
                clear_line(34, 1);
              }
              break;
            }
            case 'q': {
              conClear();
              free(Users);
              return 0;
              break;
            }
          }
        }

        free(Users);
        break;
      }
      case 'q': {
        return EXIT_SUCCESS;
      }
    }
  }
}
