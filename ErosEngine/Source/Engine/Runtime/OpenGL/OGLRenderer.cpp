#include "OGLRenderer.h"
#include <QtCore/QDebug>
#include "Core/Platform.h"
#if defined(EROS_WINDOWS)
	#include <GL/wglew.h>
	#include <wingdi.h>
	#include <WinUser.h>
#elif defined(EROS_LINUX)
	
#endif
#include <GL/glew.h>


bool OpenGLRenderer::Create(Handle hWindow, Sint32 width, Sint32 height, Sint32 flags)
{

#if defined(EROS_WINDOWS)
	
	HWND windowHandle = (HWND)hWindow;
	
	m_DeviceHandle = GetDC(windowHandle);
	PIXELFORMATDESCRIPTOR pixelFormatDescriptor =
	{
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA,
		32,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // useless parameters
		16,
		0, 0, 0, 0, 0, 0, 0
	};
	
	int indexPixelFormat = ChoosePixelFormat(m_DeviceHandle, &pixelFormatDescriptor);
	DescribePixelFormat(m_DeviceHandle, indexPixelFormat,
		sizeof(PIXELFORMATDESCRIPTOR), &pixelFormatDescriptor);
	
	SetPixelFormat(m_DeviceHandle, indexPixelFormat, &pixelFormatDescriptor);
	
	HGLRC openglRenderContextHandle = wglCreateContext(m_DeviceHandle);
	
	wglMakeCurrent(NULL, NULL);
	
	if (!wglMakeCurrent(m_DeviceHandle, openglRenderContextHandle))
		return false;
	
	assert(glewInit() == GLEW_OK);
	
	PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB 
			= (PFNWGLCREATECONTEXTATTRIBSARBPROC)wglGetProcAddress("wglCreateContextAttribsARB");
	
	m_OGLrenderContextHandle = wglCreateContextAttribsARB(m_DeviceHandle, openglRenderContextHandle, NULL);
		
	if (m_OGLrenderContextHandle)
	{
		if (!wglMakeCurrent(m_DeviceHandle, m_OGLrenderContextHandle))
		{
			return false;
		}
	}

	// Here we just test if they will be able to run the version that the engine uses
	Sint32 glVersionMinor, glVersionMajor;
	glGetIntegerv(GL_MAJOR_VERSION, &glVersionMajor);
	glGetIntegerv(GL_MINOR_VERSION, &glVersionMinor);

	if (glVersionMajor < 4)
		return false;

	
#elif defined(EROS_LINUX)
	
#endif
	
    glLoadIdentity();
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glewExperimental = GL_TRUE;
	
	qDebug() << (const char *)glGetString(GL_VERSION);

	OGLShader globalVertexShader;
	OGLShader globalFragmentShader;

	globalVertexShader.LoadFromFile("Source/Engine/Runtime/Shaders/GlobalVertexShader.vsh", GL_VERTEX_SHADER);
	globalFragmentShader.LoadFromFile("Source/Engine/Runtime/Shaders/GlobalFragmentShader.fsh", GL_FRAGMENT_SHADER);
	globalVertexShader.Compile();
	globalFragmentShader.Compile();

	m_GlobalShader.Create();
	m_GlobalShader.AddShader(globalFragmentShader);
	m_GlobalShader.AddShader(globalVertexShader);
	m_GlobalShader.Compile();

	return true;
}

void OpenGLRenderer::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.3f, 0.5f, 1.0f, 1.0f);
}

void OpenGLRenderer::RenderScene()
{
	for (Uint32 b = 0; b < m_OpenGLQueue.entities.size(); ++b)
	{
		const OpenGLQueueEntity &entity = m_OpenGLQueue.entities[b];

		for (Uint32 i = 0; i < entity.objects.size(); ++i)
		{
			const OpenGLQueueObject &object = entity.objects[i];

			glBindVertexArray(object.firstBuffer);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, object.thirdBuffer);
			m_GlobalShader.UseShader();
			glDrawElements(GL_TRIANGLES, object.fourthBuffer, GL_UNSIGNED_SHORT, nullptr);
			glUseProgram(0);
			glBindVertexArray(0);
		}
	}
}

void OpenGLRenderer::Swap(Sint32 vsync)
{
#if defined(EROS_WINDOWS)
	
	SwapBuffers(m_DeviceHandle);
	wglSwapIntervalEXT(vsync);
	
#elif defined(EROS_LINUX)
	
#endif
}

void OpenGLRenderer::Cleanup()
{

	SetScene(nullptr); // Flush the scene

#if defined(EROS_WINDOWS)
	wglMakeCurrent(NULL, NULL);
	DeleteDC(m_DeviceHandle);
#endif
}

void OpenGLRenderer::ResizeTarget(Sint32 width, Sint32 height)
{
	glViewport(0, 0, width, height);
}

void OpenGLRenderer::SetScene(Scene *pScene)
{
	// If we have a scene already then just release any
	// data that we have associated with said scene
	if (m_pCurrentScene)
	{
		for (Uint32 i = 0; i < m_OpenGLQueue.entities.size(); ++i)
		{
			const auto &entityList = m_OpenGLQueue.entities.at(i);
			for (Uint32 b = 0; b < entityList.objects.size(); ++b)
			{
				const auto &openGLQueue = entityList.objects[b];
				
				if (openGLQueue.type == RenderableType_MESH)
				{
					glDeleteVertexArrays(1, &openGLQueue.firstBuffer);
					glDeleteBuffers(1, &openGLQueue.secondBuffer);
					glDeleteBuffers(1, &openGLQueue.thirdBuffer);
				}
			}
		}
	}

	m_pCurrentScene = pScene;
	OnSceneUnload();
}

