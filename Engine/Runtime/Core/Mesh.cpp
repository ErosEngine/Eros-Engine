#include "Mesh.h"
#include <QDebug>
#include <QFile>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>



MeshComponent CreateCube()
{
    MeshComponent shape;
    
    // Note(kiecker): Hackey right now, but I will fix it later
    // This is for reference
    /* position              normals                
     * -0.5f,  0.5f, -0.5f,  0.0f,  0.0f,  0.0f,
     *  0.5f,  0.5f, -0.5f,  0.0f,  0.0f,  0.0f,
     * -0.5f, -0.5f, -0.5f,  0.0f,  0.0f,  0.0f,
     *  0.5f, -0.5f, -0.5f,  0.0f,  0.0f,  0.0f,
     * -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  0.0f,
     *  0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  0.0f,
     *  0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  0.0f,
     * -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  0.0f
     */
    
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


void ProcessAssimpTexture(aiMaterial *mat, aiTextureType type, int tType, MeshComponent *base)
{
    for (uint i = 0; i < mat->GetTextureCount(type); ++i)
    {
        aiString str;
        mat->GetTexture(type, i, &str);
        bool skip = false;
        for (uint t = 0; t < base->textures.size(); t++)
        {
            if (base->textures[t].fileName == str.C_Str())
            {
                base->textures.push_back(base->textures[t]);
                skip = true;
                break;
            }
        }
        if (!skip)
        {
            std::string texName;
            texName.append(base->fileName.toLatin1().constData());
            texName.append(str.C_Str());
            Texture texture;
            texture.type = tType;
            if (texture.loadFromFile(texName.c_str()))
			{
                base->textures.push_back(texture);
            }
        }
    }
}

void ProcessAssimpMesh(aiMesh *pMesh, const aiScene *pScene, MeshComponent *pBase)
{
    for (uint i = 0; i < pMesh->mNumVertices; ++i)
    {
        Vertex vert;
        vert.position.x = pMesh->mVertices[i].x;
        vert.position.y = pMesh->mVertices[i].y;
        vert.position.z = pMesh->mVertices[i].z;
        
        if (pMesh->mNormals)
        {
            vert.normal.x = pMesh->mNormals[i].x;
            vert.normal.y = pMesh->mNormals[i].y;
            vert.normal.z = pMesh->mNormals[i].z;
        }
        else
        {
            vert.normal.x = 1.0f;
            vert.normal.y = 1.0f;
            vert.normal.z = 1.0f;
        }
        
        if (pMesh->mTextureCoords[0])
        {
            vert.texCoords.x = pMesh->mTextureCoords[0][i].x;
            vert.texCoords.y = pMesh->mTextureCoords[0][i].y;
        }
        else
        {
            vert.texCoords.x = 0.0f; 
            vert.texCoords.y = 0.0f;
        }
        
        pBase->vertexes.push_back(vert);
    }
    
    for (uint i = 0; i < pMesh->mNumFaces; ++i)
    {
        aiFace face = pMesh->mFaces[i];
        for (uint j = 0; j < face.mNumIndices; ++j)
        {
            pBase->indices.push_back(face.mIndices[j]);
        }
    }
    
    if (pMesh->mMaterialIndex >= 0)
    {
        aiMaterial *material = pScene->mMaterials[pMesh->mMaterialIndex];
        ProcessAssimpTexture(material, aiTextureType_DIFFUSE, DiffuseTexture, pBase);
        ProcessAssimpTexture(material, aiTextureType_SPECULAR, SpecularTexture, pBase);
    }
}

void ProcessAssimpNodes(aiNode *pNode, const aiScene *cpScene, MeshComponent *pBase)
{
	for (uint i = 0; i < pNode->mNumMeshes; ++i)		 
    {		
        aiMesh *mesh = cpScene->mMeshes[pNode->mMeshes[i]];		 
        ProcessAssimpMesh(mesh, cpScene, pBase);		
    }		
    		
    for (uint i = 0; i < pNode->mNumChildren; ++i)		
    {		
        ProcessAssimpNodes(pNode->mChildren[i], cpScene, pBase);		
    }
}

// Core model loading function
bool MeshComponent::loadFromFile(const char *fileName)
{
    Assimp::Importer importer;
	
	const aiScene *pScene = importer.ReadFile(fileName, aiProcess_Triangulate | aiProcess_FlipUVs);
    if(!pScene || pScene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !pScene->mRootNode) 
    {
        qDebug() << "Failed to load mesh: Assimp error: " << importer.GetErrorString();
        return false;
	}
    
    ProcessAssimpNodes(pScene->mRootNode, pScene, this);
	
	return true;
}

void MeshComponent::fromExisting(const IComponent *other)
{
	assert(other != nullptr);
	MeshComponent *pOther = (MeshComponent *)(other);
	
	this->indices.clear();
	this->vertexes.clear();
	this->textures.clear();
	
	this->indices = pOther->indices;
	this->vertexes = pOther->vertexes;
	this->textures = pOther->textures;
	this->fileName = pOther->fileName;
}
