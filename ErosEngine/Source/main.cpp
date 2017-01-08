#include "Engine/Runtime/Window/Window.h"
#include "Runtime/OpenGL/OGLRenderer.h"
#include "Engine/Runtime/Core/Framework/Application.h"
#include "Editor/Widgets/SceneEditor.h"
#include "Editor/EditorWindow.h"


#define TEST 1


int main(int argc, char **argv)
{
#if TEST
	
	D3D11Renderer renderer;
	EditorWindow window;
	window.Create("Eros Engine test window", ERect(200, 100, 1000, 700));
	
	SceneEditor *sceneEditor = new SceneEditor();
	sceneEditor->Create(&window, ERect(30, 50, 400, 600), "TestRendeerThing");
	sceneEditor->SetRenderer(&renderer);
	
	window.AddWidget(sceneEditor);
	window.Run();

#else
    
	IRenderBase *pRenderer;
	QString applicationName = "Eros Engine ";
	pRenderer = new D3D11Renderer();


    {
	    Window window;
        window.Create(applicationName.toLatin1().constData(), 1024, 700, WINDOWED_RESIZEABLE_WINDOW);
		
		pRenderer->Create(window.GetPlatformHandle(), window.GetWidth(), window.GetHeight(), 0);
		Application game;
		game.SetVSyncEnabled(true);
		game.SetWindow(&window);
		game.SetRenderer(pRenderer, API_DIRECTX_11);
		game.InitializeLoop();
		game.RunGameLoop();
		game.EndGameLoop();
    }
    
	delete pRenderer;
    
#endif
    
    return 0;
}