void OpenGLRenderer::OnSceneUnload()
{
	// This is almost solely for scene flushing
	if (!m_pCurrentScene)
		return;

	for (Uint32 b = 0; b < m_pCurrentScene->Entities.size(); ++b)
	{
		Entity *entity = m_pCurrentScene->Entities[b];

		std::vector<IComponent *> &componentList = entity->GetComponents();

		OpenGLQueueEntity queueEntity;
		queueEntity.entityRef = entity->GetID();

		for (Uint32 i = 0; i < componentList.size(); ++i)
		{
			IComponent *pComponent = componentList[i];

			if (pComponent->GetType() == ComponentType_MESH)
			{
				// FIRST BUFFER: OpenGL Vertex array
				// SECOND BUFFER: OpenGL Array buffer
				// THIRD BUFFER: OpenGL Index buffer
				// FOURTH BUFFER: How many indices there are

				OpenGLQueueObject buffer;
				MeshComponent *pInMesh = (MeshComponent *)componentList[i];
				glGenVertexArrays(1, &buffer.firstBuffer);
				glGenBuffers(1, &buffer.secondBuffer);
				glGenBuffers(1, &buffer.thirdBuffer);

				glBindVertexArray(buffer.firstBuffer);
				glBindBuffer(GL_ARRAY_BUFFER, buffer.secondBuffer);
				glBufferData(GL_ARRAY_BUFFER, pInMesh->vertexes.size() * sizeof(Vertex), pInMesh->vertexes.data(), GL_STATIC_DRAW);
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer.thirdBuffer);
				glBufferData(GL_ELEMENT_ARRAY_BUFFER, pInMesh->indices.size() * sizeof(ushort), pInMesh->indices.data(), GL_STATIC_DRAW);

				glBindBuffer(GL_ARRAY_BUFFER, buffer.secondBuffer);
				
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), NULL);

				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), NULL);

				glEnableVertexAttribArray(2);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), NULL);

				glBindVertexArray(0);

				buffer.type = RenderableType_MESH;
				buffer.fourthBuffer = pInMesh->indices.size();
				queueEntity.objects.push_back(buffer);
			}
			else if (pComponent->GetType() == ComponentType_CAMERA)
			{

			}
			else if (pComponent->GetType() == ComponentType_MATERIAL) // Not yet implemented
			{
				OpenGLQueueObject mat;
				Material *pMaterial = (Material *)pComponent;
				Uint32 textureFlags = pMaterial->diffuseTexture.textureFlags;
				Texture *pInTexture = &pMaterial->diffuseTexture;
				
				GLuint texture;

				glGenTextures(1, &texture);
				glBindTexture(GL_TEXTURE_2D, texture);
				glTexImage2D
				(
					GL_TEXTURE_2D,
					0, GL_RGB,
					pInTexture->width,
					pInTexture->height,
					0, GL_RGB,
					GL_UNSIGNED_BYTE,
					pInTexture->GetBuffer()
				);
				glGenerateMipmap(GL_TEXTURE_2D);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				glBindTexture(GL_TEXTURE_2D, 0);


			}
		}
		m_OpenGLQueue.AddItem(queueEntity);
	}
}


/*

Handle OpenGLRenderer::PushTexture(Texture *pInTexture)
{
	BasicBuffer *pBuffer = new BasicBuffer;
	pBuffer->data = new Byte[sizeof(GLuint)];
	GLuint texture = 0;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D
	(
		GL_TEXTURE_2D,
		0, GL_RGB,
		pInTexture->width,
		pInTexture->height,
		0, GL_RGB,
		GL_UNSIGNED_BYTE,
		pInTexture->GetBuffer()
	);
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);

	memcpy(pBuffer->data, &texture, sizeof(GLuint));
	std::shared_ptr<BasicBuffer> buf(pBuffer);

	return pBuffer->data;
}

Handle OpenGLRenderer::PushMesh(MeshComponent *pInMesh)
{
	OpenGLBuffer buffer;

	glGenVertexArrays(1, &buffer.vertexArray);
	glGenBuffers(1, &buffer.arrayBuffer);
	glGenBuffers(1, &buffer.indexBuffer);

	glBindVertexArray(buffer.vertexArray);
	glBindBuffer(GL_ARRAY_BUFFER, buffer.arrayBuffer);
	glBufferData(GL_ARRAY_BUFFER, pInMesh->vertexes.size() * sizeof(Vertex), pInMesh->vertexes.data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer.indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, pInMesh->indices.size() * sizeof(ushort), pInMesh->indices.data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, buffer.arrayBuffer);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), NULL);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), NULL);

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), NULL);

	glBindVertexArray(0);

	buffer.indexCount = pInMesh->indices.size();
	
	BasicBuffer *basicBuffer = new BasicBuffer;
	basicBuffer->data = new Byte[sizeof(BasicBuffer)];
	memcpy(basicBuffer->data, &buffer, sizeof(OpenGLBuffer));

	std::shared_ptr<BasicBuffer> bufferHandle(basicBuffer);
	i_Renderables.push_back(bufferHandle);
	return basicBuffer->data;
}

Handle OpenGLRenderer::PushMaterial(Material *pInMaterial)
{
	return nullptr;
}

*/
