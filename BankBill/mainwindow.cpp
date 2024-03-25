#include "mainwindow.h"
#include "model.cpp"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model=new Model();
    connect(model, &Model::BalanceChanged, this, &MainWindow::show_balance);
    connect(model, &Model::BalanceChanged, this, &MainWindow::show_balance);
    connect(model, &Model::BalanceChanged, this, &MainWindow::show_balance);
}

MainWindow::~MainWindow()
{
    delete model;
    delete ui;
}


void MainWindow::on_mButton1_clicked()
{
    double bill1 = ui->mBill1->text().toDouble();
    double period = ui->mPeriod1->value();
    model->setBalance(0,bill1);
    model->setPeriod(0,period);
}

void MainWindow::on_mButton2_clicked()
{
    double bill1 = ui->mBill2->text().toDouble();
    double period = ui->mPeriod2->value();
    model->setBalance(1,bill1);
    model->setPeriod(1,period);
}

void MainWindow::on_mButton3_clicked()
{
    double bill1 = ui->mBill3->text().toDouble();
    double period = ui->mPeriod1_3->value();
    model->setBalance(2,bill1);
    model->setPeriod(2,period);
}

void MainWindow::show_balance(){
    ui->mTotalBill->setText(QString::number(model->getTotalBalans()));
}
