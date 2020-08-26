#ifndef DISPLAY_H
#define DISPLAY_H



#include <buffer_vao.h>
#include <GL/glew.h>



class Display{

private:
    void (Display::*draw_type)(GLint &){&Display::DrawArrays};
    Buffer_VAO VAO;
    bool instan=false;
    bool line=false;
public:
void  start();
void Instanced_on();
void on_line();
void DrawArrays(GLint &indices_size);
void DrawElements(GLint &indices_size);
void DrawArraysInstanced(GLint &indices_size);
void DrawElementsInstanced(GLint &indices_size);

void DrawArrays_line(GLint &indices_size);
int instance=1;
int cout_line=GL_UNSIGNED_INT;
Display(Buffer_VAO &vao);

Display & operator=(const Display & display);
Display & operator=(Display && display);
Display (Display && display);
Display (const Display & display);
};

#endif // DRAW_H
