#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <internetprovider.h>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
	Q_OBJECT

public:
	explicit Dialog(QWidget *parent = 0);
	InternetProvider getInternetProvider(void);
	~Dialog();

private slots:

	void on_pushButton_clicked();

	void on_pushButton_2_clicked();

	void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

private:
	Ui::Dialog *ui;
};

#endif // DIALOG_H
