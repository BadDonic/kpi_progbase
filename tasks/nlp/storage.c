#include <stdio.h>
#include <string.h>
#include "storage.h"

Text * Storage_readText(const char * filepath) {
    FILE * fin = fopen(filepath, "r");
    if (NULL == fin) {
        puts("ERROR: OPEN FILE\n");
        return NULL;
    }

    char text[STR_SIZE] = "";

    while (!feof(fin)) {
        fgets(text + strlen(text), STR_SIZE, fin);
    }
    Text * result = Text_new(text);
	fclose(fin);
    return result;
}

void Storage_writeResult(const char * filepath, Text * result) {
	FILE * fout = fopen(filepath, "w");
	if (NULL == fout) {
		puts("ERROR: OPEN FILE\n");
		return ;
	}
	for (int i = 0; i < Text_countSentence(result); ++i) {
		Sentence * curSentence = Text_getSentence(result,i);
		for (int j = 0; j < Sentence_countWord(curSentence); ++j) {
			Word * curWord = Sentence_getWord(curSentence, j);
			char buffer[100] = "";
			fprintf(fout, "%s, ", Word_getString(curWord, buffer));
		}
		fputs("\n", fout);
	}
	fclose(fout);
}


