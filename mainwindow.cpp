#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString cCode = convert.doTi();
    ui->textBrowser->setText(cCode);

}

MainWindow::~MainWindow()
{
    delete ui;
}

