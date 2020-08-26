#include <draw.h>>



void DRAW::start(){
glBindVertexArray(VAO.VAO);
(this->*draw_type)(VAO.indices_size);
glBindVertexArray(0);
};

DRAW::DRAW(Buffer_VAO vao):VAO(vao){
    if(VAO.indices_size){
    draw_type=&DRAW::DrawElements;
    };
}


void DRAW::DrawArrays(GLint &indices_size){
 glDrawArrays(GL_TRIANGLES,0,GL_UNSIGNED_INT);
};


void DRAW::DrawElements(GLint &indices_size){
  glDrawElements(GL_TRIANGLES, static_cast<GLint>(indices_size), GL_UNSIGNED_INT, nullptr);
};


DRAW & DRAW::operator=(const DRAW & draw){
    this->VAO=draw.VAO;
    if(draw.VAO.indices_size){
    this->draw_type=&DRAW::DrawElements;
    };
    return *this;
}
DRAW & DRAW::operator=(DRAW && draw){
    this->VAO=std::move(draw.VAO);
    if(draw.VAO.indices_size){
    this->draw_type=&DRAW::DrawElements;
    };
    return *this;
}
DRAW::DRAW(DRAW && draw){
    this->VAO=std::move(draw.VAO);
    if(draw.VAO.indices_size){
    this->draw_type=&DRAW::DrawElements;
    };
}
DRAW::DRAW(const DRAW & draw){
    this->VAO=draw.VAO;
    if(draw.VAO.indices_size){
    this->draw_type=&DRAW::DrawElements;
    };
}
