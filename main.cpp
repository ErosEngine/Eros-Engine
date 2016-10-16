#include "Engine/Runtime/Window/OpeningDialog.h"
#include "Engine/Runtime/Window/MainWindow.h"
#include "Engine/Editor/MainWindow_Qt.h"
#include "Engine/Runtime/OpenGL/Shape/Shape.h"
#include <QApplication>


int _main(int argc, char **argv)
{
    QApplication a(argc, argv);
    
    Shape s;
    for (int i = 0; i < 4; ++i)
    {
        s.points.push_back(glm::vec3(i * 2, i * 5, i * 6));
    }
    
    s.convertPointsToGLFloatPointer();
    
    for (int i = 0; i < 12; ++i)
    {
        qDebug() << s.verts[i];
    }
    
    return 0;
}


int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    
    OpeningDialog d;
    d.show();
    d.exec();
    
    if (d.returnedType == WindowType::WINDOW_SDL)
    {
        MainWindow_SDL w;
        w.start();
        return 0;
    }
    if (d.returnedType == WindowType::WINDOW_QT)
    {
        MainWindow_Qt w;
        w.show();
        a.exec();
    }
    
    return 0;
}

