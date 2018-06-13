#include <iostream>
#include <progbase-cpp/net.h>
#include <cstring>
#include <dirent.h>
#include <fstream>

#define BUFFER_LEN 1024

using namespace std;
using namespace progbase::net;


class Request {
public :
	string command;
	string filename;

	Request();
	Request(string msgStr);

	void print(void);
};

string getDir(void);
string createFile(const string filename);


int main(void) {
	int serverPort = 9999;
	UdpClient server;
	NetMessage message(BUFFER_LEN);
	IpAddress clientAddress;

	try {
		server.bind(IpAddress("127.0.0.1", serverPort));
		while (true) {
			cout << ">> Waiting for data at " << serverPort << "..." << endl;
			server.receiveFrom(message, clientAddress);
			cout << ">> Received: " << endl << message.dataAsString() << endl;
			Request request(message.dataAsString());
			request.print();
			if (!request.command.compare("show") && !request.filename.compare("")) {
				message.setDataString(getDir());
			}else if (!request.command.compare("create") && request.filename.compare("")) {
				message.setDataString(createFile(request.filename));
			}else if (!request.command.compare("delete") && request.filename.compare("")) {
				if ( remove(request.filename.c_str()) == 0 ) message.setDataString("File successfully deleted");
				else message.setDataString("File UNsuccessfully deleted");
			}else {
				message.setDataString("ERROR COMMAND");
			}
			server.sendTo(message, clientAddress);
			cout << ">> Response sent." << endl;
		}
	} catch (NetException const & exc) {
		cerr << exc.what()<< endl;
	}
	return EXIT_SUCCESS;
}

string getDir(void) {
	DIR *dir;
	struct dirent *ent;
	string directory;

	if ((dir = opendir ("./")) != NULL) {
		while ((ent = readdir (dir)) != NULL) directory += (string)ent->d_name + '\n';
		closedir (dir);
	} else perror("CAN NOT OPEN DIRECTORY");
	return directory;
}

string createFile(const string filename) {
	if (filename.find(".txt") == filename.npos) return "File must have .txt format";
	ofstream myfile(filename);
	myfile.close();
	return "File successfully created";
}

Request::Request(string msgStr) : Request() {
		if (msgStr.find(' ') != msgStr.npos && msgStr.find(' ') + 1 != msgStr.length())  {
			command = msgStr.substr(0, msgStr.find(' '));
			filename = msgStr.substr(msgStr.find(' ') + 1, msgStr.length() - msgStr.find(' '));
		}else command = msgStr.substr(0, msgStr.length());

	}

	void Request::print(void) {
		cout << "Request :" << endl;
		cout << "Command : " << command << endl;
		if (filename.compare("")) cout << "Filename : " << filename << endl;
	}

	Request::Request() { command = ""; filename = ""; }