#include "country.h"

Country::Country()
{
    return;
}

Country::Country(QString name, QString officialName, QString citizenNames, int entryNumber, QString startDate)
{
    this->name = name;
    this->officialName = officialName;
    this->citizenNames = citizenNames;
    this->entryNumber = entryNumber;
    this->startDate = startDate;
}

QString Country::getName()
{
    return name;
}

QString Country::getOfficialName()
{
    return officialName;
}

QString Country::getCitizenNames()
{
    return citizenNames;
}

QString Country::getStartDate()
{
    return startDate;
}

int Country::getEntryNumber()
{
    return entryNumber;
}
