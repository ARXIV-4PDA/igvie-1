#ifndef TEXTURE_H
#define TEXTURE_H
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <glm/vec3.hpp> // glm::vec3
#include<GL/glew.h>

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_STATIC
#include <stb_image.h>
#include <GL/gl.h>


enum TYPE_IMAGE {
     /**
     2D текстура,одна
     */
     D21,
     /**
     2D текстура,шесть штук
     */
    D26,
    /**
    2D текстура,одна,с анимацией
    */
   D21A,
    /**
    2D текстура,шесть штук ,с анимацией
    */
    D26A,
    /**

    */
    D2
       };
enum TYPE_TEXTURE {Map_diffusion,Map_normals, Map_reflection, Map_height,Map_cub,Map_font};


class Texture{
GLuint Textur;
public:
int  type_image;
int  type_texture;
bool GenerateMipmap=true;
virtual GLuint texture(){return Textur;};
Texture(std::string path, int type_image__,int type_texture__):type_image(type_image__),type_texture(type_texture__){
if(((type_image==D21) ||( type_image==D21A) ) && type_texture==Map_diffusion){
glGenTextures(1,&Textur);
glBindTexture(GL_TEXTURE_2D,Textur);
// Set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT (usually basic wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // Set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // Load image, create texture and generate mipmaps
    int widths1=0;
    int heights1=0;
    int n=0;
    unsigned char* image = stbi_load(path.data(), &widths1, &heights1,&n,STBI_rgb_alpha );
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA , widths1, heights1, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(image);
glBindTexture(GL_TEXTURE_2D, 0);
};
};




Texture(std::vector<std::string> path, int type_image__,int type_texture__):type_image(type_image__),type_texture(type_texture__){
if(((type_image==D26) ||( type_image==D26A) ) && type_texture==Map_cub){
    glGenTextures(1,&Textur);
    glBindTexture(GL_TEXTURE_CUBE_MAP, Textur);
    int widths1=0;
    int heights1=0;
    int n=0;
    int i=0;
    for (auto &T:path){
        unsigned char* image = stbi_load(T.data(), &widths1, &heights1,&n,STBI_rgb_alpha );
        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGBA , widths1, heights1, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
        std::cout<<*image<<":image:"<<i<<"widths1:"<<widths1<<"heights1:"<<heights1<<":path_picters:"<<T.data()<<std::endl;
        stbi_image_free(image);
        i++;
        }

    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
    glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
    };
};

virtual void new_cicl(){
};

};
#undef STB_IMAGE_IMPLEMENTATION
#endif // TEXTURE_H

