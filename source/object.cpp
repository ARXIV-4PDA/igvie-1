#include "object.h"

#include <model.h>
#define M3D_NOIMPORTER
#define ASSIMP_BUILD_NO_C4D_IMPORTER
#include<assimp/scene.h>
#include<assimp/postprocess.h>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <iostream>
#include <assimp/Importer.hpp>
#include <vector>
#include <string>

Object::Object(std::string path,Shader shad,glm::mat4 *proj,glm::mat4 *viw,Position pos):shader(shad),projection(proj),view(viw),position_object(pos)
{
Assimp::Importer import;
this->scene =import.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);
directory = path.substr(0, path.find_last_of('/'));
directory+="/";
std::cout<<"directory:"<<directory<<std::endl;
processNode(this->scene->mRootNode, this->scene);
};

void Object::DraW(){

    for(auto &T:this->models){
    T.Draw();
    }
}
void Object::processNode(aiNode *node, const aiScene *scene)
{
    // process each mesh located at the current node
    for(unsigned int i = 0; i < node->mNumMeshes; i++)
    {

        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];

        std::vector<Vertex> vertices;
        Vertex T(glm::vec3(0.0f,0.0f,0.0f),
                 glm::vec3(0.0f,0.0f,0.0f),
                 glm::vec2(0.0f,0.0f),
                 glm::vec3(0.0f,0.0f,0.0f),
                 glm::vec3(0.0f,0.0f,0.0f));

        std::cout<<"i:"<<i<<std::endl;
        std::vector<unsigned int> index;
        for(unsigned int i = 0; i < mesh->mNumVertices; i++){

            if(mesh->mVertices!=nullptr){
            T.Position.x=std::move(mesh->mVertices[i].x);
            T.Position.y=std::move(mesh->mVertices[i].y);
            T.Position.z=std::move(mesh->mVertices[i].z);
            };

            if(mesh->mNormals!=nullptr){
                T.Normal.x=std::move(mesh->mNormals[i].x);
                T.Normal.y=std::move(mesh->mNormals[i].y);
                T.Normal.z=std::move(mesh->mNormals[i].z);
                };

            if(mesh->mTextureCoords[0]!=nullptr){
            T.TexCoords1.x=std::move(mesh->mTextureCoords[0][i].x);
            T.TexCoords1.y=std::move(mesh->mTextureCoords[0][i].y);
            }else {
             T.TexCoords1=std::move(glm::vec2(0.0f, 0.0f));
            };


            if(mesh->mTangents!=nullptr){
            T.Tangent.x=std::move(mesh->mTangents[i].x);
            T.Tangent.y=std::move(mesh->mTangents[i].y);
            T.Tangent.z=std::move(mesh->mTangents[i].z);
            };

            if(mesh->mBitangents!=nullptr){
            T.Bitangent.x=std::move(mesh->mBitangents[i].x);
            T.Bitangent.y=std::move(mesh->mBitangents[i].y);
            T.Bitangent.z=std::move(mesh->mBitangents[i].z);
            };
            vertices.push_back(T);
              };




        for(unsigned int i = 0; i < mesh->mNumFaces; i++)
                {
                    aiFace face = mesh->mFaces[i];
                    // retrieve all indices of the face and store them in the indices vector
                    for(unsigned int j = 0; j < face.mNumIndices; j++)

                        index.push_back(face.mIndices[j]);
                }





        Buffer_VAO VAO_(vertices,index);
        models.emplace_back(this->shader,VAO_,this->projection,this->view,this->position_object);
        models.back().position.conection_object(&position_object);


        aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
                // we assume a convention for sampler names in the shaders. Each diffuse texture should be named
                // as 'texture_diffuseN' where N is a sequential number ranging from 1 to MAX_SAMPLER_NUMBER.
                // Same applies to other texture as the following list summarizes:
                // diffuse: texture_diffuseN
                // specular: texture_specularN
                // normal: texture_normalN



        Material mat;
        aiColor3D color;
        material->Get(AI_MATKEY_COLOR_DIFFUSE,color);
        mat.diffuse.r=color.r;
        mat.diffuse.g=color.g;
        mat.diffuse.b=color.b;
        material->Get(AI_MATKEY_COLOR_AMBIENT,color);
        mat.ambient.r=color.r;
        mat.ambient.g=color.g;
        mat.ambient.b=color.b;
        material->Get(AI_MATKEY_COLOR_SPECULAR,color);
        mat.specular.r=color.r;
        mat.specular.g=color.g;
        mat.specular.b=color.b;
        float spec;
        material->Get(AI_MATKEY_SHININESS,spec);
        mat.shininess=spec;
        models.back().material=mat;
        std::cout<<spec<<"[{"<< models.back().textures.size()<<std::endl;



             aiTextureType type[4]={aiTextureType_DIFFUSE,
                                    aiTextureType_NORMALS,
                                    aiTextureType_SPECULAR,
                                    aiTextureType_HEIGHT,
                                                            };
            std::cout<<node->mNumChildren<<std::endl;
                for (int j=0;j<4;j++) {

                    for(unsigned int i = 0; i < material->GetTextureCount(type[j]); i++)
                            {
                                aiString str;
                                material->GetTexture(type[j], i, &str);
                                  std::cout<<'['<<directory+str.C_Str()<<"]type:"<<type[j]<<std::endl;
//                                switch (j) {
//                                    case Map_diffusion  : name="ourTexture";            break;
//                                    case Map_normals    : name="ourTexture_normal";     break;
//                                    case Map_reflection : name="ourTexture_reflection"; break;
//                                    case Map_height     : name="ourTexture_reflection"; break;
//                              }
                                std::string g=str.C_Str();

                                if(g!="None"){
                                models.back().textures.emplace_back(directory+str.C_Str(),D21A,j,1,1,1,-1);
                                models.back().Textur_on_or_off=true;
                                std::cout<<"lll:"<<g<<std::endl;
                                }
                                }
                            }

                if(!(models.back().Textur_on_or_off)){
                    models.back().shader=shaderMaterial;
                    std::cout<<"TTTTTTTTTTTTTTTTTTTTTTdddda"<<std::endl;
                }


    }



    // after we've processed all of the meshes (if any) we then recursively process each of the children nodes
    for(unsigned int i = 0; i < node->mNumChildren; i++)
    {
        processNode(node->mChildren[i], scene);
    }

}




