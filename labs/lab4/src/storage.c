#include <storage.h>
#include <convert.h>

void Storage_writeResult(const char * filename, Provider * result) {
	FILE * fin = fopen(filename, "w");
	if (fin == NULL) {
		puts("ERROR: CAN NOT OPEN FILE");
		return;
	}
	for (int i = 0; i < Provider_countList(result); ++i) {
		char buffer[STR_SIZE] = "";
		Convert_structureToString(buffer, Provider_getStructure(result, i));
		fprintf(fin, "%s\n", buffer);
	}
	fclose(fin);
}

Provider * Storage_readText(const char * filename) {
	FILE * fout = fopen(filename, "r");
	if (fout == NULL) {
		return NULL;
	}
	char buffer[STR_SIZE * STR_SIZE] = "";
	char * text = buffer;
	while (!feof(fout)) {
		fgets(text + strlen(text), STR_SIZE, fout);
		if (text[strlen(text) - 1] == '\n') text[strlen(text) - 1] = ' ';
	}
	if (text[strlen(text) - 1] == ' ') {
		text[strlen(text) - 1] = '\0';
	}
	fclose(fout);
	return Convert_stringToList(text);
}

bool isExistingFile(char * filename) {
	if (!correctFileName(filename)) return false;
	FILE * fin = fopen(filename, "r");
	if (fin == NULL) {
		return false;
	}
	fclose(fin);
	return true;
}

