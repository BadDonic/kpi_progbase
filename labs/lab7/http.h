#ifndef HTTP_H
#define HTTP_H
#include<QList>
#include<QString>
#include<country.h>
#include<iostream>

using namespace std;

QString httpRequest(string site, string path, string request, int port);
QList<Country> loadFromJson(QString jsonStr);

#endif // HTTP_H
