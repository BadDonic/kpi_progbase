#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char GetLastCharacter(char buff ,const char * str);

int main(void) {
  char str[500] = "";
  char chr = '\0';
  puts("Enter some string!");
  scanf("%s", str);
  printf("You've entered: %s\n", str);

  chr = GetLastCharacter('0',str);
  printf("Task: Output the character which following after the last character '@'\nThis character -> %c\n", chr);
  return 0;
}

char GetLastCharacter(char buff ,const char * str) {
  char FirstChar = str[0];
  if ('\0' != FirstChar) {
    if ('@' == FirstChar && str[1] != '\0' && str[1] != '@') {
      buff = str[1];
    }
    return GetLastCharacter(buff, str + 1);
  }
  return buff;
}
