#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <dialog.h>
#include <QDebug>
#include <QVariant>
#include <QListWidgetItem>
#include <QString>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	InternetProvider providers[4] = {
		InternetProvider("LanNet", 8, 200.00),
		InternetProvider("SunNet", 100, 150.50),
		InternetProvider("Vodafone", 1, 75.00),
		InternetProvider("Kievstar", 16, 24.50)
	};

	for (int i = 0; i < 4; i++) {
		QVariant variant;
		variant.setValue(providers[i]);
		QListWidgetItem * qProvider = new QListWidgetItem();
		qProvider->setText(providers[i].getName());
		qProvider->setData(Qt::UserRole, variant);
		ui->listWidget->addItem(qProvider);
	}
	ui->listWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
	ui->spinBox->setMaximum(ui->listWidget->count());
	ui->pushButton->setToolTip("Add New Object");
	ui->pushButton_2->setToolTip("Remove Chosen Object");
	ui->pushButton_3->setToolTip("Find X providers of the most expensive tariff for Internet");
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Dialog dialog;
	dialog.setWindowTitle("New Internet_Provider !!!!");
	if (dialog.exec()) {
		InternetProvider provider = dialog.getInternetProvider();
		QVariant qVariantProv;
		qVariantProv.setValue(provider);
		QListWidgetItem * qProvider = new QListWidgetItem();
		qProvider->setText(provider.getName());
		qProvider->setData(Qt::UserRole, qVariantProv);
		ui->listWidget->addItem(qProvider);
		ui->spinBox->setMaximum(ui->listWidget->count());
		ui->spinBox->setEnabled(true);
		ui->pushButton_3->setEnabled(true);
	}
}

void MainWindow::on_pushButton_2_clicked()
{
	QList<QListWidgetItem*> items = ui->listWidget->selectedItems();
		foreach(QListWidgetItem * item, items) {
			delete ui->listWidget->takeItem(ui->listWidget->row(item));
		}
		ui->spinBox->setMaximum(ui->listWidget->count());
		if (ui->listWidget->count() == 0) {
			ui->spinBox->setEnabled(false);
			ui->pushButton_3->setEnabled(false);
		}
}

void MainWindow::on_listWidget_itemSelectionChanged()
{
	QList<QListWidgetItem *> items = ui->listWidget->selectedItems();
	if (items.size() == 0) {
		ui->label_5->setText("");
		ui->label_7->setText("");
		ui->label_9->setText("");
		ui->pushButton_2->setEnabled(false);
		return;
	}
	ui->pushButton_2->setEnabled(true);
	QListWidgetItem * selectedItem = items[0];
	InternetProvider provider =  selectedItem->data(Qt::UserRole).value<InternetProvider>();
	ui->label_5->setText(provider.getName());
	ui->label_7->setNum(provider.getMegaBytes());
	ui->label_9->setNum(provider.getPrice());
}

void MainWindow::on_pushButton_3_clicked()
{
	ui->listWidget_2->clear();
	QList<InternetProvider> items;
	int number = ui->spinBox->value();
	for (int i = 0; i < ui->listWidget->count(); i++)
		items.push_back(ui->listWidget->item(i)->data(Qt::UserRole).value<InternetProvider>());

	while (!items.isEmpty() && number != 0) {
		int max = 0;
		for (int i = 1; i < items.size(); i++) {
			if (items[i].getPrice() > items[max].getPrice())
				max = i;
		}
		InternetProvider maxProvider = items.takeAt(max);
		QVariant variant;
		variant.setValue(maxProvider);
		QListWidgetItem * qProvider = new QListWidgetItem();
		qProvider->setText(maxProvider.getName());
		qProvider->setData(Qt::UserRole, variant);
		ui->listWidget_2->addItem(qProvider);
		number--;
	}
}
