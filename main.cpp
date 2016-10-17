#include "Engine/Runtime/Window/OpeningDialog.h"
#include "Engine/Runtime/Window/MainWindow.h"
#include "Engine/Editor/MainWindow_Qt.h"
#include "Engine/Runtime/OpenGL/Shape/Shape.h"
#include <QApplication>


int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    
    glm::vec3 vector = glm::vec3( 50.0f, 28.0f, 60.0f );
    glm::vec3 normalized = glm::normalize(vector);
    qDebug() << "X: " << normalized.x;
    qDebug() << "Y: " << normalized.y;
    qDebug() << "Z: " << normalized.z;
    
    return a.exec();
}


int _main(int argc, char **argv)
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

