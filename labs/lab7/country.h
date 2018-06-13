#ifndef COUNTRY_H
#define COUNTRY_H

#include <QString>
#include <QMetaType>


class Country
{
    QString name;
    QString officialName;
    QString citizenNames;
    int entryNumber;
    QString startDate;
public:
    Country();
    Country(QString name, QString officialName, QString citizenNames, int entryNumber, QString startDate);
    QString getName(void);
    QString getOfficialName(void);
    QString getCitizenNames(void);
    QString getStartDate(void);
    int getEntryNumber(void);

};

Q_DECLARE_METATYPE(Country)
#endif // COUNTRY_H
