#include <model.h>
#include <iostream>
#include <string>
#include <vector>
#include <glm/vec3.hpp> // glm::vec3
#include <glm/gtc/type_ptr.hpp>


void   Model::VAO_inzilization(std::vector<Vertex> vertices, std::vector<unsigned int> indices){
VAO=Buffer_VAO{vertices,indices};
draw=Display(VAO);
};


void   Model::Draw(){
shader.use();
 //анимация
 for(auto &T:textures){
     if(T.Texture::type_image==D21A){
 T.new_cicl();
 T.new_fream();
     }
};
 //присоединение текстур и анимации
 int i=0;
 std::string nomer;

 std::string name("");
 std::string name1("ourColor");
 for(auto &T:textures){
    switch (T.Texture::type_texture) {
        case Map_diffusion  : name="ourTexture";            break;
        case Map_normals    : name="ourTexture_normal";     break;
        case Map_reflection : name="ourTexture_reflection"; break;
        case Map_height     : name="ourTexture_height";     break;
        case Map_cub        : name="skybox";               break;
  }


 glActiveTexture(static_cast<unsigned int>(GL_TEXTURE0+i));
 nomer=std::to_string(i);
 shader.Uniform((name+nomer).c_str(), i);
 if(T.Texture::type_image==D21 || T.Texture::type_image==D21A){
     glBindTexture(GL_TEXTURE_2D,T.texture());
 };
if(T.Texture::type_image==D26 || T.Texture::type_image==D26A){
    glBindTexture(GL_TEXTURE_CUBE_MAP,T.texture());
};

 if(T.Texture::type_image==D21){
   shader.Uniform((name1+nomer).c_str(),0.0f, 0.0f,1.0f,1.0f);
 }else{
   shader.Uniform((name1+nomer).c_str(),T.result[0], T.result[1],T.result[2],T.result[3]);
 }
 i++;

}

 //присоединение движения (GLuint program,  name);

model=position.pos();
shader.Uniform<4,4>("model", 1, GL_FALSE, glm::value_ptr(model));
shader.Uniform<4,4>("projection", 1, GL_FALSE, glm::value_ptr(*projection));
shader.Uniform<4,4>("view", 1, GL_FALSE, glm::value_ptr(*view));
//
    draw.start();

    glActiveTexture(GL_TEXTURE0);
    };



void   Model::DrawIndef(){
shaderIndef.use();
model=position.pos();

shaderIndef.Uniform<4,4>("model", 1, GL_FALSE, glm::value_ptr(model));
shaderIndef.Uniform("colorIndef",id.r/100.0f,id.g/100.0f,id.b/100.0f,1.0f);
shaderIndef.Uniform<4,4>("projection", 1, GL_FALSE, glm::value_ptr(*projection));
shaderIndef.Uniform<4,4>("view", 1, GL_FALSE, glm::value_ptr(*view));

draw.start();
    };

void   Model::DrawMaterial(){
shader.use();
 //присоединение движения (GLuint program,  name);

model=position.pos();
shader.Uniform<4,4>("projection", 1, GL_FALSE, glm::value_ptr(*projection));
shader.Uniform<4,4>("view", 1, GL_FALSE, glm::value_ptr(*view));
shader.Uniform<4,4>("model", 1, GL_FALSE, glm::value_ptr(model));

shader.Uniform("material.diffuse",material.diffuse.r,material.diffuse.g,material.diffuse.b);
shader.Uniform("material.ambient",material.ambient.r,material.ambient.g,material.ambient.b);
shader.Uniform("material.specular",material.specular.r,material.specular.g,material.specular.b);
shader.Uniform("material.shininess",material.shininess);

shader.Uniform("light.direction", -1.0f, -1.0f, -1.0f);

 // light properties
shader.Uniform("light.ambient", 0.02f, 0.02f, 0.02f);
shader.Uniform("light.diffuse", 0.5f, 0.5f, 0.5f);
shader.Uniform("light.specular", 1.0f, 1.0f, 1.0f);

    draw.start();


};












int Model::countr{0};
int Model::countg{0};
int Model::countb{0};

/*
        std::cout<<"####################################"<<std::endl;
        std::cout<<"|"<<model[0][0]<<"|"<<model[0][1]<<"|"<<model[0][2]<<"|"<<model[0][3]<<"|"<<std::endl;
        std::cout<<"|"<<model[1][0]<<"|"<<model[1][1]<<"|"<<model[1][2]<<"|"<<model[1][3]<<"|"<<std::endl;
        std::cout<<"|"<<model[2][0]<<"|"<<model[2][1]<<"|"<<model[2][2]<<"|"<<model[2][3]<<"|"<<std::endl;
        std::cout<<"|"<<model[3][0]<<"|"<<model[3][1]<<"|"<<model[3][2]<<"|"<<model[3][3]<<"|"<<std::endl;
        std::cout<<"#####################################"<<std::endl;
        */



