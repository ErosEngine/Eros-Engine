#include "Engine/Runtime/Window/Window.h"
#include "Runtime/OpenGL/OGLRenderer.h"
#include "Engine/Runtime/Core/Framework/Application.h"
#include "Editor/Widgets/SceneEditor.h"
#include "Editor/EditorWindow.h"


#define TEST 0


int main(int argc, char **argv)
{
#if TEST
	
	OpenGLRenderer renderer;
	EditorWindow window;
	window.Create("Eros Engine", ERect(200, 100, 1000, 700));
	
	SceneEditor *sceneEditor = new SceneEditor();
	sceneEditor->Create(&window, ERect(30, 50, 400, 600), "TestRendeerThing");
	sceneEditor->SetRenderer(&renderer);
	
	window.AddWidget(sceneEditor);
	window.Run();

#else
    
	OpenGLRenderer renderer;
	QString applicationName = "Eros Engine | Renderer: OpenGL";

    {
	    Window window;
        window.Create(applicationName.toLatin1().constData(), 1024, 700, CW_USEDEFAULT, CW_USEDEFAULT, 0);
		renderer.Create(window.GetPlatformHandle(), window.GetWidth(), window.GetHeight(), 0);
		Application game;
		game.SetVSyncEnabled(true);
		game.SetWindow(&window);
		game.SetRenderer(&renderer, Api_OPENGL_4_0);
		game.InitializeLoop();
		game.RunGameLoop();
		game.EndGameLoop();
    }
    
    
#endif
    
    return 0;
}

