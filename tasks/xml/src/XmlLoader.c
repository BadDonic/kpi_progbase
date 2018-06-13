#include <XmlLoader.h>

void XmlLoader_saveToString(char * str, const TaxiDriver * entity) {
	xmlDoc * doc = NULL;
	xmlNode * rootNode = NULL;
	xmlNode * driverNode = NULL;
	xmlNode * clientNode = NULL;
	int size = 3;
	char strBuf[STR_SIZE] = "";

	doc = xmlNewDoc(BAD_CAST "1.0");
	rootNode = xmlNewNode(NULL, BAD_CAST "drivers");
	xmlDocSetRootElement(doc,rootNode);
	while (entity != NULL) {
		driverNode = xmlNewChild(rootNode, NULL, BAD_CAST "driver", NULL);
		xmlNewProp(driverNode, BAD_CAST "name", BAD_CAST entity->name);
		sprintf(strBuf, "%i", entity->age);
		xmlNewChild(driverNode, NULL, BAD_CAST "age", BAD_CAST strBuf);
		sprintf(strBuf, "%g", entity->salary);
		xmlNewChild(driverNode, NULL, BAD_CAST "salary", BAD_CAST strBuf);

		for (int i = 0; i < size; i++) {
			clientNode = xmlNewChild(driverNode, NULL, BAD_CAST "client", NULL);
			xmlNewChild(clientNode, NULL, BAD_CAST "name", BAD_CAST entity->topClients[i].name);
			sprintf(strBuf, "%g", entity->topClients[i].pay);
			xmlNewChild(clientNode, NULL, BAD_CAST "pay", BAD_CAST strBuf);
		}
		entity = entity->next;
	}

	xmlBuffer * bufferPtr = xmlBufferCreate();
	xmlNodeDump(bufferPtr, NULL, (xmlNode *)doc, 0, 1);
	sprintf(str, "%s", (char *)bufferPtr->content);
	xmlBufferFree(bufferPtr);
	xmlFreeDoc(doc);
	xmlCleanupParser();

}

void XmlLoader_loadFromString(TaxiDriver * entity, const char * xmlStr) {
	xmlDoc * xDoc = xmlReadMemory(xmlStr, (int)strlen(xmlStr), NULL, NULL, 0);
	if (xDoc == NULL) {
		puts("ERR0R");
		return;
	}

	xmlNode * xRootEl = xmlDocGetRootElement(xDoc);
	for (xmlNode * xCur = xRootEl->children; xCur != NULL; xCur = xCur->next) {
		if (XML_ELEMENT_NODE == xCur->type) {
			char * driverName =  (char *)xmlGetProp(xCur, BAD_CAST "name");
			strcpy(entity->name, driverName);
			free(driverName);
			int i = 0;
			for (xmlNode * xJ = xCur->children; NULL != xJ ; xJ = xJ->next) {
				if (XML_ELEMENT_NODE == xJ->type) {
					char * content = (char *)xmlNodeGetContent(xJ);
					if (xmlStrcmp(xJ->name, BAD_CAST "age") == 0) {
						entity->age = atoi(content);
					}else if (xmlStrcmp(xJ->name, BAD_CAST "salary") == 0) {
						entity->salary = atof(content);
					}else {
						for (xmlNode * xClient = xJ->children; NULL != xClient ; xClient = xClient->next) {
							if (XML_ELEMENT_NODE == xClient->type) {
								char * contentClient  = (char *)xmlNodeGetContent(xClient);
								if (xmlStrcmp(xClient->name, BAD_CAST "name") == 0) {
									strcpy(entity->topClients[i].name, contentClient);
								}else {
									entity->topClients[i].pay = atof(contentClient);
								}
								free(contentClient);
							}
						}
						i++;
					}
					free(content);
				}
			}
			entity = entity->next;
		}
	}
	xmlFreeDoc(xDoc);
}
