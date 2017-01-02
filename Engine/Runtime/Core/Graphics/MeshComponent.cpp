#include "MeshComponent.h"
#include <QDebug>
#include <QFile>
#include <fbxsdk.h>


MeshComponent CreateCube()
{
    MeshComponent shape;
    
    return shape;
}

MeshComponent CreatePlane()
{
    return MeshComponent();
}

MeshComponent CreateQuad()
{
    return MeshComponent();
}

MeshComponent CreatePyramid()
{
    return MeshComponent();
}

MeshComponent CreateSphere()
{
    return MeshComponent();
}


void ProcessMesh(FbxMesh *pMesh, MeshComponent *pBase)
{
	for (uint i = 0; i < pMesh->GetControlPointsCount(); ++i)
	{
		Vertex vertex;
		FbxVector4 currentVertex = pMesh->GetControlPointAt(i);
		vertex.position.x = currentVertex.mData[0];
		vertex.position.y = currentVertex.mData[1];
		vertex.position.z = currentVertex.mData[2];
		
		vertex.normal = EVector3(0.0f, 0.0f, 0.0f);
		// TODO
		vertex.texCoords = EVector2(0.0f, 0.0f);
		
		pBase->vertexes.push_back(vertex);
	}
}

void ProcessNodes(FbxNode *pNode, MeshComponent *pBase)
{
	FbxMesh *pMesh = pNode->GetMesh();
	
	for (uint i = 0; i < pNode->GetChildCount(); ++i)
	{
		ProcessNodes(pNode->GetChild(i), pBase);
	}
}

void ProcessScene(FbxScene *pScene, MeshComponent *pBase)
{
	FbxNode *pRootNode = pScene->GetRootNode();
	
	for (uint i = 0; i < pRootNode->GetChildCount(); ++i)
	{
		ProcessNodes(pRootNode->GetChild(i), pBase);
	}
}

bool MeshComponent::LoadFromFile(const char *fileName)
{
	FbxManager *pManager = FbxManager::Create();
	FbxIOSettings *pIoSettings = FbxIOSettings::Create(pManager, IOSROOT);
	
	pManager->SetIOSettings(pIoSettings);
	
	FbxImporter *pImporter = FbxImporter::Create(pManager, "");
	
	if (!pImporter->Initialize(fileName, -1, pManager->GetIOSettings()))
	{
		qDebug() << "Failed to load the specified model with the following errors: \n" <<
					pImporter->GetStatus().GetErrorString();
		return false;
	}
	
	FbxScene *pMainScene = FbxScene::Create(pManager, "loadedScene");
	pImporter->Import(pMainScene);
	pImporter->Destroy();
	
	ProcessScene(pMainScene, this);
	return true;	
}

void MeshComponent::ClearMesh()
{
	vertexes.clear();
	indices.clear();
	fileName.clear();
}

