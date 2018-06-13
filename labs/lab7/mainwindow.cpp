#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <country.h>
#include <iostream>
#include <progbase-cpp/net.h>
#include <QList>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QString>
#include <country.h>
#include <QVariant>
#include<http.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem("Name");
    ui->comboBox->addItem("Entry Number");
    ui->comboBox->addItem("Start Date");
    QString jsonString = httpRequest("progbase.herokuapp.com", "/apis/country.register.gov.uk/records.json", "GET", 80);
    QList<Country> list = loadFromJson(jsonString);
    foreach (Country cur, list) {
        QVariant varCountry;
        varCountry.setValue(cur);
        QListWidgetItem * itemCountry = new QListWidgetItem();
        itemCountry->setText(cur.getName());
        itemCountry->setData(Qt::UserRole, varCountry);
        ui->listWidget->addItem(itemCountry);
    }
    if (list.size() == 0) {
        ui->comboBox->setEnabled(false);
    }
    ui->listWidget->sortItems(Qt::AscendingOrder);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_listWidget_itemSelectionChanged()
{
    QList<QListWidgetItem *> items = ui->listWidget->selectedItems();
    if (items.size() == 0) {
        ui->label_8->setText("");
        ui->label_10->setText("");
        ui->label_12->setText("");
        ui->label_14->setText("");
        ui->label_16->setText("");
        return;
    }
    QListWidgetItem * selectedItem = items[0];
    Country country = selectedItem->data(Qt::UserRole).value<Country>();
    ui->label_8->setText(country.getName());
    ui->label_10->setText(country.getOfficialName());
    ui->label_12->setText(country.getCitizenNames());
    ui->label_14->setNum(country.getEntryNumber());
    ui->label_16->setText(country.getStartDate());
}


void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    if (arg1 == "Name") {
        ui->listWidget->sortItems(Qt::AscendingOrder);
        return;
    }
    QList<Country> list;
    for (int i = 0; i < ui->listWidget->count(); i++)
        list.push_back(ui->listWidget->item(i)->data(Qt::UserRole).value<Country>());
    ui->listWidget->clear();
    Country min;
    if (arg1 == "Start Date") {
        while (!list.isEmpty()) {
            int minIndex = 0;
            for (int i = 0; i < list.count(); i++)
                if (QString::compare(list.value(minIndex).getStartDate(), list.value(i).getStartDate()) < 0) minIndex = i;
            ui->listWidget->addItem(this->getItem(list.takeAt(minIndex)));
        }
    }else {
        while (!list.isEmpty()) {
            int minIndex = 0;
            for (int i = 0; i < list.count(); i++)
                if (list.value(minIndex).getEntryNumber() < list.value(i).getEntryNumber()) minIndex = i;
            ui->listWidget->addItem(this->getItem(list.takeAt(minIndex)));
        }
    }


}

QListWidgetItem * MainWindow::getItem(Country item) {
    QVariant varCountry;
    varCountry.setValue(item);
    QListWidgetItem * itemCountry = new QListWidgetItem();
    itemCountry->setText(item.getName());
    itemCountry->setData(Qt::UserRole, varCountry);
    return itemCountry;
}
