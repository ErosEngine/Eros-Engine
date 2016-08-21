#include "Engine/Window/OpeningDialog.h"
#include "Engine/Window/MainWindow.h"
#include "Engine/Editor/MainWindow_Qt.h"
#include "Engine/Window/Util.h"
#include <QApplication>


int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    
    OpeningDialog d;
    d.show();
    d.exec();
    
    // Once the selector is finished    
    if (d.returnedType == WindowType::WINDOW_SDL)
    {
        MainWindow_SDL w;
        w.start();
    }
    if (d.returnedType == WindowType::WINDOW_QT)
    {
        MainWindow_Qt w;
        w.show();
        return a.exec();
    }
    
    return a.exec();    
}
