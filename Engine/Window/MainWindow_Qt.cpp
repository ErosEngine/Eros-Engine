#include "MainWindow_Qt.h"
#include "ui_MainWindow_Qt.h"

MainWindow_Qt::MainWindow_Qt(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow_Qt)
{
    ui->setupUi(this);
}

MainWindow_Qt::~MainWindow_Qt()
{
    delete ui;
}
