#include "dialog.h"
#include "ui_dialog.h"
#include <QString>
#include <string>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

void Dialog::setTaxiDriver(TaxiDriver & driver){
    ui->label_9->setText(QString::fromStdString(driver.getName()));
    ui->label_10->setText(QString::number(driver.getAge()));
    ui->label_11->setText(QString::number(driver.getSalary()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    close();
}
