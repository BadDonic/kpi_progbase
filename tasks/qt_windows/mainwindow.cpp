#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "taxidriver.h"
#include "dialog.h"
#include "incorrect.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    string name = ui->nameLineEdit->text().toStdString();
    string age = ui->ageLineEdit->text().toStdString();
    string salary = ui->salaryLineEdit->text().toStdString();
    if (correctName(name) && correctAge(age) && correctSalary(salary)) {
       TaxiDriver driver(name, stoi(age), stod(salary));
        Dialog dialog;
        dialog.setTaxiDriver(driver);
        dialog.exec();
    }else {
        incorrect erroWindow;
        erroWindow.setError(correctName(name), correctAge(age), correctSalary(salary));
        erroWindow.exec();
    }

}

bool MainWindow::correctName(string name)
{
    if (!name.compare("") || !isupper(name[0])) return false;
    for (int i = 0; i < name.size(); i++)
        if(!isalpha(name[i])) return false;
    return true;
}

bool MainWindow::correctAge(string age)
{
    if (!age.compare("")) return false;
    for (int i = 0; i < age.size(); i++)
        if(!isdigit(age[i])) return false;
    if (stoi(age) <= 0 || stoi(age) > 140) return false;
    return true;
}

bool MainWindow::correctSalary(string salary)
{
    if (!salary.compare("")) return false;
    for (int i = 0; i < salary.size(); i++)
        if (!isdigit(salary[i]) && !(salary[i] == '.' && i != 0 && i != salary.size() - 1 && salary.size() - i <= 3)) return false;
    return true;
}
