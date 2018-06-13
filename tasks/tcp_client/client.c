#include <stdlib.h>
#include <stdio.h>
#include <jansson.h>

#include <progbase/net.h>
#include <vector.h>
#include <memory.h>

#define BUFFER_LEN 1000

Vector * JsonLoader_loadFromString(const char * jsonString);


int main(int argc, char * argv[]) {
	if (argc < 2) {
		puts("Please, specify server port in command line arguments");
		return 1;
	}
	const int port = atoi(argv[1]);
	TcpClient * tcpClient = TcpClient_init(&(TcpClient){});
	IpAddress * serverAddress = IpAddress_init(
			&(IpAddress){},
			"127.0.0.1",
			port);

	NetMessage * message = NetMessage_init(
			&(NetMessage){},
			(char[BUFFER_LEN]){},
			BUFFER_LEN);

	if (!TcpClient_connect(tcpClient, serverAddress)) {
		perror("tcp connect");
		return 1;
	}
	printf(">> Connected to server (%s:%i)\n",
		   IpAddress_address(serverAddress),
		   IpAddress_port(serverAddress));

	NetMessage_setDataString(message, "numbers");

	if(!TcpClient_send(tcpClient, message)) {
		perror("send");
		return 1;
	}
	if(!TcpClient_receive(tcpClient, message)) {
		perror("recv");
		return 1;
	}
	TcpClient_close(tcpClient);

	printf(">> Response received from server (%d bytes):\r\n%s\r\n",
		   message->dataLength,
		   message->buffer);

	Vector * numbers = JsonLoader_loadFromString(NetMessage_data(message));
	if (numbers == NULL) return 1;
	Vector_print(numbers);
	Vector * task = NULL;
	puts("\n\n\nTASK : Вектор цілих числел, що містить попарні суми сусідніх елементів ");
	Vector * current = numbers;
	while (current->next != NULL) {
		Vector_addLast(&task, Vector_new(current->number + current->next->number));
		current = current->next;
	}
	if (task != NULL) {
		Vector_print(task);
		Vector_freeList(&task);
	}else puts("DATA HAS 1 NUMBER");

	Vector_freeList(&numbers);

	return 0;
}

Vector * JsonLoader_loadFromString(const char * jsonString) {
	json_error_t err;
	json_t * jsonObj = json_loads(jsonString, 0, &err);
	if (json_boolean_value(json_object_get(jsonObj, "status")) == false) {
		puts("STATUS FAILED");
		return NULL;
	}
	json_t *numbersArr = json_object_get(jsonObj, "data");
	Vector * vector = NULL;
	for (size_t i = 0; i < json_array_size(numbersArr); ++i) {
		Vector_addLast(&vector, Vector_new( (int)json_integer_value(json_array_get(numbersArr, i))));
	}
	if (vector == NULL) puts("DATA IS EMPTY");
	json_decref(jsonObj);
	return vector;
}