#ifndef OBJECT_H
#define OBJECT_H
#include <model.h>
#include<assimp/scene.h>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <vector>
#include <string>
class Object
{
Shader shader;
Shader shaderMaterial=shader;
const aiScene * scene;
public:
  std::vector<Model> models;
  glm::mat4 * projection;
  glm::mat4 * view;
  Position position_object;
  std::string directory;


Object(std::string path,Shader shad,glm::mat4 *proj,glm::mat4 *viw,Position pos);
void DraW();
void processNode(aiNode *node, const aiScene *scene);
void setShaderId(Shader id){
    for(auto &T:models){
        T.shaderIndef=id;
    }
};

void SetShaderMaterial(Shader shader_){
    shaderMaterial=shader_;
    for(auto &T:models){

    if(!(T.Textur_on_or_off)){
        T.shader=shaderMaterial;
        std::cout<<"TTTTTTmaterialTTTTTTTTTdddda"<<std::endl;
        }
    }
}


void DraWIndeF(){
    for(auto &T:models){
        T.DrawIndef();
    }
};
void DraWMateriaL(){
    for(auto &T:models){
        T.DrawMaterial();
    }    
};


void DraWMylt(){
    for(auto &T:models){
        if(!(T.Textur_on_or_off)){
         T.DrawMaterial();
       //  std::cout<<"ddddddddddddddddddddddddddda"<<std::endl;
        }else{
         T.Draw();
        }
    }
};




};
#endif // OBJECT_H
