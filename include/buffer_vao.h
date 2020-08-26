#ifndef VBO_H
#define VBO_H
#include<GL/glew.h>
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec2.hpp>
#include <vector>

struct Vertex {
    // position
    glm::vec3 Position;
    // normal
    glm::vec3 Normal;
    // texCoords
    glm::vec2 TexCoords1;
    // tangent
    glm::vec3 Tangent;
    // bitangent
    glm::vec3 Bitangent;
    Vertex(glm::vec3 Position_,glm::vec3 Normal_,glm::vec2 TexCoords1_,glm::vec3 Tangent_,glm::vec3 Bitangent_)
        :Position(Position_),Normal(Normal_),TexCoords1(TexCoords1_),Tangent(Tangent_),Bitangent(Bitangent_){};
    Vertex(){};
};

class Buffer_VAO{
public:
GLuint VAO{0};
GLint indices_size{0};
Buffer_VAO(std::vector<Vertex> vertices, std::vector<unsigned int> indices);
///defolt cub
Buffer_VAO();

Buffer_VAO(Buffer_VAO &&r);
Buffer_VAO & operator=(const Buffer_VAO  && r);

Buffer_VAO(Buffer_VAO &r)=default;
Buffer_VAO & operator=( const Buffer_VAO  & r)=default;
private:
GLuint EBO{0};
GLuint VBO{0};


};

Buffer_VAO & line_VAO();
Buffer_VAO & plate_VAO();
Buffer_VAO & skybox_VAO();
#endif // VBO_H
