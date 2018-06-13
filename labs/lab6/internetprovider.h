#ifndef INTERNETPROVIDER_H
#define INTERNETPROVIDER_H

#include <QString>
#include <QMetaType>

class InternetProvider {
    QString name;
	int megaBytes;
    double price;
public:
    InternetProvider();
	InternetProvider(QString name, int megaBytes, double price);
    QString getName(void);
	int getMegaBytes(void);
    double getPrice(void);
    void setName(QString & name);
	void setMegaBytes(int & megaBytes);
	void setPrice(double & price);
	static bool correctName(QString & nameString);
};

Q_DECLARE_METATYPE(InternetProvider)
#endif
