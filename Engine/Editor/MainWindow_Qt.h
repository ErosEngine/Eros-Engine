#ifndef MAINWINDOW_QT_H
#define MAINWINDOW_QT_H

#include <GL/glew.h>
#include <QMainWindow>
#include <QTextBrowser>
#include <QWidget>
#include <QObject>


namespace Ui 
{
    class MainWindow_Qt;
}

class MainWindow_Qt : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow_Qt(QWidget *parent = 0);
    ~MainWindow_Qt();
    
    static MainWindow_Qt *getInstance();
    
    void test();
    
private slots:
    void on_pushButton_released();

private:
    
    static MainWindow_Qt *m_singleton;
    Ui::MainWindow_Qt *ui;
};



#endif // MAINWINDOW_QT_H
