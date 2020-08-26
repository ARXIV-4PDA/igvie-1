#ifndef WINDOW_H
#define WINDOW_H

#define GLFW_INCLUDE_NONE
#include<GL/glew.h>
//#define STB_IMAGE_IMPLEMENTATION

#include <GL/gl.h>
// GLFW
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
#include <functional>


class Window{
public:
GLFWwindow* window;
int width;
int height;
GLfloat lastX = 400;
GLfloat lastY = 300;
GLdouble xpos=0.0f;
GLdouble ypos=0.0f;
bool firstMouse = true;

GLfloat deltaTime = 0.0f;
GLfloat lastFrame = 0.0f;

std::string name_okno;
static std::function<void*> f;
Window(int WIDTH, int HEIGHT,std::string _name_okno);
void new_fraem();
};
#endif // WINDOW_H
