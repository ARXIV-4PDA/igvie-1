#ifndef SHADER_H
#define SHADER_H

#include <string>
#include<GL/glew.h>

class Shader{
    GLuint Program;
public:
    Shader(const  std::string && vertexPath,const std::string&& fragmentPath);
   void  use();
   GLuint  program() noexcept;


   GLint  Uniform_Location( std::string && name);

    //var float
    void   Uniform(std::string && name, GLfloat v0);
    void   Uniform(std::string && name, GLfloat v0, GLfloat v1);
    void   Uniform(std::string && name, GLfloat v0, GLfloat v1, GLfloat v2);
    void   Uniform(std::string && name, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
     //array float
    template<int i>
    void   Uniform(std::string && name, GLsizei count, const GLfloat* value);
    //mat float
    template<int i,int j>
    void  Uniform(std::string && name, GLsizei count, GLboolean transpose, const GLfloat* value);

    //var int
    void   Uniform(std::string && name, GLint v0);
    void   Uniform(std::string && name, GLint v0, GLint v1);
    void   Uniform(std::string && name, GLint v0, GLint v1, GLint v2);
    void   Uniform(std::string && name, GLint v0, GLint v1, GLint v2, GLint v3);
    //array int
    template<int i>
    void  Uniform(std::string && name, GLsizei count, const GLint* value);

     //var double
    void   Uniform(std::string && name, GLdouble x);
    void   Uniform(std::string && name, GLdouble x, GLdouble y);
    void   Uniform(std::string && name, GLdouble x, GLdouble y, GLdouble z);
    void   Uniform(std::string && name, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
    //array double
    template<int i>
    void  Uniform(std::string && name, GLsizei count, const GLdouble* value);
    //mat double
    template<int i,int j>
    void  Uniform(std::string && name, GLsizei count, GLboolean transpose, const GLdouble* value);

};

// void ();
// void  ();

// void  ();
// void  ();

// void ();
// void  ();

// void (GLAPIENTRY * PFNGLUNIFORM2IPROC) (GLint location, GLsizei count, const GLfloat* value);
// void (GLint location, GLsizei count, const GLint* value);

// void (GLAPIENTRY * PFNGLUNIFORM3FPROC) ();
// void (GLAPIENTRY * PFNGLUNIFORM3FVPROC) (GLint location, GLsizei count, const GLfloat* value);

// void (GLAPIENTRY * PFNGLUNIFORM3IPROC) ();
// void ) (GLint location, GLsizei count, const GLint* value);

// void  ();
// void (GLAPIENTRY * PFNGLUNIFORM4FVPROC) (GLint location, GLsizei count, const GLfloat* value);

// void (GLAPIENTRY * PFNGLUNIFORM4IPROC) ();
// void (GLAPIENTRY * PFNGLUNIFORM4IVPROC) (GLint location, GLsizei count, const GLint* value);

//typedef void (GLAPIENTRY * PFNGLUNIFORM1DPROC) (GLint location, GLdouble x);
//typedef void (GLAPIENTRY * PFNGLUNIFORM1DVPROC) (GLint location, GLsizei count, const GLdouble* value);
//typedef void (GLAPIENTRY * PFNGLUNIFORM2DPROC) (GLint location, GLdouble x, GLdouble y);
//typedef void (GLAPIENTRY * PFNGLUNIFORM2DVPROC) (GLint location, GLsizei count, const GLdouble* value);
//typedef void (GLAPIENTRY * PFNGLUNIFORM3DPROC) (GLint location, GLdouble x, GLdouble y, GLdouble z);
//typedef void (GLAPIENTRY * PFNGLUNIFORM3DVPROC) (GLint location, GLsizei count, const GLdouble* value);
//typedef void (GLAPIENTRY * PFNGLUNIFORM4DPROC) (GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
//typedef void (GLAPIENTRY * PFNGLUNIFORM4DVPROC) (GLint location, GLsizei count, const GLdouble* value);



// void (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
// void (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
// void (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);

#endif // SHADER_H
