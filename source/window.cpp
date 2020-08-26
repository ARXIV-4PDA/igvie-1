#include <window.h>
#include <iostream>

Window::Window(int WIDTH, int HEIGHT,std::string _name_okno):
    width(WIDTH),height(HEIGHT),name_okno(_name_okno){
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_SAMPLES, 4);
    window = glfwCreateWindow(WIDTH, HEIGHT, _name_okno.data(), nullptr, nullptr);
     if (window == nullptr)
     {
         std::cout << "Failed to create GLFW window" << std::endl;
         glfwTerminate();
         }


     glfwGetFramebufferSize(window, &width, &height);
     glViewport(0, 0, width, height);



};

void Window::new_fraem(){
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
    GLfloat currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
    glfwGetCursorPos(window,&xpos,&ypos);
}



