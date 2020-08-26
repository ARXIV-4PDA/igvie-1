#include<shader.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdio>
#include <fstream>
#include<GL/glew.h>

    // Constructor generates the shader on the fly
    Shader::Shader(const std::string && vertexPath,const  std::string && fragmentPath)
    {
        // 1. Retrieve the vertex/fragment source code from filePath
        std::string vertexCode;
        std::string fragmentCode;
        std::ifstream vShaderFile{vertexPath};
        std::ifstream fShaderFile{fragmentPath};
        std::cout <<vertexPath<<std::endl<<fragmentPath<<std::endl;
        // ensures ifstream objects can throw exceptions:
        vShaderFile.exceptions(std::ifstream::badbit);
        fShaderFile.exceptions(std::ifstream::badbit);
        try
        {

            std::stringstream vShaderStream, fShaderStream;
            // Read file's buffer contents into streams
            vShaderStream << vShaderFile.rdbuf();
            fShaderStream << fShaderFile.rdbuf();
            // close file handlers
            vShaderFile.close();
            fShaderFile.close();
            // Convert stream into string
            vertexCode=vShaderStream.str();
            fragmentCode=fShaderStream.str();
            std::cout <<vertexCode<<std::endl<<fragmentCode<<std::endl;
        }
        catch (std::ifstream::failure e)
        {
            std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
        }
        const GLchar* vShaderCode = vertexCode.c_str();
        const GLchar * fShaderCode = fragmentCode.c_str();
        // 2. Compile shaders
        GLuint vertex, fragment;
        GLint success;
        GLchar infoLog[512];
        // Vertex Shader
        vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex, 1, &vShaderCode, nullptr);
        glCompileShader(vertex);
        // Print compile errors if any
        glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(vertex, 512, nullptr, infoLog);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        }
        // Fragment Shader
        fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &fShaderCode, nullptr);
        glCompileShader(fragment);
        // Print compile errors if any
        glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragment, 512, nullptr, infoLog);
            std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        }
        // Shader Program
        this->Program = glCreateProgram();
        glAttachShader(this->Program, vertex);
        glAttachShader(this->Program, fragment);
        glLinkProgram(this->Program);
        // Print linking errors if any
        glGetProgramiv(this->Program, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(this->Program, 512, nullptr, infoLog);
            std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;

        }
        // Delete the shaders as they're linked into our program now and no longer necessery
        glDeleteShader(vertex);
        glDeleteShader(fragment);

    }
    // Uses the current shader
    GLuint  Shader::program() noexcept {
      return this->Program;
    };


    void  Shader::use()
    {
        glUseProgram(this->Program);
    }



 //UNIFORM

  GLint  Shader::Uniform_Location( std::string && name){
  return glGetUniformLocation(Program,name.c_str());
  };





    //var float
  void   Shader::Uniform(std::string && name, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3){
      glUniform4f(Uniform_Location(name.c_str()),v0,v1,v2,v3);
  };
  void   Shader::Uniform(std::string && name, GLfloat v0, GLfloat v1, GLfloat v2){
      glUniform3f(Uniform_Location(name.c_str()),v0,v1,v2);
  };
  void   Shader::Uniform(std::string && name, GLfloat v0, GLfloat v1){
      glUniform2f(Uniform_Location(name.c_str()),v0,v1);
  };
  void   Shader::Uniform(std::string && name, GLfloat v0){
      glUniform1f(Uniform_Location(name.c_str()),v0);
  };

   //array float
  template<> void   Shader::Uniform<4>(std::string && name, GLsizei count, const GLfloat* value){

      glUniform4fv(Uniform_Location(name.c_str()),count,value);
  };
  template<> void   Shader::Uniform<3>(std::string && name, GLsizei count, const GLfloat* value){

      glUniform3fv(Uniform_Location(name.c_str()),count,value);
  };
  template<> void   Shader::Uniform<2>(std::string && name, GLsizei count, const GLfloat* value){

      glUniform2fv(Uniform_Location(name.c_str()),count,value);
  };
  template<> void   Shader::Uniform<1>(std::string && name, GLsizei count, const GLfloat* value){

      glUniform1fv(Uniform_Location(name.c_str()),count,value);
  };


  //mat float
    template<> void  Shader::Uniform<4,4>(std::string && name, GLsizei count, GLboolean transpose, const GLfloat* value){
        glUniformMatrix4fv(Uniform_Location(name.c_str()), count, transpose,value);
    };
    template<> void  Shader::Uniform<4,3>(std::string && name, GLsizei count, GLboolean transpose, const GLfloat* value){
        glUniformMatrix4x3fv(Uniform_Location(name.c_str()), count, transpose,value);
    };
    template<> void  Shader::Uniform<4,2>(std::string && name, GLsizei count, GLboolean transpose, const GLfloat* value){
        glUniformMatrix4x2fv(Uniform_Location(name.c_str()), count, transpose,value);
    };


    template<> void  Shader::Uniform<3,4>(std::string && name, GLsizei count, GLboolean transpose, const GLfloat* value){
        glUniformMatrix3x4fv(Uniform_Location(name.c_str()), count, transpose,value);
    };
    template<> void  Shader::Uniform<3,3>(std::string && name, GLsizei count, GLboolean transpose, const GLfloat* value){
        glUniformMatrix3fv(Uniform_Location(name.c_str()), count, transpose,value);
    };
    template<> void  Shader::Uniform<3,2>(std::string && name, GLsizei count, GLboolean transpose, const GLfloat* value){
        glUniformMatrix3x2fv(Uniform_Location(name.c_str()), count, transpose,value);
    };

    template<> void  Shader::Uniform<2,4>(std::string && name, GLsizei count, GLboolean transpose, const GLfloat* value){
        glUniformMatrix2x4fv(Uniform_Location(name.c_str()), count, transpose,value);
    };
    template<> void  Shader::Uniform<2,3>(std::string && name, GLsizei count, GLboolean transpose, const GLfloat* value){
        glUniformMatrix2x3fv(Uniform_Location(name.c_str()), count, transpose,value);
    };
    template<> void  Shader::Uniform<2,2>(std::string && name, GLsizei count, GLboolean transpose, const GLfloat* value){
        glUniformMatrix2fv(Uniform_Location(name.c_str()), count, transpose,value);
    };



  //var int
  void   Shader::Uniform(std::string && name, GLint v0, GLint v1, GLint v2, GLint v3){
      glUniform4i(Uniform_Location(name.c_str()),v0,v1,v2,v3);
  };
  void   Shader::Uniform(std::string && name, GLint v0, GLint v1, GLint v2){
      glUniform3i(Uniform_Location(name.c_str()),v0,v1,v2);
  };
  void   Shader::Uniform(std::string && name, GLint v0, GLint v1){
      glUniform2i(Uniform_Location(name.c_str()),v0,v1);
  };
  void   Shader::Uniform(std::string && name, GLint v0){
     glUniform1i(Uniform_Location(name.c_str()),v0);
  };


     //array int
    template<> void   Shader::Uniform<4>(std::string && name, GLsizei count, const GLint* value){
        glUniform4iv(Uniform_Location(name.c_str()),count,value);
    };
    template<> void   Shader::Uniform<3>(std::string && name, GLsizei count, const GLint* value){
        glUniform3iv(Uniform_Location(name.c_str()),count,value);
    };
    template<> void   Shader::Uniform<2>(std::string && name, GLsizei count, const GLint* value){
        glUniform2iv(Uniform_Location(name.c_str()),count,value);
    };
    template<> void   Shader::Uniform<1>(std::string && name, GLsizei count, const GLint* value){
        glUniform1iv(Uniform_Location(name.c_str()),count,value);
    };

     //var double
  void   Shader::Uniform(std::string && name, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3){
      glUniform4d(Uniform_Location(name.c_str()),v0,v1,v2,v3);
  };
  void   Shader::Uniform(std::string && name, GLdouble v0, GLdouble v1, GLdouble v2){
      glUniform3d(Uniform_Location(name.c_str()),v0,v1,v2);
  };
  void   Shader::Uniform(std::string && name, GLdouble v0, GLdouble v1){
      glUniform2d(Uniform_Location(name.c_str()),v0,v1);
  };
  void   Shader::Uniform(std::string && name, GLdouble v0){
      glUniform1d(Uniform_Location(name.c_str()),v0);
  };

   //array double
  template<> void   Shader::Uniform<4>(std::string && name, GLsizei count, const GLdouble* value){

      glUniform4dv(Uniform_Location(name.c_str()),count,value);
  };
  template<> void   Shader::Uniform<3>(std::string && name, GLsizei count, const GLdouble* value){

      glUniform3dv(Uniform_Location(name.c_str()),count,value);
  };
  template<> void   Shader::Uniform<2>(std::string && name, GLsizei count, const GLdouble* value){

      glUniform2dv(Uniform_Location(name.c_str()),count,value);
  };
  template<> void   Shader::Uniform<1>(std::string && name, GLsizei count, const GLdouble* value){

      glUniform1dv(Uniform_Location(name.c_str()),count,value);
  };


  //mat double
    template<> void  Shader::Uniform<4,4>(std::string && name, GLsizei count, GLboolean transpose, const GLdouble* value){
        glUniformMatrix4dv(Uniform_Location(name.c_str()), count, transpose,value);
    };
    template<> void  Shader::Uniform<4,3>(std::string && name, GLsizei count, GLboolean transpose, const GLdouble* value){
        glUniformMatrix4x3dv(Uniform_Location(name.c_str()), count, transpose,value);
    };
    template<> void  Shader::Uniform<4,2>(std::string && name, GLsizei count, GLboolean transpose, const GLdouble* value){
        glUniformMatrix4x2dv(Uniform_Location(name.c_str()), count, transpose,value);
    };


    template<> void  Shader::Uniform<3,4>(std::string && name, GLsizei count, GLboolean transpose, const GLdouble* value){
        glUniformMatrix3x4dv(Uniform_Location(name.c_str()), count, transpose,value);
    };
    template<> void  Shader::Uniform<3,3>(std::string && name, GLsizei count, GLboolean transpose, const GLdouble* value){
        glUniformMatrix3dv(Uniform_Location(name.c_str()), count, transpose,value);
    };
    template<> void  Shader::Uniform<3,2>(std::string && name, GLsizei count, GLboolean transpose, const GLdouble* value){
        glUniformMatrix3x2dv(Uniform_Location(name.c_str()), count, transpose,value);
    };

    template<> void  Shader::Uniform<2,4>(std::string && name, GLsizei count, GLboolean transpose, const GLdouble* value){
        glUniformMatrix2x4dv(Uniform_Location(name.c_str()), count, transpose,value);
    };
    template<> void  Shader::Uniform<2,3>(std::string && name, GLsizei count, GLboolean transpose, const GLdouble* value){
        glUniformMatrix2x3dv(Uniform_Location(name.c_str()), count, transpose,value);
    };
    template<> void  Shader::Uniform<2,2>(std::string && name, GLsizei count, GLboolean transpose, const GLdouble* value){
        glUniformMatrix2dv(Uniform_Location(name.c_str()), count, transpose,value);
    };






