#include <display.h>
#include <iostream>


void Display::start(){
glBindVertexArray(VAO.VAO);
(this->*draw_type)(VAO.indices_size);
glBindVertexArray(0);
};

Display::Display(Buffer_VAO &vao):VAO(vao){
    std::cout<<"new desplay"<<std::endl;
    if(VAO.indices_size){
    draw_type=&Display::DrawElements;
    };
}
void Display::DrawArrays_line(GLint &indices_size){
 glDrawArrays(GL_LINE_STRIP,0,cout_line);///
};

void Display::DrawArrays(GLint &indices_size){
 glDrawArrays(GL_TRIANGLES,0,GL_UNSIGNED_INT);
};


void Display::DrawElements(GLint &indices_size){
  glDrawElements(GL_TRIANGLES, static_cast<GLint>(indices_size), GL_UNSIGNED_INT, nullptr);
};

void Display::DrawArraysInstanced(GLint &indices_size){
 glDrawArraysInstanced(GL_TRIANGLES,0,GL_UNSIGNED_INT,instance);
};


void Display::DrawElementsInstanced(GLint &indices_size){
  glDrawElementsInstanced(GL_TRIANGLES, static_cast<GLint>(indices_size), GL_UNSIGNED_INT, nullptr,instance);
};


void Display::Instanced_on(){
    instan=true;
    draw_type=&Display::DrawArraysInstanced;
    std::cout<<"Instanced_on()"<<std::endl;
    if(VAO.indices_size){
    draw_type=&Display::DrawElementsInstanced;
    };
};
void Display::on_line(){
    line=true;
    draw_type=&Display::DrawArrays_line;
    std::cout<<"Instanced_on_line()"<<std::endl;
};



Display & Display::operator=(const Display & display){
    this->VAO=display.VAO;
    if(display.VAO.indices_size){
    this->draw_type=&Display::DrawElements;
    };
    if(display.instan){
        this->Instanced_on();
    }
    if(display.line){
        this->on_line();
    }

    return *this;
}
Display & Display::operator=(Display && display){
    this->VAO=std::move(display.VAO);
    if(display.VAO.indices_size){
    this->draw_type=&Display::DrawElements;
    };
    if(display.instan){
        this->Instanced_on();
    }
    if(display.line){
        this->on_line();
    }
    return *this;
}
Display::Display(Display && display){
    this->VAO=std::move(display.VAO);
    if(display.VAO.indices_size){
    this->draw_type=&Display::DrawElements;
    };
    if(display.instan){
        this->Instanced_on();
    }
    if(display.line){
        this->on_line();
    }
}
Display::Display(const Display & display){
    this->VAO=display.VAO;
    if(display.VAO.indices_size){
    this->draw_type=&Display::DrawElements;
    };
    if(display.instan){
        this->Instanced_on();
    }
    if(display.line){
        this->on_line();
    }
}
