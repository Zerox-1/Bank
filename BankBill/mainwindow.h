#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "model.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_mButton1_clicked();

    void on_mButton2_clicked();

    void on_mButton3_clicked();

    void show_balance();

private:
    Ui::MainWindow *ui;
    Model *model;
};
#endif // MAINWINDOW_H
