#ifndef LAB4_STORAGE_H
#define LAB4_STORAGE_H


#include <list.h>
#include <stdbool.h>

void Storage_writeResult(const char * filename, Provider * result);
Provider * Storage_readText(const char * filename);

bool isExistingFile(char * filename);

#endif //LAB4_STORAGE_H
