#ifndef MAINWINDOW_QT_H
#define MAINWINDOW_QT_H

#include <GL/glew.h>
#include <QMainWindow>
#include <QTextBrowser>
#include <QWidget>
#include "Widgets/SceneViewport.h"
#include <QObject>
#include "Core/Platform.h"


namespace Ui 
{
    class EditorWindow;
}

class EditorWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit EditorWindow(QWidget *parent = 0);
    ~EditorWindow();
    
    static EditorWindow *GetInstance();
	
	void SetRenderer(IRenderBase *pRenderer);
	
private slots:
    void on_pushButton_released();

private:
    
    static EditorWindow *m_singleton;
    Ui::EditorWindow *ui;
};



#endif // MAINWINDOW_QT_H
