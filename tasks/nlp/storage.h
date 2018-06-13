#ifndef NLP_STORAGE_H
#define NLP_STORAGE_H

#include "nlp.h"

Text * Storage_readText(const char * filepath);
void Storage_writeResult(const char * filepath, Text * result);

#endif