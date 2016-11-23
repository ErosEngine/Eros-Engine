#include "ShapeData.h"
#include <QDebug>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>



Mesh CreateCube()
{
    Mesh shape;
    
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

Mesh CreatePlane()
{
    return Mesh();
}

Mesh CreateQuad()
{
    return Mesh();
}

Mesh CreatePyramid()
{
    return Mesh();
}

Mesh CreateSphere()
{
    return Mesh();
}

void ProcessAssimpTexture(aiMaterial *mat, aiTextureType type, int tType, Model *base)
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

void ProcessAssimpMesh(aiMesh *pMesh, const aiScene *pScene, Model *pBase)
{
    for (uint i = 0; i < pMesh->mNumVertices; ++i)
    {
        Vertex vert;
        vert.position.x = pMesh->mVertices[i].x;
        vert.position.y = pMesh->mVertices[i].y;
        vert.position.z = pMesh->mVertices[i].z;
        vert.normal.x = pMesh->mNormals[i].x;
        vert.normal.y = pMesh->mNormals[i].y;
        vert.normal.z = pMesh->mNormals[i].z;
        
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

void ProcessAssimpNodes(aiNode *pNode, const aiScene *cpScene, Model *pBase)
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

Model *LoadMeshFromFile(const char *fileName)
{
    Model *returnVal = new Model;
    Assimp::Importer importer;
    const aiScene *pscene = importer.ReadFile(fileName, aiProcess_Triangulate | aiProcess_FlipUVs);
    
    if(!pscene || pscene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !pscene->mRootNode) 
    {
        qDebug() << "Failed to load mesh: Assimp error: " << importer.GetErrorString();
        return nullptr;
    }
    
    QString returnValDir = fileName;
    returnVal->fileName = returnValDir;
    
    ProcessAssimpNodes(pscene->mRootNode, pscene, returnVal);
    
    return returnVal;
}
