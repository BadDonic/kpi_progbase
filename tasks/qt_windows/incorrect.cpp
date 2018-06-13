#include "incorrect.h"
#include "ui_incorrect.h"

using namespace std;

incorrect::incorrect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::incorrect)
{
    ui->setupUi(this);
}

void incorrect::setError(bool correctName, bool correctAge, bool correctSalary)
{
    if (!correctName) {
        ui->label_7->setText("<font color='red'>Name</font>");
        ui->label->setText(QString::fromStdString(" 0nly the alphabetic characters\n(First letter must be upper)"));
    }else {
         ui->label->setText(QString::fromStdString("Correct"));
    }
    if (!correctAge) {

        ui->label_6->setText("<font color='red'>Age</font>");
        ui->label_2->setText(QString::fromStdString("Only digit\nNumber within [1 - 140]"));
    }else {
         ui->label_2->setText(QString::fromStdString("Correct"));
    }
    if (!correctSalary) {
        ui->label_8->setText("<font color='red'>Salary</font>");
        ui->label_3->setText(QString::fromStdString("Only positive float numbers\n 2 digit after dot"));
    }else {
         ui->label_3->setText(QString::fromStdString("Correct"));
    }
}

incorrect::~incorrect()
{
    delete ui;
}

void incorrect::on_pushButton_clicked()
{
    close();
}
