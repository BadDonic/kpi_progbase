#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
  char * InputStr = NULL;
  int * pi = NULL;

  InputStr = (char *)malloc(100 * sizeof(char));
  pi = (int  *) malloc(sizeof(int));
  if (NULL == InputStr || NULL == pi) {
    puts("Allocate Error");
    return 1;
  }

  printf("Please, input string: ");
  fgets(InputStr, 100, stdin);
  *(InputStr + strlen(InputStr) - 1) = '\0';
  for (*pi = strlen(InputStr) - 1; *pi >= 0; (*pi)--) {
    if (isdigit(*(InputStr + *pi))) {
      printf("%c\n", *(InputStr + *pi));
      return 0;
    }
  }
  printf("0\n");
  free(pi);
  free(InputStr);
  return 0;
}
