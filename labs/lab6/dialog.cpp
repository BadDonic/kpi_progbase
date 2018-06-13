#include "dialog.h"
#include "ui_dialog.h"
#include <internetprovider.h>
#include <QErrorMessage>

Dialog::Dialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Dialog)
{
	ui->setupUi(this);
	ui->lineEdit->setPlaceholderText("<InternetProvider>");
	ui->pushButton->setEnabled(false);
}

InternetProvider Dialog::getInternetProvider()
{
	QString name = ui->lineEdit->text();
	int megaBytes = ui->spinBox->value();
	double price = ui->doubleSpinBox->value();
	return InternetProvider(name, megaBytes, price);
}

Dialog::~Dialog()
{
	delete ui;
}

void Dialog::on_pushButton_clicked()
{
	QString name = ui->lineEdit->text();
	if (!InternetProvider::correctName(name)) {
		(new QErrorMessage(this))->showMessage("Error. Name only consists of letter(First Lettter is Upper). Please, re-enter correct Name");
		return;
	}
	this->accept();
}

void Dialog::on_pushButton_2_clicked()
{
	this->reject();
}

void Dialog::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{
	if (arg2 == 0) ui->pushButton->setEnabled(false);
	else ui->pushButton->setEnabled(true);

}
