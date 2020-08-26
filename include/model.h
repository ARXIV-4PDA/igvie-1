#ifndef MODEL_H
#define MODEL_H
#include <position.h>
#include <vector>
#include <glm/vec3.hpp> // glm::vec3
#include <animation.h>
#include<shader.h>
#include <buffer_vao.h>
#include <display.h>

struct Pixel{
    int r=0;
    int g=0;
    int b=0;

};

struct Material{

    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
    float shininess;
};

class Model{

public:
    Shader shader;
    Shader shaderIndef;
    Pixel id;
    static int countr;
    static int countg;
    static int countb;

    Material material;
    std::vector<Animation> textures;

    glm::mat4 model{1.0f};
    Position  position;
    glm::mat4 * projection;
    glm::mat4 * view;
    Buffer_VAO VAO;
    bool Textur_on_or_off=false;

    Display draw;

    Model(Shader shad,Buffer_VAO VAO_,glm::mat4 *proj,glm::mat4 *viw,Position pos):shader(shad),VAO(VAO_),projection(proj),view(viw),position(pos),draw(VAO_),shaderIndef(shad){

           countr++;
           if(countr==100){
            countg++;
            if(countg==100){
             countb++;
             countg=0;
            }
            countr=0;
           }


           id.r=countr;
           id.g=countg;
           id.b=countb;
    std::cout<<"new model:"<<std::endl;
    std::cout<<"("<<id.r<<","<<id.g<<","<<id.b<<")"<<std::endl;
    };
    void  VAO_inzilization(std::vector<Vertex> vertices, std::vector<unsigned int> indices);
    void Draw();
    void DrawMaterial();
    void DrawIndef();

};



#endif // MODEL_H

