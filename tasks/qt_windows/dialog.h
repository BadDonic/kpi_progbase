#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <iostream>
#include <string>
#include "taxidriver.h"

using namespace std;

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    void setTaxiDriver(TaxiDriver & driver);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
