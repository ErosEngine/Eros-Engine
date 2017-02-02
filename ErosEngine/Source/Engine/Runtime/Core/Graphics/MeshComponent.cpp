#include "MeshComponent.h"
#include <QtCore/QDebug>
#include <fbxsdk.h>


void ProcessMesh(FbxMesh *pMesh, MeshComponent *pBase)
{
	FbxLayerElementArrayTemplate<FbxVector2> *pTexCoords;
	pMesh->GetTextureUV(&pTexCoords);

	for (Uint32 i = 0; i < pMesh->GetControlPointsCount(); ++i)
	{
		Vertex vertex;
		FbxVector4 currentVertex = pMesh->GetControlPointAt(i);
		vertex.position.x = currentVertex.mData[0];
		vertex.position.y = currentVertex.mData[1];
		vertex.position.z = currentVertex.mData[2];
		
		// TODO
		vertex.normal = EVector3(0.0f, 0.0f, 0.0f);
		
		FbxVector2 currentTexCoord = pTexCoords->GetAt(i);
		vertex.texCoords.x = currentTexCoord.mData[0];
		vertex.texCoords.y = currentTexCoord.mData[1];

		pBase->vertexes.push_back(vertex);
	}

	Uint32 numIndices = pMesh->GetPolygonVertexCount();
	Uint32 *indices = (Uint32 *)pMesh->GetPolygonVertices();

	for (Uint32 i = 0; i < numIndices; ++i)
	{
		pBase->indices.push_back((Uint16)indices[i]);
	}
}

void ProcessNodes(FbxNode *pNode, MeshComponent *pBase)
{
	FbxMesh *pMesh = pNode->GetMesh();
	if (pMesh)
		ProcessMesh(pMesh, pBase);
	
	for (Uint32 i = 0; i < pNode->GetChildCount(); ++i)
	{
		ProcessNodes(pNode->GetChild(i), pBase);
	}
}

void ProcessScene(FbxScene *pScene, MeshComponent *pBase)
{
	FbxNode *pRootNode = pScene->GetRootNode();
	
	for (Uint32 i = 0; i < pRootNode->GetChildCount(); ++i)
	{
		ProcessNodes(pRootNode->GetChild(i), pBase);
	}
}

void MeshComponent::CreateFromOther(const IComponent *other)
{
	if (other->ToString() != "Mesh Component")
		return;

	MeshComponent *pOther = (MeshComponent *)other;
	
	vertexes.clear();
	vertexes.swap(pOther->vertexes);
	indices.clear();
	indices.swap(pOther->indices);
}

bool MeshComponent::LoadFromFile(const char *fileName)
{
	FileName = fileName;

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

void MeshComponent::FreeResources()
{
	vertexes.clear();
	indices.clear();
	FileName = nullptr;

	if (this)
		delete this;
}

QString MeshComponent::ToString() const
{
	return "Mesh Component";
}

ComponentType MeshComponent::GetType() const
{
	return ComponentType_MESH;
}
