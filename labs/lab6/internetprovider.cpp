#include "internetprovider.h"

#include <QChar>

InternetProvider::InternetProvider() {}

InternetProvider::InternetProvider(QString name, int megaBytes, double price)
{
    this->name = name;
	this->megaBytes = megaBytes;
    this->price = price;
}

QString InternetProvider::getName()
{
    return name;
}
int InternetProvider::getMegaBytes()
{
	return megaBytes;
}

double InternetProvider::getPrice()
{
    return price;
}

void InternetProvider::setName(QString & name)
{
    this->name = name;
}

void InternetProvider::setMegaBytes(int & megaBytes) {
	this->megaBytes = megaBytes;
}

void InternetProvider::setPrice(double & price)
{
	this->price = price;
}

bool InternetProvider::correctName(QString & nameString)
{
	if (nameString == "") return false;
	if (!nameString.at(0).isUpper()) return false;
	for (int i = 1; i < nameString.count(); i++)
		if (!(nameString[i]).isLetter()) return false;
	return true;
}
