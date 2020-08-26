#ifndef DRAW_H
#define DRAW_H



#include <buffer_vao.h>
#include <GL/glew.h>



class DRAW{

private:
    void (DRAW::*draw_type)(GLint &){&DRAW::DrawArrays};
    Buffer_VAO VAO;
public:
void  start();
void DrawArrays(GLint &indices_size);
void DrawElements(GLint &indices_size);
DRAW(Buffer_VAO vao);

DRAW & operator=(const DRAW & draw);
DRAW & operator=(DRAW && draw);
DRAW (DRAW && draw);
DRAW (const DRAW & draw);
};

#endif // DRAW_H
