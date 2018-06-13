#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <country.h>
#include <progbase-cpp/net.h>
#include <QListWidgetItem>

using namespace std;
using namespace progbase::net;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    static QListWidgetItem * getItem(Country item);
    ~MainWindow();

private slots:
    void on_listWidget_itemSelectionChanged();


    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
