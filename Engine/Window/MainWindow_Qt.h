#ifndef MAINWINDOW_QT_H
#define MAINWINDOW_QT_H

#include <QMainWindow>

namespace Ui {
class MainWindow_Qt;
}

class MainWindow_Qt : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow_Qt(QWidget *parent = 0);
    ~MainWindow_Qt();
    
private:
    Ui::MainWindow_Qt *ui;
};

#endif // MAINWINDOW_QT_H
