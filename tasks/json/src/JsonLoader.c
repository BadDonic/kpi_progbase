#include <JsonLoader.h>

void JsonLoader_saveToString(char * str, const TaxiDriver * entity) {
	int size = 3;
	json_t * driversArr = json_array();
	while (entity != NULL) {
		json_t * driverObj = json_object();
		json_object_set_new(driverObj, "name", json_string(entity->name));
		json_object_set_new(driverObj, "age", json_integer(entity->age));
		json_object_set_new(driverObj, "salary", json_real(entity->salary));
		json_t * clientArr = json_array();
		json_object_set(driverObj, "topClients", clientArr);
		for (size_t i = 0; i < size; ++i) {
			json_t * clientObj = json_object();
			json_object_set_new(clientObj, "name", json_string(entity->topClients[i].name));
			json_object_set_new(clientObj, "pay", json_real(entity->topClients[i].pay));
			json_array_append(clientArr, clientObj);
			json_decref(clientObj);
		}
		json_decref(clientArr);
		json_array_append(driversArr, driverObj);
		entity = entity->next;
		json_decref(driverObj);
	}

	char * jsonString = json_dumps(driversArr, JSON_INDENT(2));
	strcpy(str, jsonString);
	free(jsonString);
	json_decref(driversArr);
}

void JsonLoader_loadFromString(TaxiDriver * entity, const char * jsonString) {
	json_error_t err;
	json_t * jsonArr = json_loads(jsonString, 0, &err);
	size_t index = 0;
	json_t * value = NULL;
	json_array_foreach(jsonArr, index, value) {
		json_t * clientsArr = json_object_get(value, "topClients");
		strcpy(entity->name, json_string_value(json_object_get(value, "name")));
		entity->age = (int)json_integer_value(json_object_get(value, "age"));
		entity->salary = json_real_value(json_object_get(value, "salary"));
		size_t indexClient = 0;
		json_t * valueClient = NULL;
		int count = 0;
		json_array_foreach(clientsArr, indexClient, valueClient) {
			strcpy(entity->topClients[count].name, json_string_value(json_object_get(valueClient, "name")));
			entity->topClients[count].pay = json_real_value(json_object_get(valueClient, "pay"));
			count++;
		}

		entity = entity->next;
	}
	json_decref(jsonArr);
}
