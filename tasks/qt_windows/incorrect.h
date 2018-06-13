#ifndef INCORRECT_H
#define INCORRECT_H

#include <QDialog>
#include <taxidriver.h>

namespace Ui {
class incorrect;
}

class incorrect : public QDialog
{
    Q_OBJECT

public:
    explicit incorrect(QWidget *parent = 0);
    void setError(bool correctName, bool correctAge, bool correctSalary);
    ~incorrect();

private slots:
    void on_pushButton_clicked();

private:
    Ui::incorrect *ui;
};

#endif // INCORRECT_H
