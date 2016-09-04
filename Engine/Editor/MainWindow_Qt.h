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
    
    void queueDebugStr(QString &string);
    void queueDebugStr(const char *string);
    void queueDebugStr(GLenum &errorCode);
    void freeQueue();
    
    static MainWindow_Qt *getInstance();
    
private:
    
    std::vector<QString> m_stringArr;
    
    static MainWindow_Qt *m_singleton;
    Ui::MainWindow_Qt *ui;
};



#endif // MAINWINDOW_QT_H
