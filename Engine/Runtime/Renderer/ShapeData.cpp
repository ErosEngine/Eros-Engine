#include "ShapeData.h"
#include <QDebug>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <linux/kernel.h>



ShapeData CreateCube()
{
    ShapeData shape;
    
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

ShapeData CreatePlane()
{
    return ShapeData();
}

ShapeData CreateQuad()
{
    return ShapeData();
}

ShapeData CreatePyramid()
{
    return ShapeData();
}

ShapeData CreateSphere()
{
    return ShapeData();
}

void ProcessAssimpTexture(aiMaterial *mat, aiTextureType type, int tType, Mesh *base)
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
            texName.append(base->directory.toLatin1().constData());
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

void ProcessAssimpMesh(aiMesh *mesh, const aiScene *scene, Mesh *base)
{
    for (uint i = 0; i < mesh->mNumVertices; ++i)
    {
        Vertex vert;
        vert.position.x = mesh->mVertices[i].x;
        vert.position.y = mesh->mVertices[i].y;
        vert.position.z = mesh->mVertices[i].z;
        vert.normal.x = mesh->mNormals[i].x;
        vert.normal.y = mesh->mNormals[i].y;
        vert.normal.z = mesh->mNormals[i].z;
        
        if (mesh->mTextureCoords[0])
        {
            vert.texCoords.x = mesh->mTextureCoords[0][i].x;
            vert.texCoords.y = mesh->mTextureCoords[0][i].y;
        }
        else
        {
            vert.texCoords.x = 0.0f; 
            vert.texCoords.y = 0.0f;
        }
        
        base->vertexes.push_back(vert);
    }
    
    for (uint i = 0; i < mesh->mNumFaces; ++i)
    {
        aiFace face = mesh->mFaces[i];
        for (uint j = 0; j < face.mNumIndices; ++j)
        {
            base->indices.push_back(face.mIndices[j]);
        }
    }
    
    if (mesh->mMaterialIndex >= 0)
    {
        aiMaterial *material = scene->mMaterials[mesh->mMaterialIndex];
        ProcessAssimpTexture(material, aiTextureType_DIFFUSE, DiffuseTexture, base);
        ProcessAssimpTexture(material, aiTextureType_SPECULAR, SpecularTexture, base);
    }
}

void ProcessAssimpNodes(aiNode *node, const aiScene *scene, Mesh *base)
{
    for (uint i = 0; i < node->mNumMeshes; ++i)
    {
        aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
        ProcessAssimpMesh(mesh, scene, base);
    }
    
    for (uint i = 0; i < node->mNumChildren; ++i)
    {
        ProcessAssimpNodes(node->mChildren[i], scene, base);
    }
}

Mesh *LoadMeshFromFile(const char *fileName)
{
    Mesh *returnVal = new Mesh;
    Assimp::Importer importer;
    const aiScene *pscene = importer.ReadFile(fileName, aiProcess_Triangulate | aiProcess_FlipUVs);
    
    if(!pscene || pscene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !pscene->mRootNode) 
    {
        qDebug() << "Failed to load mesh: Assimp error: " << importer.GetErrorString();
        return nullptr;
    }
    
    QString returnValDir = fileName;
    returnValDir.remove(returnValDir.lastIndexOf("/") + 1, returnValDir.size());
    returnVal->directory = returnValDir;
    
    ProcessAssimpNodes(pscene->mRootNode, pscene, returnVal);
    
    return returnVal;
}
