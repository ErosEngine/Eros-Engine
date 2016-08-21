#ifndef MAINWINDOW_QT_H
#define MAINWINDOW_QT_H

#include <GL/glew.h>
#include <QMainWindow>
#include <QTextBrowser>
#include <QWidget>
#include <QObject>


namespace Ui {
class MainWindow_Qt;
}

class MainWindow_Qt : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow_Qt(QWidget *parent = 0);
    ~MainWindow_Qt();
    
    void sendDebugString(QString &string);
    void sendDebugString(const char *string);
    void sendDebugString(GLenum &errorCode);
    
    static MainWindow_Qt *getInstance();
    
private:
    
    static MainWindow_Qt *m_singleton;
    Ui::MainWindow_Qt *ui;
};



#endif // MAINWINDOW_QT_H
