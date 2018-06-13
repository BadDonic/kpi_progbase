#include <stdlib.h>
#include <stdio.h>
#include <pbconsole.h>

void line(int x) {
    int i = 0;
    conMove(x,2);
    conSetAttr(FG_GREEN);
    for (i = 2; i <= 99; i++) {
        printf("=");
    }
    conSetAttr(FG_DEFAULT);
    printf("\n");
}

void clear_line(int line, int numbers) {
    int i = 0;

    for (int j = 0; j < numbers; j++) {
        for (i = 2; i <= 99; i++) {
            conMove(line + j,i);
            printf(" ");
        }
    }
}

void clear_field(int x, int startY, int numbers) {
  for (int i = 0; i < numbers; i++) {
  conMove(x, startY + i);
  printf(" ");
  }
}

void parallel_Lines(void) {
  conSetAttr(FG_GREEN);
  for (int i = 0; i < 37; i++) {
      conMove(2 + i, 1);
      printf("|");
      conMove(2 + i,100);
      printf("|");
  }
  conSetAttr(FG_DEFAULT);
}

void stand_out(char str[],int x, int y, int attr) {
    conMove(x,y);
    conSetAttr(attr);
    printf("%s", str);
    conSetAttr(FG_DEFAULT);
}
