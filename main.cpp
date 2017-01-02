#include "Engine/Runtime/Window/OpeningDialog.h"
#include "Engine/Runtime/Window/Window.h"
#include "Engine/Editor/EditorWindow.h"
#include "Engine/Runtime/Core/Framework/Application.h"
#include <QApplication>

#define TEST 0

int main(int argc, char **argv)
{
#if TEST
    
    QApplication a(argc, argv);
    OpenGLViewPort p;
    p.show();
    a.exec();
    
#else
    
    QApplication a(argc, argv);
    
    OpeningDialog d;
    d.show();
    d.exec();
	IRenderBase *pRenderer;
	QString applicationName = "Eros Engine ";
	if (d.apiType == API_OPENGL_4_5)
	{
		pRenderer = new OpenGLRenderer();	
		applicationName.append("OpenGL 4.5");
	}
	else if (d.apiType == API_DIRECTX_11)
	{
		pRenderer = new D3D11Renderer();
		applicationName.append("DirectX 11");
	}
    
    if (d.returnedType == WindowType::WINDOW_SDL)
	{
	    Window w;
        w.Create(applicationName.toLatin1().constData(), 1000, 650, WINDOWED_RESIZEABLE_WINDOW);
		
		pRenderer->Create(w.GetPlatformHandle(), w.GetWidth(), w.GetHeight(), 0);
		Application game;
		game.SetWindow(&w);
		game.SetRenderer(pRenderer, d.apiType);
		game.InitializeLoop();
		game.RunGameLoop();
		game.EndGameLoop();
    }
    if (d.returnedType == WindowType::WINDOW_QT)
    {
        EditorWindow w;
		w.setWindowTitle(applicationName);
		w.SetRenderer(pRenderer);
        w.show();
        a.exec();
    }
	
	delete pRenderer;
    
#endif
    
    return 0;
}

