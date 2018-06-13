#include<http.h>
#include<progbase-cpp/net.h>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include<QJsonValue>
#include<iostream>

using namespace std;
using namespace progbase::net;

QList<Country> loadFromJson(QString jsonStr) {
    QList<Country> list;
    QJsonDocument doc = QJsonDocument::fromJson(jsonStr.toUtf8());
    QJsonObject mainObj = doc.object();
    foreach (const QJsonValue & val, mainObj) {
        QJsonObject obj = val.toObject();
        QString entryNumber = obj["entry-number"].toString();
        QJsonArray array = obj["item"].toArray();
        foreach (const QJsonValue & value, array) {
            QJsonObject cur = value.toObject();
            list.push_back(Country(cur["name"].toString(),
                           cur["official-name"].toString(),
                           cur["citizen-names"].toString(),
                           entryNumber.toInt(),
                           cur["start-date"].toString()));
        }
    }
    return list;
}

QString httpRequest(string site, string path, string request, int port) {
    string jsonStr;
    TcpClient client;
    NetMessage message(1000);
    try {
        //"progbase.herokuapp.com"
        auto ipAddress = IpAddress(Ip::resolveHostname(site), port);
        client.connect(ipAddress);
        //
        message.setDataString(request + " " + path +" HTTP/1.0\r\n"
                              "Host: " + site + "\r\n"
                              "\r\n");
        client.send(message);
        do {
            client.receive(message);
            jsonStr += message.dataAsString();
        }while (!message.isEmpty());

    }catch(NetException const & exc) {
        cerr << exc.what() << endl;
    }
    return QString::fromStdString(jsonStr.substr(jsonStr.find('{')));
}
