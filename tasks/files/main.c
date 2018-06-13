#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

enum { BUFFER_SIZE = 100 };

int file_process(const char * readFileName, const char * writeFileName);

int main() {
  return file_process("text.txt", "out.txt");
}

int file_process(const char * readFileName, const char * writeFileName) {
  FILE * fin = fopen(readFileName, "r");
  FILE * fout = fopen(writeFileName, "w");
  char buffer[BUFFER_SIZE] = "";
  int i = 0;
  if (NULL == fin || NULL == fout) {
    puts("Error openning File");
    return 1;
  }

  while (!feof(fin)) {
    fgets(buffer, BUFFER_SIZE, fin);
    buffer[strlen(buffer) - 1] = '\0';
    if (isdigit(buffer[0]) || ('-' == buffer[0] && isdigit(buffer[1]))) {
      for (i = 1; i < strlen(buffer); i++) {
        if (isspace(buffer[i])) {
          fprintf(fout, "%s\n", buffer);
          break;
        }
      }
    }
  }
  fprintf(fout, "\n");
  fclose(fin);
  fclose(fout);
  return 0;
}
