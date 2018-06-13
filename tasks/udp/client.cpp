#include <iostream>
#include <progbase-cpp/net.h>

using namespace std;
using namespace progbase::net;

#define BUFFER_LEN 1024


int main(void) {
	UdpClient client;
	NetMessage message(BUFFER_LEN);
	IpAddress serverAddress("127.0.0.1", 9999);
	cout << "Commands:" << endl;
	cout << "1.> show < - displays a list of files in directory;" << endl;
	cout << "2.> create (filename) < - create a new file in directory);" << endl;
	cout << "3.> delete (filename) < - delete file from directory;" << endl;

	while (1) {
		cout << "Waiting for input..." << endl;
		string str;
		getline(cin, str);
		message.setDataString(str);
		client.sendTo(message, serverAddress);
		cout << ">> Request sent" << endl;
		client.receiveFrom(message, serverAddress);
		str = message.dataAsString();
		cout << ">> Received " << str.length() << " bytes: " << endl << str << endl;
	}
}