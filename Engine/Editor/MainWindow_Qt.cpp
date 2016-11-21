#include "MainWindow_Qt.h"
#include "ui_MainWindow_Qt.h"
#include "Engine/Runtime/Window/MainWindow.h"


MainWindow_Qt::MainWindow_Qt(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow_Qt)
{
    ui->setupUi(this);
    
    // allocate the singleton to this
    m_singleton = this;
}

MainWindow_Qt::~MainWindow_Qt()
{
    delete ui;
}

MainWindow_Qt *MainWindow_Qt::m_singleton = 0;

MainWindow_Qt *MainWindow_Qt::getInstance()
{
    if (!m_singleton)
    {
        m_singleton = new MainWindow_Qt();
    }
    return m_singleton;
}

void MainWindow_Qt::on_pushButton_released()
{
    MainWindow_SDL w;
    w.start();
    return;
}
