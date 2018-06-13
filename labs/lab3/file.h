#ifndef FILE_H
#define FILE_H

struct Provider * GetStructuresFromFile(FILE * fileflow, struct Provider * Users, int * size);
void RecordStructure(FILE * fileflow, struct Provider * users, int * size);

#endif
