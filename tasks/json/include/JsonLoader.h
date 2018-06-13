#ifndef JSON_JSONLOADER_H
#define JSON_JSONLOADER_H

#include <list.h>
#include <jansson.h>

void JsonLoader_saveToString(char * str, const TaxiDriver * entity);
void JsonLoader_loadFromString(TaxiDriver * entity, const char * jsonString);

#endif //JSON_JSONLOADER_H
