#ifndef XML_XMLLOADER_H
#define XML_XMLLOADER_H

#include <libxml/parser.h>
#include <libxml/tree.h>
#include <list.h>


void XmlLoader_saveToString(char * str, const TaxiDriver * entity);
void XmlLoader_loadFromString(TaxiDriver * entity, const char * xmlStr);

#endif //XML_XMLLOADER_H
