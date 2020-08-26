#include <buffer_vao.h>
#include <iostream>

Buffer_VAO::Buffer_VAO(std::vector<Vertex> vertices, std::vector<unsigned int> indices){



            glGenVertexArrays(1, &VAO);
            glGenBuffers(1, &VBO);
            glGenBuffers(1, &EBO);

        glBindVertexArray(VAO);
            // load data into vertex buffers
            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            // A great thing about structs is that their memory layout is sequential for all its items.
            // The effect is that we can simply pass a pointer to the struct and it translates perfectly to a glm::vec3/2 array which
            // again translates to 3/2 floats which translates to a byte array.
            glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(vertices.size() * sizeof(Vertex)), &vertices[0], GL_STATIC_DRAW);

            if(indices.size()){
                std::cout<<"EBO"<<std::endl;
            indices_size=indices.size();
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, static_cast<GLsizeiptr>(indices.size() * sizeof(unsigned int)), &indices[0], GL_STATIC_DRAW);
            }else {
              std::cout<<"aaamm"<<std::endl;
              indices_size=0;
            }
            // set the vertex attribute pointers
            // vertex Positions

            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),reinterpret_cast<void*>(offsetof(Vertex, Position)) );
      //      // vertex normals
              glEnableVertexAttribArray(1);
              glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, Normal)));
            // vertex texture coords
            glEnableVertexAttribArray(2);
            glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),reinterpret_cast<void*>(offsetof(Vertex, TexCoords1)));
            // vertex tangent
      //      glEnableVertexAttribArray(3);
      //      glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, Tangent)));
      //      // vertex bitangent
      //      glEnableVertexAttribArray(4);
      //      glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, Bitangent)));

      glBindVertexArray(0);
      std::cout<<"VAO:"<<VAO<<std::endl;
}

Buffer_VAO::Buffer_VAO(){

    std::vector<GLfloat> vertices{
            // Позиции         // Текстурные координаты
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };

std::vector<Vertex> vert;
volatile int i=1;
for(auto& R:vertices){

    Vertex T;


    switch (i) {
    case 1:T.Position.x=R ;break;
    case 2:T.Position.y=R ;break;
    case 3:T.Position.z=R ;break;
    case 4:T.TexCoords1.x=R;break;
    case 5:T.TexCoords1.y=R;break;
        }
    i++;
    if(i==6){
    i=1;
    vert.push_back(T);
    }

}



indices_size=0;
glGenVertexArrays(1, &VAO);
glGenBuffers(1, &VBO);


glBindVertexArray(VAO);
glBindBuffer(GL_ARRAY_BUFFER, VBO);
glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(vert.size() * sizeof(Vertex)), &vert[0], GL_STATIC_DRAW);
glEnableVertexAttribArray(0);
glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),reinterpret_cast<void*>(offsetof(Vertex, Position)) );
glEnableVertexAttribArray(2);
glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),reinterpret_cast<void*>(offsetof(Vertex, TexCoords1)));
glBindVertexArray(0);
std::cout<<"VAO:"<<VAO<<std::endl;
}

Buffer_VAO::Buffer_VAO(Buffer_VAO  && r){
    this->VAO=std::move(r.VAO);
    this->indices_size=std::move(r.indices_size);
    this->EBO=std::move(r.EBO);
    this->VBO=std::move(r.VBO);
}

Buffer_VAO & Buffer_VAO::operator=(const Buffer_VAO  && r){
    this->VAO=std::move(r.VAO);
    this->indices_size=std::move(r.indices_size);
    this->EBO=std::move(r.EBO);
    this->VBO=std::move(r.VBO);
    return *this;
}
Buffer_VAO & line_VAO(){
    std::vector<GLfloat> vertices{
            // Позиции         // Текстурные координаты
            0.0f,   0.0f,  0.0f,
            0.0f,   1.0f,  0.0f,

    };
    std::vector<Vertex> vert;
    volatile int i=1;
    for(auto& R:vertices){

    Vertex T;
    switch (i) {
    case 1:T.Position.x=R ;break;
    case 2:T.Position.y=R ;break;
    case 3:T.Position.z=R ;break;
        }
    i++;
    if(i==4){
    i=1;
    vert.push_back(T);
    }

    }
    std::vector<unsigned int> idddd;

    Buffer_VAO *VAO_p=new Buffer_VAO(vert,idddd);

    return *VAO_p;

};

Buffer_VAO & plate_VAO(){
    std::vector<GLfloat> vertices{
            // Позиции         // Текстурные координаты

        -0.5f, -0.5f,  0.0f,  0.0f, 0.0f,
         0.5f, -0.5f,  0.0f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.0f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.0f,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.0f,  0.0f, 0.0f,
    };

    std::vector<Vertex> vert;
    volatile int i=1;
    for(auto& R:vertices){

    Vertex T;


    switch (i) {
    case 1:T.Position.x=R ;break;
    case 2:T.Position.y=R ;break;
    case 3:T.Position.z=R ;break;
    case 4:T.TexCoords1.x=R;break;
    case 5:T.TexCoords1.y=R;break;
        }
    i++;
    if(i==6){
    i=1;
    vert.push_back(T);
    }

    }
    std::vector<unsigned int> idddd;

    Buffer_VAO *VAO_p=new Buffer_VAO(vert,idddd);

    return *VAO_p;

};

Buffer_VAO & skybox_VAO(){
    std::vector<GLfloat> vertices{
            // Позиции         // Текстурные координаты
       -1.0f,  1.0f, -1.0f,
       -1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,
        1.0f,  1.0f, -1.0f,
       -1.0f,  1.0f, -1.0f,

       -1.0f, -1.0f,  1.0f,
       -1.0f, -1.0f, -1.0f,
       -1.0f,  1.0f, -1.0f,
       -1.0f,  1.0f, -1.0f,
       -1.0f,  1.0f,  1.0f,
       -1.0f, -1.0f,  1.0f,

        1.0f, -1.0f, -1.0f,
        1.0f, -1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,

       -1.0f, -1.0f,  1.0f,
       -1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f, -1.0f,  1.0f,
       -1.0f, -1.0f,  1.0f,

       -1.0f,  1.0f, -1.0f,
        1.0f,  1.0f, -1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
       -1.0f,  1.0f,  1.0f,
       -1.0f,  1.0f, -1.0f,

       -1.0f, -1.0f, -1.0f,
       -1.0f, -1.0f,  1.0f,
        1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,
       -1.0f, -1.0f,  1.0f,
        1.0f, -1.0f,  1.0f
    };

    std::vector<Vertex> vert;
    volatile int i=1;
    for(auto& R:vertices){

    Vertex T;


    switch (i) {
    case 1:T.Position.x=R ;break;
    case 2:T.Position.y=R ;break;
    case 3:T.Position.z=R ;break;
        }
    i++;
    if(i==4){
    i=1;
    vert.push_back(T);
    }

    }
    std::vector<unsigned int> idddd;

    Buffer_VAO *VAO_p=new Buffer_VAO(vert,idddd);

    return *VAO_p;

};


