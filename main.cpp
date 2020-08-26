
#include <iostream>
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stdio.h>
#include <position.h>
#include <cstdio>
#include <algorithm>
#include <iterator>
#include <list>
#include <math.h>
#include <random>
// GLEW нужно подключать до GLFW.
// GLEW

//#define TARGET_LINUX
//#define TARGET_WINDOWS
//#define GLFW_DLL
//#define GLFW_INCLUDE_NONE
#include<GL/glew.h>
//#define STB_IMAGE_IMPLEMENTATION

#include <GL/gl.h>
// GLFW
#include <GLFW/glfw3.h>

#define GLEW_STATIC
#include<shader.h>
#include <model.h>
#include <camera.h>
#include "object.h"
#include <window.h>
#include <chrono>
#include <text.h>
#include <input_plate.h>
#include <infomation_input_field.h>
#include <chart.h>
#include <time_model.h>

const float GRAD_RAD =3.14/180.0f;
const std::string Directory="/home/arhiv/Downloads/Engine-3D-testing/";
const std::string Directory_pictures=Directory+"pictures/";
const std::string Directory_shaders=Directory+"shaders/";
const std::string Directory_3D_object=Directory+"3D_objects/";

auto mat1=glm::mat4(1.0f);

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void movent();
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void mouse_callback(GLFWwindow* window, double xpos_, double ypos_);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void close_callback(GLFWwindow* window);
void Do_Movement(Window &window);


Time time_curent;
// Window dimensions
const GLuint WIDTH = 1920/1.2, HEIGHT = 1024/1.2;
    float  trans1=0.0f;
    float  trans2=0.0f;
    float  trans3=0.0f;
    float  trans4=0.0f;
    float  trans5=0.0f;
    int digit;

    bool keys[1024];
    bool keys_1[1024];

    Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
    Camera camera_two(glm::vec3(0.0f, 0.0f, 3.0f));
    glm::mat4 view_pos(1.0f);
    glm::mat4 projection(1.0f);
    glm::mat4 view(1.0f);
    bool graf_button_clic=false;

    struct{
        float wind_speed=0.0f;
    }regions[7][12][24];

// The MAIN function, from here we start the application and run the game loop
   int main(){
    int current_region=0;
    int current_station=0;

    regions[MOSCOW][0][0].wind_speed=3;
    regions[MOSCOW][0][1].wind_speed=3;
    regions[MOSCOW][0][2].wind_speed=3;
    regions[MOSCOW][0][3].wind_speed=2;
    regions[MOSCOW][0][4].wind_speed=2;
    regions[MOSCOW][0][5].wind_speed=2;
    regions[MOSCOW][0][6].wind_speed=2;
    regions[MOSCOW][0][7].wind_speed=2;
    regions[MOSCOW][0][8].wind_speed=2;
    regions[MOSCOW][0][9].wind_speed=2;
    regions[MOSCOW][0][10].wind_speed=2;
    regions[MOSCOW][0][11].wind_speed=2;
    regions[MOSCOW][0][12].wind_speed=2;
    regions[MOSCOW][0][13].wind_speed=2;
    regions[MOSCOW][0][14].wind_speed=2;
    regions[MOSCOW][0][15].wind_speed=4;
    regions[MOSCOW][0][16].wind_speed=4;
    regions[MOSCOW][0][17].wind_speed=4;
    regions[MOSCOW][0][18].wind_speed=2;
    regions[MOSCOW][0][19].wind_speed=2;
    regions[MOSCOW][0][20].wind_speed=2;
    regions[MOSCOW][0][21].wind_speed=3;
    regions[MOSCOW][0][22].wind_speed=3;
    regions[MOSCOW][0][23].wind_speed=3;

       //февраль|час
    regions[MOSCOW][1][0].wind_speed=3;
    regions[MOSCOW][1][1].wind_speed=3;
    regions[MOSCOW][1][2].wind_speed=3;
    regions[MOSCOW][1][3].wind_speed=1;
    regions[MOSCOW][1][4].wind_speed=1;
    regions[MOSCOW][1][5].wind_speed=1;
    regions[MOSCOW][1][6].wind_speed=2;
    regions[MOSCOW][1][7].wind_speed=2;
    regions[MOSCOW][1][8].wind_speed=2;
    regions[MOSCOW][1][9].wind_speed=3;
    regions[MOSCOW][1][10].wind_speed=3;
    regions[MOSCOW][1][11].wind_speed=3;
    regions[MOSCOW][1][12].wind_speed=3;
    regions[MOSCOW][1][13].wind_speed=3;
    regions[MOSCOW][1][14].wind_speed=3;
    regions[MOSCOW][1][15].wind_speed=4;
    regions[MOSCOW][1][16].wind_speed=4;
    regions[MOSCOW][1][17].wind_speed=4;
    regions[MOSCOW][1][18].wind_speed=4;
    regions[MOSCOW][1][19].wind_speed=4;
    regions[MOSCOW][1][20].wind_speed=4;
    regions[MOSCOW][1][21].wind_speed=3;
    regions[MOSCOW][1][22].wind_speed=3;
    regions[MOSCOW][1][23].wind_speed=3;

    //март|час
    regions[MOSCOW][2][0].wind_speed=3;
    regions[MOSCOW][2][1].wind_speed=3;
    regions[MOSCOW][2][2].wind_speed=3;
    regions[MOSCOW][2][3].wind_speed=2;
    regions[MOSCOW][2][4].wind_speed=2;
    regions[MOSCOW][2][5].wind_speed=2;
    regions[MOSCOW][2][6].wind_speed=3;
    regions[MOSCOW][2][7].wind_speed=3;
    regions[MOSCOW][2][8].wind_speed=3;
    regions[MOSCOW][2][9].wind_speed=2;
    regions[MOSCOW][2][10].wind_speed=2;
    regions[MOSCOW][2][11].wind_speed=2;
    regions[MOSCOW][2][12].wind_speed=3;
    regions[MOSCOW][2][13].wind_speed=3;
    regions[MOSCOW][2][14].wind_speed=3;
    regions[MOSCOW][2][15].wind_speed=6;
    regions[MOSCOW][2][16].wind_speed=6;
    regions[MOSCOW][2][17].wind_speed=6;
    regions[MOSCOW][2][18].wind_speed=3;
    regions[MOSCOW][2][19].wind_speed=3;
    regions[MOSCOW][2][20].wind_speed=3;
    regions[MOSCOW][2][21].wind_speed=6;
    regions[MOSCOW][2][22].wind_speed=6;
    regions[MOSCOW][2][23].wind_speed=6;

    //апрель|час
    regions[MOSCOW][3][0].wind_speed=3;
    regions[MOSCOW][3][1].wind_speed=3;
    regions[MOSCOW][3][2].wind_speed=3;
    regions[MOSCOW][3][3].wind_speed=2;
    regions[MOSCOW][3][4].wind_speed=2;
    regions[MOSCOW][3][5].wind_speed=2;
    regions[MOSCOW][3][6].wind_speed=3;
    regions[MOSCOW][3][7].wind_speed=3;
    regions[MOSCOW][3][8].wind_speed=3;
    regions[MOSCOW][3][9].wind_speed=3;
    regions[MOSCOW][3][10].wind_speed=3;
    regions[MOSCOW][3][11].wind_speed=3;
    regions[MOSCOW][3][12].wind_speed=5;
    regions[MOSCOW][3][13].wind_speed=5;
    regions[MOSCOW][3][14].wind_speed=5;
    regions[MOSCOW][3][15].wind_speed=6;
    regions[MOSCOW][3][16].wind_speed=6;
    regions[MOSCOW][3][17].wind_speed=6;
    regions[MOSCOW][3][18].wind_speed=4;
    regions[MOSCOW][3][19].wind_speed=4;
    regions[MOSCOW][3][20].wind_speed=4;
    regions[MOSCOW][3][21].wind_speed=2;
    regions[MOSCOW][3][22].wind_speed=2;
    regions[MOSCOW][3][23].wind_speed=2;

    //май|час
    regions[MOSCOW][4][0].wind_speed=1;
    regions[MOSCOW][4][1].wind_speed=1;
    regions[MOSCOW][4][2].wind_speed=1;
    regions[MOSCOW][4][3].wind_speed=1;
    regions[MOSCOW][4][4].wind_speed=1;
    regions[MOSCOW][4][5].wind_speed=1;
    regions[MOSCOW][4][6].wind_speed=1;
    regions[MOSCOW][4][7].wind_speed=1;
    regions[MOSCOW][4][8].wind_speed=1;
    regions[MOSCOW][4][9].wind_speed=4;
    regions[MOSCOW][4][10].wind_speed=4;
    regions[MOSCOW][4][11].wind_speed=4;
    regions[MOSCOW][4][12].wind_speed=1;
    regions[MOSCOW][4][13].wind_speed=1;
    regions[MOSCOW][4][14].wind_speed=1;
    regions[MOSCOW][4][15].wind_speed=2;
    regions[MOSCOW][4][16].wind_speed=2;
    regions[MOSCOW][4][17].wind_speed=2;
    regions[MOSCOW][4][18].wind_speed=6;
    regions[MOSCOW][4][19].wind_speed=6;
    regions[MOSCOW][4][20].wind_speed=6;
    regions[MOSCOW][4][21].wind_speed=2;
    regions[MOSCOW][4][22].wind_speed=2;
    regions[MOSCOW][4][23].wind_speed=2;

    //июнь|час
    regions[MOSCOW][5][0].wind_speed=3;
    regions[MOSCOW][5][1].wind_speed=3;
    regions[MOSCOW][5][2].wind_speed=3;
    regions[MOSCOW][5][3].wind_speed=2;
    regions[MOSCOW][5][4].wind_speed=2;
    regions[MOSCOW][5][5].wind_speed=2;
    regions[MOSCOW][5][6].wind_speed=3;
    regions[MOSCOW][5][7].wind_speed=3;
    regions[MOSCOW][5][8].wind_speed=3;
    regions[MOSCOW][5][9].wind_speed=5;
    regions[MOSCOW][5][10].wind_speed=5;
    regions[MOSCOW][5][11].wind_speed=5;
    regions[MOSCOW][5][12].wind_speed=5;
    regions[MOSCOW][5][13].wind_speed=5;
    regions[MOSCOW][5][14].wind_speed=5;
    regions[MOSCOW][5][15].wind_speed=3;
    regions[MOSCOW][5][16].wind_speed=3;
    regions[MOSCOW][5][17].wind_speed=3;
    regions[MOSCOW][5][18].wind_speed=3;
    regions[MOSCOW][5][19].wind_speed=3;
    regions[MOSCOW][5][20].wind_speed=3;
    regions[MOSCOW][5][21].wind_speed=3;
    regions[MOSCOW][5][22].wind_speed=3;
    regions[MOSCOW][5][23].wind_speed=3;

    //июль|час
    regions[MOSCOW][6][0].wind_speed=1;
    regions[MOSCOW][6][1].wind_speed=1;
    regions[MOSCOW][6][2].wind_speed=1;
    regions[MOSCOW][6][3].wind_speed=1;
    regions[MOSCOW][6][4].wind_speed=1;
    regions[MOSCOW][6][5].wind_speed=1;
    regions[MOSCOW][6][6].wind_speed=2;
    regions[MOSCOW][6][7].wind_speed=2;
    regions[MOSCOW][6][8].wind_speed=2;
    regions[MOSCOW][6][9].wind_speed=3;
    regions[MOSCOW][6][10].wind_speed=3;
    regions[MOSCOW][6][11].wind_speed=3;
    regions[MOSCOW][6][12].wind_speed=2;
    regions[MOSCOW][6][13].wind_speed=2;
    regions[MOSCOW][6][14].wind_speed=2;
    regions[MOSCOW][6][15].wind_speed=4;
    regions[MOSCOW][6][16].wind_speed=4;
    regions[MOSCOW][6][17].wind_speed=4;
    regions[MOSCOW][6][18].wind_speed=5;
    regions[MOSCOW][6][19].wind_speed=5;
    regions[MOSCOW][6][20].wind_speed=5;
    regions[MOSCOW][6][21].wind_speed=3;
    regions[MOSCOW][6][22].wind_speed=3;
    regions[MOSCOW][6][23].wind_speed=3;

    //август|час
    regions[MOSCOW][7][0].wind_speed=2;
    regions[MOSCOW][7][1].wind_speed=2;
    regions[MOSCOW][7][2].wind_speed=2;
    regions[MOSCOW][7][3].wind_speed=3;
    regions[MOSCOW][7][4].wind_speed=3;
    regions[MOSCOW][7][5].wind_speed=3;
    regions[MOSCOW][7][6].wind_speed=4;
    regions[MOSCOW][7][7].wind_speed=4;
    regions[MOSCOW][7][8].wind_speed=4;
    regions[MOSCOW][7][9].wind_speed=3;
    regions[MOSCOW][7][10].wind_speed=3;
    regions[MOSCOW][7][11].wind_speed=3;
    regions[MOSCOW][7][12].wind_speed=5;
    regions[MOSCOW][7][13].wind_speed=5;
    regions[MOSCOW][7][14].wind_speed=5;
    regions[MOSCOW][7][15].wind_speed=3;
    regions[MOSCOW][7][16].wind_speed=3;
    regions[MOSCOW][7][17].wind_speed=3;
    regions[MOSCOW][7][18].wind_speed=5;
    regions[MOSCOW][7][19].wind_speed=5;
    regions[MOSCOW][7][20].wind_speed=5;
    regions[MOSCOW][7][21].wind_speed=3;
    regions[MOSCOW][7][22].wind_speed=3;
    regions[MOSCOW][7][23].wind_speed=3;

    //сентябрь|час
    regions[MOSCOW][8][0].wind_speed=1;
    regions[MOSCOW][8][1].wind_speed=1;
    regions[MOSCOW][8][2].wind_speed=1;
    regions[MOSCOW][8][3].wind_speed=1;
    regions[MOSCOW][8][4].wind_speed=1;
    regions[MOSCOW][8][5].wind_speed=1;
    regions[MOSCOW][8][6].wind_speed=1;
    regions[MOSCOW][8][7].wind_speed=1;
    regions[MOSCOW][8][8].wind_speed=1;
    regions[MOSCOW][8][9].wind_speed=2;
    regions[MOSCOW][8][10].wind_speed=2;
    regions[MOSCOW][8][11].wind_speed=2;
    regions[MOSCOW][8][12].wind_speed=2;
    regions[MOSCOW][8][13].wind_speed=2;
    regions[MOSCOW][8][14].wind_speed=2;
    regions[MOSCOW][8][15].wind_speed=2;
    regions[MOSCOW][8][16].wind_speed=2;
    regions[MOSCOW][8][17].wind_speed=2;
    regions[MOSCOW][8][18].wind_speed=1;
    regions[MOSCOW][8][19].wind_speed=1;
    regions[MOSCOW][8][20].wind_speed=1;
    regions[MOSCOW][8][21].wind_speed=2;
    regions[MOSCOW][8][22].wind_speed=2;
    regions[MOSCOW][8][23].wind_speed=2;

    //отябрь|час
    regions[MOSCOW][9][0].wind_speed=4;
    regions[MOSCOW][9][1].wind_speed=4;
    regions[MOSCOW][9][2].wind_speed=4;
    regions[MOSCOW][9][3].wind_speed=3;
    regions[MOSCOW][9][4].wind_speed=3;
    regions[MOSCOW][9][5].wind_speed=3;
    regions[MOSCOW][9][6].wind_speed=1;
    regions[MOSCOW][9][7].wind_speed=1;
    regions[MOSCOW][9][8].wind_speed=1;
    regions[MOSCOW][9][9].wind_speed=1;
    regions[MOSCOW][9][10].wind_speed=2;
    regions[MOSCOW][9][11].wind_speed=2;
    regions[MOSCOW][9][12].wind_speed=3;
    regions[MOSCOW][9][13].wind_speed=3;
    regions[MOSCOW][9][14].wind_speed=3;
    regions[MOSCOW][9][15].wind_speed=3;
    regions[MOSCOW][9][16].wind_speed=3;
    regions[MOSCOW][9][17].wind_speed=3;
    regions[MOSCOW][9][18].wind_speed=4;
    regions[MOSCOW][9][19].wind_speed=4;
    regions[MOSCOW][9][20].wind_speed=4;
    regions[MOSCOW][9][21].wind_speed=3;
    regions[MOSCOW][9][22].wind_speed=3;
    regions[MOSCOW][9][23].wind_speed=3;

    //ноябрь|час
    regions[MOSCOW][10][0].wind_speed=2;
    regions[MOSCOW][10][1].wind_speed=2;
    regions[MOSCOW][10][2].wind_speed=2;
    regions[MOSCOW][10][3].wind_speed=2;
    regions[MOSCOW][10][4].wind_speed=2;
    regions[MOSCOW][10][5].wind_speed=2;
    regions[MOSCOW][10][6].wind_speed=3;
    regions[MOSCOW][10][7].wind_speed=3;
    regions[MOSCOW][10][8].wind_speed=3;
    regions[MOSCOW][10][9].wind_speed=3;
    regions[MOSCOW][10][10].wind_speed=3;
    regions[MOSCOW][10][11].wind_speed=3;
    regions[MOSCOW][10][12].wind_speed=3;
    regions[MOSCOW][10][13].wind_speed=3;
    regions[MOSCOW][10][14].wind_speed=3;
    regions[MOSCOW][10][15].wind_speed=2;
    regions[MOSCOW][10][16].wind_speed=2;
    regions[MOSCOW][10][17].wind_speed=2;
    regions[MOSCOW][10][18].wind_speed=2;
    regions[MOSCOW][10][19].wind_speed=2;
    regions[MOSCOW][10][20].wind_speed=2;
    regions[MOSCOW][10][21].wind_speed=2;
    regions[MOSCOW][10][22].wind_speed=2;
    regions[MOSCOW][10][23].wind_speed=2;

    //декабрь|час
    regions[MOSCOW][11][0].wind_speed=4;
    regions[MOSCOW][11][1].wind_speed=4;
    regions[MOSCOW][11][2].wind_speed=4;
    regions[MOSCOW][11][3].wind_speed=4;
    regions[MOSCOW][11][4].wind_speed=4;
    regions[MOSCOW][11][5].wind_speed=4;
    regions[MOSCOW][11][6].wind_speed=4;
    regions[MOSCOW][11][7].wind_speed=4;
    regions[MOSCOW][11][8].wind_speed=4;
    regions[MOSCOW][11][9].wind_speed=3;
    regions[MOSCOW][11][10].wind_speed=3;
    regions[MOSCOW][11][11].wind_speed=3;
    regions[MOSCOW][11][12].wind_speed=4;
    regions[MOSCOW][11][13].wind_speed=4;
    regions[MOSCOW][11][14].wind_speed=4;
    regions[MOSCOW][11][15].wind_speed=4;
    regions[MOSCOW][11][16].wind_speed=4;
    regions[MOSCOW][11][17].wind_speed=4;
    regions[MOSCOW][11][18].wind_speed=4;
    regions[MOSCOW][11][19].wind_speed=4;
    regions[MOSCOW][11][20].wind_speed=4;
    regions[MOSCOW][11][21].wind_speed=3;
    regions[MOSCOW][11][22].wind_speed=3;
    regions[MOSCOW][11][23].wind_speed=3;

    regions[MURMANSK_REGION][0][0].wind_speed=8;
    regions[MURMANSK_REGION][0][1].wind_speed=8;
    regions[MURMANSK_REGION][0][2].wind_speed=8;
    regions[MURMANSK_REGION][0][3].wind_speed=10;
    regions[MURMANSK_REGION][0][4].wind_speed=10;
    regions[MURMANSK_REGION][0][5].wind_speed=10;
    regions[MURMANSK_REGION][0][6].wind_speed=10;
    regions[MURMANSK_REGION][0][7].wind_speed=10;
    regions[MURMANSK_REGIO
            Если честно, то абсолютно не жалко её было. Всегда казалось мне ебанутой дурой, уже хотелось самомN][0][8].wind_speed=10;
    regions[MURMANSK_REGION][0][9].wind_speed=10;
    regions[MURMANSK_REGION][0][10].wind_speed=10;
    regions[MURMANSK_REGION][0][11].wind_speed=10;
    regions[MURMANSK_REGION][0][12].wind_speed=9;
    regions[MURMANSK_REGION][0][13].wind_speed=9;
    regions[MURMANSK_REGION][0][14].wind_speed=9;
    regions[MURMANSK_REGION][0][15].wind_speed=8;
    regions[MURMANSK_REGION][0][16].wind_speed=8;
    regions[MURMANSK_REGION][0][17].wind_speed=8;
    regions[MURMANSK_REGION][0][18].wind_speed=9;
    regions[MURMANSK_REGION][0][19].wind_speed=9;
    regions[MURMANSK_REGION][0][20].wind_speed=9;
    regions[MURMANSK_REGION][0][21].wind_speed=11;
    regions[MURMANSK_REGION][0][22].wind_speed=11;
    regions[MURMANSK_REGION][0][23].wind_speed=11;

       //февраль|час
    regions[MURMANSK_REGION][1][0].wind_speed=6;
    regions[MURMANSK_REGION][1][1].wind_speed=6;
    regions[MURMANSK_REGION][1][2].wind_speed=6;
    regions[MURMANSK_REGION][1][3].wind_speed=4;
    regions[MURMANSK_REGION][1][4].wind_speed=4;
    regions[MURMANSK_REGION][1][5].wind_speed=4;
    regions[MURMANSK_REGION][1][6].wind_speed=6;
    regions[MURMANSK_REGION][1][7].wind_speed=6;
    regions[MURMANSK_REGION][1][8].wind_speed=6;
    regions[MURMANSK_REGION][1][9].wind_speed=6;
    regions[MURMANSK_REGION][1][10].wind_speed=6;
    regions[MURMANSK_REGION][1][11].wind_speed=6;
    regions[MURMANSK_REGION][1][12].wind_speed=5;
    regions[MURMANSK_REGION][1][13].wind_speed=5;
    regions[MURMANSK_REGION][1][14].wind_speed=5;
    regions[MURMANSK_REGION][1][15].wind_speed=4;
    regions[MURMANSK_REGION][1][16].wind_speed=4;
    regions[MURMANSK_REGION][1][17].wind_speed=4;
    regions[MURMANSK_REGION][1][18].wind_speed=3;
    regions[MURMANSK_REGION][1][19].wind_speed=3;
    regions[MURMANSK_REGION][1][20].wind_speed=3;
    regions[MURMANSK_REGION][1][21].wind_speed=3;
    regions[MURMANSK_REGION][1][22].wind_speed=3;
    regions[MURMANSK_REGION][1][23].wind_speed=3;

    //март|час
    regions[MURMANSK_REGION][2][0].wind_speed=1;
    regions[MURMANSK_REGION][2][1].wind_speed=1;
    regions[MURMANSK_REGION][2][2].wind_speed=1;
    regions[MURMANSK_REGION][2][3].wind_speed=1;
    regions[MURMANSK_REGION][2][4].wind_speed=1;
    regions[MURMANSK_REGION][2][5].wind_speed=1;
    regions[MURMANSK_REGION][2][6].wind_speed=2;
    regions[MURMANSK_REGION][2][7].wind_speed=2;
    regions[MURMANSK_REGION][2][8].wind_speed=2;
    regions[MURMANSK_REGION][2][9].wind_speed=1;
    regions[MURMANSK_REGION][2][10].wind_speed=1;
    regions[MURMANSK_REGION][2][11].wind_speed=1;
    regions[MURMANSK_REGION][2][12].wind_speed=2;
    regions[MURMANSK_REGION][2][13].wind_speed=2;
    regions[MURMANSK_REGION][2][14].wind_speed=2;
    regions[MURMANSK_REGION][2][15].wind_speed=2;
    regions[MURMANSK_REGION][2][16].wind_speed=2;
    regions[MURMANSK_REGION][2][17].wind_speed=2;
    regions[MURMANSK_REGION][2][18].wind_speed=5;
    regions[MURMANSK_REGION][2][19].wind_speed=5;
    regions[MURMANSK_REGION][2][20].wind_speed=5;
    regions[MURMANSK_REGION][2][21].wind_speed=3;
    regions[MURMANSK_REGION][2][22].wind_speed=3;
    regions[MURMANSK_REGION][2][23].wind_speed=3;

    //апрель|час
    regions[MURMANSK_REGION][3][0].wind_speed=1;
    regions[MURMANSK_REGION][3][1].wind_speed=1;
    regions[MURMANSK_REGION][3][2].wind_speed=1;
    regions[MURMANSK_REGION][3][3].wind_speed=3;
    regions[MURMANSK_REGION][3][4].wind_speed=3;
    regions[MURMANSK_REGION][3][5].wind_speed=3;
    regions[MURMANSK_REGION][3][6].wind_speed=3;
    regions[MURMANSK_REGION][3][7].wind_speed=3;
    regions[MURMANSK_REGION][3][8].wind_speed=3;
    regions[MURMANSK_REGION][3][9].wind_speed=4;
    regions[MURMANSK_REGION][3][10].wind_speed=4;
    regions[MURMANSK_REGION][3][11].wind_speed=4;
    regions[MURMANSK_REGION][3][12].wind_speed=2;
    regions[MURMANSK_REGION][3][13].wind_speed=2;
    regions[MURMANSK_REGION][3][14].wind_speed=2;
    regions[MURMANSK_REGION][3][15].wind_speed=3;
    regions[MURMANSK_REGION][3][16].wind_speed=3;
    regions[MURMANSK_REGION][3][17].wind_speed=3;
    regions[MURMANSK_REGION][3][18].wind_speed=2;
    regions[MURMANSK_REGION][3][19].wind_speed=2;
    regions[MURMANSK_REGION][3][20].wind_speed=2;
    regions[MURMANSK_REGION][3][21].wind_speed=1;
    regions[MURMANSK_REGION][3][22].wind_speed=1;
    regions[MURMANSK_REGION][3][23].wind_speed=1;

    //май|час
    regions[MURMANSK_REGION][4][0].wind_speed=4;
    regions[MURMANSK_REGION][4][1].wind_speed=4;
    regions[MURMANSK_REGION][4][2].wind_speed=4;
    regions[MURMANSK_REGION][4][3].wind_speed=3;
    regions[MURMANSK_REGION][4][4].wind_speed=3;
    regions[MURMANSK_REGION][4][5].wind_speed=3;
    regions[MURMANSK_REGION][4][6].wind_speed=2;
    regions[MURMANSK_REGION][4][7].wind_speed=2;
    regions[MURMANSK_REGION][4][8].wind_speed=2;
    regions[MURMANSK_REGION][4][9].wind_speed=2;
    regions[MURMANSK_REGION][4][10].wind_speed=2;
    regions[MURMANSK_REGION][4][11].wind_speed=2;
    regions[MURMANSK_REGION][4][12].wind_speed=3;
    regions[MURMANSK_REGION][4][13].wind_speed=3;
    regions[MURMANSK_REGION][4][14].wind_speed=3;
    regions[MURMANSK_REGION][4][15].wind_speed=2;
    regions[MURMANSK_REGION][4][16].wind_speed=2;
    regions[MURMANSK_REGION][4][17].wind_speed=2;
    regions[MURMANSK_REGION][4][18].wind_speed=2;
    regions[MURMANSK_REGION][4][19].wind_speed=2;
    regions[MURMANSK_REGION][4][20].wind_speed=2;
    regions[MURMANSK_REGION][4][21].wind_speed=3;
    regions[MURMANSK_REGION][4][22].wind_speed=3;
    regions[MURMANSK_REGION][4][23].wind_speed=3;

    //июнь|час
    regions[MURMANSK_REGION][5][0].wind_speed=3;
    regions[MURMANSK_REGION][5][1].wind_speed=3;
    regions[MURMANSK_REGION][5][2].wind_speed=3;
    regions[MURMANSK_REGION][5][3].wind_speed=3;
    regions[MURMANSK_REGION][5][4].wind_speed=3;
    regions[MURMANSK_REGION][5][5].wind_speed=3;
    regions[MURMANSK_REGION][5][6].wind_speed=4;
    regions[MURMANSK_REGION][5][7].wind_speed=4;
    regions[MURMANSK_REGION][5][8].wind_speed=4;
    regions[MURMANSK_REGION][5][9].wind_speed=6;
    regions[MURMANSK_REGION][5][10].wind_speed=6;
    regions[MURMANSK_REGION][5][11].wind_speed=6;
    regions[MURMANSK_REGION][5][12].wind_speed=8;
    regions[MURMANSK_REGION][5][13].wind_speed=8;
    regions[MURMANSK_REGION][5][14].wind_speed=8;
    regions[MURMANSK_REGION][5][15].wind_speed=8;
    regions[MURMANSK_REGION][5][16].wind_speed=8;
    regions[MURMANSK_REGION][5][17].wind_speed=8;
    regions[MURMANSK_REGION][5][18].wind_speed=7;
    regions[MURMANSK_REGION][5][19].wind_speed=7;
    regions[MURMANSK_REGION][5][20].wind_speed=7;
    regions[MURMANSK_REGION][5][21].wind_speed=4;
    regions[MURMANSK_REGION][5][22].wind_speed=4;
    regions[MURMANSK_REGION][5][23].wind_speed=4;

    //июль|час
    regions[MURMANSK_REGION][6][0].wind_speed=4;
    regions[MURMANSK_REGION][6][1].wind_speed=4;
    regions[MURMANSK_REGION][6][2].wind_speed=4;
    regions[MURMANSK_REGION][6][3].wind_speed=4;
    regions[MURMANSK_REGION][6][4].wind_speed=4;
    regions[MURMANSK_REGION][6][5].wind_speed=4;
    regions[MURMANSK_REGION][6][6].wind_speed=1;
    regions[MURMANSK_REGION][6][7].wind_speed=1;
    regions[MURMANSK_REGION][6][8].wind_speed=1;
    regions[MURMANSK_REGION][6][9].wind_speed=2;
    regions[MURMANSK_REGION][6][10].wind_speed=2;
    regions[MURMANSK_REGION][6][11].wind_speed=2;
    regions[MURMANSK_REGION][6][12].wind_speed=4;
    regions[MURMANSK_REGION][6][13].wind_speed=4;
    regions[MURMANSK_REGION][6][14].wind_speed=4;
    regions[MURMANSK_REGION][6][15].wind_speed=3;
    regions[MURMANSK_REGION][6][16].wind_speed=3;
    regions[MURMANSK_REGION][6][17].wind_speed=3;
    regions[MURMANSK_REGION][6][18].wind_speed=3;
    regions[MURMANSK_REGION][6][19].wind_speed=3;
    regions[MURMANSK_REGION][6][20].wind_speed=3;
    regions[MURMANSK_REGION][6][21].wind_speed=4;
    regions[MURMANSK_REGION][6][22].wind_speed=4;
    regions[MURMANSK_REGION][6][23].wind_speed=4;

    //август|час
    regions[MURMANSK_REGION][7][0].wind_speed=2;
    regions[MURMANSK_REGION][7][1].wind_speed=2;
    regions[MURMANSK_REGION][7][2].wind_speed=2;
    regions[MURMANSK_REGION][7][3].wind_speed=2;
    regions[MURMANSK_REGION][7][4].wind_speed=2;
    regions[MURMANSK_REGION][7][5].wind_speed=2;
    regions[MURMANSK_REGION][7][6].wind_speed=2;
    regions[MURMANSK_REGION][7][7].wind_speed=2;
    regions[MURMANSK_REGION][7][8].wind_speed=2;
    regions[MURMANSK_REGION][7][9].wind_speed=2;
    regions[MURMANSK_REGION][7][10].wind_speed=2;
    regions[MURMANSK_REGION][7][11].wind_speed=2;
    regions[MURMANSK_REGION][7][12].wind_speed=2;
    regions[MURMANSK_REGION][7][13].wind_speed=2;
    regions[MURMANSK_REGION][7][14].wind_speed=2;
    regions[MURMANSK_REGION][7][15].wind_speed=1;
    regions[MURMANSK_REGION][7][16].wind_speed=1;
    regions[MURMANSK_REGION][7][17].wind_speed=1;
    regions[MURMANSK_REGION][7][18].wind_speed=2;
    regions[MURMANSK_REGION][7][19].wind_speed=2;
    regions[MURMANSK_REGION][7][20].wind_speed=2;
    regions[MURMANSK_REGION][7][21].wind_speed=1;
    regions[MURMANSK_REGION][7][22].wind_speed=1;
    regions[MURMANSK_REGION][7][23].wind_speed=1;

    //сентябрь|час
    regions[MURMANSK_REGION][8][0].wind_speed=4;
    regions[MURMANSK_REGION][8][1].wind_speed=4;
    regions[MURMANSK_REGION][8][2].wind_speed=4;
    regions[MURMANSK_REGION][8][3].wind_speed=4;
    regions[MURMANSK_REGION][8][4].wind_speed=4;
    regions[MURMANSK_REGION][8][5].wind_speed=4;
    regions[MURMANSK_REGION][8][6].wind_speed=4;
    regions[MURMANSK_REGION][8][7].wind_speed=4;
    regions[MURMANSK_REGION][8][8].wind_speed=4;
    regions[MURMANSK_REGION][8][9].wind_speed=5;
    regions[MURMANSK_REGION][8][10].wind_speed=5;
    regions[MURMANSK_REGION][8][11].wind_speed=5;
    regions[MURMANSK_REGION][8][12].wind_speed=5;
    regions[MURMANSK_REGION][8][13].wind_speed=5;
    regions[MURMANSK_REGION][8][14].wind_speed=5;
    regions[MURMANSK_REGION][8][15].wind_speed=5;
    regions[MURMANSK_REGION][8][16].wind_speed=5;
    regions[MURMANSK_REGION][8][17].wind_speed=5;
    regions[MURMANSK_REGION][8][18].wind_speed=2;
    regions[MURMANSK_REGION][8][19].wind_speed=2;
    regions[MURMANSK_REGION][8][20].wind_speed=2;
    regions[MURMANSK_REGION][8][21].wind_speed=4;
    regions[MURMANSK_REGION][8][22].wind_speed=4;
    regions[MURMANSK_REGION][8][23].wind_speed=4;

    //отябрь|час
    regions[MURMANSK_REGION][9][0].wind_speed=3;
    regions[MURMANSK_REGION][9][1].wind_speed=3;
    regions[MURMANSK_REGION][9][2].wind_speed=3;
    regions[MURMANSK_REGION][9][3].wind_speed=7;
    regions[MURMANSK_REGION][9][4].wind_speed=7;
    regions[MURMANSK_REGION][9][5].wind_speed=7;
    regions[MURMANSK_REGION][9][6].wind_speed=8;
    regions[MURMANSK_REGION][9][7].wind_speed=8;
    regions[MURMANSK_REGION][9][8].wind_speed=8;
    regions[MURMANSK_REGION][9][9].wind_speed=8;
    regions[MURMANSK_REGION][9][10].wind_speed=8;
    regions[MURMANSK_REGION][9][11].wind_speed=8;
    regions[MURMANSK_REGION][9][12].wind_speed=8;
    regions[MURMANSK_REGION][9][13].wind_speed=8;
    regions[MURMANSK_REGION][9][14].wind_speed=8;
    regions[MURMANSK_REGION][9][15].wind_speed=6;
    regions[MURMANSK_REGION][9][16].wind_speed=6;
    regions[MURMANSK_REGION][9][17].wind_speed=6;
    regions[MURMANSK_REGION][9][18].wind_speed=3;
    regions[MURMANSK_REGION][9][19].wind_speed=3;
    regions[MURMANSK_REGION][9][20].wind_speed=3;
    regions[MURMANSK_REGION][9][21].wind_speed=6;
    regions[MURMANSK_REGION][9][22].wind_speed=6;
    regions[MURMANSK_REGION][9][23].wind_speed=6;

    //ноябрь|час
    regions[MURMANSK_REGION][10][0].wind_speed=6;
    regions[MURMANSK_REGION][10][1].wind_speed=6;
    regions[MURMANSK_REGION][10][2].wind_speed=6;
    regions[MURMANSK_REGION][10][3].wind_speed=6;
    regions[MURMANSK_REGION][10][4].wind_speed=6;
    regions[MURMANSK_REGION][10][5].wind_speed=6;
    regions[MURMANSK_REGION][10][6].wind_speed=8;
    regions[MURMANSK_REGION][10][7].wind_speed=8;
    regions[MURMANSK_REGION][10][8].wind_speed=8;
    regions[MURMANSK_REGION][10][9].wind_speed=8;
    regions[MURMANSK_REGION][10][10].wind_speed=8;
    regions[MURMANSK_REGION][10][11].wind_speed=8;
    regions[MURMANSK_REGION][10][12].wind_speed=7;
    regions[MURMANSK_REGION][10][13].wind_speed=7;
    regions[MURMANSK_REGION][10][14].wind_speed=7;
    regions[MURMANSK_REGION][10][15].wind_speed=7;
    regions[MURMANSK_REGION][10][16].wind_speed=7;
    regions[MURMANSK_REGION][10][17].wind_speed=7;
    regions[MURMANSK_REGION][10][18].wind_speed=8;
    regions[MURMANSK_REGION][10][19].wind_speed=8;
    regions[MURMANSK_REGION][10][20].wind_speed=8;
    regions[MURMANSK_REGION][10][21].wind_speed=5;
    regions[MURMANSK_REGION][10][22].wind_speed=5;
    regions[MURMANSK_REGION][10][23].wind_speed=5;

    //декабрь|час
    regions[MURMANSK_REGION][11][0].wind_speed=6;
    regions[MURMANSK_REGION][11][1].wind_speed=6;
    regions[MURMANSK_REGION][11][2].wind_speed=6;
    regions[MURMANSK_REGION][11][3].wind_speed=6;
    regions[MURMANSK_REGION][11][4].wind_speed=6;
    regions[MURMANSK_REGION][11][5].wind_speed=6;
    regions[MURMANSK_REGION][11][6].wind_speed=5;
    regions[MURMANSK_REGION][11][7].wind_speed=5;
    regions[MURMANSK_REGION][11][8].wind_speed=5;
    regions[MURMANSK_REGION][11][9].wind_speed=6;
    regions[MURMANSK_REGION][11][10].wind_speed=6;
    regions[MURMANSK_REGION][11][11].wind_speed=6;
    regions[MURMANSK_REGION][11][12].wind_speed=6;
    regions[MURMANSK_REGION][11][13].wind_speed=6;
    regions[MURMANSK_REGION][11][14].wind_speed=6;
    regions[MURMANSK_REGION][11][15].wind_speed=6;
    regions[MURMANSK_REGION][11][16].wind_speed=6;
    regions[MURMANSK_REGION][11][17].wind_speed=6;
    regions[MURMANSK_REGION][11][18].wind_speed=4;
    regions[MURMANSK_REGION][11][19].wind_speed=4;
    regions[MURMANSK_REGION][11][20].wind_speed=4;
    regions[MURMANSK_REGION][11][21].wind_speed=4;
    regions[MURMANSK_REGION][11][22].wind_speed=4;
    regions[MURMANSK_REGION][11][23].wind_speed=4;

    regions[PRIMORSKY_KRAI][0][0].wind_speed=3;
    regions[PRIMORSKY_KRAI][0][1].wind_speed=3;
    regions[PRIMORSKY_KRAI][0][2].wind_speed=3;
    regions[PRIMORSKY_KRAI][0][3].wind_speed=1;
    regions[PRIMORSKY_KRAI][0][4].wind_speed=1;
    regions[PRIMORSKY_KRAI][0][5].wind_speed=1;
    regions[PRIMORSKY_KRAI][0][6].wind_speed=3;
    regions[PRIMORSKY_KRAI][0][7].wind_speed=3;
    regions[PRIMORSKY_KRAI][0][8].wind_speed=3;
    regions[PRIMORSKY_KRAI][0][9].wind_speed=1;
    regions[PRIMORSKY_KRAI][0][10].wind_speed=1;
    regions[PRIMORSKY_KRAI][0][11].wind_speed=1;
    regions[PRIMORSKY_KRAI][0][12].wind_speed=6;
    regions[PRIMORSKY_KRAI][0][13].wind_speed=6;
    regions[PRIMORSKY_KRAI][0][14].wind_speed=6;
    regions[PRIMORSKY_KRAI][0][15].wind_speed=7;
    regions[PRIMORSKY_KRAI][0][16].wind_speed=7;
    regions[PRIMORSKY_KRAI][0][17].wind_speed=7;
    regions[PRIMORSKY_KRAI][0][18].wind_speed=5;
    regions[PRIMORSKY_KRAI][0][19].wind_speed=5;
    regions[PRIMORSKY_KRAI][0][20].wind_speed=5;
    regions[PRIMORSKY_KRAI][0][21].wind_speed=3;
    regions[PRIMORSKY_KRAI][0][22].wind_speed=3;
    regions[PRIMORSKY_KRAI][0][23].wind_speed=3;

       //февраль|час
    regions[PRIMORSKY_KRAI][1][0].wind_speed=5;
    regions[PRIMORSKY_KRAI][1][1].wind_speed=5;
    regions[PRIMORSKY_KRAI][1][2].wind_speed=5;
    regions[PRIMORSKY_KRAI][1][3].wind_speed=2;
    regions[PRIMORSKY_KRAI][1][4].wind_speed=2;
    regions[PRIMORSKY_KRAI][1][5].wind_speed=2;
    regions[PRIMORSKY_KRAI][1][6].wind_speed=2;
    regions[PRIMORSKY_KRAI][1][7].wind_speed=2;
    regions[PRIMORSKY_KRAI][1][8].wind_speed=2;
    regions[PRIMORSKY_KRAI][1][9].wind_speed=3;
    regions[PRIMORSKY_KRAI][1][10].wind_speed=3;
    regions[PRIMORSKY_KRAI][1][11].wind_speed=3;
    regions[PRIMORSKY_KRAI][1][12].wind_speed=6;
    regions[PRIMORSKY_KRAI][1][13].wind_speed=6;
    regions[PRIMORSKY_KRAI][1][14].wind_speed=6;
    regions[PRIMORSKY_KRAI][1][15].wind_speed=6;
    regions[PRIMORSKY_KRAI][1][16].wind_speed=6;
    regions[PRIMORSKY_KRAI][1][17].wind_speed=6;
    regions[PRIMORSKY_KRAI][1][18].wind_speed=2;
    regions[PRIMORSKY_KRAI][1][19].wind_speed=2;
    regions[PRIMORSKY_KRAI][1][20].wind_speed=2;
    regions[PRIMORSKY_KRAI][1][21].wind_speed=1;
    regions[PRIMORSKY_KRAI][1][22].wind_speed=1;
    regions[PRIMORSKY_KRAI][1][23].wind_speed=1;

    //март|час
    regions[PRIMORSKY_KRAI][2][0].wind_speed=4;
    regions[PRIMORSKY_KRAI][2][1].wind_speed=4;
    regions[PRIMORSKY_KRAI][2][2].wind_speed=4;
    regions[PRIMORSKY_KRAI][2][3].wind_speed=3;
    regions[PRIMORSKY_KRAI][2][4].wind_speed=3;
    regions[PRIMORSKY_KRAI][2][5].wind_speed=3;
    regions[PRIMORSKY_KRAI][2][6].wind_speed=4;
    regions[PRIMORSKY_KRAI][2][7].wind_speed=4;
    regions[PRIMORSKY_KRAI][2][8].wind_speed=4;
    regions[PRIMORSKY_KRAI][2][9].wind_speed=6;
    regions[PRIMORSKY_KRAI][2][10].wind_speed=6;
    regions[PRIMORSKY_KRAI][2][11].wind_speed=6;
    regions[PRIMORSKY_KRAI][2][12].wind_speed=7;
    regions[PRIMORSKY_KRAI][2][13].wind_speed=7;
    regions[PRIMORSKY_KRAI][2][14].wind_speed=7;
    regions[PRIMORSKY_KRAI][2][15].wind_speed=7;
    regions[PRIMORSKY_KRAI][2][16].wind_speed=7;
    regions[PRIMORSKY_KRAI][2][17].wind_speed=7;
    regions[PRIMORSKY_KRAI][2][18].wind_speed=8;
    regions[PRIMORSKY_KRAI][2][19].wind_speed=8;
    regions[PRIMORSKY_KRAI][2][20].wind_speed=8;
    regions[PRIMORSKY_KRAI][2][21].wind_speed=6;
    regions[PRIMORSKY_KRAI][2][22].wind_speed=6;
    regions[PRIMORSKY_KRAI][2][23].wind_speed=6;

    //апрель|час
    regions[PRIMORSKY_KRAI][3][0].wind_speed=2;
    regions[PRIMORSKY_KRAI][3][1].wind_speed=2;
    regions[PRIMORSKY_KRAI][3][2].wind_speed=2;
    regions[PRIMORSKY_KRAI][3][3].wind_speed=2;
    regions[PRIMORSKY_KRAI][3][4].wind_speed=2;
    regions[PRIMORSKY_KRAI][3][5].wind_speed=2;
    regions[PRIMORSKY_KRAI][3][6].wind_speed=1;
    regions[PRIMORSKY_KRAI][3][7].wind_speed=1;
    regions[PRIMORSKY_KRAI][3][8].wind_speed=1;
    regions[PRIMORSKY_KRAI][3][9].wind_speed=2;
    regions[PRIMORSKY_KRAI][3][10].wind_speed=2;
    regions[PRIMORSKY_KRAI][3][11].wind_speed=2;
    regions[PRIMORSKY_KRAI][3][12].wind_speed=2;
    regions[PRIMORSKY_KRAI][3][13].wind_speed=2;
    regions[PRIMORSKY_KRAI][3][14].wind_speed=2;
    regions[PRIMORSKY_KRAI][3][15].wind_speed=5;
    regions[PRIMORSKY_KRAI][3][16].wind_speed=5;
    regions[PRIMORSKY_KRAI][3][17].wind_speed=5;
    regions[PRIMORSKY_KRAI][3][18].wind_speed=4;
    regions[PRIMORSKY_KRAI][3][19].wind_speed=4;
    regions[PRIMORSKY_KRAI][3][20].wind_speed=4;
    regions[PRIMORSKY_KRAI][3][21].wind_speed=2;
    regions[PRIMORSKY_KRAI][3][22].wind_speed=2;
    regions[PRIMORSKY_KRAI][3][23].wind_speed=2;

    //май|час
    regions[PRIMORSKY_KRAI][4][0].wind_speed=2;
    regions[PRIMORSKY_KRAI][4][1].wind_speed=2;
    regions[PRIMORSKY_KRAI][4][2].wind_speed=2;
    regions[PRIMORSKY_KRAI][4][3].wind_speed=1;
    regions[PRIMORSKY_KRAI][4][4].wind_speed=1;
    regions[PRIMORSKY_KRAI][4][5].wind_speed=1;
    regions[PRIMORSKY_KRAI][4][6].wind_speed=1;
    regions[PRIMORSKY_KRAI][4][7].wind_speed=1;
    regions[PRIMORSKY_KRAI][4][8].wind_speed=1;
    regions[PRIMORSKY_KRAI][4][9].wind_speed=1;
    regions[PRIMORSKY_KRAI][4][10].wind_speed=1;
    regions[PRIMORSKY_KRAI][4][11].wind_speed=1;
    regions[PRIMORSKY_KRAI][4][12].wind_speed=1;
    regions[PRIMORSKY_KRAI][4][13].wind_speed=1;
    regions[PRIMORSKY_KRAI][4][14].wind_speed=1;
    regions[PRIMORSKY_KRAI][4][15].wind_speed=3;
    regions[PRIMORSKY_KRAI][4][16].wind_speed=3;
    regions[PRIMORSKY_KRAI][4][17].wind_speed=3;
    regions[PRIMORSKY_KRAI][4][18].wind_speed=3;
    regions[PRIMORSKY_KRAI][4][19].wind_speed=3;
    regions[PRIMORSKY_KRAI][4][20].wind_speed=3;
    regions[PRIMORSKY_KRAI][4][21].wind_speed=2;
    regions[PRIMORSKY_KRAI][4][22].wind_speed=2;
    regions[PRIMORSKY_KRAI][4][23].wind_speed=2;

    //июнь|час
    regions[PRIMORSKY_KRAI][5][0].wind_speed=5;
    regions[PRIMORSKY_KRAI][5][1].wind_speed=5;
    regions[PRIMORSKY_KRAI][5][2].wind_speed=5;
    regions[PRIMORSKY_KRAI][5][3].wind_speed=4;
    regions[PRIMORSKY_KRAI][5][4].wind_speed=4;
    regions[PRIMORSKY_KRAI][5][5].wind_speed=4;
    regions[PRIMORSKY_KRAI][5][6].wind_speed=3;
    regions[PRIMORSKY_KRAI][5][7].wind_speed=3;
    regions[PRIMORSKY_KRAI][5][8].wind_speed=3;
    regions[PRIMORSKY_KRAI][5][9].wind_speed=4;
    regions[PRIMORSKY_KRAI][5][10].wind_speed=4;
    regions[PRIMORSKY_KRAI][5][11].wind_speed=4;
    regions[PRIMORSKY_KRAI][5][12].wind_speed=6;
    regions[PRIMORSKY_KRAI][5][13].wind_speed=6;
    regions[PRIMORSKY_KRAI][5][14].wind_speed=6;
    regions[PRIMORSKY_KRAI][5][15].wind_speed=6;
    regions[PRIMORSKY_KRAI][5][16].wind_speed=6;
    regions[PRIMORSKY_KRAI][5][17].wind_speed=6;
    regions[PRIMORSKY_KRAI][5][18].wind_speed=6;
    regions[PRIMORSKY_KRAI][5][19].wind_speed=6;
    regions[PRIMORSKY_KRAI][5][20].wind_speed=6;
    regions[PRIMORSKY_KRAI][5][21].wind_speed=4;
    regions[PRIMORSKY_KRAI][5][22].wind_speed=4;
    regions[PRIMORSKY_KRAI][5][23].wind_speed=4;

    //июль|час
    regions[PRIMORSKY_KRAI][6][0].wind_speed=4;
    regions[PRIMORSKY_KRAI][6][1].wind_speed=4;
    regions[PRIMORSKY_KRAI][6][2].wind_speed=4;
    regions[PRIMORSKY_KRAI][6][3].wind_speed=1;
    regions[PRIMORSKY_KRAI][6][4].wind_speed=1;
    regions[PRIMORSKY_KRAI][6][5].wind_speed=1;
    regions[PRIMORSKY_KRAI][6][6].wind_speed=1;
    regions[PRIMORSKY_KRAI][6][7].wind_speed=1;
    regions[PRIMORSKY_KRAI][6][8].wind_speed=1;
    regions[PRIMORSKY_KRAI][6][9].wind_speed=1;
    regions[PRIMORSKY_KRAI][6][10].wind_speed=1;
    regions[PRIMORSKY_KRAI][6][11].wind_speed=1;
    regions[PRIMORSKY_KRAI][6][12].wind_speed=1;
    regions[PRIMORSKY_KRAI][6][13].wind_speed=1;
    regions[PRIMORSKY_KRAI][6][14].wind_speed=1;
    regions[PRIMORSKY_KRAI][6][15].wind_speed=5;
    regions[PRIMORSKY_KRAI][6][16].wind_speed=5;
    regions[PRIMORSKY_KRAI][6][17].wind_speed=5;
    regions[PRIMORSKY_KRAI][6][18].wind_speed=6;
    regions[PRIMORSKY_KRAI][6][19].wind_speed=6;
    regions[PRIMORSKY_KRAI][6][20].wind_speed=6;
    regions[PRIMORSKY_KRAI][6][21].wind_speed=4;
    regions[PRIMORSKY_KRAI][6][22].wind_speed=4;
    regions[PRIMORSKY_KRAI][6][23].wind_speed=4;

    //август|час
    regions[PRIMORSKY_KRAI][7][0].wind_speed=2;
    regions[PRIMORSKY_KRAI][7][1].wind_speed=2;
    regions[PRIMORSKY_KRAI][7][2].wind_speed=2;
    regions[PRIMORSKY_KRAI][7][3].wind_speed=1;
    regions[PRIMORSKY_KRAI][7][4].wind_speed=1;
    regions[PRIMORSKY_KRAI][7][5].wind_speed=1;
    regions[PRIMORSKY_KRAI][7][6].wind_speed=1;
    regions[PRIMORSKY_KRAI][7][7].wind_speed=1;
    regions[PRIMORSKY_KRAI][7][8].wind_speed=1;
    regions[PRIMORSKY_KRAI][7][9].wind_speed=2;
    regions[PRIMORSKY_KRAI][7][10].wind_speed=2;
    regions[PRIMORSKY_KRAI][7][11].wind_speed=2;
    regions[PRIMORSKY_KRAI][7][12].wind_speed=2;
    regions[PRIMORSKY_KRAI][7][13].wind_speed=2;
    regions[PRIMORSKY_KRAI][7][14].wind_speed=2;
    regions[PRIMORSKY_KRAI][7][15].wind_speed=2;
    regions[PRIMORSKY_KRAI][7][16].wind_speed=2;
    regions[PRIMORSKY_KRAI][7][17].wind_speed=2;
    regions[PRIMORSKY_KRAI][7][18].wind_speed=2;
    regions[PRIMORSKY_KRAI][7][19].wind_speed=2;
    regions[PRIMORSKY_KRAI][7][20].wind_speed=2;
    regions[PRIMORSKY_KRAI][7][21].wind_speed=2;
    regions[PRIMORSKY_KRAI][7][22].wind_speed=2;
    regions[PRIMORSKY_KRAI][7][23].wind_speed=2;

    //сентябрь|час
    regions[PRIMORSKY_KRAI][8][0].wind_speed=2;
    regions[PRIMORSKY_KRAI][8][1].wind_speed=2;
    regions[PRIMORSKY_KRAI][8][2].wind_speed=2;
    regions[PRIMORSKY_KRAI][8][3].wind_speed=2;
    regions[PRIMORSKY_KRAI][8][4].wind_speed=2;
    regions[PRIMORSKY_KRAI][8][5].wind_speed=2;
    regions[PRIMORSKY_KRAI][8][6].wind_speed=1;
    regions[PRIMORSKY_KRAI][8][7].wind_speed=1;
    regions[PRIMORSKY_KRAI][8][8].wind_speed=1;
    regions[PRIMORSKY_KRAI][8][9].wind_speed=5;
    regions[PRIMORSKY_KRAI][8][10].wind_speed=5;
    regions[PRIMORSKY_KRAI][8][11].wind_speed=5;
    regions[PRIMORSKY_KRAI][8][12].wind_speed=6;
    regions[PRIMORSKY_KRAI][8][13].wind_speed=6;
    regions[PRIMORSKY_KRAI][8][14].wind_speed=6;
    regions[PRIMORSKY_KRAI][8][15].wind_speed=6;
    regions[PRIMORSKY_KRAI][8][16].wind_speed=6;
    regions[PRIMORSKY_KRAI][8][17].wind_speed=6;
    regions[PRIMORSKY_KRAI][8][18].wind_speed=4;
    regions[PRIMORSKY_KRAI][8][19].wind_speed=4;
    regions[PRIMORSKY_KRAI][8][20].wind_speed=4;
    regions[PRIMORSKY_KRAI][8][21].wind_speed=3;
    regions[PRIMORSKY_KRAI][8][22].wind_speed=3;
    regions[PRIMORSKY_KRAI][8][23].wind_speed=3;

    //отябрь|час
    regions[PRIMORSKY_KRAI][9][0].wind_speed=2;
    regions[PRIMORSKY_KRAI][9][1].wind_speed=2;
    regions[PRIMORSKY_KRAI][9][2].wind_speed=2;
    regions[PRIMORSKY_KRAI][9][3].wind_speed=1;
    regions[PRIMORSKY_KRAI][9][4].wind_speed=1;
    regions[PRIMORSKY_KRAI][9][5].wind_speed=1;
    regions[PRIMORSKY_KRAI][9][6].wind_speed=1;
    regions[PRIMORSKY_KRAI][9][7].wind_speed=1;
    regions[PRIMORSKY_KRAI][9][8].wind_speed=1;
    regions[PRIMORSKY_KRAI][9][9].wind_speed=4;
    regions[PRIMORSKY_KRAI][9][10].wind_speed=4;
    regions[PRIMORSKY_KRAI][9][11].wind_speed=4;
    regions[PRIMORSKY_KRAI][9][12].wind_speed=4;
    regions[PRIMORSKY_KRAI][9][13].wind_speed=4;
    regions[PRIMORSKY_KRAI][9][14].wind_speed=4;
    regions[PRIMORSKY_KRAI][9][15].wind_speed=0;
    regions[PRIMORSKY_KRAI][9][16].wind_speed=0;
    regions[PRIMORSKY_KRAI][9][17].wind_speed=0;
    regions[PRIMORSKY_KRAI][9][18].wind_speed=2;
    regions[PRIMORSKY_KRAI][9][19].wind_speed=2;
    regions[PRIMORSKY_KRAI][9][20].wind_speed=2;
    regions[PRIMORSKY_KRAI][9][21].wind_speed=1;
    regions[PRIMORSKY_KRAI][9][22].wind_speed=1;
    regions[PRIMORSKY_KRAI][9][23].wind_speed=1;

    //ноябрь|час
    regions[PRIMORSKY_KRAI][10][0].wind_speed=2;
    regions[PRIMORSKY_KRAI][10][1].wind_speed=2;
    regions[PRIMORSKY_KRAI][10][2].wind_speed=2;
    regions[PRIMORSKY_KRAI][10][3].wind_speed=1;
    regions[PRIMORSKY_KRAI][10][4].wind_speed=1;
    regions[PRIMORSKY_KRAI][10][5].wind_speed=1;
    regions[PRIMORSKY_KRAI][10][6].wind_speed=1;
    regions[PRIMORSKY_KRAI][10][7].wind_speed=1;
    regions[PRIMORSKY_KRAI][10][8].wind_speed=1;
    regions[PRIMORSKY_KRAI][10][9].wind_speed=1;
    regions[PRIMORSKY_KRAI][10][10].wind_speed=1;
    regions[PRIMORSKY_KRAI][10][11].wind_speed=1;
    regions[PRIMORSKY_KRAI][10][12].wind_speed=1;
    regions[PRIMORSKY_KRAI][10][13].wind_speed=1;
    regions[PRIMORSKY_KRAI][10][14].wind_speed=1;
    regions[PRIMORSKY_KRAI][10][15].wind_speed=1;
    regions[PRIMORSKY_KRAI][10][16].wind_speed=1;
    regions[PRIMORSKY_KRAI][10][17].wind_speed=1;
    regions[PRIMORSKY_KRAI][10][18].wind_speed=2;
    regions[PRIMORSKY_KRAI][10][19].wind_speed=2;
    regions[PRIMORSKY_KRAI][10][20].wind_speed=2;
    regions[PRIMORSKY_KRAI][10][21].wind_speed=1;
    regions[PRIMORSKY_KRAI][10][22].wind_speed=1;
    regions[PRIMORSKY_KRAI][10][23].wind_speed=1;

    //декабрь|час
    regions[PRIMORSKY_KRAI][11][0].wind_speed=1;
    regions[PRIMORSKY_KRAI][11][1].wind_speed=1;
    regions[PRIMORSKY_KRAI][11][2].wind_speed=1;
    regions[PRIMORSKY_KRAI][11][3].wind_speed=1;
    regions[PRIMORSKY_KRAI][11][4].wind_speed=1;
    regions[PRIMORSKY_KRAI][11][5].wind_speed=1;
    regions[PRIMORSKY_KRAI][11][6].wind_speed=1;
    regions[PRIMORSKY_KRAI][11][7].wind_speed=1;
    regions[PRIMORSKY_KRAI][11][8].wind_speed=1;
    regions[PRIMORSKY_KRAI][11][9].wind_speed=1;
    regions[PRIMORSKY_KRAI][11][10].wind_speed=1;
    regions[PRIMORSKY_KRAI][11][11].wind_speed=1;
    regions[PRIMORSKY_KRAI][11][12].wind_speed=1;
    regions[PRIMORSKY_KRAI][11][13].wind_speed=1;
    regions[PRIMORSKY_KRAI][11][14].wind_speed=1;
    regions[PRIMORSKY_KRAI][11][15].wind_speed=2;
    regions[PRIMORSKY_KRAI][11][16].wind_speed=2;
    regions[PRIMORSKY_KRAI][11][17].wind_speed=2;
    regions[PRIMORSKY_KRAI][11][18].wind_speed=2;
    regions[PRIMORSKY_KRAI][11][19].wind_speed=2;
    regions[PRIMORSKY_KRAI][11][20].wind_speed=2;
    regions[PRIMORSKY_KRAI][11][21].wind_speed=3;
    regions[PRIMORSKY_KRAI][11][22].wind_speed=3;
    regions[PRIMORSKY_KRAI][11][23].wind_speed=3;

    regions[REPUBLIC_OF_DAGESTAN][0][0].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][0][1].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][0][2].wind_speed= 2;
    regions[REPUBLIC_OF_DAGESTAN][0][3].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][0][4].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][0][5].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][0][6].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][0][7].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][0][8].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][0][9].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][0][10].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][0][11].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][0][12].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][0][13].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][0][14].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][0][15].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][0][16].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][0][17].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][0][18].wind_speed=7;
    regions[REPUBLIC_OF_DAGESTAN][0][19].wind_speed=7;
    regions[REPUBLIC_OF_DAGESTAN][0][20].wind_speed=7;
    regions[REPUBLIC_OF_DAGESTAN][0][21].wind_speed=7;
    regions[REPUBLIC_OF_DAGESTAN][0][22].wind_speed=7;
    regions[REPUBLIC_OF_DAGESTAN][0][23].wind_speed=7;

       //февраль|час
    regions[REPUBLIC_OF_DAGESTAN][1][0].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][1][1].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][1][2].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][1][3].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][1][4].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][1][5].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][1][6].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][1][7].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][1][8].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][1][9].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][1][10].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][1][11].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][1][12].wind_speed=7;
    regions[REPUBLIC_OF_DAGESTAN][1][13].wind_speed=7;
    regions[REPUBLIC_OF_DAGESTAN][1][14].wind_speed=7;
    regions[REPUBLIC_OF_DAGESTAN][1][15].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][1][16].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][1][17].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][1][18].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][1][19].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][1][20].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][1][21].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][1][22].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][1][23].wind_speed=5;

    //март|час
    regions[REPUBLIC_OF_DAGESTAN][2][0].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][2][1].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][2][2].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][2][3].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][2][4].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][2][5].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][2][6].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][2][7].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][2][8].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][2][9].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][2][10].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][2][11].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][2][12].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][2][13].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][2][14].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][2][15].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][2][16].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][2][17].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][2][18].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][2][19].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][2][20].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][2][21].wind_speed=6;
    regions[REPUBLIC_OF_DAGESTAN][2][22].wind_speed=6;
    regions[REPUBLIC_OF_DAGESTAN][2][23].wind_speed=6;

    //апрель|час
    regions[REPUBLIC_OF_DAGESTAN][3][0].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][3][1].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][3][2].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][3][3].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][3][4].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][3][5].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][3][6].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][3][7].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][3][8].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][3][9].wind_speed=7;
    regions[REPUBLIC_OF_DAGESTAN][3][10].wind_speed=7;
    regions[REPUBLIC_OF_DAGESTAN][3][11].wind_speed=7;
    regions[REPUBLIC_OF_DAGESTAN][3][12].wind_speed=7;
    regions[REPUBLIC_OF_DAGESTAN][3][13].wind_speed=7;
    regions[REPUBLIC_OF_DAGESTAN][3][14].wind_speed=7;
    regions[REPUBLIC_OF_DAGESTAN][3][15].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][3][16].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][3][17].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][3][18].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][3][19].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][3][20].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][3][21].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][3][22].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][3][23].wind_speed=1;

    //май|час
    regions[REPUBLIC_OF_DAGESTAN][4][0].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][4][1].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][4][2].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][4][3].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][4][4].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][4][5].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][4][6].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][4][7].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][4][8].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][4][9].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][4][10].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][4][11].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][4][12].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][4][13].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][4][14].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][4][15].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][4][16].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][4][17].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][4][18].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][4][19].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][4][20].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][4][21].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][4][22].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][4][23].wind_speed=1;

    //июнь|час
    regions[REPUBLIC_OF_DAGESTAN][5][0].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][5][1].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][5][2].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][5][3].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][5][4].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][5][5].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][5][6].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][5][7].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][5][8].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][5][9].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][5][10].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][5][11].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][5][12].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][5][13].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][5][14].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][5][15].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][5][16].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][5][17].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][5][18].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][5][19].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][5][20].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][5][21].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][5][22].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][5][23].wind_speed=2;

    //июль|час
    regions[REPUBLIC_OF_DAGESTAN][6][0].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][6][1].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][6][2].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][6][3].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][6][4].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][6][5].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][6][6].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][6][7].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][6][8].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][6][9].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][6][10].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][6][11].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][6][12].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][6][13].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][6][14].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][6][15].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][6][16].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][6][17].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][6][18].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][6][19].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][6][20].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][6][21].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][6][22].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][6][23].wind_speed=2;

    //август|час
    regions[REPUBLIC_OF_DAGESTAN][7][0].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][7][1].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][7][2].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][7][3].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][7][4].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][7][5].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][7][6].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][7][7].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][7][8].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][7][9].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][7][10].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][7][11].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][7][12].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][7][13].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][7][14].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][7][15].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][7][16].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][7][17].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][7][18].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][7][19].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][7][20].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][7][21].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][7][22].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][7][23].wind_speed=2;

    //сентябрь|час
    regions[REPUBLIC_OF_DAGESTAN][8][0].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][8][1].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][8][2].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][8][3].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][8][4].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][8][5].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][8][6].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][8][7].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][8][8].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][8][9].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][8][10].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][8][11].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][8][12].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][8][13].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][8][14].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][8][15].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][8][16].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][8][17].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][8][18].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][8][19].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][8][20].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][8][21].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][8][22].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][8][23].wind_speed=2;

    //отябрь|час
    regions[REPUBLIC_OF_DAGESTAN][9][0].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][9][1].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][9][2].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][9][3].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][9][4].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][9][5].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][9][6].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][9][7].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][9][8].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][9][9].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][9][10].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][9][11].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][9][12].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][9][13].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][9][14].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][9][15].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][9][16].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][9][17].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][9][18].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][9][19].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][9][20].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][9][21].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][9][22].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][9][23].wind_speed=1;

    //ноябрь|час
    regions[REPUBLIC_OF_DAGESTAN][10][0].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][10][1].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][10][2].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][10][3].wind_speed=6;
    regions[REPUBLIC_OF_DAGESTAN][10][4].wind_speed=6;
    regions[REPUBLIC_OF_DAGESTAN][10][5].wind_speed=6;
    regions[REPUBLIC_OF_DAGESTAN][10][6].wind_speed=7;
    regions[REPUBLIC_OF_DAGESTAN][10][7].wind_speed=7;
    regions[REPUBLIC_OF_DAGESTAN][10][8].wind_speed=7;
    regions[REPUBLIC_OF_DAGESTAN][10][9].wind_speed=8;
    regions[REPUBLIC_OF_DAGESTAN][10][10].wind_speed=8;
    regions[REPUBLIC_OF_DAGESTAN][10][11].wind_speed=8;
    regions[REPUBLIC_OF_DAGESTAN][10][12].wind_speed=8;
    regions[REPUBLIC_OF_DAGESTAN][10][13].wind_speed=8;
    regions[REPUBLIC_OF_DAGESTAN][10][14].wind_speed=8;
    regions[REPUBLIC_OF_DAGESTAN][10][15].wind_speed=6;
    regions[REPUBLIC_OF_DAGESTAN][10][16].wind_speed=6;
    regions[REPUBLIC_OF_DAGESTAN][10][17].wind_speed=6;
    regions[REPUBLIC_OF_DAGESTAN][10][18].wind_speed=7;
    regions[REPUBLIC_OF_DAGESTAN][10][19].wind_speed=7;
    regions[REPUBLIC_OF_DAGESTAN][10][20].wind_speed=7;
    regions[REPUBLIC_OF_DAGESTAN][10][21].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][10][22].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][10][23].wind_speed=5;

    //декабрь|час
    regions[REPUBLIC_OF_DAGESTAN][11][0].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][11][1].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][11][2].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][11][3].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][11][4].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][11][5].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][11][6].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][11][7].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][11][8].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][11][9].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][11][10].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][11][11].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][11][12].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][11][13].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][11][14].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][11][15].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][11][16].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][11][17].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][11][18].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][11][19].wind_speed=2;
    regglBindVertexArrayions[REPUBLIC_OF_DAGESTAN][11][20].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][11][21].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][11][22].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][11][23].wind_speed=1;

    regions[REPUBLIC_OF_DAGESTAN][0][0].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][0][1].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][0][2].wind_speed= 2;
    regions[REPUBLIC_OF_DAGESTAN][0][3].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][0][4].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][0][5].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][0][6].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][0][7].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][0][8].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][0][9].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][0][10].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][0][11].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][0][12].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][0][13].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][0][14].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][0][15].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][0][16].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][0][17].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][0][18].wind_speed=7;
    regions[REPUBLIC_OF_DAGESTAN][0][19].wind_speed=7;
    regions[REPUBLIC_OF_DAGESTAN][0][20].wind_speed=7;
    regions[REPUBLIC_OF_DAGESTAN][0][21].wind_speed=7;
    regions[REPUBLIC_OF_DAGESTAN][0][22].wind_speed=7;
    regions[REPUBLIC_OF_DAGESTAN][0][23].wind_speed=7;

       //февраль|час
    regions[REPUBLIC_OF_DAGESTAN][1][0].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][1][1].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][1][2].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][1][3].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][1][4].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][1][5].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][1][6].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][1][7].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][1][8].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][1][9].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][1][10].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][1][11].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][1][12].wind_speed=7;
    regions[REPUBLIC_OF_DAGESTAN][1][13].wind_speed=7;
    regions[REPUBLIC_OF_DAGESTAN][1][14].wind_speed=7;
    regions[REPUBLIC_OF_DAGESTAN][1][15].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][1][16].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][1][17].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][1][18].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][1][19].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][1][20].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][1][21].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][1][22].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][1][23].wind_speed=5;

    //март|час
    regions[REPUBLIC_OF_DAGESTAN][2][0].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][2][1].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][2][2].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][2][3].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][2][4].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][2][5].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][2][6].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][2][7].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][2][8].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][2][9].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][2][10].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][2][11].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][2][12].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][2][13].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][2][14].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][2][15].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][2][16].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][2][17].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][2][18].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][2][19].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][2][20].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][2][21].wind_speed=6;
    regions[REPUBLIC_OF_DAGESTAN][2][22].wind_speed=6;
    regions[REPUBLIC_OF_DAGESTAN][2][23].wind_speed=6;

    //апрель|час
    regions[REPUBLIC_OF_DAGESTAN][3][0].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][3][1].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][3][2].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][3][3].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][3][4].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][3][5].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][3][6].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][3][7].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][3][8].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][3][9].wind_speed=7;
    regions[REPUBLIC_OF_DAGESTAN][3][10].wind_speed=7;
    regions[REPUBLIC_OF_DAGESTAN][3][11].wind_speed=7;
    regions[REPUBLIC_OF_DAGESTAN][3][12].wind_speed=7;
    regions[REPUBLIC_OF_DAGESTAN][3][13].wind_speed=7;
    regions[REPUBLIC_OF_DAGESTAN][3][14].wind_speed=7;
    regions[REPUBLIC_OF_DAGESTAN][3][15].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][3][16].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][3][17].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][3][18].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][3][19].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][3][20].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][3][21].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][3][22].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][3][23].wind_speed=1;

    //май|час
    regions[REPUBLIC_OF_DAGESTAN][4][0].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][4][1].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][4][2].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][4][3].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][4][4].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][4][5].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][4][6].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][4][7].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][4][8].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][4][9].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][4][10].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][4][11].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][4][12].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][4][13].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][4][14].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][4][15].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][4][16].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][4][17].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][4][18].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][4][19].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][4][20].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][4][21].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][4][22].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][4][23].wind_speed=1;

    //июнь|час
    regions[REPUBLIC_OF_DAGESTAN][5][0].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][5][1].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][5][2].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][5][3].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][5][4].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][5][5].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][5][6].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][5][7].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][5][8].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][5][9].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][5][10].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][5][11].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][5][12].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][5][13].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][5][14].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][5][15].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][5][16].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][5][17].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][5][18].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][5][19].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][5][20].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][5][21].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][5][22].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][5][23].wind_speed=2;

    //июль|час
    regions[REPUBLIC_OF_DAGESTAN][6][0].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][6][1].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][6][2].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][6][3].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][6][4].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][6][5].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][6][6].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][6][7].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][6][8].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][6][9].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][6][10].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][6][11].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][6][12].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][6][13].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][6][14].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][6][15].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][6][16].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][6][17].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][6][18].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][6][19].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][6][20].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][6][21].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][6][22].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][6][23].wind_speed=2;

    //август|час
    regions[REPUBLIC_OF_DAGESTAN][7][0].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][7][1].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][7][2].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][7][3].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][7][4].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][7][5].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][7][6].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][7][7].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][7][8].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][7][9].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][7][10].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][7][11].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][7][12].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][7][13].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][7][14].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][7][15].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][7][16].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][7][17].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][7][18].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][7][19].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][7][20].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][7][21].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][7][22].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][7][23].wind_speed=2;

    //сентябрь|час
    regions[REPUBLIC_OF_DAGESTAN][8][0].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][8][1].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][8][2].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][8][3].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][8][4].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][8][5].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][8][6].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][8][7].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][8][8].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][8][9].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][8][10].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][8][11].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][8][12].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][8][13].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][8][14].wind_speed=4;
    regions[REPUBLIC_OF_DAGESTAN][8][15].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][8][16].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][8][17].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][8][18].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][8][19].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][8][20].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][8][21].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][8][22].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][8][23].wind_speed=2;

    //отябрь|час
    regions[REPUBLIC_OF_DAGESTAN][9][0].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][9][1].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][9][2].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][9][3].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][9][4].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][9][5].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][9][6].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][9][7].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][9][8].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][9][9].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][9][10].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][9][11].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][9][12].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][9][13].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][9][14].wind_speed=3;
    regions[REPUBLIC_OF_DAGESTAN][9][15].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][9][16].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][9][17].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][9][18].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][9][19].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][9][20].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][9][21].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][9][22].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][9][23].wind_speed=1;

    //ноябрь|час
    regions[REPUBLIC_OF_DAGESTAN][10][0].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][10][1].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][10][2].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][10][3].wind_speed=6;
    regions[REPUBLIC_OF_DAGESTAN][10][4].wind_speed=6;
    regions[REPUBLIC_OF_DAGESTAN][10][5].wind_speed=6;
    regions[REPUBLIC_OF_DAGESTAN][10][6].wind_speed=7;
    regions[REPUBLIC_OF_DAGESTAN][10][7].wind_speed=7;
    regions[REPUBLIC_OF_DAGESTAN][10][8].wind_speed=7;
    regions[REPUBLIC_OF_DAGESTAN][10][9].wind_speed=8;
    regions[REPUBLIC_OF_DAGESTAN][10][10].wind_speed=8;
    regions[REPUBLIC_OF_DAGESTAN][10][11].wind_speed=8;
    regions[REPUBLIC_OF_DAGESTAN][10][12].wind_speed=8;
    regions[REPUBLIC_OF_DAGESTAN][10][13].wind_speed=8;
    regions[REPUBLIC_OF_DAGESTAN][10][14].wind_speed=8;
    regions[REPUBLIC_OF_DAGESTAN][10][15].wind_speed=6;
    regions[REPUBLIC_OF_DAGESTAN][10][16].wind_speed=6;
    regions[REPUBLIC_OF_DAGESTAN][10][17].wind_speed=6;
    regions[REPUBLIC_OF_DAGESTAN][10][18].wind_speed=7;
    regions[REPUBLIC_OF_DAGESTAN][10][19].wind_speed=7;
    regions[REPUBLIC_OF_DAGESTAN][10][20].wind_speed=7 ;
    regions[REPUBLIC_OF_DAGESTAN][10][21].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][10][22].wind_speed=5;
    regions[REPUBLIC_OF_DAGESTAN][10][23].wind_speed=5;

    //декабрь|час
    regions[REPUBLIC_OF_DAGESTAN][11][0].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][11][1].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][11][2].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][11][3].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][11][4].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][11][5].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][11][6].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][11][7].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][11][8].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][11][9].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][11][10].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][11][11].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][11][12].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][11][13].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][11][14].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][11][15].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][11][16].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][11][17].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][11][18].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][11][19].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][11][20].wind_speed=2;
    regions[REPUBLIC_OF_DAGESTAN][11][21].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][11][22].wind_speed=1;
    regions[REPUBLIC_OF_DAGESTAN][11][23].wind_speed=1;

    regions[REPUBLIC_OF_SAKHA_YAKUTIA][0][0].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][0][1].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][0][2].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][0][3].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][0][4].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][0][5].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][0][6].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][0][7].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][0][8].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][0][9].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][0][10].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][0][11].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][0][12].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][0][13].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][0][14].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][0][15].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][0][16].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][0][17].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][0][18].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][0][19].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][0][20].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][0][21].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][0][22].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][0][23].wind_speed=1;

       //февраль|час
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][1][0].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][1][1].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][1][2].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][1][3].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][1][4].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][1][5].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][1][6].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][1][7].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][1][8].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][1][9].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][1][10].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][1][11].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][1][12].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][1][13].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][1][14].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][1][15].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][1][16].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][1][17].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][1][18].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][1][19].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][1][20].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][1][21].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][1][22].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][1][23].wind_speed=2;

    //март|час
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][2][0].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][2][1].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][2][2].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][2][3].wind_speed=3;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][2][4].wind_speed=3;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][2][5].wind_speed=3;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][2][6].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][2][7].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][2][8].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][2][9].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][2][10].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][2][11].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][2][12].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][2][13].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][2][14].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][2][15].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][2][16].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][2][17].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][2][18].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][2][19].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][2][20].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][2][21].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][2][22].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][2][23].wind_speed=2;

    //апрель|час
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][3][0].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][3][1].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][3][2].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][3][3].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][3][4].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][3][5].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][3][6].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][3][7].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][3][8].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][3][9].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][3][10].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][3][11].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][3][12].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][3][13].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][3][14].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][3][15].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][3][16].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][3][17].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][3][18].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][3][19].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][3][20].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][3][21].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][3][22].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][3][23].wind_speed=1;

    //май|час
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][4][0].wind_speed=5;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][4][1].wind_speed=5;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][4][2].wind_speed=5;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][4][3].wind_speed=4;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][4][4].wind_speed=4;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][4][5].wind_speed=4;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][4][6].wind_speed=4;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][4][7].wind_speed=4;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][4][8].wind_speed=4;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][4][9].wind_speed=6;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][4][10].wind_speed=6;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][4][11].wind_speed=6;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][4][12].wind_speed=6;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][4][13].wind_speed=6;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][4][14].wind_speed=6;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][4][15].wind_speed=5;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][4][16].wind_speed=5;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][4][17].wind_speed=5;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][4][18].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][4][19].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][4][20].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][4][21].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][4][22].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][4][23].wind_speed=1;

    //июнь|час
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][5][0].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][5][1].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][5][2].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][5][3].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][5][4].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][5][5].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][5][6].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][5][7].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][5][8].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][5][9].wind_speed=3;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][5][10].wind_speed=3;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][5][11].wind_speed=3;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][5][12].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][5][13].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][5][14].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][5][15].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][5][16].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][5][17].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][5][18].wind_speed=3;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][5][19].wind_speed=3;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][5][20].wind_speed=3;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][5][21].wind_speed=3;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][5][22].wind_speed=3;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][5][23].wind_speed=3;

    //июль|час
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][6][0].wind_speed=3;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][6][1].wind_speed=3;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][6][2].wind_speed=3;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][6][3].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][6][4].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][6][5].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][6][6].wind_speed=3;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][6][7].wind_speed=3;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][6][8].wind_speed=3;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][6][9].wind_speed=4;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][6][10].wind_speed=4;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][6][11].wind_speed=4;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][6][12].wind_speed=3;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][6][13].wind_speed=3;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][6][14].wind_speed=3;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][6][15].wind_speed=3;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][6][16].wind_speed=3;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][6][17].wind_speed=3;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][6][18].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][6][19].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][6][20].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][6][21].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][6][22].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][6][23].wind_speed=2;

    //август|час
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][7][0].wind_speed=3;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][7][1].wind_speed=3;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][7][2].wind_speed=3;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][7][3].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][7][4].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][7][5].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][7][6].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][7][7].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][7][8].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][7][9].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][7][10].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][7][11].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][7][12].wind_speed=3;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][7][13].wind_speed=3;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][7][14].wind_speed=3;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][7][15].wind_speed=4;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][7][16].wind_speed=4;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][7][17].wind_speed=4;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][7][18].wind_speed=4;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][7][19].wind_speed=4;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][7][20].wind_speed=4;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][7][21].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][7][22].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][7][23].wind_speed=2;

    //сентябрь|час
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][8][0].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][8][1].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][8][2].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][8][3].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][8][4].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][8][5].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][8][6].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][8][7].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][8][8].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][8][9].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][8][10].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][8][11].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][8][12].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][8][13].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][8][14].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][8][15].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][8][16].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][8][17].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][8][18].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][8][19].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][8][20].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][8][21].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][8][22].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][8][23].wind_speed=1;

    //отябрь|час
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][9][0].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][9][1].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][9][2].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][9][3].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][9][4].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][9][5].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][9][6].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][9][7].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][9][8].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][9][9].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][9][10].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][9][11].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][9][12].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][9][13].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][9][14].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][9][15].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][9][16].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][9][17].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][9][18].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][9][19].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][9][20].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][9][21].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][9][22].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][9][23].wind_speed=1;

    //ноябрь|час
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][10][0].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][10][1].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][10][2].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][10][3].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][10][4].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][10][5].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][10][6].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][10][7].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][10][8].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][10][9].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][10][10].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][10][11].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][10][12].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][10][13].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][10][14].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][10][15].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][10][16].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][10][17].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][10][18].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][10][19].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][10][20].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][10][21].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][10][22].wind_speed=1;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][10][23].wind_speed=1;

    //декабрь|час
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][11][0].wind_speed=3;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][11][1].wind_speed=3;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][11][2].wind_speed=3;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][11][3].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][11][4].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][11][5].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][11][6].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][11][7].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][11][8].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][11][9].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][11][10].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][11][11].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][11][12].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][11][13].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][11][14].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][11][15].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][11][16].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][11][17].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][11][18].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][11][19].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][11][20].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][11][21].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][11][22].wind_speed=2;
    regions[REPUBLIC_OF_SAKHA_YAKUTIA][11][23].wind_speed=2;
    regions[SAKHALIN_REGION][0][0].wind_speed=4;
    regions[SAKHALIN_REGION][0][1].wind_speed=4;
    regions[SAKHALIN_REGION][0][2].wind_speed=4;
    regions[SAKHALIN_REGION][0][3].wind_speed=4;
    regions[SAKHALIN_REGION][0][4].wind_speed=4;
    regions[SAKHALIN_REGION][0][5].wind_speed=4;
    regions[SAKHALIN_REGION][0][6].wind_speed=3;
    regions[SAKHALIN_REGION][0][7].wind_speed=3;
    regions[SAKHALIN_REGION][0][8].wind_speed=3;
    regions[SAKHALIN_REGION][0][9].wind_speed=3;
    regions[SAKHALIN_REGION][0][10].wind_speed=3;
    regions[SAKHALIN_REGION][0][11].wind_speed=3;
    regions[SAKHALIN_REGION][0][12].wind_speed=2;
    regions[SAKHALIN_REGION][0][13].wind_speed=2;
    regions[SAKHALIN_REGION][0][14].wind_speed=2;
    regions[SAKHALIN_REGION][0][15].wind_speed=1;
    regions[SAKHALIN_REGION][0][16].wind_speed=1;
    regions[SAKHALIN_REGION][0][17].wind_speed=1;
    regions[SAKHALIN_REGION][0][18].wind_speed=2;
    regions[SAKHALIN_REGION][0][19].wind_speed=2;
    regions[SAKHALIN_REGION][0][20].wind_speed=2;
    regions[SAKHALIN_REGION][0][21].wind_speed=2;
    regions[SAKHALIN_REGION][0][22].wind_speed=2;
    regions[SAKHALIN_REGION][0][23].wind_speed=2;

       //февраль|час
    regions[SAKHALIN_REGION][1][0].wind_speed=1;
    regions[SAKHALIN_REGION][1][1].wind_speed=1;
    regions[SAKHALIN_REGION][1][2].wind_speed=1;
    regions[SAKHALIN_REGION][1][3].wind_speed=2;
    regions[SAKHALIN_REGION][1][4].wind_speed=2;
    regions[SAKHALIN_REGION][1][5].wind_speed=2;
    regions[SAKHALIN_REGION][1][6].wind_speed=2;
    regions[SAKHALIN_REGION][1][7].wind_speed=2;
    regions[SAKHALIN_REGION][1][8].wind_speed=2;
    regions[SAKHALIN_REGION][1][9].wind_speed=3;
    regions[SAKHALIN_REGION][1][10].wind_speed=3;
    regions[SAKHALIN_REGION][1][11].wind_speed=3;
    regions[SAKHALIN_REGION][1][12].wind_speed=2;
    regions[SAKHALIN_REGION][1][13].wind_speed=2;
    regions[SAKHALIN_REGION][1][14].wind_speed=2;
    regions[SAKHALIN_REGION][1][15].wind_speed=3;
    regions[SAKHALIN_REGION][1][16].wind_speed=3;
    regions[SAKHALIN_REGION][1][17].wind_speed=3;
    regions[SAKHALIN_REGION][1][18].wind_speed=1;
    regions[SAKHALIN_REGION][1][19].wind_speed=1;
    regions[SAKHALIN_REGION][1][20].wind_speed=1;
    regions[SAKHALIN_REGION][1][21].wind_speed=2;
    regions[SAKHALIN_REGION][1][22].wind_speed=2;
    regions[SAKHALIN_REGION][1][23].wind_speed=2;

    //март|час
    regions[SAKHALIN_REGION][2][0].wind_speed=5;
    regions[SAKHALIN_REGION][2][1].wind_speed=5;
    regions[SAKHALIN_REGION][2][2].wind_speed=5;
    regions[SAKHALIN_REGION][2][3].wind_speed=4;
    regions[SAKHALIN_REGION][2][4].wind_speed=4;
    regions[SAKHALIN_REGION][2][5].wind_speed=4;
    regions[SAKHALIN_REGION][2][6].wind_speed=1;
    regions[SAKHALIN_REGION][2][7].wind_speed=1;
    regions[SAKHALIN_REGION][2][8].wind_speed=1;
    regions[SAKHALIN_REGION][2][9].wind_speed=2;
    regions[SAKHALIN_REGION][2][10].wind_speed=2;
    regions[SAKHALIN_REGION][2][11].wind_speed=2;
    regions[SAKHALIN_REGION][2][12].wind_speed=4;
    regions[SAKHALIN_REGION][2][13].wind_speed=4;
    regions[SAKHALIN_REGION][2][14].wind_speed=4;
    regions[SAKHALIN_REGION][2][15].wind_speed=5;
    regions[SAKHALIN_REGION][2][16].wind_speed=5;
    regions[SAKHALIN_REGION][2][17].wind_speed=5;
    regions[SAKHALIN_REGION][2][18].wind_speed=2;
    regions[SAKHALIN_REGION][2][19].wind_speed=2;
    regions[SAKHALIN_REGION][2][20].wind_speed=2;
    regions[SAKHALIN_REGION][2][21].wind_speed=1;
    regions[SAKHALIN_REGION][2][22].wind_speed=1;
    regions[SAKHALIN_REGION][2][23].wind_speed=1;

    //апрель|час
    regions[SAKHALIN_REGION][3][0].wind_speed=2;
    regions[SAKHALIN_REGION][3][1].wind_speed=2;
    regions[SAKHALIN_REGION][3][2].wind_speed=2;
    regions[SAKHALIN_REGION][3][3].wind_speed=3;
    regions[SAKHALIN_REGION][3][4].wind_speed=3;
    regions[SAKHALIN_REGION][3][5].wind_speed=3;
    regions[SAKHALIN_REGION][3][6].wind_speed=4;
    regions[SAKHALIN_REGION][3][7].wind_speed=4;
    regions[SAKHALIN_REGION][3][8].wind_speed=4;
    regions[SAKHALIN_REGION][3][9].wind_speed=3;
    regions[SAKHALIN_REGION][3][10].wind_speed=3;
    regions[SAKHALIN_REGION][3][11].wind_speed=3;
    regions[SAKHALIN_REGION][3][12].wind_speed=5;
    regions[SAKHALIN_REGION][3][13].wind_speed=5;
    regions[SAKHALIN_REGION][3][14].wind_speed=5;
    regions[SAKHALIN_REGION][3][15].wind_speed=5;
    regions[SAKHALIN_REGION][3][16].wind_speed=5;
    regions[SAKHALIN_REGION][3][17].wind_speed=5;
    regions[SAKHALIN_REGION][3][18].wind_speed=2;
    regions[SAKHALIN_REGION][3][19].wind_speed=2;
    regions[SAKHALIN_REGION][3][20].wind_speed=2;
    regions[SAKHALIN_REGION][3][21].wind_speed=2;
    regions[SAKHALIN_REGION][3][22].wind_speed=2;
    regions[SAKHALIN_REGION][3][23].wind_speed=2;

    //май|час
    regions[SAKHALIN_REGION][4][0].wind_speed=1;
    regions[SAKHALIN_REGION][4][1].wind_speed=1;
    regions[SAKHALIN_REGION][4][2].wind_speed=1;
    regions[SAKHALIN_REGION][4][3].wind_speed=3;
    regions[SAKHALIN_REGION][4][4].wind_speed=3;
    regions[SAKHALIN_REGION][4][5].wind_speed=3;
    regions[SAKHALIN_REGION][4][6].wind_speed=3;
    regions[SAKHALIN_REGION][4][7].wind_speed=3;
    regions[SAKHALIN_REGION][4][8].wind_speed=3;
    regions[SAKHALIN_REGION][4][9].wind_speed=6;
    regions[SAKHALIN_REGION][4][10].wind_speed=6;
    regions[SAKHALIN_REGION][4][11].wind_speed=6;
    regions[SAKHALIN_REGION][4][12].wind_speed=5;
    regions[SAKHALIN_REGION][4][13].wind_speed=5;
    regions[SAKHALIN_REGION][4][14].wind_speed=5;
    regions[SAKHALIN_REGION][4][15].wind_speed=4;
    regions[SAKHALIN_REGION][4][16].wind_speed=4;
    regions[SAKHALIN_REGION][4][17].wind_speed=4;
    regions[SAKHALIN_REGION][4][18].wind_speed=2;
    regions[SAKHALIN_REGION][4][19].wind_speed=2;
    regions[SAKHALIN_REGION][4][20].wind_speed=2;
    regions[SAKHALIN_REGION][4][21].wind_speed=2;
    regions[SAKHALIN_REGION][4][22].wind_speed=2;
    regions[SAKHALIN_REGION][4][23].wind_speed=2;

    //июнь|час
    regions[SAKHALIN_REGION][5][0].wind_speed=1;
    regions[SAKHALIN_REGION][5][1].wind_speed=1;
    regions[SAKHALIN_REGION][5][2].wind_speed=1;
    regions[SAKHALIN_REGION][5][3].wind_speed=3;
    regions[SAKHALIN_REGION][5][4].wind_speed=3;
    regions[SAKHALIN_REGION][5][5].wind_speed=3;
    regions[SAKHALIN_REGION][5][6].wind_speed=3;
    regions[SAKHALIN_REGION][5][7].wind_speed=3;
    regions[SAKHALIN_REGION][5][8].wind_speed=3;
    regions[SAKHALIN_REGION][5][9].wind_speed=3;
    regions[SAKHALIN_REGION][5][10].wind_speed=3;
    regions[SAKHALIN_REGION][5][11].wind_speed=3;
    regions[SAKHALIN_REGION][5][12].wind_speed=4;
    regions[SAKHALIN_REGION][5][13].wind_speed=4;
    regions[SAKHALIN_REGION][5][14].wind_speed=4;
    regions[SAKHALIN_REGION][5][15].wind_speed=5;
    regions[SAKHALIN_REGION][5][16].wind_speed=5;
    regions[SAKHALIN_REGION][5][17].wind_speed=5;
    regions[SAKHALIN_REGION][5][18].wind_speed=6;
    regions[SAKHALIN_REGION][5][19].wind_speed=6;
    regions[SAKHALIN_REGION][5][20].wind_speed=6;
    regions[SAKHALIN_REGION][5][21].wind_speed=5;
    regions[SAKHALIN_REGION][5][22].wind_speed=5;
    regions[SAKHALIN_REGION][5][23].wind_speed=5;

    //июль|час
    regions[SAKHALIN_REGION][6][0].wind_speed=1;
    regions[SAKHALIN_REGION][6][1].wind_speed=1;
    regions[SAKHALIN_REGION][6][2].wind_speed=1;
    regions[SAKHALIN_REGION][6][3].wind_speed=1;
    regions[SAKHALIN_REGION][6][4].wind_speed=1;
    regions[SAKHALIN_REGION][6][5].wind_speed=1;
    regions[SAKHALIN_REGION][6][6].wind_speed=1;
    regions[SAKHALIN_REGION][6][7].wind_speed=1;
    regions[SAKHALIN_REGION][6][8].wind_speed=1;
    regions[SAKHALIN_REGION][6][9].wind_speed=2;
    regions[SAKHALIN_REGION][6][10].wind_speed=2;
    regions[SAKHALIN_REGION][6][11].wind_speed=2;
    regions[SAKHALIN_REGION][6][12].wind_speed=3;
    regions[SAKHALIN_REGION][6][13].wind_speed=3;
    regions[SAKHALIN_REGION][6][14].wind_speed=3;
    regions[SAKHALIN_REGION][6][15].wind_speed=2;
    regions[SAKHALIN_REGION][6][16].wind_speed=2;
    regions[SAKHALIN_REGION][6][17].wind_speed=2;
    regions[SAKHALIN_REGION][6][18].wind_speed=1;
    regions[SAKHALIN_REGION][6][19].wind_speed=1;
    regions[SAKHALIN_REGION][6][20].wind_speed=1;
    regions[SAKHALIN_REGION][6][21].wind_speed=3;
    regions[SAKHALIN_REGION][6][22].wind_speed=3;
    regions[SAKHALIN_REGION][6][23].wind_speed=3;

    //август|час
    regions[SAKHALIN_REGION][7][0].wind_speed=1;
    regions[SAKHALIN_REGION][7][1].wind_speed=1;
    regions[SAKHALIN_REGION][7][2].wind_speed=1;
    regions[SAKHALIN_REGION][7][3].wind_speed=1;
    regions[SAKHALIN_REGION][7][4].wind_speed=1;
    regions[SAKHALIN_REGION][7][5].wind_speed=1;
    regions[SAKHALIN_REGION][7][6].wind_speed=2;
    regions[SAKHALIN_REGION][7][7].wind_speed=2;
    regions[SAKHALIN_REGION][7][8].wind_speed=2;
    regions[SAKHALIN_REGION][7][9].wind_speed=3;
    regions[SAKHALIN_REGION][7][10].wind_speed=3;
    regions[SAKHALIN_REGION][7][11].wind_speed=3;
    regions[SAKHALIN_REGION][7][12].wind_speed=4;
    regions[SAKHALIN_REGION][7][13].wind_speed=4;
    regions[SAKHALIN_REGION][7][14].wind_speed=4;
    regions[SAKHALIN_REGION][7][15].wind_speed=4;
    regions[SAKHALIN_REGION][7][16].wind_speed=4;
    regions[SAKHALIN_REGION][7][17].wind_speed=4;
    regions[SAKHALIN_REGION][7][18].wind_speed=1;
    regions[SAKHALIN_REGION][7][19].wind_speed=1;
    regions[SAKHALIN_REGION][7][20].wind_speed=1;
    regions[SAKHALIN_REGION][7][21].wind_speed=2;
    regions[SAKHALIN_REGION][7][22].wind_speed=2;
    regions[SAKHALIN_REGION][7][23].wind_speed=2;

    //сентябрь|час
    regions[SAKHALIN_REGION][8][0].wind_speed=7;
    regions[SAKHALIN_REGION][8][1].wind_speed=7;
    regions[SAKHALIN_REGION][8][2].wind_speed=7;
    regions[SAKHALIN_REGION][8][3].wind_speed=6;
    regions[SAKHALIN_REGION][8][4].wind_speed=6;
    regions[SAKHALIN_REGION][8][5].wind_speed=6;
    regions[SAKHALIN_REGION][8][6].wind_speed=5;
    regions[SAKHALIN_REGION][8][7].wind_speed=5;
    regions[SAKHALIN_REGION][8][8].wind_speed=5;
    regions[SAKHALIN_REGION][8][9].wind_speed=3;
    regions[SAKHALIN_REGION][8][10].wind_speed=3;
    regions[SAKHALIN_REGION][8][11].wind_speed=3;
    regions[SAKHALIN_REGION][8][12].wind_speed=5;
    regions[SAKHALIN_REGION][8][13].wind_speed=5;
    regions[SAKHALIN_REGION][8][14].wind_speed=5;
    regions[SAKHALIN_REGION][8][15].wind_speed=5;
    regions[SAKHALIN_REGION][8][16].wind_speed=5;
    regions[SAKHALIN_REGION][8][17].wind_speed=5;
    regions[SAKHALIN_REGION][8][18].wind_speed=2;
    regions[SAKHALIN_REGION][8][19].wind_speed=2;
    regions[SAKHALIN_REGION][8][20].wind_speed=2;
    regions[SAKHALIN_REGION][8][21].wind_speed=4;
    regions[SAKHALIN_REGION][8][22].wind_speed=4;
    regions[SAKHALIN_REGION][8][23].wind_speed=4;

    //отябрь|час
    regions[SAKHALIN_REGION][9][0].wind_speed=3;
    regions[SAKHALIN_REGION][9][1].wind_speed=3;
    regions[SAKHALIN_REGION][9][2].wind_speed=3;
    regions[SAKHALIN_REGION][9][3].wind_speed=2;
    regions[SAKHALIN_REGION][9][4].wind_speed=2;
    regions[SAKHALIN_REGION][9][5].wind_speed=2;
    regions[SAKHALIN_REGION][9][6].wind_speed=1;
    regions[SAKHALIN_REGION][9][7].wind_speed=1;
    regions[SAKHALIN_REGION][9][8].wind_speed=1;
    regions[SAKHALIN_REGION][9][9].wind_speed=1;
    regions[SAKHALIN_REGION][9][10].wind_speed=1;
    regions[SAKHALIN_REGION][9][11].wind_speed=1;
    regions[SAKHALIN_REGION][9][12].wind_speed=1;
    regions[SAKHALIN_REGION][9][13].wind_speed=1;
    regions[SAKHALIN_REGION][9][14].wind_speed=1;
    regions[SAKHALIN_REGION][9][15].wind_speed=3;
    regions[SAKHALIN_REGION][9][16].wind_speed=3;
    regions[SAKHALIN_REGION][9][17].wind_speed=3;
    regions[SAKHALIN_REGION][9][18].wind_speed=4;
    regions[SAKHALIN_REGION][9][19].wind_speed=4;
    regions[SAKHALIN_REGION][9][20].wind_speed=4;
    regions[SAKHALIN_REGION][9][21].wind_speed=2;
    regions[SAKHALIN_REGION][9][22].wind_speed=2;
    regions[SAKHALIN_REGION][9][23].wind_speed=2;

    //ноябрь|час
    regions[SAKHALIN_REGION][10][0].wind_speed=2;
    regions[SAKHALIN_REGION][10][1].wind_speed=2;
    regions[SAKHALIN_REGION][10][2].wind_speed=2;
    regions[SAKHALIN_REGION][10][3].wind_speed=3;
    regions[SAKHALIN_REGION][10][4].wind_speed=3;
    regions[SAKHALIN_REGION][10][5].wind_speed=3;
    regions[SAKHALIN_REGION][10][6].wind_speed=2;
    regions[SAKHALIN_REGION][10][7].wind_speed=2;
    regions[SAKHALIN_REGION][10][8].wind_speed=2;
    regions[SAKHALIN_REGION][10][9].wind_speed=3;
    regions[SAKHALIN_REGION][10][10].wind_speed=3;
    regions[SAKHALIN_REGION][10][11].wind_speed=3;
    regions[SAKHALIN_REGION][10][12].wind_speed=3;
    regions[SAKHALIN_REGION][10][13].wind_speed=3;
    regions[SAKHALIN_REGION][10][14].wind_speed=3;
    regions[SAKHALIN_REGION][10][15].wind_speed=2;
    regions[SAKHALIN_REGION][10][16].wind_speed=2;
    regions[SAKHALIN_REGION][10][17].wind_speed=2;
    regions[SAKHALIN_REGION][10][18].wind_speed=2;
    regions[SAKHALIN_REGION][10][19].wind_speed=2;
    regions[SAKHALIN_REGION][10][20].wind_speed=2;
    regions[SAKHALIN_REGION][10][21].wind_speed=2;
    regions[SAKHALIN_REGION][10][22].wind_speed=2;
    regions[SAKHALIN_REGION][10][23].wind_speed=2;

    //декабрь|час
    regions[SAKHALIN_REGION][11][0].wind_speed=3;
    regions[SAKHALIN_REGION][11][1].wind_speed=3;
    regions[SAKHALIN_REGION][11][2].wind_speed=3;
    regions[SAKHALIN_REGION][11][3].wind_speed=3;
    regions[SAKHALIN_REGION][11][4].wind_speed=3;
    regions[SAKHALIN_REGION][11][5].wind_speed=3;
    regions[SAKHALIN_REGION][11][6].wind_speed=3;
    regions[SAKHALIN_REGION][11][7].wind_speed=3;
    regions[SAKHALIN_REGION][11][8].wind_speed=3;
    regions[SAKHALIN_REGION][11][9].wind_speed=3;
    regions[SAKHALIN_REGION][11][10].wind_speed=3;
    regions[SAKHALIN_REGION][11][11].wind_speed=3;
    regions[SAKHALIN_REGION][11][12].wind_speed=3;
    regions[SAKHALIN_REGION][11][13].wind_speed=3;
    regions[SAKHALIN_REGION][11][14].wind_speed=3;
    regions[SAKHALIN_REGION][11][15].wind_speed=2;
    regions[SAKHALIN_REGION][11][16].wind_speed=2;
    regions[SAKHALIN_REGION][11][17].wind_speed=2;
    regions[SAKHALIN_REGION][11][18].wind_speed=3;
    regions[SAKHALIN_REGION][11][19].wind_speed=3;
    regions[SAKHALIN_REGION][11][20].wind_speed=3;
    regions[SAKHALIN_REGION][11][21].wind_speed=2;
    regions[SAKHALIN_REGION][11][22].wind_speed=2;
    regions[SAKHALIN_REGION][11][23].wind_speed=2;



  std::vector<reg_rad> reg_rad;
  reg_rad=in_reg_rad_dagestan();
    std::cout << "Starting GLFW context, OpenGL 3.colores.txt 3" << std::endl;
    // Init GLFW
    glfwInit();


    Window test{WIDTH,HEIGHT,"TEST"};
  //  glfwWindowHint(GLFW_DECORATED,GL_FALSE);
    glfwWindowHint(GLFW_VISIBLE,GL_FALSE);
    Window test2{WIDTH,HEIGHT,"graficks"};
    glfwSetWindowCloseCallback(test2.window,close_callback);
    //glfwSetFramebufferSizeCallback(test2.window, framebuffer_size_callback);
    //glfwHideWindow (окно);
    //glfwShowWindow (test2);
    glfwMakeContextCurrent(test.window);
    glfwSetKeyCallback(test.window, key_callback);
    glfwSetScrollCallback(test.window,scroll_callback);
    //glfwSetFramebufferSizeCallback(test.window, framebuffer_size_callback);
    // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
    glfwSetInputMode(test.window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    glfwSetCursorPos(test.window,test.width/2,test.height/2);
 glewExperimental = GL_TRUE;
    // Initialize GLEW to setup the OpenGL Function pointers
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

Buffer_VAO VAOsb=skybox_VAO();
Buffer_VAO VAO_p=plate_VAO();

Shader      ourShader(Directory_shaders+"vector.txt"     ,Directory_shaders+"colores7.txt");
Shader       shederId(Directory_shaders+"vector.txt"     ,Directory_shaders+"coloresId.txt");
Shader    ourShader11(Directory_shaders+"vector.txt"     ,Directory_shaders+ "colores1.txt");
Shader materialSheder(Directory_shaders+"vector.txt"     ,Directory_shaders+ "colores2.txt");
Shader   skyboxSheder(Directory_shaders+"vectorSB.txt"   ,Directory_shaders+"coloresSB.txt");
Shader     textShader(Directory_shaders+"vectorText1.txt",Directory_shaders+"coloresText.txt");

std::vector<std::string> faces1;
std::string Directory_skybox="Sky_box4/";
faces1.push_back(Directory_pictures+Directory_skybox+"right.jpg");
faces1.push_back(Directory_pictures+Directory_skybox+"left.jpg");
faces1.push_back(Directory_pictures+Directory_skybox+"top.jpg");
faces1.push_back(Directory_pictures+Directory_skybox+"bottom.jpg");
faces1.push_back(Directory_pictures+Directory_skybox+"front.jpg");
faces1.push_back(Directory_pictures+Directory_skybox+"back.jpg");

std::vector<std::string> faces2;


faces2.push_back(Directory_pictures+Directory_skybox+"posx.jpg");//
faces2.push_back(Directory_pictures+Directory_skybox+"negx.jpg");

faces2.push_back(Directory_pictures+Directory_skybox+"posy.jpg");//
faces2.push_back(Directory_pictures+Directory_skybox+"negy.jpg");//

faces2.push_back(Directory_pictures+Directory_skybox+"posz.jpg");//
faces2.push_back(Directory_pictures+Directory_skybox+"negz.jpg");//

Animation                   skybox_t(faces2,                                       D26A,Map_cub      ,1,1,1,-1);
Animation                      cubes(Directory_pictures+"picters.png",             D21A,Map_diffusion,1,1,1,-1);
Animation                 interface1(Directory_pictures+"inerfec.png",             D21A,Map_diffusion,1,1,1,-1);
Animation         interfaceLightning(Directory_pictures+"lightning.png",           D21A,Map_diffusion,1,1,1,-1);
//Animation           n gros_texture(Directory_pictures+"groses1",                 D21A,Map_diffusion,1,1,1,-1);
//Animation               menu_panel(Directory_pictures+"menu_Panel.png",          D21A,Map_diffusion,1,1,1,-1);
Animation      start_display_texyure(Directory_pictures+"LOGO.png",                D21A,Map_diffusion,1,1,1,-1);
Animation        input_field_texture(Directory_pictures+"jjj1.png",                D21A,Map_diffusion,1,1,1,-1);
Animation             rect_1_texture(Directory_pictures+"rect.png",                D21A,Map_diffusion,1,1,1,-1);
Animation             rect_2_texture(Directory_pictures+"rect_2.png",              D21A,Map_diffusion,1,1,1,-1);
Animation                      start(Directory_pictures+"start.png",               D21A,Map_diffusion,1,1,1,-1);
Animation                       stop(Directory_pictures+"stop.png",                D21A,Map_diffusion,1,1,1,-1);
Animation                      reset(Directory_pictures+"reset.png",               D21A,Map_diffusion,1,1,1,-1);
Animation      setting_model_texture(Directory_pictures+"setting_model_button.png",D21A,Map_diffusion,1,1,1,-1);
Animation                       cods(Directory_pictures+"jjj1.png",                D21A,Map_diffusion,1,1,1,-1);
Animation                 grid_class(Directory_pictures+"VEU_class_alternative-2.png",                D21A,Map_diffusion,1,1,1,-1);
Animation                     closed(Directory_pictures+"closed.png",              D21A,Map_diffusion,1,1,1,-1);

Animation                       font(Directory_pictures+"Hack_Regular.png",D21A,Map_diffusion,256,32,8,1);
Animation   input_field_text_texrure(Directory_pictures+"jjj1-input.png",   D21A,Map_diffusion,1,1,1,-1);
Animation                 button_PHT(Directory_pictures+"button_PHT.png",   D21A,Map_diffusion,1,1,1,-1);
Animation              marker_orange(Directory_pictures+"marker_orange.png",   D21A,Map_diffusion,1,1,1,-1);
Animation                  icon_graf(Directory_pictures+"graf_icon.png",    D21A,Map_diffusion,1,1,1,-1);
Animation                       logo(Directory_pictures+"logo.png",    D21A,Map_diffusion,1,1,1,-1);

Font font_Hack(font);


// Game loop
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glEnable(GL_MULTISAMPLE);
  //  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ZERO);
    ////


glfwMakeContextCurrent(test2.window);
Buffer_VAO VAO_p_1=plate_VAO();

Shader          ourShader_1(Directory_shaders+"vector.txt"          ,Directory_shaders+"colores7.txt");
Shader    ourShader_1_color(Directory_shaders+"vector.txt"          ,Directory_shaders+"colores8.txt");

Shader      ourShader_Chart(Directory_shaders+"vectorChart.txt"     ,Directory_shaders+"coloresChart.txt");
Shader           shederId_1(Directory_shaders+"vector.txt"          ,Directory_shaders+"coloresId.txt");
Shader        ourShader11_1(Directory_shaders+"vector.txt"          ,Directory_shaders+ "colores1.txt");
Shader         textShader_1(Directory_shaders+"vectorText1.txt",Directory_shaders+"coloresText.txt");

Animation         start_display_texyure_1(Directory_pictures+"LOGO.png",                   D21A,Map_diffusion,1,1,1,-1);
Animation                           white(Directory_pictures+"white.png",                  D21A,Map_diffusion,1,1,1,-1);
Animation                    white_button(Directory_pictures+"white_button.png",           D21A,Map_diffusion,1,1,1,-1);
Animation        input_field_texture_graf(Directory_pictures+"setting_graf_1.png",         D21A,Map_diffusion,1,1,1,-1);
Animation                    querty_white(Directory_pictures+"querty_white.png",           D21A,Map_diffusion,1,1,1,-1);
Animation  setting_graf__diapozon_texture(Directory_pictures+"setting_graf__diapozon.png", D21A,Map_diffusion,1,1,1,-1);
Animation                           cross(Directory_pictures+"cross.png",                  D21A,Map_diffusion,1,1,1,-1);
Animation                          button(Directory_pictures+"setting_graf_button.png",    D21A,Map_diffusion,1,1,1,-1);
Animation                      start_graf(Directory_pictures+"start.png",               D21A,Map_diffusion,1,1,1,-1);
Animation                       stop_graf(Directory_pictures+"stop.png",                D21A,Map_diffusion,1,1,1,-1);


Animation                       font_1(Directory_pictures+"Samson_light_Regular.png",D21A,Map_diffusion,256,32,8,1);
Animation                       font_2(Directory_pictures+"Hack_Regular.png",        D21A,Map_diffusion,256,32,8,1);

Font font_Samson(font_1);
Font font_Hack_2(font_2);

std::vector<Vertex> vertices;
Vertex T(glm::vec3(0.0f,0.0f,0.0f),
         glm::vec3(0.0f,0.0f,0.0f),
         glm::vec2(0.0f,0.0f),
         glm::vec3(0.0f,0.0f,0.0f),
         glm::vec3(0.0f,0.0f,0.0f));


std::vector<unsigned int> index;
int k_k=1;
std::cout<<"@@@@@@@@@@@@@@@@@@@@@@@"<<std::endl;
for(unsigned int i = 0; i <24*60*60*100+100; i=i+100){

    if(i%864==0){
       k_k++;
    }

    T.Position.x=i;
    T.Position.y=std::pow(i,0.05)*10.1f;
    T.Position.z=0.0f;
    //std::cout<<i<<"||"<<"{"<<sin(i)*2.1f*2.0f/4.0f<<"}"<<std::endl;
     T.TexCoords1=std::move(glm::vec2(0.0f, 0.0f));

    vertices.push_back(T);
      };




Buffer_VAO VAO_(vertices,index);

std::vector<Vertex> vertices1;
Vertex T1(glm::vec3(0.0f,0.0f,0.0f),
         glm::vec3(0.0f,0.0f,0.0f),
         glm::vec2(0.0f,0.0f),
         glm::vec3(0.0f,0.0f,0.0f),
         glm::vec3(0.0f,0.0f,0.0f));


std::vector<unsigned int> index1;
std::cout<<"@@@@@@@@@@@@@@@@@@@@@@@"<<std::endl;
for(unsigned int i = 0; i <24*60*60*100+100; i=i+100){

    T1.Position.x=i;
    T1.Position.y=std::pow(i,0.05)*20.1f;
    T1.Position.z=0.0f;
    T1.TexCoords1=std::move(glm::vec2(0.0f, 0.0f));

    vertices1.push_back(T1);
      };

Buffer_VAO VAO____1(vertices1,index1);


std::vector<Vertex> vertices2;
Vertex T2(glm::vec3(0.0f,0.0f,0.0f),
         glm::vec3(0.0f,0.0f,0.0f),
         glm::vec2(0.0f,0.0f),
         glm::vec3(0.0f,0.0f,0.0f),
         glm::vec3(0.0f,0.0f,0.0f));


std::vector<unsigned int> index2;
std::cout<<"@@@@@@@@@@@@@@@@@@@@@@@"<<std::endl;
for(unsigned int i = 0; i <24*60*60*100+100; i=i+100){

    T2.Position.x=i;
    T2.Position.y=std::pow(i,0.05)*30.1f;
    T2.Position.z=0.0f;
    T2.TexCoords1=std::move(glm::vec2(0.0f, 0.0f));
    vertices2.push_back(T2);
      };

Buffer_VAO VAO____2(vertices2,index2);

Model start_display_1(ourShader_1,VAO_p_1,&mat1,&mat1,glm::mat4{1.0f});
start_display_1.position.scale(glm::vec3(2.0f,2.0f,1.0f));
start_display_1.textures.push_back(start_display_texyure_1);//





Chart chart_1(ourShader_Chart,&mat1,&mat1,glm::mat4{1.0f},glm::vec3(0.0f,0.5f,0.7f));
chart_1.graf_new(VAO_);
chart_1.Set_time(1);
chart_1.position.move(glm::vec3(-1.0f,0.5f,0.0f));
chart_1.position.scale(glm::vec3(0.333f,0.5f,1.0f));

std::vector<Text>  text_name_graf;
std::vector<Text>  text_division_x;
std::vector<Text>  text_division_y;

std::vector<Text> dimension_x;
std::vector<Text> dimension_y;

bool char_job[12];
for(auto &T:char_job){
    T=false;
}
int current_char=0;
char_job[0]=true;
std::vector<Chart> charts;
std::vector<Chart> charts_separate;
std::vector<Chart> lines_x;
std::vector<Chart> lines_y;
std::vector<Model> background;
std::vector<Model> buttons;
std::vector<Animation> button_texture;
for(int k=0;k<4;k++){
    for(int j=0;j<4;j++){
        text_name_graf.emplace_back(textShader_1,&mat1,&mat1,glm::mat4{1.0f},font_Hack_2,"1");
        text_name_graf.back().position.move(glm::vec3(-1.0f+(101.0f)/1920.0f+0.238f+101.0f/1920.0f*0.5*9+101.0f/1920.0f*0.5f*16.5f*j-0.210f,0.95f-0.666f*k,0.0f));
        text_name_graf.back().position.scale(glm::vec3(0.025f*0.42f,0.1f*0.42f,1.0f));

        dimension_x.emplace_back(textShader_1,&mat1,&mat1,glm::mat4{1.0f},font_Hack_2,"1");
        dimension_x.back().position.move(glm::vec3(-1.0f+0.261f+0.021-0.035f+0.07*6+(0.434f)*j,1.0f-0.588f-0.666f*k+0.04f,0.0f));
        dimension_x.back().position.scale(glm::vec3(0.025f*0.7f,0.1f*0.7f,1.0f));

        dimension_y.emplace_back(textShader_1,&mat1,&mat1,glm::mat4{1.0f},font_Hack_2,"1");
        dimension_y.back().position.move(glm::vec3(-1.0f+0.251f+0.01f+(0.434f)*j,1.0f-0.11f-0.666f*k+0.04f,0.0f));
        dimension_y.back().position.scale(glm::vec3(0.025f*0.35f,0.1f*0.35f,1.0f));

        charts.emplace_back(ourShader_Chart,&mat1,&mat1,glm::vec3(0.261f,1.0f-0.333f,0.0f),glm::vec3(0.5f,0.3f,0.7f));
        charts.back().graf_new(VAO_);
        charts.back().Set_time(1);
        charts.back().grid_x=j;
        charts.back().grid_y=k;

        charts.back().position.move(glm::vec3(-1.0f+0.434f*j+0.434f*0.1f,-0.666f*k-0.434*0.5*0.75f,0.0f));
        charts.back().position.scale(glm::vec3(0.434f*0.5f*0.8f,0.434f*0.5f*0.89f,1.0f));//неправильный маштаб:)

        charts_separate.emplace_back(ourShader_Chart,&mat1,&mat1,/*glm::vec3(0.261f,1.0f-0.333f,0.0f)*/glm::vec3(0.0f,0.0f,0.0f),glm::vec3(0.5f,0.3f,0.7f));
        charts_separate.back().graf_new(VAO_);
        charts_separate.back().Set_time(1);
        charts_separate.back().grid_x=0;
        charts_separate.back().grid_y=0;
        charts_separate.back().position.move(glm::vec3(-0.653f,-0.862f,0.0f));
        charts_separate.back().position.scale(glm::vec3(0.434f*0.5f*0.8f*4.615,0.434f*0.5f*0.89f*4.4,1.0f));//неправильный маштаб:)

        background.emplace_back(ourShader_1,VAO_p_1,&mat1,&mat1,glm::vec3(0.434f*0.5f+0.261f,1.0f-0.333f,0.7f));
        background.back().position.move(glm::vec3(-1.0f+0.434*j,0.0f-0.666f*k,0.0f));
        background.back().position.scale(glm::vec3(0.434f,0.666f,1.0f));
        background.back().textures.push_back(white);
        for(int i=0;i<6;i++){
        lines_x.emplace_back(ourShader_Chart,&mat1,&mat1,glm::vec3(0.261f,0.0f,0.0f),glm::vec3(1.0f,1.0f,1.0f));
        lines_x.back().position.move(glm::vec3(-1.0f+0.434f*j+0.434f*0.1f+0.07f*i,0.460f-0.666f*k,0.0f));
        lines_x.back().position.scale(glm::vec3(0.434f*0.5f*0.8f,0.460f,1.0f));
        text_division_x.emplace_back(textShader_1,&mat1,&mat1,glm::mat4{1.0f},font_Samson,"1");
        text_division_x.back().position.move(glm::vec3(-1.0f+0.261f+0.021+0.07f*i+(0.434f)*j,1.0f-0.588f-0.666f*k,0.0f));
        text_division_x.back().position.scale(glm::vec3(0.025f*0.45f,0.1f*0.45f,1.0f));

        lines_y.emplace_back(ourShader_Chart,&mat1,&mat1,glm::vec3(0.261f,0.0f,0.0f),glm::vec3(1.0f,1.0f,1.0f));
        lines_y.back().position.rotete(glm::vec3(1.0f, 1.0f, 0.0f),180.0f);
        lines_y.back().position.move(glm::vec3(-1.0f+0.434f*j+0.434f*0.1f,1.0f-0.11f-0.666f*k-0.08f*i,0.0f));
        lines_y.back().position.scale(glm::vec3(0.434f*0.5f*0.8f*2.01f,0.460f,1.0f));
        text_division_y.emplace_back(textShader_1,&mat1,&mat1,glm::mat4{1.0f},font_Samson,"1");
        text_division_y.back().position.move(glm::vec3(-1.0f+0.261f+0.01f+(0.434f)*j,1.0f-0.11f-0.666f*k-0.08f*i,0.0f));
        text_division_y.back().position.scale(glm::vec3(0.025f*0.45f,0.1f*0.45f,1.0f));
      //  text_division.back().color_text=glm::vec3{0.0f,0.5f,0.0f};
        }

    }
}
///////
std::vector<Chart> lines_x_separate;
std::vector<Chart> lines_y_separate;
std::vector<Model> background_separate;
std::vector<Model> buttons_separate;
std::vector<Animation> button_texture_separate;

Text  dimension_x_separate(textShader_1,&mat1,&mat1,glm::mat4{1.0f},font_Hack_2,"1");
dimension_x_separate.position.move(glm::vec3(-1.0f+0.261f+0.021+0.07f*23.55+0.04f,1.0f-0.555f-1.35f,0.0f));
dimension_x_separate.position.scale(glm::vec3(0.025f*0.7f,0.1f*0.7f,1.0f));

Text  dimension_y_separate(textShader_1,&mat1,&mat1,glm::mat4{1.0f},font_Hack_2,"1");
dimension_y_separate.position.move(glm::vec3(-1.0f+0.261f+0.01f+0.04f,1.0f-0.11f+0.05,0.0f));
dimension_y_separate.position.scale(glm::vec3(0.025f*0.5f,0.1f*0.5f,1.0f));

std::vector<Text> text_division_x_separate;
std::vector<Text> text_division_y_separate;


for(int i=0;i<24;i++){
lines_x_separate.emplace_back(ourShader_Chart,&mat1,&mat1,glm::vec3(0.261f,0.0f,0.0f),glm::vec3(1.0f,1.0f,1.0f));
lines_x_separate.back().position.move(glm::vec3(-1.0f+0.434f*0.1f+0.07f*i+0.04f,0.8+0.05f,0.0f));
lines_x_separate.back().position.scale(glm::vec3(0.434f*2.0f*0.8f,1.750f,1.0f));
lines_x_separate.back().position.rotete(glm::vec3(0.0f, 0.0f, 1.0f),180.0f);//

text_division_x_separate.emplace_back(textShader_1,&mat1,&mat1,glm::mat4{1.0f},font_Samson,"1");
text_division_x_separate.back().position.move(glm::vec3(-1.0f+0.261f+0.021+0.07f*i+0.04f,1.0f-0.588f-1.35f,0.0f));
text_division_x_separate.back().position.scale(glm::vec3(0.025f*0.45f,0.1f*0.45f,1.0f));
}
lines_x_separate[0].position.scale(glm::vec3(1.02f,1.0f,1.0f));

for(int i=0;i<23;i++){
lines_y_separate.emplace_back(ourShader_Chart,&mat1,&mat1,glm::vec3(0.261f,0.0f,0.0f),glm::vec3(1.0f,1.0f,1.0f));
lines_y_separate.back().position.rotete(glm::vec3(1.0f, 1.0f, 0.0f),180.0f);
lines_y_separate.back().position.move(glm::vec3(-1.0f+0.434f*0.1f+0.04f,1.0f-0.11f-0.08f*i,0.0f));
lines_y_separate.back().position.scale(glm::vec3(0.434f*2.0f*0.8f*2.32f,0.460f,1.0f));

text_division_y_separate.emplace_back(textShader_1,&mat1,&mat1,glm::mat4{1.0f},font_Samson,"1");
text_division_y_separate.back().position.move(glm::vec3(-1.0f+0.261f+0.01f,1.0f-0.11f-0.08f*i+0.05,0.0f));
text_division_y_separate.back().position.scale(glm::vec3(0.025f*0.45f,0.1f*0.45f,1.0f));
//  text_division.back().color_text=glm::vec3{0.0f,0.5f,0.0f};
}
lines_y_separate[22].position.scale(glm::vec3(1.02f,1.0f,1.0f));

Text text_name_graf_separate(textShader_1,&mat1,&mat1,glm::mat4{1.0f},font_Hack_2,"1");
text_name_graf_separate.position.move(glm::vec3(-1.0f+(101.0f)/1920.0f+0.238f+101.0f/1920.0f*0.5*11-0.210f,0.94f,0.0f));
text_name_graf_separate.position.scale(glm::vec3(0.025f*1.3f,0.1f*1.3f,1.0f));

std::vector<std::string> name_chart;
name_chart.push_back("Все обЪекты");

name_chart.push_back("ВЭУ");
name_chart.push_back("ФЭУ");
name_chart.push_back("ДГУ");
name_chart.push_back("Li-ion");

name_chart.push_back("ВСАЭ");
name_chart.push_back("СК");
name_chart.push_back("ССТ");
name_chart.push_back("НТЭ");

name_chart.push_back("ПЭЭ");
name_chart.push_back("SOC CK");
name_chart.push_back("SOC Li-ion");
name_chart.push_back("SOC ВСАЭ");

name_chart.push_back("ПТЭ");
name_chart.push_back("");
name_chart.push_back("");
name_chart.push_back("");

for(int i=0;i<charts.size();i++){
lines_x[0+i*6].position.scale(glm::vec3(1.2f,1.1f,1.0f));
lines_y[5+i*6].position.scale(glm::vec3(1.1f,1.1f,1.0f));
charts[i].setting.visible_scale_length_y=100;
charts[i].name=name_chart[i];
charts[i].disconnect_chart();
charts_separate[i].setting.visible_scale_length_y=10000;
charts_separate[i].name=name_chart[i];
charts_separate[i].disconnect_chart();
std::cout<<"<>"<<charts[i].grid_x<<"|"<<charts[i].grid_y<<"#########################################"<<std::endl;
}

charts[6].graf_new(VAO____1);
charts[7].graf_new(VAO____2);

button_texture.emplace_back(Directory_pictures+"arrow_left.png" ,D21A,Map_diffusion,1,1,1,-1);
button_texture.emplace_back(Directory_pictures+"arrow_right.png",D21A,Map_diffusion,1,1,1,-1);
button_texture.emplace_back(Directory_pictures+"arrow_up.png"   ,D21A,Map_diffusion,1,1,1,-1);
button_texture.emplace_back(Directory_pictures+"arrow_down.png" ,D21A,Map_diffusion,1,1,1,-1);
button_texture.emplace_back(Directory_pictures+"plus.png"       ,D21A,Map_diffusion,1,1,1,-1);
button_texture.emplace_back(Directory_pictures+"plus_x.png"     ,D21A,Map_diffusion,1,1,1,-1);
button_texture.emplace_back(Directory_pictures+"plus_y.png"     ,D21A,Map_diffusion,1,1,1,-1);
button_texture.emplace_back(Directory_pictures+"minus.png"      ,D21A,Map_diffusion,1,1,1,-1);
button_texture.emplace_back(Directory_pictures+"minus_x.png"    ,D21A,Map_diffusion,1,1,1,-1);
button_texture.emplace_back(Directory_pictures+"minus_y.png"    ,D21A,Map_diffusion,1,1,1,-1);
button_texture.emplace_back(Directory_pictures+"setting.png"    ,D21A,Map_diffusion,1,1,1,-1);
button_texture.emplace_back(Directory_pictures+"mods.png"       ,D21A,Map_diffusion,1,1,1,-1);


for(int i=0;i<11;i++){
  buttons_separate.emplace_back(ourShader_1,VAO_p_1,&mat1,&mat1,glm::vec3(-1.0f+(101.0f)/1920.0f+0.235f+101.0f/1920.0f*0.43*2*i+101.0f/1920.0f*0.43f*19.2f*2+0.14f,0.94,0.0f));
  buttons_separate.back().position.scale(glm::vec3(101.0f/1920.0f*0.43f*2,135.0f/1080.0f*0.43f*2,1.0f));
  buttons_separate.back().textures.push_back(button_texture[i]);//
  buttons_separate.back().shaderIndef=shederId_1;
}


for(int k=0;k<4;k++){
    for(int j=0;j<4;j++){
      for(int i=0;i<12;i++){
        if(i<4){
        buttons.emplace_back(ourShader_1_color,VAO_p_1,&mat1,&mat1,glm::vec3(-1.0f+(101.0f)/1920.0f+0.235f+101.0f/1920.0f*0.43*i+101.0f/1920.0f*0.43f*19.2f*j+0.14f,0.94-0.666f*k,0.0f));
        buttons.back().position.scale(glm::vec3(101.0f/1920.0f*0.43f,135.0f/1080.0f*0.43f,1.0f));
        buttons.back().textures.push_back(button_texture[i]);//
        buttons.back().shaderIndef=shederId_1;
        }else{
        buttons.emplace_back(ourShader_1,VAO_p_1,&mat1,&mat1,glm::vec3(-1.0f+(101.0f)/1920.0f+0.235f+101.0f/1920.0f*0.43*i+101.0f/1920.0f*0.43f*19.2f*j+0.14f,0.94-0.666f*k,0.0f));
        buttons.back().position.scale(glm::vec3(101.0f/1920.0f*0.43f,135.0f/1080.0f*0.43f,1.0f));
        buttons.back().textures.push_back(button_texture[i]);//
        buttons.back().shaderIndef=shederId_1;
        }
      }
    }
}


std::vector<Model> menu_graf;
std::vector<Text> name_menu_graf;
for(int i=0;i<16;i++){
  menu_graf.emplace_back(ourShader_1,VAO_p_1,&mat1,&mat1,glm::vec3(-1.0f+0.238f*0.5f,1.0f-0.153*0.5f-0.153f*i,0.0f));
  menu_graf.back().position.scale(glm::vec3(0.282f,85.0f/1080.0f*2.0f,1.0f));
  menu_graf.back().textures.push_back(white_button);//
  menu_graf.back().shaderIndef=shederId_1;
  name_menu_graf.emplace_back(textShader_1,&mat1,&mat1,glm::mat4{1.0f},font_Hack_2,"1");
  name_menu_graf.back().position.move(glm::vec3(-1.0f+0.025f*1.0f,1.0f-0.153f*0.5f-0.153f*i,0.0f));
  name_menu_graf.back().position.scale(glm::vec3(0.025f*0.7f*1.1f,0.1f*0.7f*1.1f,1.0f));
}
std::vector<Text> V_graf;
for(int i=0;i<10;i++){
  V_graf.emplace_back(textShader_1,&mat1,&mat1,glm::mat4{1.0f},font_Hack_2,"1");
  V_graf.back().position.move(glm::vec3(-1.0f+0.025f*1.0f+0.1f,1.0f-0.153f*3.5f-0.153f*i,0.0f));
  V_graf.back().position.scale(glm::vec3(0.025f*0.7f*0.7f,0.1f*0.7f*0.7f,1.0f));
}

Model input_field_windous_graf(ourShader11_1,VAO_p_1,&mat1,&mat1,glm::mat4{1.0f});
input_field_windous_graf.textures.push_back(input_field_texture_graf);
input_field_windous_graf.shaderIndef=shederId_1;
input_field_windous_graf.position.scale(glm::vec3(1.0f,1.0f,1.0f));

Text diapozon_x_installation(textShader,&mat1,&mat1,glm::mat4{1.0f},font_Hack_2,"");
diapozon_x_installation.position.move(glm::vec3(-0.43f,-0.13-0.2f*0,0.0f));
diapozon_x_installation.position.scale(glm::vec3(0.25f,1.0f,1.0f));
diapozon_x_installation.position.scale(glm::vec3(0.075f,0.055f,0.2f));
diapozon_x_installation.position.scale(glm::vec3(1.5f,1.5f,0.2f));

Text diapozon_y_installation(textShader,&mat1,&mat1,glm::mat4{1.0f},font_Hack_2,"");
diapozon_y_installation.position.move(glm::vec3(-0.43f,-0.13-0.2f*1,0.0f));
diapozon_y_installation.position.scale(glm::vec3(0.25f,1.0f,1.0f));
diapozon_y_installation.position.scale(glm::vec3(0.075f,0.055f,0.2f));
diapozon_y_installation.position.scale(glm::vec3(1.5f,1.5f,0.2f));


Text header_input_field_windous_graf(textShader,&mat1,&mat1,glm::mat4{1.0f},font_Hack_2,"");
header_input_field_windous_graf.position.move(glm::vec3(-0.40f,0.45f,0.0f));
header_input_field_windous_graf.position.scale(glm::vec3(0.25f,1.0f,1.0f));
header_input_field_windous_graf.position.scale(glm::vec3(0.075f,0.055f,0.2f));
header_input_field_windous_graf.position.scale(glm::vec3(1.5f,1.5f,0.2f));


Text time_curent_model_graf(textShader_1,&mat1,&mat1,glm::mat4{1.0f},font_Hack_2,"");
time_curent_model_graf.position.move(glm::vec3(-0.98f,0.88f,0.0f));
time_curent_model_graf.position.scale(glm::vec3(0.25f,1.0f,1.0f));
time_curent_model_graf.position.scale(glm::vec3(0.075f,0.055f,0.2f));
time_curent_model_graf.position.scale(glm::vec3(1.0f,1.0f,0.2f));

Text time_curent_model_graf_yuers(textShader_1,&mat1,&mat1,glm::mat4{1.0f},font_Hack_2,"");
time_curent_model_graf_yuers.position.move(glm::vec3(-0.98f,0.95f,0.0f));
time_curent_model_graf_yuers.position.scale(glm::vec3(0.25f,1.0f,1.0f));
time_curent_model_graf_yuers.position.scale(glm::vec3(0.075f,0.055f,0.2f));
time_curent_model_graf_yuers.position.scale(glm::vec3(1.0f,1.0f,0.2f));

std::vector<Model> querty_colors;
std::vector<glm::vec3> color_chair;

std::cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^6"<<std::endl;
for(int i=0;i<125;i=i+25){
    for(int j=0;j<125;j=j+25){
        for(int k=0;k<125;k=k+25){
            std::cout<<i*0.01<<"|"<<j*0.01<<"|"<<k*0.01<<std::endl;
             color_chair.push_back(glm::vec3{k*0.01*2,i*0.01*2,j*0.01*2});
        }
    }
}


std::vector<Model> diapozon_set;
for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
        diapozon_set.emplace_back(ourShader_1,VAO_p_1,&mat1,&mat1,glm::vec3(0.025f+200.5f/1920.0f*2.0f*j+0.069f*j,-0.13-0.2f*i,0.0f));
        diapozon_set.back().position.scale(glm::vec3(200.5f/1920.0f*2.0f,71.0f/1080.0f*2.0f,1.0f));
        diapozon_set.back().textures.push_back(setting_graf__diapozon_texture);//
        diapozon_set.back().shaderIndef=shederId_1;
    }
}

std::vector<std::vector<Input_plate>> input_diapozon(25);
for(int j=0;j<16;j++){
    for(int i=0;i<diapozon_set.size();i++){
        input_diapozon[j].emplace_back(&test2,&diapozon_set[i]);
    }
}

for(auto &T:input_diapozon){
    for(auto&J:T){
        J.click_button.push_back(GLFW_MOUSE_BUTTON_LEFT);
        J.on_input();
        J.date.accuracy=0;
        J.date.max_size_input_symbol=7;
        J.date.on_imput=true;
        J.date.max_nomber=999999999.0f;
        J.date.min_nomber=-999999999.0f;
    }
}

bool cross_active[16][125];
for(int i=0;i<16;i++){
    for(auto &T:cross_active[i]){
        T=false;
    }
}

std::vector<std::vector<Input_plate>> input_diapozon_separate(25);
for(int j=0;j<16;j++){
    for(int i=0;i<diapozon_set.size();i++){
        input_diapozon_separate[j].emplace_back(&test2,&diapozon_set[i]);
    }
}

for(auto &T:input_diapozon_separate){
    for(auto&J:T){
        J.click_button.push_back(GLFW_MOUSE_BUTTON_LEFT);
        J.on_input();
        J.date.accuracy=0;
        J.date.max_size_input_symbol=7;
        J.date.on_imput=true;
        J.date.max_nomber=999999999.0f;
        J.date.min_nomber=-999999999.0f;
    }
}

bool cross_active_separate[16][125];
for(int i=0;i<16;i++){
    for(auto &T:cross_active_separate[i]){
        T=false;
    }
}


color_chair.push_back(glm::vec3{0.5,0.5,0.5});
std::vector<Model> querty_colors_cross;
for(int i=0;i<5;i++){
    for(int j=0;j<25;j++){

        querty_colors_cross.emplace_back(ourShader_1,VAO_p_1,&mat1,&mat1,glm::vec3(-0.43f+j*0.012f*3.0f,0.3-0.024*3.0*i,0.0f));
        querty_colors_cross.back().position.scale(glm::vec3(0.012f*3.0f,0.024f*3.0f,1.0f));
        querty_colors_cross.back().textures.push_back(cross);//
        querty_colors_cross.back().shaderIndef=shederId_1;

        querty_colors.emplace_back(ourShader_1_color,VAO_p_1,&mat1,&mat1,glm::vec3(-0.43f+j*0.012f*3.0f,0.3-0.024*3.0*i,0.0f));
        querty_colors.back().position.scale(glm::vec3(0.012f*3.0f,0.024f*3.0f,1.0f));
        querty_colors.back().textures.push_back(querty_white);//
        querty_colors.back().shaderIndef=shederId_1;
    }
}

Model button_graf_diapozon_ok(ourShader_1,VAO_p_1,&mat1,&mat1,glm::vec3(0.1f,-0.45f,0.0f));
button_graf_diapozon_ok.position.scale(glm::vec3(1.0f/6,1.0f/16,1.0f));
button_graf_diapozon_ok.textures.push_back(button);//
button_graf_diapozon_ok.shaderIndef=shederId_1;

Model button_graf_diapozon_off(ourShader_1,VAO_p_1,&mat1,&mat1,glm::vec3(-0.1f,-0.45f,0.0f));
button_graf_diapozon_off.position.scale(glm::vec3(1.0f/6,1.0f/16,1.0f));
button_graf_diapozon_off.textures.push_back(button);//
button_graf_diapozon_off.shaderIndef=shederId_1;



Text button_graf_diapozon_ok_text(textShader,&mat1,&mat1,glm::mat4{1.0f},font_Hack_2,"");
button_graf_diapozon_ok_text.position.move(glm::vec3(0.04f,-0.447f,0.0f));
button_graf_diapozon_ok_text.position.scale(glm::vec3(0.25f,1.0f,1.0f));
button_graf_diapozon_ok_text.position.scale(glm::vec3(0.075f,0.055f,0.2f));
button_graf_diapozon_ok_text.position.scale(glm::vec3(1.1f,1.1f,0.2f));

Text button_graf_diapozon_off_text(textShader,&mat1,&mat1,glm::mat4{1.0f},font_Hack_2,"");
button_graf_diapozon_off_text.position.move(glm::vec3(-0.15f,-0.447f,0.0f));
button_graf_diapozon_off_text.position.scale(glm::vec3(0.25f,1.0f,1.0f));
button_graf_diapozon_off_text.position.scale(glm::vec3(0.075f,0.055f,0.2f));
button_graf_diapozon_off_text.position.scale(glm::vec3(1.1f,1.1f,0.2f));

Model start_button_graf(ourShader,VAO_p_1,&mat1,&mat1,glm::vec3(0.955-0.065f*1,0.835f,0.0f));
start_button_graf.position.scale(glm::vec3(0.06f*0.9f,0.12f*0.9f,1.0f));
start_button_graf.textures.push_back(start_graf);//
start_button_graf.shaderIndef=shederId_1;

Model stop_button_graf(ourShader,VAO_p_1,&mat1,&mat1,glm::vec3(0.955-0.065f*1,0.835f,0.0f));
stop_button_graf.position.scale(glm::vec3(0.06f*0.9f,0.12f*0.9f,1.0f));
stop_button_graf.textures.push_back(stop_graf);//
stop_button_graf.shaderIndef=shederId_1;


glEnable(GL_DEPTH_TEST);
glEnable(GL_BLEND);
glEnable(GL_MULTISAMPLE);
 glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ZERO);
////
glfwPollEvents();
glClearColor(0.0f, 0.5f, 0.3f, 1.0f);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

start_display_1.Draw();
glFinish();
glfwSwapBuffers(test2.window);
////
///
///
glfwMakeContextCurrent(test.window);
Model start_display(ourShader,VAO_p,&mat1,&mat1,glm::mat4{1.0f});
start_display.position.scale(glm::vec3(2.0f,2.0f,1.0f));
start_display.textures.push_back(start_display_texyure);//
///
///

////
glfwPollEvents();
glClearColor(0.0f, 0.5f, 0.3f, 1.0f);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
start_display.Draw();
glFinish();
glfwSwapBuffers(test.window);
////

Model skybox(skyboxSheder,VAOsb,&projection,&view,glm::vec3(0.0f,0.0f,0.0f));
skybox.textures.push_back(skybox_t);

Object object(Directory_3D_object+"vetr7r.obj",materialSheder,&projection,&view,glm::vec3(-1.2f, -1.3f,-10.0f));
object.setShaderId(shederId);
object.SetShaderMaterial(materialSheder);
object.position_object.rotete(glm::vec3(0.0f, 0.0f, 1.0f),270.0f);//
object.position_object.rotete(glm::vec3(1.0f, 0.0f, 0.0f),90.0f);//
object.position_object.move(glm::vec3(10.5,-1.5+36+8.5,-142.5));
object.position_object.scale(glm::vec3(2.0f,2.0f,2.0f));


Object vert2(Directory_3D_object+"untitled.obj",materialSheder,&projection,&view,glm::vec3(-10.2f, -10.3f,-10.0f));
vert2.setShaderId(shederId);
vert2.position_object.scale(glm::vec3(10.0f,10.0f,10.0f));
vert2.position_object.move(glm::vec3(18.1,0.85,-2.8)+glm::vec3(10.5,-1.5+36+8.5-38.5,-142.5));
vert2.position_object.scale(glm::vec3(2.0f,2.0f,2.0f));
vert2.SetShaderMaterial(materialSheder);

Object solar_panel(Directory_3D_object+"Solar_panel.obj",ourShader,&projection,&view,glm::vec3(-10.2f, -10.3f,-10.0f));
//solar_panel.position_object.scale(glm::vec3(5.0f,5.0f,5.0f));
solar_panel.position_object.move(glm::vec3(74,-3.5+8.5,-16));
solar_panel.setShaderId(shederId);
solar_panel.position_object.move(glm::vec3(79.5,-2.5,-115));
solar_panel.position_object.scale(glm::vec3(2.0f,2.0f,2.0f));
solar_panel.SetShaderMaterial(materialSheder);

Object diesel_generator(Directory_3D_object+"diesel_generator.fbx",materialSheder,&projection,&view,glm::vec3(-10.2f, -10.3f,-10.0f));
diesel_generator.position_object.scale(glm::vec3(2.5f,2.5f,2.5f));
diesel_generator.setShaderId(shederId);
diesel_generator.position_object.move(glm::vec3(-30,-6-9,-138.5));
diesel_generator.position_object.rotete(glm::vec3(0.0f, 1.0f, 0.0f),270.0f);
diesel_generator.SetShaderMaterial(materialSheder);
diesel_generator.position_object.move(glm::vec3(61,2.5+4.5,121+10.0f));

Object accumulators(Directory_3D_object+"accamulators.obj",materialSheder,&projection,&view,glm::vec3(15.5f,1.5f,-87.0f));
accumulators.position_object.scale(glm::vec3(3.0f,3.0f,3.0f));
accumulators.position_object.rotete(glm::vec3(0.0f, 1.0f, 0.0f),270.0f);//
accumulators.position_object.move(glm::vec3(-17,-28,63.5f+14.0f+32.0f)+glm::vec3(0,-2.1,0));
accumulators.setShaderId(shederId);


Object supercapacitors(Directory_3D_object+"supercapacitors.obj",materialSheder,&projection,&view,glm::vec3(-1.2f, -10.3f,-10.0f));
supercapacitors.setShaderId(shederId);
supercapacitors.SetShaderMaterial(materialSheder);
supercapacitors.position_object.move(glm::vec3(12.5,-6.5,-8));
supercapacitors.position_object.scale(glm::vec3(0.7f,0.7f,0.7f));
supercapacitors.position_object.move(glm::vec3(0,-1.5,-19+10.0f));

Object electrolyzer(Directory_3D_object+"electrolyzer.obj",materialSheder,&projection,&view,glm::vec3(-18.5+9.0f,-0.5,11.5));
electrolyzer.setShaderId(shederId);
electrolyzer.position_object.move(glm::vec3(-50.5,-26,-30)+glm::vec3(0,0,-24.5));
electrolyzer.position_object.rotete(glm::vec3(0.0f, 1.0f, 0.0f),270.0f);//

Object pump(Directory_3D_object+"pump.obj",materialSheder,&projection,&view,glm::vec3(0.0f,0.0f,0.0));
pump.setShaderId(shederId);
pump.position_object.move(glm::vec3(-62,-25,-6)+glm::vec3(1,-1,-12.5)+glm::vec3(1.0f,0.5,-4.0f-0.3-0.075f)+glm::vec3(-0.4,-0.2,0));
pump.position_object.rotete(glm::vec3(0.0f, 1.0f, 0.0f),180.0f);//
pump.position_object.scale(glm::vec3(2.1f,2.1f,2.1f));
//electrolyzer.position_object.rotete(glm::vec3(0.0f, 1.0f, 0.0f),270.0f);

Object holder_H(Directory_3D_object+"gasholder.obj",materialSheder,&projection,&view,glm::vec3(0.0f,0.0f,0.0));
holder_H.setShaderId(shederId);
holder_H.position_object.rotete(glm::vec3(1.0f, 0.0f, 0.0f),180.0f);
holder_H.position_object.scale(glm::vec3(0.3333f,0.3333f,0.3333f));
holder_H.position_object.move(glm::vec3(-50.5998,-29.6001,-45.6999)+glm::vec3(-35.6,-0.4,-16.5-5)+glm::vec3(5.6,-1.1,0)+glm::vec3(-0.9,-0.8,0.4)+glm::vec3(-0.1,0.3,0.5));

Object holder_O(Directory_3D_object+"gasholder.obj",materialSheder,&projection,&view,glm::vec3(0.0f,0.0f,0.0));
holder_O.setShaderId(shederId);
holder_O.position_object.rotete(glm::vec3(1.0f, 0.0f, 0.0f),180.0f);
holder_O.position_object.scale(glm::vec3(0.3333f,0.3333f,0.3333f));
holder_O.position_object.move(glm::vec3(-50.5998,-29.6001,-55.6999)+glm::vec3(-19.3,0.0999999,-27.1001)+glm::vec3(7.6,-2.5,16.4));

Object fuel_cell_block(Directory_3D_object+"fuel_cell_block.obj",materialSheder,&projection,&view,glm::vec3(0.0f,0.0f,0.0));
fuel_cell_block.setShaderId(shederId);
fuel_cell_block.position_object.move(glm::vec3(-60.2997,-24.5001,-81.6993)+glm::vec3(2.4,-0.7,0)+glm::vec3(-0.5,0.4,-0.7)+glm::vec3(1.3,0.2,3.1));
fuel_cell_block.position_object.scale(glm::vec3(3.0f*std::pow(1.01,12),3.0f*std::pow(1.01,12),3.0f*std::pow(1.01,12)));
fuel_cell_block.position_object.rotete(glm::vec3(0.0f, 1.0f, 0.0f),180.0f);

Object tank_water(Directory_3D_object+"tank_water.obj",materialSheder,&projection,&view,glm::vec3(0.0f,0.0f,0.0));
tank_water.setShaderId(shederId);
tank_water.position_object.move(glm::vec3(-76.9994,-28.2001,6.2)+glm::vec3(30.2001,0,-2)+glm::vec3(0,0,-0.8));
tank_water.position_object.scale(glm::vec3(0.25f,0.5f,0.25f));
tank_water.position_object.rotete(glm::vec3(0.0f, 1.0f, 0.0f),90.0f);

Object NTE_object(Directory_3D_object+"NTE.obj",ourShader,&projection,&view,glm::vec3(0.0f,0.0f,0.0));
NTE_object.setShaderId(shederId);
NTE_object.SetShaderMaterial(materialSheder);
NTE_object.position_object.move(glm::vec3(-228.305,-16,40.1)+glm::vec3(0,-10.5,0));
NTE_object.position_object.scale(glm::vec3(4.5f,4.5f,4.5f));
//NTE.position_object.rotete(glm::vec3(0.0f, 1.0f, 0.0f),90.0f);

Object CCT_object(Directory_3D_object+"CCT.obj",ourShader,&projection,&view,glm::vec3(0.0f,0.0f,0.0));
CCT_object.setShaderId(shederId);
CCT_object.SetShaderMaterial(materialSheder);
CCT_object.position_object.move(glm::vec3(-228.305,-16,40.1)+glm::vec3(0,-10.5,0));
CCT_object.position_object.scale(glm::vec3(4.5f,4.5f,4.5f));
//NTE.position_object.rotete(glm::vec3(0.0f, 1.0f, 0.0f),90.0f)


Object invertor(Directory_3D_object+"invert.obj",materialSheder,&projection,&view,glm::vec3(0.0f,0.0f,0.0));
invertor.setShaderId(shederId);
invertor.position_object.rotete(glm::vec3(0.0f, 1.0f, 0.0f),-90.0f);
invertor.position_object.scale(glm::vec3(1.3333f,1.3333f,1.3333f));
invertor.position_object.move(glm::vec3(24.2001,-27.0001,-57.9997));

Object control(Directory_3D_object+"control.obj",materialSheder,&projection,&view,glm::vec3(0.0f,0.0f,0.0));
control.setShaderId(shederId);
control.position_object.rotete(glm::vec3(0.0f, 0.0f, 1.0f),90.0f);
control.position_object.scale(glm::vec3(0.4f,0.4f,0.4f));
control.position_object.move(glm::vec3(22.9001,-24.6001,-62.6996)+glm::vec3(0.8,0.5,-1.1));
//holder_O.position_object.move();

//Object holder_O(Directory_3D_object+"gasholder.obj",materialSheder,&projection,&view,glm::vec3(0.0f,0.0f,0.0));
//holder_O.setShaderId(shederId);

Object canopy(Directory_3D_object+"canopy.obj",materialSheder,&projection,&view,glm::vec3(-1.2f, -10.3f,-10.0f));
canopy.setShaderId(shederId);
canopy.SetShaderMaterial(materialSheder);
canopy.position_object.scale(glm::vec3(6.0f,6.0f,6.0f));
canopy.position_object.move(glm::vec3(29.5,-8.5,0));

Position trub_position(glm::mat4(1.0f));
std::vector<Object> normal_pipes;
std::vector<glm::vec3> positions_normal_pipes;
std::vector<glm::vec3> positions_rotete_normal_pipes;
std::vector<float> lenghts_normal;

positions_normal_pipes.emplace_back(glm::vec3(-59,-12+1.0-1.0,-27.5+3.9-5.25)+glm::vec3(0.0f,2.5,0.0));
positions_rotete_normal_pipes.emplace_back(glm::vec3(0.0f,0.0f,0.0f));
lenghts_normal.push_back(0.5f);
positions_normal_pipes.emplace_back(glm::vec3(glm::vec3(-2,-1.5,-27.5+4.9-5.25)+glm::vec3(-57,-19.5,0.0f)+glm::vec3(0,4,0.0f))+glm::vec3(0.0f,2.5,0.0));
positions_rotete_normal_pipes.emplace_back(glm::vec3(90.0f,0.0f,90.0f));
lenghts_normal.push_back(0.5f);
positions_normal_pipes.emplace_back(glm::vec3(glm::vec3(-2,-1.5-4.1f,-27.5+4.9-5.25)+glm::vec3(-57,-19.5,0.0f)+glm::vec3(0,4,0.0f))+glm::vec3(0.0f,2.5,0.0));
positions_rotete_normal_pipes.emplace_back(glm::vec3(90.0f,0.0f,90.0f));
lenghts_normal.push_back(0.5f);
positions_normal_pipes.emplace_back(glm::vec3(glm::vec3(-2,-1.5-8.2f,-27.5+4.9-5.25)+glm::vec3(-57,-19.5,0.0f)+glm::vec3(0,4,0.0f))+glm::vec3(0.0f,2.5,0.0));
positions_rotete_normal_pipes.emplace_back(glm::vec3(90.0f,0.0f,90.0f));
lenghts_normal.push_back(0.5f);

positions_normal_pipes.emplace_back(glm::vec3(glm::vec3(glm::vec3(-58.5,-16.0f-8.2f,-26.8f)+glm::vec3(0,-2.7,-1.6f)+glm::vec3(0.0f,2.5,0.0)+glm::vec3(-0.5,9.9,-5.45))));
positions_rotete_normal_pipes.emplace_back(glm::vec3(90.0f,0.0f,90.0f));
lenghts_normal.push_back(0.5f);
positions_normal_pipes.emplace_back(glm::vec3(-59.5-0.5,-24.25,-19)+glm::vec3(1.0f,0.5,-4.0f+0.2-0.075f));
positions_rotete_normal_pipes.emplace_back(glm::vec3(0.0f,0.0f,0.0f));
lenghts_normal.push_back(0.5f);
positions_normal_pipes.emplace_back(glm::vec3(glm::vec3(glm::vec3(-58.5,-16.0f-8.2f-2.52f,-26.8f)+glm::vec3(0,-2.7,-1.6f)+glm::vec3(0.0f,2.5,0.0)+glm::vec3(-0.5,9.9,-5.45))));
positions_rotete_normal_pipes.emplace_back(glm::vec3(90.0f,0.0f,90.0f));
lenghts_normal.push_back(0.5f);

positions_normal_pipes.emplace_back(glm::vec3(-29-0.2,-1.5+1.0-0.1f+0.3,-0.5-0.1)+glm::vec3(0.5,0,-0.5)+glm::vec3(-4.5,-7.5,-10)+glm::vec3(-23,-17.5,-28));
positions_rotete_normal_pipes.emplace_back(glm::vec3(0.0f,270.0f,0.0f));
lenghts_normal.push_back(1.0f);
positions_normal_pipes.emplace_back(glm::vec3(-45.2999,-21.3,-17)+glm::vec3(-10,-3.5,-14.1)+glm::vec3(2,20.4,-2));
positions_rotete_normal_pipes.emplace_back(glm::vec3(00.0f,0.0f,00.0f));
lenghts_normal.push_back(1.0f);

positions_normal_pipes.emplace_back(glm::vec3(-45.2999,-21.3,-17)+glm::vec3(-0.8,-1.9,-22.1));
positions_rotete_normal_pipes.emplace_back(glm::vec3(90.0f,0.0f,90.0f));
lenghts_normal.push_back(1.0f);
positions_normal_pipes.emplace_back(glm::vec3(-45.2999,-21.3,-17)+glm::vec3(0.1-8.2f,-1.4,-14.1));
positions_rotete_normal_pipes.emplace_back(glm::vec3(90.0f,0.0f,90.0f));
lenghts_normal.push_back(1.0);

positions_normal_pipes.emplace_back(glm::vec3(-45.2999,-21.3+8.2f,-17)+glm::vec3(-0.8,-1.9,-22.1));
positions_rotete_normal_pipes.emplace_back(glm::vec3(90.0f,0.0f,90.0f));
lenghts_normal.push_back(1.0f);
positions_normal_pipes.emplace_back(glm::vec3(-45.2999,-21.3+8.2f,-17)+glm::vec3(0.1-8.2f,-1.4,-14.1));
positions_rotete_normal_pipes.emplace_back(glm::vec3(90.0f,0.0f,90.0f));
lenghts_normal.push_back(1.0);

positions_normal_pipes.emplace_back(glm::vec3(-45.2999,-21.3,-17-8.2f)+glm::vec3(-10,-3.5,-14.1)+glm::vec3(2,20.4,-2));
positions_rotete_normal_pipes.emplace_back(glm::vec3(00.0f,0.0f,00.0f));
lenghts_normal.push_back(1.0f);
positions_normal_pipes.emplace_back(glm::vec3(-45.2999,-21.3,-17)+glm::vec3(-0.8,16.5,-24.3001));
positions_rotete_normal_pipes.emplace_back(glm::vec3(00.0f,0.0f,00.0f));
lenghts_normal.push_back(1.0f);
positions_normal_pipes.emplace_back(glm::vec3(-45.2999,-21.3,-17)+glm::vec3(-18.9,18.3,-25.9001)+glm::vec3(0.8,-1.4,-8.5));
positions_rotete_normal_pipes.emplace_back(glm::vec3(0.0f,270.0f,0.0f));
lenghts_normal.push_back(1.0f);
////////////////////////////////////////////////////////////glm::vec3(-20.9,0,0)
positions_normal_pipes.emplace_back(glm::vec3(-45.2999,-21.3+8.2f,-17)+glm::vec3(0.2,-1.2,-40)+glm::vec3(2.5,0,0));
positions_rotete_normal_pipes.emplace_back(glm::vec3(90.0f,0.0f,90.0f));
lenghts_normal.push_back(1.0);
positions_normal_pipes.emplace_back(glm::vec3(-45.2999,-21.3+8.2f,-17)+glm::vec3(0.2,-1.2,-40)+glm::vec3(-20.9,0,0)+glm::vec3(-2.5,0,0));
positions_rotete_normal_pipes.emplace_back(glm::vec3(90.0f,0.0f,90.0f));
lenghts_normal.push_back(1.0f);

positions_normal_pipes.emplace_back(glm::vec3(-45.2999,-21.3,-17)+glm::vec3(0.2,7,-43.8999)+glm::vec3(2.5,0,0));
positions_rotete_normal_pipes.emplace_back(glm::vec3(90.0f,0.0f,90.0f));
lenghts_normal.push_back(1.0);
positions_normal_pipes.emplace_back(glm::vec3(-45.2999,-21.3,-17)+glm::vec3(0.2,7,-43.8999)+glm::vec3(-20.9,0,0)+glm::vec3(-2.5,0,0));
positions_rotete_normal_pipes.emplace_back(glm::vec3(90.0f,0.0f,90.0f));
lenghts_normal.push_back(1.0);

positions_normal_pipes.emplace_back(glm::vec3(-45.2999,-21.3-8.2f,-17)+glm::vec3(0.2,7,-43.8999)+glm::vec3(2.5,0,0));
positions_rotete_normal_pipes.emplace_back(glm::vec3(90.0f,0.0f,90.0f));
lenghts_normal.push_back(1.0);
positions_normal_pipes.emplace_back(glm::vec3(-45.2999,-21.3-8.2f,-17)+glm::vec3(0.2,7,-43.8999)+glm::vec3(-20.9,0,0)+glm::vec3(-2.5,0,0));
positions_rotete_normal_pipes.emplace_back(glm::vec3(90.0f,0.0f,90.0f));
lenghts_normal.push_back(1.0);

positions_normal_pipes.emplace_back(glm::vec3(-45.2999,-21.3,-17)+glm::vec3(-9.9,-3.2,-44.0999)+glm::vec3(0,0.2,0.1)+glm::vec3(2.5,0,0)+glm::vec3(0.20,-0.3,0.1));
positions_rotete_normal_pipes.emplace_back(glm::vec3(00.0f,270.0f,00.0f));
lenghts_normal.push_back(1.0f);
positions_normal_pipes.emplace_back(glm::vec3(-45.2999,-21.3,-17)+glm::vec3(-9.9,-3.2,-44.0999)+glm::vec3(-20.9,0,0)+glm::vec3(11.9,-0.1,0.2)+glm::vec3(-2.5,0,0));
positions_rotete_normal_pipes.emplace_back(glm::vec3(00.0f,270.0f,00.0f));
lenghts_normal.push_back(1.0f);

positions_normal_pipes.emplace_back(glm::vec3(-45.2999,-21.3,-17)+glm::vec3(-9.3,-3.3,-45.9999));
positions_rotete_normal_pipes.emplace_back(glm::vec3(00.0f,0.0f,00.0f));
lenghts_normal.push_back(1.0f);
positions_normal_pipes.emplace_back(glm::vec3(-45.2999,-21.3,-17)+glm::vec3(-9.3,-3.3,-45.9999)+glm::vec3(-2,0,0));
positions_rotete_normal_pipes.emplace_back(glm::vec3(00.0f,0.0f,00.0f));
lenghts_normal.push_back(1.0f);


positions_normal_pipes.emplace_back(glm::vec3(-58.5,-16.0f-8.2f,-26.8f)+glm::vec3(-0.5,3.6,5));
positions_rotete_normal_pipes.emplace_back(glm::vec3(90.0f,0.0f,90.0f));
lenghts_normal.push_back(0.5f);
positions_normal_pipes.emplace_back(glm::vec3(-59.5-0.5,-24.25,-19)+glm::vec3(1,8.7,2.2));
positions_rotete_normal_pipes.emplace_back(glm::vec3(0.0f,0.0f,0.0f));
lenghts_normal.push_back(0.5f);

positions_normal_pipes.emplace_back(glm::vec3(-228.305,-16,40.1)+glm::vec3(7.89999,-8.6,-8.09999));
positions_rotete_normal_pipes.emplace_back(glm::vec3(90.0f,0.0f,90.0f));
lenghts_normal.push_back(0.33f);

positions_normal_pipes.emplace_back(glm::vec3(-228.305,-16-3.2+0.5,40.1)+glm::vec3(7.89999,-8.6,-8.09999));
positions_rotete_normal_pipes.emplace_back(glm::vec3(90.0f,0.0f,90.0f));
lenghts_normal.push_back(0.33f);

std::vector<Object>  angle_pipes;
std::vector<glm::vec3> positions_angle_pipes;
std::vector<glm::vec3> positions_rotete_angle_pipes;
std::vector<float> lenghts_angle;
positions_angle_pipes.emplace_back(glm::vec3(-58,-10.00+0.15,-20.8)+glm::vec3(-0.5f,-1.5,-6.5)+glm::vec3(0.0f,2.5,0.0));//2
positions_rotete_angle_pipes.emplace_back(glm::vec3(90.0f,0.0f,90.0f));
lenghts_angle.push_back(0.5f);
positions_angle_pipes.emplace_back(glm::vec3(glm::vec3(-58.5,-16.0f-8.2f,-26.8f)+glm::vec3(0,-2.7,-1.6f)+glm::vec3(0.0f,2.5,0.0)));//1
positions_rotete_angle_pipes.emplace_back(glm::vec3(270.0f,00.0f,90.0f));
lenghts_angle.push_back(0.5f);
positions_angle_pipes.emplace_back(glm::vec3(-58-0.5,-10-1.5,-35+0.5)+glm::vec3(0.0f,2.5,0.0));//3
positions_rotete_angle_pipes.emplace_back(glm::vec3(0.0f,0.0f,90.0f));
lenghts_angle.push_back(0.5f);

positions_angle_pipes.emplace_back(glm::vec3(-45.2999,-21.3,-17)+glm::vec3(0.5,-5,-23.1001));//1
positions_rotete_angle_pipes.emplace_back(glm::vec3(90.0f,270.0f,00.0f));
lenghts_angle.push_back(1.0f);
positions_angle_pipes.emplace_back(glm::vec3(-45.2999-8.2f,-21.3,-17)+glm::vec3(1.4,-4.5,-15.2));//1
positions_rotete_angle_pipes.emplace_back(glm::vec3(90.0f,270.0f,00.0f));
lenghts_angle.push_back(1.0f);

positions_angle_pipes.emplace_back(glm::vec3(-45.2999-8.2f,-21.3+8.2f,-17)+glm::vec3(-1.2,9.7,-15.1)+glm::vec3(2.3,0.3,2));//2
//positions_rotete_angle_pipes.emplace_back(glm::vec3(270.0f,90.0f,180.0f));
positions_rotete_angle_pipes.emplace_back(glm::vec3(90.0f,00.0f,90.0f));
lenghts_angle.push_back(1.0f);
positions_angle_pipes.emplace_back(glm::vec3(-45.2999,-21.3+8.2f,-17)+glm::vec3(-2.1,9.2,-23.2001)+glm::vec3(2.3,0.3,2));//2
//positions_rotete_angle_pipes.emplace_back(glm::vec3(270.0f,90.0f,180.0f));
positions_rotete_angle_pipes.emplace_back(glm::vec3(90.0f,00.0f,90.0f));
lenghts_angle.push_back(1.0f);

positions_angle_pipes.emplace_back(glm::vec3(-45.2999,-21.3+8.2f,-17)+glm::vec3(0.2,-2.6,-13.7)+glm::vec3(-0.1,11.9,-22));//2
positions_rotete_angle_pipes.emplace_back(glm::vec3(00.0f,00.0f,90.0f));
lenghts_angle.push_back(1.0f);


positions_angle_pipes.emplace_back(glm::vec3(-45.2999,-21.3+8.2f,-17)+glm::vec3(-4.3,10,-29.5001)+glm::vec3(-2.4,-0.3,-5.9));//2
positions_rotete_angle_pipes.emplace_back(glm::vec3(270.0f,270.0f,90.0f));
lenghts_angle.push_back(1.0f);

positions_angle_pipes.emplace_back(glm::vec3(-45.2999,-21.3+8.2f,-17)+glm::vec3(-21.5,9.7,-35.4));//2
positions_rotete_angle_pipes.emplace_back(glm::vec3(270.0f,90.0f,180.0f));
lenghts_angle.push_back(1.0f);
/////////////////////////glm::vec3(-20.9,0,0)Сухая штукатурка
positions_angle_pipes.emplace_back(glm::vec3(-45.2999,-21.3+8.2f,-17)+glm::vec3(1.2,10.2,-39)+glm::vec3(2.5,0,0));//2
positions_rotete_angle_pipes.emplace_back(glm::vec3(90.0f,00.0f,90.0f));
lenghts_angle.push_back(1.0f);
positions_angle_pipes.emplace_back(glm::vec3(-45.2999,-21.3+8.2f,-17)+glm::vec3(1.2,10.2,-39)+glm::vec3(-20.9,0,0)+glm::vec3(-2.5,0,0));//2
positions_rotete_angle_pipes.emplace_back(glm::vec3(90.0f,00.0f,90.0f));
lenghts_angle.push_back(1.0f);

positions_angle_pipes.emplace_back(glm::vec3(-45.2999,-21.3+8.2f,-17)+glm::vec3(0.2,10.1,-44.8999)+glm::vec3(1,-0.2,-0.3)+glm::vec3(2.5,0,0));//2
positions_rotete_angle_pipes.emplace_back(glm::vec3(00.0f,00.0f,90.0f));
lenghts_angle.push_back(1.0f);
positions_angle_pipes.emplace_back(glm::vec3(-45.2999,-21.3+8.2f,-17)+glm::vec3(0.2,10.1,-44.8999)+glm::vec3(1,-0.2,-0.3)+glm::vec3(-20.9,0,0)+glm::vec3(-2.5,0,0));//2
positions_rotete_angle_pipes.emplace_back(glm::vec3(00.0f,00.0f,90.0f));
lenghts_angle.push_back(1.0f);

positions_angle_pipes.emplace_back(glm::vec3(-45.2999,-21.3+8.2f-0.2,-17)+glm::vec3(1.3,-12.9,-42.0999)+glm::vec3(-0.1,0.5,-0.5)+glm::vec3(0.3,-0.1,-2.4)+glm::vec3(0,0.2,0.1)+glm::vec3(2.5,0,0));//2
positions_rotete_angle_pipes.emplace_back(glm::vec3(180.0f,270.0f,90.0f));
lenghts_angle.push_back(1.0f);
positions_angle_pipes.emplace_back(glm::vec3(-45.2999+0.1,-21.3+8.2f,-17)+glm::vec3(1.3,-12.9,-42.0999)+glm::vec3(-20.9,0,0)+glm::vec3(-0.1,0.5,-0.5)+glm::vec3(0.3,-0.1,-2.4)+glm::vec3(-2.7,0,2.1)+glm::vec3(-2.5,0,0));//2
positions_rotete_angle_pipes.emplace_back(glm::vec3(180.0f,90.0f,90.0f));
lenghts_angle.push_back(1.0f);

positions_angle_pipes.emplace_back(glm::vec3(-45.2999+0.1f,-21.3+8.2f,-17)+glm::vec3(-10.7,-10.5,-42.8999));//2
positions_rotete_angle_pipes.emplace_back(glm::vec3(90.0f,90.0f,90.0f));
lenghts_angle.push_back(1.0f);
positions_angle_pipes.emplace_back(glm::vec3(-45.2999-0.1f,-21.3+8.2f,-17)+glm::vec3(-9.9,-12.5,-42.8999));//2
positions_rotete_angle_pipes.emplace_back(glm::vec3(90.0f,270.0f,90.0f));
lenghts_angle.push_back(1.0f);

//positions_angle_pipes.emplace_back(glm::vec3(0.0f,0.0f,0.0f));//3
//positions_rotete_angle_pipes.emplace_back(glm::vec3(90.0f,0.0f,00.0f));
//lenghts_angle.push_back(1.0f);
//positions_angle_pipes.emplace_back(glm::vec3(0.0f,0.0f,0.0f));//3
//positions_rotete_angle_pipes.emplace_back(glm::vec3(90.0f,0.0f,00.0f));
//lenghts_angle.push_back(1.0f);

//positions_angle_pipes.emplace_back(glm::vec3(0.0f,0.0f,0.0f));//4
//positions_rotete_angle_pipes.emplace_back(glm::vec3(90.0f,180.0f,00.0f));
//lenghts_angle.push_back(1.0f);
//positions_angle_pipes.emplace_back(glm::vec3(0.0f,0.0f,0.0f));//4
//positions_rotete_angle_pipes.emplace_back(glm::vec3(90.0f,180.0f,00.0f));
//lenghts_angle.push_back(1.0f);

positions_angle_pipes.emplace_back(glm::vec3(-58-0.5,-10-1.5,-20+0.4)+glm::vec3(0.0f,2.5,0.0)+glm::vec3(0.0f,-6.05,-2.9));//3
positions_rotete_angle_pipes.emplace_back(glm::vec3(0.0f,0.0f,90.0f));
lenghts_angle.push_back(0.5f);

Material material_pipe;
material_pipe.ambient.x=0.25;
material_pipe.ambient.y=0.25;
material_pipe.ambient.z=0.25;

material_pipe.diffuse.x=0.4;
material_pipe.diffuse.y=0.4;
material_pipe.diffuse.z=0.4;

material_pipe.specular.x=0.774597f;
material_pipe.specular.y=0.774597f;
material_pipe.specular.z=0.774597f;

material_pipe.shininess=600.0f;





for(int i=0;i<positions_normal_pipes.size();i++){
normal_pipes.emplace_back(Directory_3D_object+"long_pipe.obj",materialSheder,&projection,&view,glm::vec3(0.0f, 0.0f,0.0f));
normal_pipes.back().setShaderId(shederId);
normal_pipes.back().SetShaderMaterial(materialSheder);
normal_pipes.back().position_object.rotete(glm::vec3(1.0f, 0.0f, 0.0f),positions_rotete_normal_pipes[i].x);//
normal_pipes.back().position_object.rotete(glm::vec3(0.0f, 1.0f, 0.0f),positions_rotete_normal_pipes[i].y);
normal_pipes.back().position_object.rotete(glm::vec3(0.0f, 0.0f, 1.0f),positions_rotete_normal_pipes[i].z);
normal_pipes.back().position_object.move(positions_normal_pipes[i]);
normal_pipes.back().position_object.scale(glm::vec3(lenghts_normal[i],lenghts_normal[i],lenghts_normal[i]));
}

for(int i=0;i<positions_angle_pipes.size();i++){
angle_pipes.emplace_back(Directory_3D_object+"angle_pipe.obj",materialSheder,&projection,&view,glm::vec3(0.0f, 0.0f,0.0f));
angle_pipes.back().setShaderId(shederId);
angle_pipes.back().SetShaderMaterial(materialSheder);
angle_pipes.back().position_object.rotete(glm::vec3(1.0f, 0.0f, 0.0f),positions_rotete_angle_pipes[i].x);//
angle_pipes.back().position_object.rotete(glm::vec3(0.0f, 1.0f, 0.0f),positions_rotete_angle_pipes[i].y);
angle_pipes.back().position_object.rotete(glm::vec3(0.0f, 0.0f, 1.0f),positions_rotete_angle_pipes[i].z);
angle_pipes.back().position_object.move(positions_angle_pipes[i]);
angle_pipes.back().position_object.scale(glm::vec3(lenghts_angle[i],lenghts_angle[i],lenghts_angle[i]));
}

std::cout<<"11111111111111111111111111111222222222222111111111111111111111111111111111111111111111"<<std::endl;
for(auto &T:normal_pipes){
    T.position_object.conection_object(&trub_position);
    for(auto &J:T.models){
        J.position.conection_object(&T.position_object);
        J.material=material_pipe;
        J.shader=materialSheder;
         }
}

trub_position.rotete(glm::vec3(0.0f, 1.0f, 0.0f),90.0f);
for(auto &T:angle_pipes){
    T.position_object.conection_object(&trub_position);
    T.position_object.pos();
    for(auto &J:T.models){
        J.position.conection_object(&T.position_object);
        J.material=material_pipe;
        J.shader=materialSheder;
        }
}


//trub_position.pos();


//canopy.position_object.move(glm::vec3(29.5,-8.5,0));



Object platform(Directory_3D_object+"platform.obj",ourShader,&projection,&view,glm::vec3(-1.2f, -10.3f,-10.0f));
platform.setShaderId(shederId);
platform.SetShaderMaterial(materialSheder);
platform.position_object.rotete(glm::vec3(0.0f, 1.0f, 0.0f),-90.0f);
platform.position_object.scale(glm::vec3(2.7f,2.7f,2.7f));
platform.position_object.move(glm::vec3(17.5,-8.5,-47.5));

Object platform_1(Directory_3D_object+"platform.obj",ourShader,&projection,&view,glm::vec3(-1.2f, -10.3f,-10.0f));
platform_1.setShaderId(shederId);
platform_1.SetShaderMaterial(materialSheder);
platform_1.position_object.rotete(glm::vec3(0.0f, 1.0f, 0.0f),-90.0f);
platform_1.position_object.scale(glm::vec3(2.7f,2.7f,2.7f*0.5f));
platform_1.position_object.move(glm::vec3(17.5-20.0f,-8.5,-47.5));

Object platform_2(Directory_3D_object+"platform.obj",ourShader,&projection,&view,glm::vec3(-1.2f, -10.3f,-10.0f));
platform_2.setShaderId(shederId);
platform_2.SetShaderMaterial(materialSheder);
platform_2.position_object.rotete(glm::vec3(0.0f, 1.0f, 0.0f),-90.0f);
platform_2.position_object.scale(glm::vec3(2.7f*3.0f,2.7f,2.7f*0.5f*3.0f));
platform_2.position_object.move(glm::vec3(17.5-65.0f,-8.5,-47.5));

Object platform_3(Directory_3D_object+"platform.obj",ourShader,&projection,&view,glm::vec3(0.0f, 0.0f,0.0f));
platform_3.setShaderId(shederId);
platform_3.SetShaderMaterial(materialSheder);
platform_3.position_object.rotete(glm::vec3(0.0f, 1.0f, 0.0f),-90.0f);
platform_3.position_object.scale(glm::vec3(2.7f*3.5f,2.7f,2.7f*0.5f*3.5f));
platform_3.position_object.move(glm::vec3(-212.004,-24.7001,82.0993)+glm::vec3(18.9,1.8,20.1));

Object platform_4(Directory_3D_object+"platform.obj",ourShader,&projection,&view,glm::vec3(0.0f, 0.0f,0.0f));
platform_4.setShaderId(shederId);
platform_4.SetShaderMaterial(materialSheder);
platform_4.position_object.rotete(glm::vec3(0.0f, 0.0f, 1.0f),-90.0f);
platform_4.position_object.rotete(glm::vec3(0.0f, 1.0f, 0.0f),90.0f);
platform_4.position_object.scale(glm::vec3(0.5f,0.82f,0.9f));
platform_4.position_object.move(glm::vec3(0.0f,0.0f,0.0f)+glm::vec3(10,-25.2001,-26.4001)+glm::vec3(14.7,0,-40.8999));



//Object Factori_1(Directory_3D_object+"factoria_1.obj",materialSheder,&projection,&view,glm::vec3(0.0f, 0.0f,0.0f));
//Factori_1.setShaderId(shederId);
//Factori_1.SetShaderMaterial(materialSheder);
//Factori_1.position_object.rotete(glm::vec3(0.0f, 1.0f, 0.0f),-90.0f);
//Factori_1.position_object.scale(glm::vec3(450.0f,450.0f,450.0f));
//Factori_1.position_object.move(glm::vec3(-212.004,-24.7001,82.0993)+glm::vec3(29.3001,9.3,-22.2));



Object House_1(Directory_3D_object+"uploads_files_704845_ModernHouse_Baked.obj",ourShader,&projection,&view,glm::vec3(0.0f, 0.0f,0.0f));
House_1.setShaderId(shederId);
House_1.SetShaderMaterial(materialSheder);
House_1.position_object.rotete(glm::vec3(0.0f, 1.0f, 0.0f),-90.0f);
House_1.position_object.scale(glm::vec3(3.0f,3.0f,3.0f));
House_1.position_object.move(glm::vec3(-212.004,-24.7001,82.0993)+glm::vec3(29.3001,9.3,-22.2)+glm::vec3(-3.2,-11,-37.9));

Object gros(Directory_3D_object+"grossd.obj",materialSheder,&projection,&view,glm::vec3(-1.2f, -25.0f,-4.0f));
gros.position_object.scale(glm::vec3(30.0f,20.0f,30.0f));
gros.SetShaderMaterial(materialSheder);

std::vector<Model> menu_object;
std::vector<Animation> menu_texture;
menu_texture.emplace_back(Directory_pictures+"menu_vetr.jpg",D21A,Map_diffusion,1,1,1,-1);
menu_texture.emplace_back(Directory_pictures+"menu_vetr_s.png",D21A,Map_diffusion,1,1,1,-1);
menu_texture.emplace_back(Directory_pictures+"menu_Panel.png",D21A,Map_diffusion,1,1,1,-1);
menu_texture.emplace_back(Directory_pictures+"menu_diesel_generator.jpg",D21A,Map_diffusion,1,1,1,-1);
menu_texture.emplace_back(Directory_pictures+"menu_battary_block.png",D21A,Map_diffusion,1,1,1,-1);
menu_texture.emplace_back(Directory_pictures+"menu_sypercapasitor.png",D21A,Map_diffusion,1,1,1,-1);
menu_texture.emplace_back(Directory_pictures+"menu_fuel_sell_block.png",D21A,Map_diffusion,1,1,1,-1);

for(int i=0;i<7;i++){
   menu_object.emplace_back(ourShader,VAO_p,&mat1,&mat1,glm::vec3(-0.8f+202.0f/1920.0f*2.0f*i+0.05f*i,-0.82f,0.0f));
   menu_object.back().position.scale(glm::vec3(202.0f/1920.0f*2.0f,142.0f/1080.0f*2.0f,1.0f));
   menu_object.back().textures.push_back(menu_texture[i]);//
   menu_object.back().shaderIndef=shederId;
}
std::vector<Animation> menu_texture_off;
menu_texture_off.emplace_back(Directory_pictures+"menu_vetr_off.jpg",D21A,Map_diffusion,1,1,1,-1);
menu_texture_off.emplace_back(Directory_pictures+"menu_vetr_s_off.png",D21A,Map_diffusion,1,1,1,-1);
menu_texture_off.emplace_back(Directory_pictures+"menu_Panel_off.png",D21A,Map_diffusion,1,1,1,-1);
menu_texture_off.emplace_back(Directory_pictures+"menu_diesel_generator_off.jpg",D21A,Map_diffusion,1,1,1,-1);
menu_texture_off.emplace_back(Directory_pictures+"menu_battary_block_off.png",D21A,Map_diffusion,1,1,1,-1);
menu_texture_off.emplace_back(Directory_pictures+"menu_sypercapasitor_off.png",D21A,Map_diffusion,1,1,1,-1);
menu_texture_off.emplace_back(Directory_pictures+"menu_fuel_sell_block_off.png",D21A,Map_diffusion,1,1,1,-1);


std::vector<Model> menu_object_off;
for(int i=0;i<7;i++){
   menu_object_off.emplace_back(ourShader,VAO_p,&mat1,&mat1,glm::vec3(-0.8f+202.0f/1920.0f*2.0f*i+0.05f*i,-0.82f,0.0f));
   menu_object_off.back().position.scale(glm::vec3(202.0f/1920.0f*2.0f,142.0f/1080.0f*2.0f,1.0f));
   menu_object_off.back().textures.push_back(menu_texture_off[i]);//
   menu_object_off.back().shaderIndef=shederId;
}
Model graf_button(ourShader,VAO_p,&mat1,&mat1,glm::vec3(0.955f-0.065f,0.835f,0.0f));
graf_button.position.scale(glm::vec3(0.06f*0.9f,0.12f*0.9f,1.0f));
graf_button.textures.push_back(icon_graf);//
graf_button.shaderIndef=shederId;

Model start_button(ourShader,VAO_p,&mat1,&mat1,glm::vec3(0.955-0.065f*3,0.835f,0.0f));
start_button.position.scale(glm::vec3(0.06f*0.9f,0.12f*0.9f,1.0f));
start_button.textures.push_back(start);//
start_button.shaderIndef=shederId;

Model stop_button(ourShader,VAO_p,&mat1,&mat1,glm::vec3(0.955-0.065f*3,0.835f,0.0f));
stop_button.position.scale(glm::vec3(0.06f*0.9f,0.12f*0.9f,1.0f));
stop_button.textures.push_back(stop);//
stop_button.shaderIndef=shederId;

Model reset_button(ourShader,VAO_p,&mat1,&mat1,glm::vec3(0.955-0.065f*2,0.835f,0.0f));
reset_button.position.scale(glm::vec3(0.06f*0.9f,0.12f*0.9f,1.0f));
reset_button.textures.push_back(reset);//
reset_button.shaderIndef=shederId;

Model logo_igvie(ourShader11,VAO_p,&mat1,&mat1,glm::vec3(-0.955+0.065f*2,0.835f,0.0f));
logo_igvie.position.scale(glm::vec3(0.06f*2.9f,0.06f*2.9f,1.0f));
logo_igvie.textures.push_back(logo);//
logo_igvie.shaderIndef=shederId;

Model setting_model_button(ourShader,VAO_p,&mat1,&mat1,glm::vec3(0.955f-0.065f*4,0.835f,0.0f));
setting_model_button.position.scale(glm::vec3(0.06f*0.9f,0.12f*0.9f,1.0f));
setting_model_button.textures.push_back(setting_model_texture);//
setting_model_button.shaderIndef=shederId;

std::vector<Model> input_field_text;
std::vector<std::vector<Input_plate>> input(25);
std::vector<Text> text;
std::vector<Text> text1;
std::vector<Text> text2;
for( volatile int i=0;i<10;i++){
   input_field_text.emplace_back(ourShader11,VAO_p,&mat1,&mat1,glm::vec3(0.2f+0.15f,0.2-0.1*i+0.1f,0.0f));
   input_field_text.back().position.scale(glm::vec3(0.17f,0.06f,1.0f));
   input_field_text.back().textures.push_back(input_field_text_texrure);//
   input_field_text.back().shaderIndef=shederId;

   text.emplace_back(textShader,&mat1,&mat1,glm::mat4{1.0f},font_Hack,"32102");
   text.back().position.scale(glm::vec3(0.25f,1.0f,1.0f));
   text.back().position.scale(glm::vec3(0.075f,0.055f,0.2f));
   text.back().position.move(glm::vec3(0.14f+0.15f,0.2-0.1*i+0.1f,0.0f));

   text1.emplace_back(textShader,&mat1,&mat1,glm::mat4{1.0f},font_Hack,"");
   text1.back().position.scale(glm::vec3(0.25f,1.0f,1.0f));
   text1.back().position.scale(glm::vec3(0.075f,0.055f,0.2f));
   text1.back().position.move(glm::vec3(-0.51f,0.2-0.1*i+0.1f,0.0f));

   text2.emplace_back(textShader,&mat1,&mat1,glm::mat4{1.0f},font_Hack,"");
   text2.back().position.scale(glm::vec3(0.25f,1.0f,1.0f));
   text2.back().position.scale(glm::vec3(0.075f,0.055f,0.2f));
   text2.back().position.move(glm::vec3(0.35+0.1f,0.2-0.1*i+0.1f,0.0f));

}
std::cout<<"1@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<std::endl;

for(volatile int j=0;j<25;j++){
    for( volatile int i=0;i<10;i++){
    input[j].emplace_back(&test,&input_field_text[i]);
    }
}
std::cout<<"2@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<std::endl;
for(auto &T:input){
    for(auto &J:T){
        J.click_button.push_back(GLFW_MOUSE_BUTTON_LEFT);
        J.on_input();
    }
}
std::cout<<"3@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<std::endl;
Model input_field_windous(ourShader,VAO_p,&mat1,&mat1,glm::mat4{1.0f});
input_field_windous.textures.push_back(input_field_texture);
input_field_windous.shaderIndef=shederId;
input_field_windous.position.scale(glm::vec3(1.1f,1.2f,1.0f));

Model input_field_windous_insert(ourShader,VAO_p,&mat1,&mat1,glm::mat4{1.0f});
input_field_windous_insert.textures.push_back(input_field_texture);
input_field_windous_insert.shaderIndef=shederId;
input_field_windous_insert.position.scale(glm::vec3(0.7f,1.025f,1.0f));
input_field_windous_insert.position.move(glm::vec3(0.0f,-0.014f,0.0f));

Model input_field_windous_insert_VEU(ourShader,VAO_p,&mat1,&mat1,glm::mat4{1.0f});
input_field_windous_insert_VEU.textures.push_back(input_field_texture);
input_field_windous_insert_VEU.shaderIndef=shederId;
input_field_windous_insert_VEU.position.scale(glm::vec3(0.7f,0.635f,1.0f));
input_field_windous_insert_VEU.position.move(glm::vec3(0.0f,0.177f,0.0f));

Model button_field_text_content(ourShader11,VAO_p,&mat1,&mat1,glm::vec3(0.0f,0.5-0.075*(-1)-0.135f,0.0f));
button_field_text_content.position.scale(glm::vec3(0.68f,0.15f/2,1.0f));
button_field_text_content.textures.push_back(button_PHT);//
button_field_text_content.shaderIndef=shederId;

Text text_button_content(textShader,&mat1,&mat1,glm::mat4{1.0f},font_Hack,"32102");
text_button_content.position.scale(glm::vec3(0.25f,0.9f,1.0f));
text_button_content.position.scale(glm::vec3(0.075f,0.055f,0.2f));
text_button_content.position.move(glm::vec3(-0.30f,0.5-0.075*(-1)-0.135f,0.0f));

Text text_button_content_p(textShader,&mat1,&mat1,glm::mat4{1.0f},font_Hack,"");
text_button_content_p.position.scale(glm::vec3(0.25f,0.9f,1.0f));
text_button_content_p.position.scale(glm::vec3(0.075f,0.055f,0.2f));
text_button_content_p.position.move(glm::vec3(0.05f,0.5-0.075*(-1)-0.135f,0.0f));

std::vector<Model> button_field_text_PHT;
std::vector<Model> button_marker;

std::vector<Text> text_button_PHT;
std::vector<Text> text_button_PHT_p;

std::vector<std::string> name_chart_PHT;
name_chart_PHT.push_back("Свежий снег");
name_chart_PHT.push_back("Старый снег");
name_chart_PHT.push_back("Пустыня");
name_chart_PHT.push_back("Сухая почва");
name_chart_PHT.push_back("Мокрая почва");
name_chart_PHT.push_back("Сухой асфальт");
name_chart_PHT.push_back("Сухая штукатурка");
name_chart_PHT.push_back("Сухая растительность");
name_chart_PHT.push_back("Растительность после дождя");
name_chart_PHT.push_back("Сухой бетон");
name_chart_PHT.push_back("Вода при В<45грд");
name_chart_PHT.push_back("Вода при В>45грд");

std::vector<std::string> namber_chart_PHT_p;
namber_chart_PHT_p.push_back("    0.85");
namber_chart_PHT_p.push_back("    0.50");
namber_chart_PHT_p.push_back("    0.35");
namber_chart_PHT_p.push_back("    0.22");
namber_chart_PHT_p.push_back("    0.16");
namber_chart_PHT_p.push_back("    0.70");
namber_chart_PHT_p.push_back("    0.44");
namber_chart_PHT_p.push_back("    0.33");
namber_chart_PHT_p.push_back("    0.15");
namber_chart_PHT_p.push_back("    0.35");
namber_chart_PHT_p.push_back("    0.05");
namber_chart_PHT_p.push_back("    0.53");

std::vector<float> namber_float_chart_PHT_p;
namber_float_chart_PHT_p.push_back(0.85);
namber_float_chart_PHT_p.push_back(0.50);
namber_float_chart_PHT_p.push_back(0.35);
namber_float_chart_PHT_p.push_back(0.22);
namber_float_chart_PHT_p.push_back(0.16);
namber_float_chart_PHT_p.push_back(0.70);
namber_float_chart_PHT_p.push_back(0.44);
namber_float_chart_PHT_p.push_back(0.33);
namber_float_chart_PHT_p.push_back(0.15);
namber_float_chart_PHT_p.push_back(0.35);
namber_float_chart_PHT_p.push_back(0.05);
namber_float_chart_PHT_p.push_back(0.53);

bool button_marker_job[12];
for(auto &T:button_marker_job){
    T=false;
}
//button_marker_job[0]=true;

for( volatile int i=0;i<12;i++){
    for(int j=0;j<1;j++){
   button_field_text_PHT.emplace_back(ourShader11,VAO_p,&mat1,&mat1,glm::vec3(0.0f,0.5-0.075*i-0.135f,0.0f));
   button_field_text_PHT.back().position.scale(glm::vec3(0.68f,0.15f/2,1.0f));
   button_field_text_PHT.back().textures.push_back(button_PHT);//
   button_field_text_PHT.back().shaderIndef=shederId;

   button_marker.emplace_back(ourShader11,VAO_p,&mat1,&mat1,glm::vec3(-0.325f,0.5-0.075*i-0.135f,0.0f));
   button_marker.back().position.scale(glm::vec3(0.012f,0.024f,1.0f));
   button_marker.back().textures.push_back(marker_orange);//
   button_marker.back().shaderIndef=shederId;

   text_button_PHT.emplace_back(textShader,&mat1,&mat1,glm::mat4{1.0f},font_Hack,"32102");
   text_button_PHT.back().position.scale(glm::vec3(0.25f,0.9f,1.0f));
   text_button_PHT.back().position.scale(glm::vec3(0.075f,0.055f,0.2f));
   text_button_PHT.back().position.move(glm::vec3(-0.30f,0.5-0.075*i-0.135f,0.0f));

   text_button_PHT_p.emplace_back(textShader,&mat1,&mat1,glm::mat4{1.0f},font_Hack,"");
   text_button_PHT_p.back().position.scale(glm::vec3(0.25f,0.9f,1.0f));
   text_button_PHT_p.back().position.scale(glm::vec3(0.075f,0.055f,0.2f));
   text_button_PHT_p.back().position.move(glm::vec3(0.18f,0.5-0.075*i-0.135f,0.0f));
    }
}

std::vector<Model> button_field_text_VEU;
std::vector<Model> button_marker_VEU;

std::vector<Text> text_button_VEU;
std::vector<Text> text_button_VEU_p;

std::vector<std::string> name_chart_VEU;
name_chart_VEU.push_back("Москва");
name_chart_VEU.push_back("Республика Дагестан");
name_chart_VEU.push_back("Мурманская область");
name_chart_VEU.push_back("Республика Карелия");
name_chart_VEU.push_back("Сахалинская область");
name_chart_VEU.push_back("Республика Саха (Якутия)");
name_chart_VEU.push_back("Приморский край");

std::vector<std::string> namber_chart_VEU_p;
namber_chart_VEU_p.push_back("      77");
namber_chart_VEU_p.push_back("       5");
namber_chart_VEU_p.push_back("      51");
namber_chart_VEU_p.push_back("      10");
namber_chart_VEU_p.push_back("      65");
namber_chart_VEU_p.push_back("      14");
namber_chart_VEU_p.push_back("      25");


std::vector<float> namber_float_chart_VEU_p;
namber_float_chart_VEU_p.push_back(77.0f);
namber_float_chart_VEU_p.push_back(5.0f);
namber_float_chart_VEU_p.push_back(51.0f);
namber_float_chart_VEU_p.push_back(10.0f);
namber_float_chart_VEU_p.push_back(65.0f);
namber_float_chart_VEU_p.push_back(14.0f);
namber_float_chart_VEU_p.push_back(25.0f);


bool button_marker_job_VEU[7];
for(auto &T:button_marker_job_VEU){
    T=false;
}
//button_marker_job[0]=true;

for( volatile int i=0;i<7;i++){
    for(int j=0;j<1;j++){
   button_field_text_VEU.emplace_back(ourShader11,VAO_p,&mat1,&mat1,glm::vec3(0.0f,0.5-0.075*i-0.135f,0.0f));
   button_field_text_VEU.back().position.scale(glm::vec3(0.68f,0.15f/2,1.0f));
   button_field_text_VEU.back().textures.push_back(button_PHT);//
   button_field_text_VEU.back().shaderIndef=shederId;

   button_marker_VEU.emplace_back(ourShader11,VAO_p,&mat1,&mat1,glm::vec3(-0.325f,0.5-0.075*i-0.135f,0.0f));
   button_marker_VEU.back().position.scale(glm::vec3(0.012f,0.024f,1.0f));
   button_marker_VEU.back().textures.push_back(marker_orange);//
   button_marker_VEU.back().shaderIndef=shederId;

   text_button_VEU.emplace_back(textShader,&mat1,&mat1,glm::mat4{1.0f},font_Hack,"32102");
   text_button_VEU.back().position.scale(glm::vec3(0.25f,0.9f,1.0f));
   text_button_VEU.back().position.scale(glm::vec3(0.075f,0.055f,0.2f));
   text_button_VEU.back().position.move(glm::vec3(-0.30f,0.5-0.075*i-0.135f,0.0f));

   text_button_VEU_p.emplace_back(textShader,&mat1,&mat1,glm::mat4{1.0f},font_Hack,"");
   text_button_VEU_p.back().position.scale(glm::vec3(0.25f,0.9f,1.0f));
   text_button_VEU_p.back().position.scale(glm::vec3(0.075f,0.055f,0.2f));
   text_button_VEU_p.back().position.move(glm::vec3(0.18f,0.5-0.075*i-0.135f,0.0f));
    }
}


Text header_input_field_windous(textShader,&mat1,&mat1,glm::mat4{1.0f},font_Hack,"");
header_input_field_windous.position.move(glm::vec3(-0.48f,0.5f,0.0f));
header_input_field_windous.position.scale(glm::vec3(0.25f,1.0f,1.0f));
header_input_field_windous.position.scale(glm::vec3(0.075f,0.055f,0.2f));
header_input_field_windous.position.scale(glm::vec3(2.5f,2.5f,0.2f));

Text time_curent_model(textShader,&mat1,&mat1,glm::mat4{1.0f},font_Hack,"");
time_curent_model.position.move(glm::vec3(0.65f-0.065*3.0f,0.8f,0.0f));
time_curent_model.position.scale(glm::vec3(0.25f,1.0f,1.0f));
time_curent_model.position.scale(glm::vec3(0.075f,0.055f,0.2f));
time_curent_model.position.scale(glm::vec3(1.0f,1.0f,0.2f));

Text time_curent_model_yuers(textShader,&mat1,&mat1,glm::mat4{1.0f},font_Hack,"");
time_curent_model_yuers.position.move(glm::vec3(0.65f-0.065*3.0f,0.86f,0.0f));
time_curent_model_yuers.position.scale(glm::vec3(0.25f,1.0f,1.0f));
time_curent_model_yuers.position.scale(glm::vec3(0.075f,0.055f,0.2f));
time_curent_model_yuers.position.scale(glm::vec3(1.0f,1.0f,0.2f));

Model inerf(ourShader,VAO_p,&mat1,&mat1,glm::mat4{1.0f});
inerf.position.scale(glm::vec3(2.0f,2.0f,1.0f));
inerf.textures.push_back(interface1);//

Model inerfj(ourShader11,VAO_p,&mat1,&mat1,glm::mat4{1.0f});
inerfj.position.scale(glm::vec3(2.0f,2.0f,1.0f));
inerfj.textures.push_back(interfaceLightning);


Text sleep(textShader,&mat1,&mat1,glm::mat4{1.0f},font_Hack,"");
sleep.position.move(glm::vec3(-0.9f,0.8f,0.0f));
sleep.position.scale(glm::vec3(0.25f,1.0f,1.0f));
sleep.position.scale(glm::vec3(0.075f,0.055f,0.2f));
sleep.position.scale(glm::vec3(2.5f,2.5f,0.2f));

Text sleep_2(textShader,&mat1,&mat1,glm::mat4{1.0f},font_Hack,"");
sleep_2.position.move(glm::vec3(-0.9f,0.6f,0.0f));
sleep_2.position.scale(glm::vec3(0.25f,1.0f,1.0f));
sleep_2.position.scale(glm::vec3(0.075f,0.055f,0.2f));
sleep_2.position.scale(glm::vec3(2.5f,2.5f,0.2f));

Text sleep_3(textShader,&mat1,&mat1,glm::mat4{1.0f},font_Hack,"");
sleep_3.position.move(glm::vec3(-0.9f,0.4f,0.0f));
sleep_3.position.scale(glm::vec3(0.25f,1.0f,1.0f));
sleep_3.position.scale(glm::vec3(0.075f,0.055f,0.2f));
sleep_3.position.scale(glm::vec3(2.5f,2.5f,0.2f));
//Model testt(ourShader11,VAO_p,&mat1,&mat1,glm::mat4{1.0f});
//testt.textures.push_back(font);
//testt.position.scale(glm::vec3(0.5f,1.0f,1.0f));

Model rect_1(ourShader,VAO_p,&mat1,&mat1,glm::mat4{1.0f});
rect_1.position.move(glm::vec3(0.75f-0.05f+0.038f-0.065f*3,0.835f,0.0f));
rect_1.position.scale(glm::vec3(0.23f,0.12f,1.0f));
rect_1.textures.push_back(rect_1_texture);
rect_1.shaderIndef=shederId;

Model cod_region(ourShader,VAO_p,&mat1,&mat1,glm::mat4{1.0f});
cod_region.position.move(glm::vec3(-0.68f,0.0f,0.0f));
cod_region.position.scale(glm::vec3(0.23f,0.80f,1.0f));
cod_region.textures.push_back(cods);
cod_region.shaderIndef=shederId;


Model grid_veu(ourShader,VAO_p,&mat1,&mat1,glm::mat4{1.0f});
grid_veu.position.move(glm::vec3(-0.7654f,0.0f,0.0f));
grid_veu.position.scale(glm::vec3(0.43f,0.78f,1.0f));
grid_veu.textures.push_back(grid_class);
grid_veu.shaderIndef=shederId;

Model close_button(ourShader11,VAO_p,&mat1,&mat1,glm::vec3(0.505,0.52f,0.0f));
close_button.position.scale(glm::vec3(0.06f*0.9f,0.12f*0.9f,1.0f));
close_button.textures.push_back(closed);//
close_button.shaderIndef=shederId;

std::vector<Model> rects;

for( volatile int i=0;i<4;i++){
   rects.emplace_back(ourShader,VAO_p,&mat1,&mat1,glm::vec3(0.955-0.065f*i-0.065f,0.835f,0.0f));
   rects.back().position.scale(glm::vec3(0.06f,0.12f,1.0f));
   rects.back().textures.push_back(rect_2_texture);//
   rects.back().shaderIndef=shederId;
}



Pixel pixcel;
Pixel pixcel_1;
bool choice[7];
for(auto &T:choice){
    T=true;
}
bool choice_menu[7];
for(auto &T:choice_menu){
    T=true;
}

choice[1]=false;
choice_menu[1]=false;
int nomber_object=0;
std::array<Date_input,25> input_fields;
in_information(input_fields);
for(auto &T:input_fields){
    for(int i=0;i<T.input_field.size();i++){
        T[i].calculate();
   }
}

read_values("test",input_fields);
read_vector_charts("graf",charts);

for(int i=0;i<charts.size();i++){
    for(int j=0;j<color_chair.size();j++){
      if(charts[i].setting.color==color_chair[j]){
          cross_active[i][j]=true;
      }
    }
}

for(volatile int j=0;j<25;j++){
    for( volatile int i=0;i<10;i++){
    input[j][i].date=input_fields[j][i];
    }
}

std::cout<<input[PMT][7].date.current_value_symbol<<std::endl;

for(int i=0;i<namber_chart_PHT_p.size();i++){
    if(input_fields[PMT][8].current_value_symbol==namber_chart_PHT_p[i]){
    button_marker_job[i]=true;
    }
}

for(int i=0;i<namber_chart_VEU_p.size();i++){
    std::cout<<input_fields[SETTING][6].current_value_symbol<<"|"<<namber_chart_VEU_p[i]<<"[]"<<std::endl;
    if(input_fields[SETTING][6].current_value_symbol==namber_chart_VEU_p[i]){
    button_marker_job_VEU[i]=true;
    }
}

//bool digits[10];
struct Chart_date_x{
    int time_one_day = 60/2;//мс
    int total_time   = 24*60*60;//мс
//    int visible_scale_length = 24*60*60*100;//мс
//    int cout_division=5;
//    int time_second=total_time/time_one_day;
//    void set_time_second(){
//        time_second=total_time/time_one_day;
//    }
//    double nomber_delenia(){
//      return  visible_scale_length*10.0f/(cout_division*10.0f);
//    }
};
Chart_date_x graf_1;


//    &normal_pipes[1],
//    &normal_pipes[2],
//    &normal_pipes[3],
//    &normal_pipes[4],
//    &normal_pipes[5],
//    &normal_pipes[6],
//    &normal_pipes[7],
//    &normal_pipes[8],
//    &normal_pipes[9]std::tan(w_g),
//    &normal_pipes[10],
//    &normal_pipes[11],
//    &normal_pipes[12],
//    &normal_pipes[13],
//    &normal_pipes[14],
//    &normal_pipes[15],

//      &normal_pipes[16],
//      &normal_pipes[17],
//      &normal_pipes[18],
//      &normal_pipes[19],
//      &normal_pipes[20],
//      &normal_pipes[21],
//      &normal_pipes[22],
//      &normal_pipes[23],
//      &normal_pipes[24],
//      &normal_pipes[25],

//    &angle_pipes[0],
//    &angle_pipes[1],
//    &angle_pipes[2],
//    &angle_pipes[3],
//    &angle_pipes[4],
//    &angle_pipes[5],
//    &angle_pipes[6],
//    &angle_pipes[7],
//    &angle_pipes[8],
//    &angle_pipes[9]
//      &angle_pipes[10],
//      &angle_pipes[11],
//      &angle_pipes[12],
//      &angle_pipes[13],
//      &angle_pipes[14],
//      &angle_pipes[15],
//      &angle_pipes[16],
//      &angle_pipes[17]
bool input_field=false;
bool input_field_graf=false;
bool input_field_graf_separate=false;
std::vector<Object *> objectss_pointer{
    &object,
    &vert2,
    &solar_panel,
    &diesel_generator,
    &accumulators,

    &supercapacitors,
    &fuel_cell_block,
    &CCT_object,
    &NTE_object,
    &holder_H,

    &invertor,
    &House_1,
};

std::vector<Text>  name_objects;

std::vector<glm::vec3> position_titles;
position_titles.push_back(glm::vec3(0.0f,10.0f,0.0f));
position_titles.push_back(glm::vec3(0.0f,10.0f,0.0f));
position_titles.push_back(glm::vec3(0.0f,10.0f,0.0f));
position_titles.push_back(glm::vec3(-14.0f,-1.0f,-10.0f));//++
position_titles.push_back(glm::vec3(0.0f,7.0f,-100.0f));//++

position_titles.push_back(glm::vec3(-7.0f,-1.0f,-10.0f));//++
position_titles.push_back(glm::vec3(-12.0f,20.0f,10.0f));//++
position_titles.push_back(glm::vec3(0.0f,6.0f,0.0f));//++
position_titles.push_back(glm::vec3(0.0f,19.50f,0.0f));
position_titles.push_back(glm::vec3(12.0f,10000.0f,15.0f));

position_titles.push_back(glm::vec3(12.0f,30.0f,15.0f));
position_titles.push_back(glm::vec3(0.0f,19.50f,0.0f));

position_titles.push_back(glm::vec3(12.0f,30.0f,15.0f));
position_titles.push_back(glm::vec3(12.0f,30.0f,15.0f));
position_titles.push_back(glm::vec3(0.0f,19.50f,0.0f));
position_titles.push_back(glm::vec3(12.0f,30.0f,15.0f));
position_titles.push_back(glm::vec3(12.0f,30.0f,15.0f));

for(int i=0;i<objectss_pointer.size();i++){
  //  name_objects.emplace_back(textShader,&projection,&view,(*objectss_pointer[i]).position_object,font_Hack,"");
   // name_objects.back().position.scale(glm::vec3(0.25f,1.0f,1.0f));
    //name_objects.back().position.scale(glm::vec3(0.075f,0.055f,0.2f));
  //  name_objects.back().position.move(position_titles[i]);
}

for(int i=0;i<objectss_pointer.size();i++){
    name_objects.emplace_back(textShader,&projection,&view_pos,glm::vec3(0.0f,0.0f,0.0f),font_Hack,"");
    //name_objects.back().position.scale(glm::vec3(0.25f,1.0f,1.0f));
    //name_objects.back().position.scale(glm::vec3(0.075f,0.055f,0.2f));
    name_objects.back().position.move(position_titles[i]+(*objectss_pointer[i]).position_object.position_world());
    std::cout<<"№№№№№glm::vec3("<<(*objectss_pointer[i]).position_object.position_world().x<<","<<(*objectss_pointer[i]).position_object.position_world().y<<","<<(*objectss_pointer[i]).position_object.position_world().z<<")"<<std::endl;
}

//std::string ss="яюэьыъщшчцхфутсрпонмлкйизжедгвба";
//ss+="ЯЮЭЬЫЪЩШЧЦХФУТСРПОНМЛКЙИЗЖЕДГВБА";

//for(int i=0;i<ss.size();i=i+2)
//std::cout<<"if(symbol1=="<<static_cast<int>(ss[i])<<" && symbol2=="<<static_cast<int>(ss[i+1])<<"){return 255-"<<i/2<<";};"<<std::endl;

int timer=0;
glm::vec3 k=glm::vec3(0.0f,0.0f,0.0f);
glm::vec1 m=glm::vec1(0.0f);
glm::vec1 u=glm::vec1(0.0f);
int h=0;
bool job=false;
bool  compute=true;
bool knopka_P=false;
bool move=false;
bool choice_PMH_9=false;
bool choice_VEU_8=false;

float E_VIE=0.0f;
float E_PMT=0.0f;
float E_DGS=0.0f;
float E_ССT=0.0f;

float E_N_NTE=0.0f;
float E_N_Li_in=0.0f;
float E_N_SC=0.0f;
float E_N_VSAE=0.0f;

float E_P_PTE=0.0f;
float E_P_PEE=0.0f;

std::vector<float> E_VIES;
std::vector<float> E_PMTS;
std::vector<float> E_DGSS;
std::vector<float> E_ССTS;

std::vector<float> E_N_NTES;
std::vector<float> E_N_Li_inS;
std::vector<float> E_N_SCS;
std::vector<float> E_N_VSAES;

std::vector<float> E_P_PTES;
std::vector<float> E_P_PEES;

E_N_NTES.push_back(0);
E_N_Li_inS.push_back(0);
E_N_SCS.push_back(0);
E_N_VSAES.push_back(0);

E_VIES.push_back(0);
E_PMTS.push_back(0);
E_DGSS.push_back(0);
E_ССTS.push_back(0);

E_P_PEES.push_back(0);
E_P_PTES.push_back(0);

test.new_fraem();
glfwSetInputMode(test.window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
glfwSetInputMode(test.window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
glfwSetCursorPos(test.window,test.width/2,test.height/2);
charts[7].setting.color=glm::vec3(0.4f,1.0f,1.0f);
charts[6].setting.color=glm::vec3(0.4f,0.5f,0.8f);
glm::vec3 position_seting=glm::vec3(0.0f,0.0f,0.0f);
int nomer_graf=0;
Time t;
input[SETTING][7].string_in_float();
input[SETTING][6].string_in_float();
t.month=input[SETTING][7].date.current_value_nomber-1;

time_curent.month= input[SETTING][7].date.current_value_nomber-1;
switch (static_cast<int>(input[SETTING][6].date.current_value_nomber)){
case  77:current_region=MOSCOW;                   break;
case   5:current_region=REPUBLIC_OF_DAGESTAN;     break;
case  51:current_region=MURMANSK_REGION;          break;
case  10:current_region=REPUBLIC_OF_KARELIA;      break;
case  65:current_region=SAKHALIN_REGION;          break;
case  14:current_region=REPUBLIC_OF_SAKHA_YAKUTIA;break;
case  25:current_region=PRIMORSKY_KRAI;           break;
}
std::cout<<current_region<<std::endl;
for(int i=12;i==12;i++){
    for(int j=0;j<buttons.size()/charts.size();j++){
      buttons[i*buttons.size()/charts.size()+j].position.move(glm::vec3(0.0,0.666f,0.0f));
       }
    text_name_graf[i].position.move(glm::vec3(0.0,0.666f,0.0f));
    for(int j=0,k=5;j<6 && k>-1;j++,k--){
    text_division_x[j+i*6].position.move(glm::vec3(0.0,0.666f,0.0f));
    lines_x[j+i*6].position.move(glm::vec3(0.0,0.666f,0.0f));
    text_division_y[j+i*6].position.move(glm::vec3(0.0,0.666f,0.0f));
    lines_y[j+i*6].position.move(glm::vec3(0.0,0.666f,0.0f));
    }
    //background[i].position.move(glm::vec3(0.434,0.0f,0.0f));
    charts[i].position.move(glm::vec3(0.0,0.666f,0.0f));
    dimension_x[i].position.move(glm::vec3(0.0,0.666f,0.0f));
    dimension_x[i].position.move(glm::vec3(0.0,0.666f,0.0f));
  //dimension_x[i].
    dimension_y[i].position.move(glm::vec3(0.0,0.666f,0.0f));
    dimension_y[i].position.move(glm::vec3(0.0,0.666f,0.0f));
  //dimension_y[i].
    if( charts[charts[i].grid_y*4+charts[i].grid_x].chart_pointre.size()){
    charts[charts[i].grid_y*4+charts[i].grid_x].disconnect_chart(&charts[i]);
    }

    charts[i].grid_y=charts[i].grid_y-1;
   if(charts[charts[i].grid_y*4+charts[i].grid_x].grid_x==charts[i].grid_x &&
     charts[charts[i].grid_y*4+charts[i].grid_x].grid_y==charts[i].grid_y){
   std::cout<<i<<"uuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuu"<<buttons.size()/charts.size()<<std::endl;
    charts[charts[i].grid_y*4+charts[i].grid_x].connect_chart(&charts[i]);
   }else{
   std::cout<<i<<"{uuuuuuuuuuuuuuuuuuuuuuuuuuuuuuu}"<<std::endl;
   }
}

    while (!glfwWindowShouldClose(test.window)){

        // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
        glfwPollEvents();
         movent();
         keys[GLFW_MOUSE_BUTTON_MIDDLE]=glfwGetMouseButton(test.window,GLFW_MOUSE_BUTTON_MIDDLE);
         keys[GLFW_MOUSE_BUTTON_LEFT]  =glfwGetMouseButton(test.window,GLFW_MOUSE_BUTTON_LEFT);
         keys[GLFW_MOUSE_BUTTON_RIGHT]  =glfwGetMouseButton(test.window,GLFW_MOUSE_BUTTON_RIGHT);
         test.new_fraem();
         Do_Movement(test);


        // Check and call events

         graf_1.time_one_day =input[SETTING][5].date.current_value_nomber*input[SETTING][4].date.current_value_nomber;//мс
         graf_1.total_time =24*60*60*input[SETTING][5].date.current_value_nomber;
         if(job){
             if(!(time_curent.second_cyrent()>=static_cast<int>(graf_1.total_time))){
                  time_curent+=static_cast<int>((graf_1.total_time)/(graf_1.time_one_day/(test.deltaTime)));
             }else{
               time_curent=static_cast<int>(graf_1.total_time);
               time_curent.year+=2020;
               time_curent.month=input[SETTING][7].date.current_value_nomber-1;
               time_curent+=0;
               job=false;
             }
         }


        // Clear the colorbuffer
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



        view=camera.GetViewMatrix();
        view_pos=camera.GetViewMatrix();
                //glm::vec4{camera.Position.x, camera.Position.y, camera.Position.z,1.0f};
        projection=glm::perspective(glm::radians(camera.Zoom), static_cast<GLfloat>(WIDTH) / static_cast<GLfloat>(HEIGHT), 0.1f, 1000.0f);
        materialSheder.Uniform("viewPos", camera.Position.x, camera.Position.y, camera.Position.z);




       object.models[0].position.rotete(glm::vec3(0.0f, 0.0f, 1.0f),0.5f);//лопасти
       vert2.models[0].position.rotete(glm::vec3(0.0f, 1.0f, 0.0f),0.5f);

//            diesel_generator.position_object.move(glm::vec3(trans2,trans1, trans4)-k);
//            k= {trans2, trans1, trans4};
//           std::cout<<"glm::vec3("<<trans2<<","<<trans1<<","<<trans4<<")"<<std::endl;


        if(choice[0]){
        object.DraWIndeF();
        }
        if(choice[1]){
        vert2.DraWIndeF();
        }
        if(choice[2]){
        solar_panel.DraWIndeF();
        }
        if(choice[3]){
        diesel_generator.DraWIndeF();
        }
        if(choice[4]){
        accumulators.DraWIndeF();
        }
        if(choice[5]){
        supercapacitors.DraWIndeF();
        }
        if(choice[6]){
        electrolyzer.DraWIndeF();
        pump.DraWIndeF();
        for(auto &T:normal_pipes){
            T.DraWIndeF();
        }
        for(auto &T:angle_pipes){
            T.DraWIndeF();
        }
        holder_O.DraWIndeF();
        holder_H.DraWIndeF();
        fuel_cell_block.DraWIndeF();
        tank_water.DraWIndeF();
        }

        for(int i=0;i<menu_object.size();i++){
            if(choice_menu[i])
            menu_object[i].DrawIndef();
        }
        for(int i=0;i<menu_object_off.size();i++){
            if(!choice_menu[i])
            menu_object_off[i].DrawIndef();
        }

        graf_button.DrawIndef();
        setting_model_button.DrawIndef();

        if(job){
            stop_button.DrawIndef();
        }else{
            start_button.DrawIndef();
        }
        reset_button.DrawIndef();
        logo_igvie.Draw();
        House_1.DraWIndeF();
        CCT_object.DraWIndeF();
        NTE_object.DraWIndeF();
        platform_4.DraWIndeF();
        invertor.DraWIndeF();
        control.DraWIndeF();

        if(choice_PMH_9){
          //input_field_windous_insert.DrawIndef();
          for(auto&T: button_field_text_PHT){
          T.DrawIndef();
      }
   }
          if(choice_VEU_8){
            //input_field_windous_insert.DrawIndef();
            for(auto&T: button_field_text_VEU){
            T.DrawIndef();
        }
    }

         if(input_field){
             close_button.DrawIndef();
             for(volatile int i=0;i<input_field_text.size();i++){
             if(input_fields[nomber_object][i].on_imput){
                input_field_text[i].DrawIndef();
             }
         }
           input_field_windous.DrawIndef();
        }

        glFinish();
        //glReadPixels(test.width*(1-0.25)/2,test.height*(1-0.05)/2,1,1,GL_RGB,GL_FLOAT,&pixcel);
        glReadPixels(test.xpos,test.height-test.ypos,1,1,GL_RGB,GL_FLOAT,&pixcel);
//        std::cout<<"("<<static_cast<int>(pixcel.r*100+0.5)<<","
//                 <<static_cast<int>(pixcel.g*100+0.5)<<","
//                 <<static_cast<int>(pixcel.b*100+0.5)<<")"<<std::endl;

        int r=static_cast<int>(pixcel.r*100+0.5);
        int g=static_cast<int>(pixcel.g*100+0.5);

/////////////////////////////////////////////////////////////////////////////////////////////
       glClearColor(0.2f, 0.4f, 0.3f, 1.0f);
       glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

       if(knopka_P){
        sleep.Print("Cоздатель:https://vk.com/porohovnik");
        sleep_2.Print("Кузнецов Даниил Андреевич");
        sleep_3.Print("Чтобы скопировать ссылку нажмите букву С");
       }

       if(keys[GLFW_KEY_H]  && keys[GLFW_KEY_L] &&!timer &&!knopka_P){
           timer=15;
           knopka_P=true;
         }

        if(keys[GLFW_KEY_C] &&knopka_P){
            glfwSetClipboardString(test.window,"https://vk.com/porohovnik");
        }

        if(keys[GLFW_KEY_Y] &&!timer &&knopka_P){
            timer=15;
            knopka_P=false;
        }


        time_curent_model.Print(std::to_string(time_curent.hours)+"h:"+std::to_string(time_curent.minutes)+"m:"+std::to_string(time_curent.seconds)+"c");
        time_curent_model_yuers.Print(std::to_string(time_curent.year)+"."+std::to_string(time_curent.month+1)+"."+std::to_string(time_curent.day+1)+"day");


        if(choice[0]){
        object.DraWMateriaL();
        }
        if(choice[1]){
        vert2.DraWMateriaL();
        }
        if(choice[2]){
        solar_panel.DraWMylt();
        }
        if(choice[3]){
        diesel_generator.DraWMateriaL();
        }
        if(choice[4]){
        accumulators.DraWMateriaL();
        }
        if(choice[5]){
        supercapacitors.DraWMateriaL();
        }
        if(choice[6]){
        electrolyzer.DraWMateriaL();
        pump.DraWMateriaL();
        for(auto &T:normal_pipes){
            T.DraWMateriaL();
        }
        for(auto &T:angle_pipes){
            T.DraWMateriaL();
        }
        holder_H.DraWMateriaL();
        holder_O.DraWMateriaL();
        fuel_cell_block.DraWMateriaL();
        tank_water.DraWMateriaL();
        }
        invertor.DraWMateriaL();
        control.DraWMateriaL();
//        switch (r) {
//        case 5:
//        case 4:
//        case 3:inerfj.Draw();break;
//       // case 20:std::cout<<"fon"<<std::endl;break;
//    //    case 0 :std::cout<<"black"<<std::endl;break;
//        }

//std::cout<<"||-3________"<<"$%@%$#$#666666666666666666666666666666666666666666666666666"<<r<<"|"<<g<<std::endl;
        for(int i=0;i<objectss_pointer.size();i++)
        for(auto &T:(*objectss_pointer[i]).models)
        if(static_cast<int>(T.id.r*100)==r && static_cast<int>(T.id.g*100)==g  ){
             name_objects[i].Print(input_fields[i].name);
        }

        if(timer!=0)
        timer--;
////
if(keys[GLFW_MOUSE_BUTTON_RIGHT] && !timer){
     timer=15;
     k=glm::vec3(0.0f,0.0f,0.0f);

     for(int i=0;i<objectss_pointer.size();i++)
     for(auto &T:(*objectss_pointer[i]).models)
     if(static_cast<int>(T.id.r*100)==r && static_cast<int>(T.id.g*100)==g  ){
       move=true;
       nomber_object=i;
     }
     trans1=0.0f;
     trans2=0.0f;
     trans3=0.0f;
     trans4=0.0f;
     trans5=0.0f;
}
     if(move){
         (*objectss_pointer[nomber_object]).position_object.move(glm::vec3(trans2,trans1, trans4)-k);
        name_objects[nomber_object].position.move(glm::vec3(trans2,trans1, trans4)-k);
         k= {trans2, trans1, trans4};

//         (*objectss_pointer[nomber_object]).position_object.rotete(glm::vec3(0.0f, 1.0f, 0.0f),trans3-m.r);
//         m.r=trans3;
        if(trans5>u.r){
         (*objectss_pointer[nomber_object]).position_object.scale(glm::vec3(1.01f, 1.01f, 1.01f));
         trans5++;
         u.r=trans5;
        }
        if(trans5<u.r){
         (*objectss_pointer[nomber_object]).position_object.scale(glm::vec3(0.99f, 0.99f, 0.99f));
         trans5--;
         u.r=trans5;
        }

        std::cout<<"glm::vec3("<<trans2<<","<<trans1<<","<<trans4<<")["<<trans3<<"]glm::vec3("<<trans5<<","<<trans5<<","<<trans5<<")["<<std::endl;

     }


//std::cout<<"||-2________"<<"$%@%$#$#666666666666666666666666666666666666666666666666666"<<r<<"|"<<g<<std::endl;

if(keys[GLFW_MOUSE_BUTTON_LEFT] && !timer){
        timer=15;

        if(static_cast<int>(graf_button.id.r*100)==r && static_cast<int>(graf_button.id.g*100)==g  ){
            graf_button_clic=true;
            glfwShowWindow(test2.window);
            std::cout<<"##################################################"<<std::endl;
        }


        if(static_cast<int>(start_button.id.r*100)==r && static_cast<int>(start_button.id.g*100)==g  ){
            job=true;
            std::cout<<"##################################################"<<std::endl;
        }

        if(static_cast<int>(reset_button.id.r*100)==r && static_cast<int>(reset_button.id.g*100)==g  ){
            job=false;
            compute=true;
            time_curent=0;
            time_curent.month= input[SETTING][7].date.current_value_nomber-1;
            time_curent.year=2020;
            std::cout<<"##################################################"<<std::endl;
        }

        if(static_cast<int>(stop_button.id.r*100)==r && static_cast<int>(stop_button.id.g*100)==g  ){
            job=false;
            std::cout<<"##################################################"<<std::endl;
        }

        if(input_field  && (static_cast<int>(close_button.id.r*100)==r && static_cast<int>(close_button.id.g*100)==g)){

            time_curent.month= input[SETTING][7].date.current_value_nomber-1;
            switch (static_cast<int>(input[SETTING][6].date.current_value_nomber)){
            case  77:current_region=MOSCOW;                   break;
            case   5:current_region=REPUBLIC_OF_DAGESTAN;     break;
            case  51:current_region=MURMANSK_REGION;          break;
            case  10:current_region=REPUBLIC_OF_KARELIA;      break;
            case  65:current_region=SAKHALIN_REGION;          break;
            case  14:current_region=REPUBLIC_OF_SAKHA_YAKUTIA;break;
            case  25:current_region=PRIMORSKY_KRAI;           break;

            }
    std::cout<<current_region<<std::endl;
           input_field=false;
           for(auto &T:input){
               for(auto&J:T){
                  J.active=false;
                  J.imput.clear();
               }
           }


        }

        if(static_cast<int>(setting_model_button.id.r*100)==r && static_cast<int>(setting_model_button.id.g*100)==g  ){
            input_field=true;
            nomber_object=24;
            std::cout<<"##################################################"<<std::endl;
        }


        for(int i=0;i<objectss_pointer.size();i++){
        for(auto &T:(*objectss_pointer[i]).models){
        if(static_cast<int>(T.id.r*100)==r && static_cast<int>(T.id.g*100)==g  ){
          input_field=true;
          nomber_object=i;
        }
    }
}
        for(int i=0;i<7;i++){
        if(static_cast<int>(menu_object[i].id.r*100)==r && static_cast<int>(menu_object[i].id.g*100)==g  ){
            choice_menu[i]=false;
            choice[i]=false;


        }
       }

       for(int i=0;i<7;i++){
        if(static_cast<int>(menu_object_off[i].id.r*100)==r && static_cast<int>(menu_object_off[i].id.g*100)==g){
            choice_menu[i]=true;
            choice[i]=true;
            std::cout<<i<<"ff"<<std::endl;
            if(i==1){
                choice_menu[0]=false;
                choice[0]=false;
            }
            if(i==0){
                choice_menu[1]=false;
                choice[1]=false;

            }
        }
     }

       for(int i=0; i<button_field_text_PHT.size();i++){
       if(static_cast<int>(button_field_text_PHT[i].id.r*100)==r && static_cast<int>(button_field_text_PHT[i].id.g*100)==g  ){
         for(auto &T: button_marker_job){
              T=false;
         }
         button_marker_job[i]=true;
        input[PMT][8].active=false;
        input[PMT][8].imput=namber_chart_PHT_p[i];
        input[PMT][8].date.current_value_symbol=namber_chart_PHT_p[i];
       }
   }
       for(int i=0; i<button_field_text_VEU.size();i++){
       if(static_cast<int>(button_field_text_VEU[i].id.r*100)==r && static_cast<int>(button_field_text_VEU[i].id.g*100)==g  ){
         for(auto &T: button_marker_job_VEU){
              T=false;
         }
         button_marker_job_VEU[i]=true;
        input[SETTING][6].active=false;
        input[SETTING][6].imput=namber_chart_VEU_p[i];
        input[SETTING][6].date.current_value_symbol=namber_chart_VEU_p[i];
       }
   }


};
        if(choice_PMH_9){
            for(int i=0;i<text_button_PHT.size();i++){
            text_button_PHT[i].Print(name_chart_PHT[i]);
            text_button_PHT_p[i].Print(namber_chart_PHT_p[i]);
            if(button_marker_job[i]){
            button_marker[i].Draw();
            }
           }
           for(auto&T:button_field_text_PHT){
            T.Draw();
           }

            text_button_content.Print("Тип поверхности");
            text_button_content_p.Print("Альбедо");
            button_field_text_content.Draw();
            input_field_windous_insert.Draw();

    }
        if(choice_VEU_8){
            for(int i=0;i<text_button_VEU.size();i++){
            text_button_VEU[i].Print(name_chart_VEU[i]);
            text_button_VEU_p[i].Print(namber_chart_VEU_p[i]);
            if(button_marker_job_VEU[i]){
            button_marker_VEU[i].Draw();
            }
           }
           for(auto&T:button_field_text_VEU){
            T.Draw();
           }


            text_button_content.Print("Название региона");
            text_button_content_p.Print("Код региона");
            button_field_text_content.Draw();
            input_field_windous_insert_VEU.Draw();

    }
////
        if(input_field){
            close_button.Draw();
            header_input_field_windous.Print(input_fields[nomber_object].name);


          for(volatile int i=0;i<input_field_text.size();i++){

          if(input[nomber_object][i].date.on_imput){


              text[i].Print(input[nomber_object][i].date.current_value_symbol);
              text1[i].Print(input[nomber_object][i].date.name);
              text2[i].Print(input[nomber_object][i].date.dimension);
              input_field_text[i].Draw();

              if(input[nomber_object][i].active){
              if(glfwGetKey(test.window,GLFW_KEY_DOWN)==GLFW_PRESS &&!timer && (i+1)!=static_cast<int>(input_field_text.size())){
                  input[nomber_object][i+1].activeted();
                  timer=15;
              }


              if(glfwGetKey(test.window,GLFW_KEY_UP)==GLFW_PRESS &&!timer && i!=0){
                  input[nomber_object][i-1].activeted();
                  timer=15;
              }



             // input[nomber_object][i].date.max_size_input_symbol=input_fields[nomber_object][i].max_size_input_symbol;
             //input_fields[nomber_object][i].current_value_symbol.clear();

              }
              if(input[PMT][8].active){
                  choice_PMH_9=true;
                  std::cout<<"###"<<std::endl;
              }else{
                  choice_PMH_9=false;
              }

              if(input[SETTING][6].active){
                  choice_VEU_8=true;
                  std::cout<<"####"<<std::endl;
              }else{
                  choice_VEU_8=false;
              }

              if(input[SETTING][6].active){
              // cod_region.Draw();
               }

              if(input[VEU_V][7].active || input[VEU_H][7].active){
              grid_veu.Draw();
              }

              }

              input[nomber_object][i].new_fraem(r,g);
           }
              input_field_windous.Draw();
       }else{
            choice_PMH_9=false;
            choice_VEU_8=false;
        }




        for(int i=0;i<menu_object.size();i++){
            if(choice_menu[i])
            menu_object[i].Draw();
        }
        for(int i=0;i<menu_object_off.size();i++){
            if(!choice_menu[i])
            menu_object_off[i].Draw();
        }


        rect_1.Draw();

        glDepthFunc(GL_ALWAYS);

        for(auto &T:rects){
            T.Draw();
        }

            if(job){
                E_VIE=0.0f;
                E_PMT=0.0f;
                E_DGS=0.0f;
                E_ССT=0.0f;

                E_N_NTE=0.0f;
                E_N_Li_in=0.0f;
                E_N_SC=0.0f;
                E_N_VSAE=0.0f;

                E_P_PTE=0.0f;
                E_P_PEE=0.0f;

                E_VIES.clear();if(choice[2])
                E_PMTS.clear();
                E_DGSS.clear();
                E_ССTS.clear();

                E_N_NTES.clear();
                E_N_Li_inS.clear();
                E_N_SCS.clear();
                E_N_VSAES.clear();

                E_P_PTES.clear();
                E_P_PEES.clear();

                E_N_NTES.push_back(0);
                E_N_Li_inS.push_back(0);
                E_N_SCS.push_back(0);
                E_N_VSAES.push_back(0);

                E_VIES.push_back(0);
                E_PMTS.push_back(0);
                E_DGSS.push_back(0);
                E_ССTS.push_back(0);


                E_P_PEES.push_back(0);
                E_P_PTES.push_back(0);

                stop_button.Draw();
               // current_region;

                if(compute){
                glfwMakeContextCurrent(test2.window);
                std::vector<Vertex> vertices3;
                Vertex T3(glm::vec3(0.0f,0.0f,0.0f),
                         glm::vec3(0.0f,0.0f,0.0f),
                         glm::vec2(0.0f,0.0f),
                         glm::vec3(0.0f,0.0f,0.0f),
                         glm::vec3(0.0f,0.0f,0.0f));


                std::vector<unsigned int> index3;



                float  coefficent_PMT=0.5f;
                float  coefficent_BAX=0.5f;
                float  Temp_PMT=0.5f;
                float  Temp_PMT_do=0.5f;
                float  Temp_okr_sred=0.5f;
                float  Temp_okr_sred_do=0.5f;
                float  delta_Temp_PMT=0.5f;
                float  Kgd=0.5;
                float  w_g=0.5;
                float  w_b=0.5;
                float delta_malay=0.5;
                float K_pi=0.5f;
                float K_sum_B=0.5f;
                float R_B=0.5f;
                int  n[12]={17,47,75,105,135,162,198,228,258,288,318,344};
                coefficent_BAX=input[PMT][3].date.current_value_nomber*input[PMT][2].date.current_value_nomber/
                //--------------------------------------------------------------------------------------------------------------
                 (input[PMT][1].date.current_value_nomber*input[PMT][0].date.current_value_nomber);

                   // std::cout<<"1PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP"<<std::endl;

                    float solar_rad_current;
                    float solar_rad_current_pp;

                    Time i;
                   t.month= input[SETTING][7].date.current_value_nomber-1;
                   i.month= input[SETTING][7].date.current_value_nomber-1;
                   i+=t.second_cyrent();
                for(; i.second_cyrent() <(graf_1.total_time+t.second_cyrent()); i+=1){
                    solar_rad_current=reg_rad[current_region].solar_rad[i.delenie_hours][i.month][i.hours];
                    //std::cout<<"2PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP"<<std::endl;

                    Time i_pp;
                    i_pp=i.second_cyrent(); i_pp.month=i.month;
                     i_pp.month=i.month;
                    i_pp+=60*10;
                    solar_rad_current_pp=reg_rad[current_region].solar_rad[i_pp.delenie_hours][i_pp.month][i_pp.hours];

                    //std::cout<<i_pp.month<<i_pp.hours<<std::endl;
                    float current_rad_colar_second=(double)rand()/(double)RAND_MAX*(solar_rad_current_pp -  solar_rad_current)+solar_rad_current;
                    if(current_rad_colar_second>1.2f){
                      current_rad_colar_second=1.2f;
                    }

                     //  std::cout<<"4.5PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP"<< current_rad_colar_second<<std::endl;
                    delta_Temp_PMT=6*std::pow(10,-6)*std::pow(current_rad_colar_second,2)+0.021*current_rad_colar_second-2.39;


                    Temp_okr_sred= input[SETTING][0].date.current_value_nomber+0.5*input[SETTING][1].date.current_value_nomber*
                                    std::cos(3.14*2.0f*GRAD_RAD*( input[SETTING][3].date.current_value_nomber- input[SETTING][2].date.current_value_nomber)/(i.hours*1.0f));

                   // std::cout<<"5PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP"<<std::endl;


                  //  std::cout<<"6PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP"<<std::endl;

\
                    Temp_PMT= Temp_okr_sred+delta_Temp_PMT+298.15;
                    Kgd=(reg_rad[current_region].diffuse_radiation[i.month])/(reg_rad[current_region].amount_diffuse_radiation[i.month]+reg_rad[current_region].diffuse_radiation[i.month]);

                    delta_malay=23.45*std::sin(GRAD_RAD*360.0f/365.0f*(284+n[i.month]));
                    w_g=std::acos(-std::tan(GRAD_RAD*reg_rad[current_region].hight)*std::tan(GRAD_RAD*delta_malay));
                    w_b=std::min(w_g,acos(-std::tan(GRAD_RAD*reg_rad[current_region].hight-GRAD_RAD*input[PMT][7].date.current_value_nomber)*std::tan(GRAD_RAD*delta_malay)));
                    K_pi=(cos(GRAD_RAD*reg_rad[current_region].hight-GRAD_RAD*input[PMT][7].date.current_value_nomber)*cos(GRAD_RAD*delta_malay)*sin(GRAD_RAD*w_b)+3.14/180*w_b*sin(GRAD_RAD*reg_rad[current_region].hight-GRAD_RAD*input[PMT][7].date.current_value_nomber)*sin(GRAD_RAD*delta_malay))/
                    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                    (cos(GRAD_RAD*reg_rad[current_region].hight)*cos(GRAD_RAD*delta_malay)*sin(GRAD_RAD*w_g)+3.14/180*w_g*sin(GRAD_RAD*reg_rad[current_region].hight)*sin(GRAD_RAD*delta_malay));

                    K_sum_B=(1-Kgd)*K_pi+Kgd*(1+std::cos(GRAD_RAD*input[PMT][7].date.current_value_nomber))/2+input[PMT][8].date.current_value_nomber*(1-std::cos(GRAD_RAD*input[PMT][7].date.current_value_nomber))/2;
                    R_B=current_rad_colar_second*K_sum_B;
                    coefficent_PMT=  coefficent_BAX*298.15f/1000.0f*(input[PMT][1].date.current_value_nomber+input[PMT][5].date.current_value_nomber*(Temp_PMT-298.15))*(input[PMT][0].date.current_value_nomber+input[PMT][4].date.current_value_nomber*(Temp_PMT-298.15))/
                    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                            std::log(std::pow(10,6)*1000);
                    //std::cout<<"|coefficent_PMT:"<<coefficent_PMT<<"|kz:"<<(input[PMT][1].date.current_value_nomber+input[PMT][5].date.current_value_nomber*(Temp_PMT-298.15))<<"|xx:"<<(input[PMT][0].date.current_value_nomber+input[PMT][4].date.current_value_nomber*(Temp_PMT-298.15))<<"|| std::log(std::pow(10,6)*1000):"<< std::log(std::pow(10,6)*1000)<<"|coefficent_BAX:"<<coefficent_BAX<<std::endl;


                    T3.Position.x=i.second_cyrent()*100;
                    if(R_B!=0.0f){
                    T3.Position.y=(coefficent_PMT*input[PMT][6].date.current_value_nomber*R_B*1.0f*input[INVERTOR][0].date.current_value_nomber*std::log(std::pow(10,6)*R_B)/ Temp_PMT)*1000.0f;
                    }else{
                    T3.Position.y=0;
                    }
                    T3.Position.z=0.0f;
                    T3.TexCoords1=std::move(glm::vec2(0.0f, 0.0f));
                    if(i.hours==13){
                    //std::cout<<i_pp.month<<"|"<<i.month<<"|::"<<i_pp.hours<<"|"<<i.hours<<std::endl;
                    //std::cout<<"|T3.Position.y:"<<T3.Position.y<<"|std::log(std::pow(10,6)*R_B):"<<std::log(std::pow(10,6)*R_B)<<"|current_rad_colar_second:"<<current_rad_colar_second<<"|R_B:"<<R_B<<"|Temp_PMT:"<<Temp_PMT<<"|Temp_okr_sred:"<<Temp_okr_sred<<"|coefficent_BAX:"<<coefficent_BAX<<"|coefficent_PMT:"<<coefficent_PMT<<"|K_sum_B:"<<K_sum_B<<"|K_pi:"<< K_pi<<"|Kgd:"<<Kgd<<"|w_b:"<<w_b<<"|w_g:"<<w_g<<"|delta_malay:"<<delta_malay<<"|hight:"<<reg_rad[current_region].hight<<std::endl;
                    }

                    if(!choice[2]){
                       T3.Position.y=0;
                    }
                    vertices3.push_back(T3);
                    if(T3.Position.y>0){
                    E_PMT+=T3.Position.y/3600.0f;
                    }

                    E_PMTS.push_back(E_PMT);
                    };

                Buffer_VAO VAO____3(vertices3,index3);
                charts[1].graf_new(VAO____3);
                charts_separate[1].graf_new(VAO____3);

                float N_consumer_e[12][24]={{0.662,0.609,0.571,0.506,0.564,0.699,0.821,0.949,0.91,0.897,0.885,0.827,0.75,0.731,0.705,0.769,0.833,0.808,0.949,1,0.949,0.923,0.821,0.667},
                                            {0.662,0.609,0.571,0.506,0.564,0.699,0.821,0.949,0.91,0.897,0.885,0.827,0.75,0.731,0.705,0.769,0.833,0.808,0.949,1,0.949,0.923,0.821,0.667},
                                            {0.449,0.41,0.404,0.385,0.449,0.47,0.538,0.594,0.594,0.607,0.615,0.611,0.585,0.494,0.474,0.487,0.526,0.546,0.551,0.594,0.607,0.637,0.571,0.487},
                                            {0.449,0.41,0.404,0.385,0.449,0.47,0.538,0.594,0.594,0.607,0.615,0.611,0.585,0.494,0.474,0.487,0.526,0.546,0.551,0.594,0.607,0.637,0.571,0.487},
                                            {0.449,0.41,0.404,0.385,0.449,0.47,0.538,0.594,0.594,0.607,0.615,0.611,0.585,0.494,0.474,0.487,0.526,0.546,0.551,0.594,0.607,0.637,0.571,0.487},
                                            {0.295,0.256,0.256,0.256,0.231,0.244,0.256,0.282,0.372,0.385,0.372,0.372,0.359,0.385,0.346,0.321,0.385,0.462,0.423,0.526,0.487,0.5,0.404,0.333},
                                            {0.295,0.256,0.256,0.256,0.231,0.244,0.256,0.282,0.372,0.385,0.372,0.372,0.359,0.385,0.346,0.321,0.385,0.462,0.423,0.526,0.487,0.5,0.404,0.333},
                                            {0.295,0.256,0.256,0.256,0.231,0.244,0.256,0.282,0.372,0.385,0.372,0.372,0.359,0.385,0.346,0.321,0.385,0.462,0.423,0.526,0.487,0.5,0.404,0.333},
                                            {0.372,0.372,0.333,0.333,0.308,0.321,0.41,0.449,0.474,0.449,0.397,0.359,0.359,0.359,0.397,0.346,0.333,0.295,0.423,0.538,0.628,0.641,0.513,0.577},
                                            {0.372,0.372,0.333,0.333,0.308,0.321,0.41,0.449,0.474,0.449,0.397,0.359,0.359,0.359,0.397,0.346,0.333,0.295,0.423,0.538,0.628,0.641,0.513,0.577},
                                            {0.372,0.372,0.333,0.333,0.308,0.321,0.41,0.449,0.474,0.449,0.397,0.359,0.359,0.359,0.397,0.346,0.333,0.295,0.423,0.538,0.628,0.641,0.513,0.577},
                                            {0.662,0.609,0.571,0.506,0.564,0.699,0.821,0.949,0.91,0.897,0.885,0.827,0.75,0.731,0.705,0.769,0.833,0.808,0.949,1,0.949,0.923,0.821,0.667}};

                float N_consumer_w[12][24]={{0.773,0.723,0.723,0.723,0.723,0.723,0.723,0.849,0.887,0.897,0.927,0.899,0.811,0.844,0.786,0.778,0.761,0.824,0.899,0.975,1,0.924,0.874,0.836},
                                            {0.773,0.723,0.723,0.723,0.723,0.723,0.723,0.849,0.887,0.897,0.927,0.899,0.811,0.844,0.786,0.778,0.761,0.824,0.899,0.975,1,0.924,0.874,0.836},
                                            {0.397,0.351,0.351,0.351,0.351,0.351,0.351,0.465,0.499,0.508,0.535,0.51,0.431,0.46,0.408,0.401,0.385,0.442,0.51,0.578,0.601,0.533,0.488,0.453},
                                            {0.397,0.351,0.351,0.351,0.351,0.351,0.351,0.465,0.499,0.508,0.535,0.51,0.431,0.46,0.408,0.401,0.385,0.442,0.51,0.578,0.601,0.533,0.488,0.453},
                                            {0.397,0.351,0.351,0.351,0.351,0.351,0.351,0.465,0.499,0.508,0.535,0.51,0.431,0.46,0.408,0.401,0.385,0.442,0.51,0.578,0.601,0.533,0.488,0.453},
                                            {0.038,0.001,0.001,0.001,0.001,0.001,0.001,0.096,0.124,0.132,0.155,0.134,0.067,0.092,0.048,0.042,0.029,0.077,0.134,0.191,0.21,0.153,0.115,0.086},
                                            {0.038,0.001,0.001,0.001,0.001,0.001,0.001,0.096,0.124,0.132,0.155,0.134,0.067,0.092,0.048,0.042,0.029,0.077,0.134,0.191,0.21,0.153,0.115,0.086},
                                            {0.038,0.001,0.001,0.001,0.001,0.001,0.001,0.096,0.124,0.132,0.155,0.134,0.067,0.092,0.048,0.042,0.029,0.077,0.134,0.191,0.21,0.153,0.115,0.086},
                                            {0.397,0.351,0.351,0.351,0.351,0.351,0.351,0.465,0.499,0.508,0.535,0.51,0.431,0.46,0.408,0.401,0.385,0.442,0.51,0.578,0.601,0.533,0.488,0.453},
                                            {0.397,0.351,0.351,0.351,0.351,0.351,0.351,0.465,0.499,0.508,0.535,0.51,0.431,0.46,0.408,0.401,0.385,0.442,0.51,0.578,0.601,0.533,0.488,0.453},
                                            {0.397,0.351,0.351,0.351,0.351,0.351,0.351,0.465,0.499,0.508,0.535,0.51,0.431,0.46,0.408,0.401,0.385,0.442,0.51,0.578,0.601,0.533,0.488,0.453},
                                            {0.773,0.723,0.723,0.723,0.723,0.723,0.723,0.849,0.887,0.897,0.927,0.899,0.811,0.844,0.786,0.778,0.761,0.824,0.899,0.975,1,0.924,0.874,0.836}};


                std::vector<Vertex> vertices4;
                Vertex T4(glm::vec3(0.0f,0.0f,0.0f),
                         glm::vec3(0.0f,0.0f,0.0f),
                         glm::vec2(0.0f,0.0f),
                         glm::vec3(0.0f,0.0f,0.0f),
                         glm::vec3(0.0f,0.0f,0.0f));


                std::vector<unsigned int> index4;

                i=0;
                t.month= input[SETTING][7].date.current_value_nomber-1;
                i.month= input[SETTING][7].date.current_value_nomber-1;
                i+=t.second_cyrent();
                for(; i.second_cyrent() <(graf_1.total_time+t.second_cyrent()); i+=1){
                    float consumer_e_current=N_consumer_e[i.month][i.hours];
                    //  std::cout<<"2PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP"<<std::endl;
                      float consumer_e_current_pp=0.5f;
                      Time i_pp;
                      i_pp.month=i.month;
                      i_pp=i.second_cyrent(); i_pp.month=i.month;

                      i_pp+=60*60;
                      consumer_e_current_pp=N_consumer_e[i_pp.month][i_pp.hours];
                   //   std::cout<<i_pp.month<<"|"<<i.month<<"|::"<<i_pp.hours<<"|"<<i.hours<<std::endl;
                      //std::cout<<"4PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP"<<std::endl;

                      float consumer_e_current_second=(consumer_e_current_pp-consumer_e_current)*(60*i.minutes)/(60*60)+consumer_e_current;


                    T4.Position.x=i.second_cyrent()*100;
                    T4.Position.y=consumer_e_current_second*input[HOUSE][0].date.current_value_nomber*1000;
                    T4.Position.z=0.0f;
                    T4.TexCoords1=std::move(glm::vec2(0.0f, 0.0f));
                   // std::cout<<std::pow(i,0.05)*25.1f<<std::endl;
                    vertices4.push_back(T4);
                    E_P_PEE+=T4.Position.y/3600.0f;
                    E_P_PEES.push_back(E_P_PEE);


                    };

                Buffer_VAO VAO____4(vertices4,index4);
                charts[8].graf_new(VAO____4);
                charts_separate[8].graf_new(VAO____4);


                std::vector<Vertex> vertices6;
                Vertex T6(glm::vec3(0.0f,0.0f,0.0f),
                         glm::vec3(0.0f,0.0f,0.0f),
                         glm::vec2(0.0f,0.0f),
                         glm::vec3(0.0f,0.0f,0.0f),
                         glm::vec3(0.0f,0.0f,0.0f));
                  std::vector<unsigned int> index6;

                 float consumer_w_current_second=0.5f;
                 i=0;
                 t.month= input[SETTING][7].date.current_value_nomber-1;
                 i.month= input[SETTING][7].date.current_value_nomber-1;
                 i+=t.second_cyrent();
                 for(; i.second_cyrent() <(graf_1.total_time+t.second_cyrent()); i+=1){
                  float consumer_w_current=N_consumer_w[i.month][i.hours];

                  //  std::cout<<"2PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP"<<std::endl;
                    float consumer_w_current_pp=0.5f;
                    Time i_pp;
                     i_pp.month=i.month;
                    i_pp=i.second_cyrent(); i_pp.month=i.month;
                    i_pp+=60*60;
                   // std::cout<<i_pp.month<<i_pp.hours<<std::endl;
                    consumer_w_current_pp=N_consumer_w[i_pp.month][i_pp.hours];


                    //std::cout<<"4PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP"<<std::endl;

                    float consumer_w_current_second=(consumer_w_current_pp-consumer_w_current)*(60*i.minutes)/(60*60)+consumer_w_current;





                    T6.Position.x=i.second_cyrent()*100;
                    T6.Position.y=consumer_w_current_second*input[HOUSE][1].date.current_value_nomber*1000;
                    T6.Position.z=0.0f;
                    T6.TexCoords1=std::move(glm::vec2(0.0f, 0.0f));
                   // std::cout<<std::pow(i,0.05)*25.1f<<std::endl;
                    vertices6.push_back(T6);
                    E_P_PTE+=T6.Position.y/3600.0f;
                    E_P_PTES.push_back(E_P_PTE);

                    };

                Buffer_VAO VAO____6(vertices6,index6);
                charts[12].graf_new(VAO____6);
                charts_separate[9].graf_new(VAO____6);

                std::vector<Vertex> vertices7;
                Vertex T7(glm::vec3(0.0f,0.0f,0.0f),
                         glm::vec3(0.0f,0.0f,0.0f),
                         glm::vec2(0.0f,0.0f),
                         glm::vec3(0.0f,0.0f,0.0f),
                         glm::vec3(0.0f,0.0f,0.0f));
                  std::vector<unsigned int> index7;

                  i=0;
                  t.month= input[SETTING][7].date.current_value_nomber-1;
                  i.month= input[SETTING][7].date.current_value_nomber-1;
                  i+=t.second_cyrent();
                  for(; i.second_cyrent() <(graf_1.total_time+t.second_cyrent()); i+=1){
                      solar_rad_current=reg_rad[current_region].solar_rad[i.delenie_hours][i.month][i.hours];
                      //std::cout<<"2PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP"<<std::endl;

                      Time i_pp;
                      i_pp=i.second_cyrent(); i_pp.month=i.month;
                       i_pp.month=i.month;
                      i_pp+=60*10;
                      solar_rad_current_pp=reg_rad[current_region].solar_rad[i_pp.delenie_hours][i_pp.month][i_pp.hours];

                      //std::cout<<i_pp.month<<i_pp.hours<<std::endl;
                      float current_rad_colar_second=(double)rand()/(double)RAND_MAX*(solar_rad_current_pp -  solar_rad_current)+solar_rad_current;
                      if(current_rad_colar_second>1.2f){
                        current_rad_colar_second=1.2f;
                      }

                       //  std::cout<<"4.5PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP"<< current_rad_colar_second<<std::endl;
                      delta_Temp_PMT=6*std::pow(10,-6)*std::pow(current_rad_colar_second,2)+0.021*current_rad_colar_second-2.39;


                      Temp_okr_sred= input[SETTING][0].date.current_value_nomber+0.5*input[SETTING][1].date.current_value_nomber*
                                      std::cos(3.14*2.0f*GRAD_RAD*( input[SETTING][3].date.current_value_nomber- input[SETTING][2].date.current_value_nomber)/(i.hours*1.0f));

                     // std::cout<<"5PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP"<<std::endl;


                    //  std::cout<<"6PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP"<<std::endl;

  \
                      Temp_PMT= Temp_okr_sred+delta_Temp_PMT+298.15;
                      Kgd=(reg_rad[current_region].diffuse_radiation[i.month])/(reg_rad[current_region].amount_diffuse_radiation[i.month]+reg_rad[current_region].diffuse_radiation[i.month]);

                      delta_malay=23.45*std::sin(GRAD_RAD*360.0f/365.0f*(284+n[i.month]));
                      w_g=std::acos(-std::tan(GRAD_RAD*reg_rad[current_region].hight)*std::tan(GRAD_RAD*delta_malay));
                      w_b=std::min(w_g,acos(-std::tan(GRAD_RAD*reg_rad[current_region].hight-GRAD_RAD*input[PMT][7].date.current_value_nomber)*std::tan(GRAD_RAD*delta_malay)));
                      K_pi=(cos(GRAD_RAD*reg_rad[current_region].hight-GRAD_RAD*input[CCT][5].date.current_value_nomber)*cos(GRAD_RAD*delta_malay)*sin(GRAD_RAD*w_b)+3.14/180*w_b*sin(GRAD_RAD*reg_rad[current_region].hight-GRAD_RAD*input[CCT][5].date.current_value_nomber)*sin(GRAD_RAD*delta_malay))/
                      //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                      (cos(GRAD_RAD*reg_rad[current_region].hight)*cos(GRAD_RAD*delta_malay)*sin(GRAD_RAD*w_g)+3.14/180*w_g*sin(GRAD_RAD*reg_rad[current_region].hight)*sin(GRAD_RAD*delta_malay));

                      K_sum_B=(1-Kgd)*K_pi+Kgd*(1+std::cos(GRAD_RAD*input[CCT][5].date.current_value_nomber))/2+input[PMT][8].date.current_value_nomber*(1-std::cos(GRAD_RAD*input[CCT][5].date.current_value_nomber))/2;
                      R_B=current_rad_colar_second*K_sum_B;



                    T7.Position.x=i.second_cyrent()*100;

                    T7.Position.y=(input[CCT][0].date.current_value_nomber*(R_B*input[CCT][1].date.current_value_nomber*input[CCT][2].date.current_value_nomber-input[CCT][3].date.current_value_nomber*(input[CCT][4].date.current_value_nomber- Temp_okr_sred))*input[CCT][6].date.current_value_nomber)*1000.0f;
                    if(T7.Position.y<0){
                    T7.Position.y=0;
                    }
                    T7.Position.z=0.0f;
                    T7.TexCoords1=std::move(glm::vec2(0.0f, 0.0f));
                   // std::cout<<std::pow(i,0.05)*25.1f<<std::endl;
                    vertices7.push_back(T7);
                    if(i.hours==12){
                   //std::cout<<"|T7.Position.y:"<<T7.Position.y<<"|current_rad_colar_second:"<<current_rad_colar_second<<"|R_B:"<<R_B<<"|Temp_PMT:"<<Temp_PMT<<"|Temp_okr_sred:"<<Temp_okr_sred<<"|coefficent_PMT:"<<coefficent_PMT<<"|K_sum_B:"<<K_sum_B<<"|K_pi:"<< K_pi<<"|Kgd:"<<Kgd<<"|w_b:"<<w_b<<"|w_g:"<<w_g<<"|delta_malay:"<<delta_malay<<"|hight:"<<reg_rad[current_region].hight<<std::endl;
                    }
                    E_ССT+=T7.Position.y/3600.0f;
                    E_ССTS.push_back(T7.Position.y);
                    };

                Buffer_VAO VAO____7(vertices7,index7);




                charts[6].graf_new(VAO____7);
                charts_separate[6].graf_new(VAO____7);

                std::vector<Vertex> vertices8;
                Vertex T8(glm::vec3(0.0f,0.0f,0.0f),
                         glm::vec3(0.0f,0.0f,0.0f),
                         glm::vec2(0.0f,0.0f),
                         glm::vec3(0.0f,0.0f,0.0f),
                         glm::vec3(0.0f,0.0f,0.0f));
                  std::vector<unsigned int> index8;


                  i=0;
                  t.month= input[SETTING][7].date.current_value_nomber-1;
                  i.month= input[SETTING][7].date.current_value_nomber-1;
                  i+=t.second_cyrent();
                  for(; i.second_cyrent() <(graf_1.total_time+t.second_cyrent()); i+=1){
                    T8.Position.x=i.second_cyrent()*100;


                    if( (E_N_NTES.back()-(vertices7[i.second_cyrent()].Position.y-vertices6[i.second_cyrent()].Position.y)*input[NTE][0].date.current_value_nomber/3600.0f)>=0){
                    T8.Position.y=(vertices7[i.second_cyrent()].Position.y-vertices6[i.second_cyrent()].Position.y)*input[NTE][0].date.current_value_nomber;
                    }else{
                    T8.Position.y=E_N_NTES.back()*3600.0f;
                    }
                    T8.Position.z=0.0f;
                    T8.TexCoords1=std::move(glm::vec2(0.0f, 0.0f));
                   // std::cout<<std::pow(i,0.05)*25.1f<<std::endl;
                    vertices8.push_back(T8);

                 //    std::cout<<"|V_NTE:"<<T8.Position.y/3600.0f<<std::endl;

                    E_N_NTE+=T8.Position.y/3600.0f;
                    if(E_N_NTE<0){
                        E_N_NTE=0;
                    }
                    E_N_NTES.push_back(E_N_NTE);

                    };

                Buffer_VAO VAO____8(vertices8,index8);
                charts[7].graf_new(VAO____8);
                charts_separate[7].graf_new(VAO____8);

                std::vector<Vertex> vertices9;
                Vertex T9(glm::vec3(0.0f,0.0f,0.0f),
                         glm::vec3(0.0f,0.0f,0.0f),
                         glm::vec2(0.0f,0.0f),
                         glm::vec3(0.0f,0.0f,0.0f),
                         glm::vec3(0.0f,0.0f,0.0f));
                  std::vector<unsigned int> index9;


                  float speed_vetrak=0.5f;
                  float speed_vetrak_pp=0.5f;
                  float  speed_veter=0.5f;
                  float K_otk=0.5f;
                  float m;

                  float input_VEU_0;
                  float input_VEU_1;
                  float input_VEU_2;
                  float input_VEU_3;
                  float input_VEU_4;
                  float input_VEU_5;
                  float input_VEU_6;
                  float input_VEU_7;
                  if(choice[0]){
                    input_VEU_0=input[VEU_V][0].date.current_value_nomber;
                    input_VEU_1=input[VEU_V][1].date.current_value_nomber;
                    input_VEU_2=input[VEU_V][2].date.current_value_nomber;
                    input_VEU_3=input[VEU_V][3].date.current_value_nomber;
                    input_VEU_4=input[VEU_V][4].date.current_value_nomber;
                    input_VEU_5=input[VEU_V][5].date.current_value_nomber;
                    input_VEU_6=input[VEU_V][6].date.current_value_nomber;
                    input_VEU_7=input[VEU_V][7].date.current_value_nomber;
                  }

                  if(choice[1]){
                    input_VEU_0=input[VEU_H][0].date.current_value_nomber;
                    input_VEU_1=input[VEU_H][1].date.current_value_nomber;
                    input_VEU_2=input[VEU_H][2].date.current_value_nomber;
                    input_VEU_3=input[VEU_H][3].date.current_value_nomber;
                    input_VEU_4=input[VEU_H][4].date.current_value_nomber;
                    input_VEU_5=input[VEU_H][5].date.current_value_nomber;
                    input_VEU_6=input[VEU_H][6].date.current_value_nomber;
                    input_VEU_7=input[VEU_H][7].date.current_value_nomber;
                  }

                  i=0;
                  t.month= input[SETTING][7].date.current_value_nomber-1;
                  i.month= input[SETTING][7].date.current_value_nomber-1;
                  i+=t.second_cyrent();
                  for(; i.second_cyrent() <(graf_1.total_time+t.second_cyrent()); i+=1){
                    Time i_pp;
                     i_pp.month=i.month;
                    i_pp=i.second_cyrent(); i_pp.month=i.month;
                    i_pp+=60*60*3;
           //        std::cout<<"|[]|"<<i_pp.month<<i_pp.hours<<std::endl;
                    solar_rad_current_pp=regions[current_region][i_pp.month][i_pp.hours].wind_speed;
                    //std::cout<<"||||||||||||current_region:"<<current_region<<i_pp.month<<i_pp.hours<<std::endl;
                    speed_veter=regions[current_region][i.month][i.hours].wind_speed+(double)rand()/(double)RAND_MAX*(solar_rad_current_pp-regions[current_region][i.month][i.hours].wind_speed+0.1f);

                    K_otk=0.2113*input_VEU_7+0.155;


                    m=0.5551*std::pow(speed_veter,-0.7275);
                    speed_vetrak=speed_veter*K_otk*std::pow( input_VEU_5/input_VEU_6,m);


                    T9.Position.x=i.second_cyrent()*100;

                    if(input_VEU_1<=speed_vetrak && speed_vetrak<=input_VEU_3){
                        float N_VIE=input_VEU_0*(speed_vetrak-input_VEU_1)/(input_VEU_3-input_VEU_1)*1000.0f;
                       if(i.second_cyrent()>0 && std::abs(T9.Position.y-N_VIE)>input_VEU_0/input_VEU_4*1000.0f){
                           if((T9.Position.y-N_VIE)>0){
                              T9.Position.y=T9.Position.y-input_VEU_0/input_VEU_4*1000.0f;
                             }
                           if((T9.Position.y-N_VIE)<0){
                              T9.Position.y=T9.Position.y+input_VEU_0/input_VEU_4*1000.0f;
                             }
                         //  std::cout<<"rrr"<<std::endl;
                      }else{
                       T9.Position.y= N_VIE;
                       }

                    }

                    if(input_VEU_3<=speed_vetrak && speed_vetrak<=input_VEU_2){
                        float N_VIE=input_VEU_0*1000.0f;
                        if(i.second_cyrent()>0 && std::abs(T9.Position.y-N_VIE)>input_VEU_0/input_VEU_4*1000.0f){
                            if((T9.Position.y-N_VIE)>0){
                               T9.Position.y=T9.Position.y-input_VEU_0/input_VEU_4*1000.0f;
                              }
                            if((T9.Position.y-N_VIE)<0){
                               T9.Position.y=T9.Position.y+input_VEU_0/input_VEU_4*1000.0f;
                              }
                           // std::cout<<"ttt"<<std::endl;
                       }else{
                        T9.Position.y= N_VIE;
                        }

                    }

                    if( speed_vetrak>input_VEU_2){
                        float N_VIE=0;
                       if(i.second_cyrent()>0 && std::abs(T9.Position.y-N_VIE)>input_VEU_0/input_VEU_4*1000.0f){
                           if((T9.Position.y-N_VIE)>0){
                              T9.Position.y=T9.Position.y-input_VEU_0/input_VEU_4*1000.0f;
                             }
                           if((T9.Position.y-N_VIE)<0){
                              T9.Position.y=T9.Position.y+input_VEU_0/input_VEU_4*1000.0f;
                             }
                          // std::cout<<"kkk"<<std::endl;
                      }else{
                       T9.Position.y= N_VIE;
                       }
                    }

                    if(!choice[1] && !choice[0]){
                       T9.Position.y=0;
                    }
                    T9.Position.z=0.0f;
                    T9.TexCoords1=std::move(glm::vec2(0.0f, 0.0f));
                    // std::cout<<"|speed_veter:"<<speed_veter<<"|m:"<<m<<"|speed_vetrak:"<<speed_vetrak<<"|T9.Position.y:"<<T9.Position.y<<"|K_otk:"<<K_otk<<"|5v:"<<input[VEU_V][5].date.current_value_nomber<<"|/6v:"<<input[VEU_V][6].date.current_value_nomber<<std::endl;
                    vertices9.push_back(T9);
                    E_VIE+=T9.Position.y/3600.0f;
                    E_VIES.push_back(E_VIE);
                  //  std::cout<<"|T9.Position.y:"<<T9.Position.y<<"|E_VIE:"<<E_VIE<<std::endl;

                    };

                Buffer_VAO VAO____9(vertices9,index9);
                charts[0].graf_new(VAO____9);
                charts_separate[0].graf_new(VAO____9);

                std::vector<Vertex> vertices10;
                Vertex T10(glm::vec3(0.0f,0.0f,0.0f),
                glm::vec3(0.0f,0.0f,0.0f),
                glm::vec2(0.0f,0.0f),
                glm::vec3(0.0f,0.0f,0.0f),
                glm::vec3(0.0f,0.0f,0.0f));
                std::vector<unsigned int> index10;


                std::vector<Vertex> vertices11;
                Vertex T11(glm::vec3(0.0f,0.0f,0.0f),
                glm::vec3(0.0f,0.0f,0.0f),
                glm::vec2(0.0f,0.0f),
                glm::vec3(0.0f,0.0f,0.0f),
                glm::vec3(0.0f,0.0f,0.0f));
                std::vector<unsigned int> index11;

                std::vector<Vertex> vertices12;
                Vertex T12(glm::vec3(0.0f,0.0f,0.0f),
                glm::vec3(0.0f,0.0f,0.0f),
                glm::vec2(0.0f,0.0f),
                glm::vec3(0.0f,0.0f,0.0f),
                glm::vec3(0.0f,0.0f,0.0f));
                std::vector<unsigned int> index12;

                std::vector<Vertex> vertices13;
                Vertex T13(glm::vec3(0.0f,0.0f,0.0f),
                glm::vec3(0.0f,0.0f,0.0f),
                glm::vec2(0.0f,0.0f),
                glm::vec3(0.0f,0.0f,0.0f),
                glm::vec3(0.0f,0.0f,0.0f));
                std::vector<unsigned int> index13;


                std::vector<Vertex> vertices14;
                Vertex T14(glm::vec3(0.0f,0.0f,0.0f),
                glm::vec3(0.0f,0.0f,0.0f),
                glm::vec2(0.0f,0.0f),
                glm::vec3(0.0f,0.0f,0.0f),
                glm::vec3(0.0f,0.0f,0.0f));
                std::vector<unsigned int> index14;

                std::vector<Vertex> vertices15;
                Vertex T15(glm::vec3(0.0f,0.0f,0.0f),
                glm::vec3(0.0f,0.0f,0.0f),
                glm::vec2(0.0f,0.0f),
                glm::vec3(0.0f,0.0f,0.0f),
                glm::vec3(0.0f,0.0f,0.0f));
                std::vector<unsigned int> index15;

                std::vector<Vertex> vertices16;
                Vertex T16(glm::vec3(0.0f,0.0f,0.0f),
                glm::vec3(0.0f,0.0f,0.0f),
                glm::vec2(0.0f,0.0f),
                glm::vec3(0.0f,0.0f,0.0f),
                glm::vec3(0.0f,0.0f,0.0f));
                std::vector<unsigned int> index16;

                Time charding_time;
                Time charding_deferent;
                bool charding_SC=true;
                bool charding_Li_in=true;
                bool charding_VSAE=true;
                i=0;
                int on_DGU=0;
                bool on_off_dgu=false;
                t.month= input[SETTING][7].date.current_value_nomber-1;
                i.month= input[SETTING][7].date.current_value_nomber-1;
                i+=t.second_cyrent();
                for(; i.second_cyrent() <(graf_1.total_time+t.second_cyrent()); i+=1,  charding_time+=1){
                    if( i.hours==0 && i.minutes==0 && i.seconds==0){
                        on_DGU=0;
                       // std::cout<<"|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<std::endl;
                    }

                    float N=(vertices4[i.second_cyrent()].Position.y-vertices3[i.second_cyrent()].Position.y-vertices9[i.second_cyrent()].Position.y);
                    if(N<0 && !charding_SC){
                    charding_time=0;
                    charding_deferent=0;
                    charding_SC=true;
                    charding_Li_in=true;
                    charding_VSAE=true;
                    }
                    if(N>0 && charding_SC){
                    charding_time=0;

                    charding_SC=false;
                    charding_Li_in=false;
                    charding_VSAE=false;
                    }


                    if( charding_time.second_cyrent()<60*5){
                    if(charding_SC){
                    T10.Position.y=N;
                    }
                    if(!charding_SC && E_N_SC>0){
                    T10.Position.y=N*input[SUPERCAPACITOR][0].date.current_value_nomber;
                    }
                    if(!charding_SC && E_N_SC<=0){
                     charding_time=60*5;
                       T10.Position.y=0;
                    }

                    if(!choice[5]){
                        charding_time=60*5;
                        T10.Position.y=0;
                    }

                    T11.Position.y=0.0f;
                    T12.Position.y=0.0f;
                    }

                    if(60*5<= charding_time.second_cyrent() &&  charding_time.second_cyrent()<60*60*3 ){

                    T10.Position.y=0.0f;
                    if(charding_Li_in){
                    T11.Position.y=N;
                    }
                    if( !charding_Li_in && E_N_Li_in >0){
                    T11.Position.y=N*input[BATTERY_PACK][0].date.current_value_nomber;
                    }
                    if(!charding_Li_in && E_N_Li_in<=0){
                     charding_time=60*60*3;
                    }
                    if(!choice[4]){
                        charding_time=60*60*3;
                        T11.Position.y=0;
                    }
                    T12.Position.y=0.0f;


                    }

                    if(charding_time.second_cyrent()>=60*60*3){
                    T10.Position.y=0.0f;
                    T11.Position.y=0.0f;
                    if( charding_VSAE) {
                    T12.Position.y=N;
                    }
                    if(!charding_VSAE && E_N_VSAE >0){
                    T12.Position.y=N*input[GAS][0].date.current_value_nomber;
                    //std::cout<<"{{"<<N<<"}}"<<std::endl;
                    }


                    if(!choice[6]){
                        T12.Position.y=0;
                    }

                    if(!charding_VSAE && E_N_VSAE<=0 ){
                        T10.Position.y=0.0f;
                        T11.Position.y=0.0f;
                        T12.Position.y=0.0f;
                    //     std::cout<<"[[[["<<"|||||||||||"<<"]]]]"<<std::endl;
                    }
                    }






                   //std::cout<<"|time_curent:"<<i.second_cyrent()<<std::endl<<"|charding_time:"<<charding_time.second_cyrent()<<"|charding_VSAE:"<<charding_VSAE<<"|N:"<<N/*<<"|vertices4:"<<vertices4[i.second_cyrent()].Position.y<<"|vertices3:"<<vertices3[i.second_cyrent()].Position.y<<"|vertices9:"<<vertices9[i.second_cyrent()].Position.y*/<<std::endl;

                    T10.Position.x=i.second_cyrent()*100;
                    T10.Position.z=0.0f;
                    T10.TexCoords1=std::move(glm::vec2(0.0f, 0.0f));


                    T11.Position.x=i.second_cyrent()*100;
                    T11.Position.z=0.0f;
                    T11.TexCoords1=std::move(glm::vec2(0.0f, 0.0f));

                    T12.Position.x=i.second_cyrent()*100;
                    T12.Position.z=0.0f;
                    T12.TexCoords1=std::move(glm::vec2(0.0f, 0.0f));




                    float difference_dgu=0.0f;
                    if(0<(vertices4[i.second_cyrent()].Position.y-vertices3[i.second_cyrent()].Position.y-vertices9[i.second_cyrent()].Position.y-(T10.Position.y+T11.Position.y+T12.Position.y))){



                      if(on_off_dgu){
                        on_DGU++;
                      }
                      on_off_dgu=false;

                    float N_DGU=vertices4[i.second_cyrent()].Position.y-vertices3[i.second_cyrent()].Position.y-vertices9[i.second_cyrent()].Position.y-(T10.Position.y+T11.Position.y+T12.Position.y);



                    if( N_DGU<input[DIESEL_GENERATOR][0].date.current_value_nomber*1000.0f){
                        charding_deferent+=1;
                        difference_dgu=input[DIESEL_GENERATOR][0].date.current_value_nomber*1000.0f-T13.Position.y;
                       // std::cout<<"|N_DGU:"<<N_DGU<<"|charding_deferent:"<<charding_deferent.second_cyrent()<<std::endl;
                        N_DGU=input[DIESEL_GENERATOR][0].date.current_value_nomber*1000.0f;
                        if(charding_deferent.second_cyrent()<60*5){
                            T10.Position.y-=difference_dgu;
                            T11.Position.y+=0.0f;
                            T12.Position.y+=0.0f;

                            if(!choice[5]){
                                charding_deferent=60*5;
                                T10.Position.y+=0.0f;
                            }

                        }

                        if(60*5<= charding_deferent.second_cyrent() &&  charding_deferent.second_cyrent()<60*60*3 ){
                            T10.Position.y+=0.0f;
                            T11.Position.y-=difference_dgu;
                            T12.Position.y+=0.0f;

                            if(!choice[4]){
                                charding_deferent=60*60*3;
                                T11.Position.y+=0.0f;
                            }
                        }

                        if(charding_deferent.second_cyrent()>=60*60*3){
                            T10.Position.y+=0.0f;
                            T11.Position.y+=0.0f;
                            T12.Position.y-=difference_dgu;

                            if(!choice[4]){
                                T12.Position.y+=0.0f;
                            }
                            //std::cout<<"[[[["<<difference_dgu<<"]]]]"<<std::endl;
                        }

                    }else{
                       charding_deferent=0;
                    }

                    if(i.second_cyrent()>0 && std::abs(T13.Position.y-N_DGU)>input[DIESEL_GENERATOR][2].date.current_value_nomber*1000.0f){
                        if((T13.Position.y-N_DGU)>0){
                          T13.Position.y=T13.Position.y-input[DIESEL_GENERATOR][2].date.current_value_nomber*1000.0f;
                          if(T13.Position.y<input[DIESEL_GENERATOR][0].date.current_value_nomber*1000.0f){
                              T13.Position.y=input[DIESEL_GENERATOR][0].date.current_value_nomber*1000.0f;

                          }

                          }
//                        if((T13.Position.y-N_DGU)<0){
//                           T13.Position.y=T13.Position.y+input[DIESEL_GENERATOR][2].date.current_value_nomber*1000.0f;
//                          }
                        //std::cout<<"||"<<T13.Position.y<<std::endl;
                    }else{
                       T13.Position.y=N_DGU;
                      // std::cout<<"|[]|"<<T13.Position.y<<std::endl;
                    }
                    }else{
                        T13.Position.y=0;
                        on_off_dgu=true;
                        if(on_DGU>2){
                        T13.Position.y=0.12*input[DIESEL_GENERATOR][1].date.current_value_nomber*1000.0f;
                        }
                    }

                    T13.Position.x=i.second_cyrent()*100;
                    T13.Position.z=0.0f;
                    T13.TexCoords1=std::move(glm::vec2(0.0f, 0.0f));

                    if(!choice[3]){
                        T13.Position.y=0.0f;
                    }

                    E_DGS+=T13.Position.y/3600.0f;

                    E_N_SC+=-T10.Position.y/3600.0f;
                    E_N_Li_in+=-T11.Position.y/3600.0f;
                    E_N_VSAE+=-T12.Position.y/3600.0f;


                    E_N_SCS.push_back(E_N_SC);
                    E_N_Li_inS.push_back(E_N_Li_in);
                    E_N_VSAES.push_back(E_N_VSAE);

                // std::cout<<"|E_N_SC:"<<E_N_SC<<"|E_N_Li_in:"<<E_N_Li_in<<"|E_N_VSAE:"<<E_N_VSAE<<"|N_dgy"<<((vertices4[i.second_cyrent()].Position.y-vertices3[i.second_cyrent()].Position.y-vertices9[i.second_cyrent()].Position.y-(T10.Position.y+T11.Position.y+T12.Position.y)))
                //   <<std::endl;
                    E_DGSS.push_back(E_DGS);
                    vertices13.push_back(T13);

                    vertices10.push_back(T10);
                    vertices11.push_back(T11);
                    vertices12.push_back(T12);


                    T14.Position.y=E_N_SC;
                    T15.Position.y=E_N_Li_in;
                    T16.Position.y=E_N_VSAE;

                    T14.Position.x=i.second_cyrent()*100;
                    T14.Position.z=0.0f;
                    T14.TexCoords1=std::move(glm::vec2(0.0f, 0.0f));

                    T15.Position.x=i.second_cyrent()*100;
                    T15.Position.z=0.0f;
                    T15.TexCoords1=std::move(glm::vec2(0.0f, 0.0f));

                    T16.Position.x=i.second_cyrent()*100;
                    T16.Position.z=0.0f;
                    T16.TexCoords1=std::move(glm::vec2(0.0f, 0.0f));

                    vertices14.push_back(T14);
                    vertices15.push_back(T15);
                    vertices16.push_back(T16);

                }

                Buffer_VAO VAO____10(vertices10,index10);
                charts[5].graf_new(VAO____10);
                charts_separate[5].graf_new(VAO____10);

                Buffer_VAO VAO____11(vertices11,index11);
                charts[3].graf_new(VAO____11);
                charts_separate[3].graf_new(VAO____11);

                Buffer_VAO VAO____12(vertices12,index12);
                charts[4].graf_new(VAO____12);
                charts_separate[4].graf_new(VAO____12);

                Buffer_VAO VAO____13(vertices13,index13);
                charts[2].graf_new(VAO____13);
                charts_separate[2].graf_new(VAO____13);

                Buffer_VAO VAO____14(vertices14,index14);
                charts[9].graf_new(VAO____14);
                charts_separate[9].graf_new(VAO____14);

                Buffer_VAO VAO____15(vertices15,index15);
                charts[10].graf_new(VAO____15);
                charts_separate[10].graf_new(VAO____15);

                Buffer_VAO VAO____16(vertices16,index16);
                charts[11].graf_new(VAO____16);
                charts_separate[11].graf_new(VAO____16);


                glfwMakeContextCurrent(test.window);

                }
                compute=false;
            }else{
                start_button.Draw();
               // compute=true;


            }





        logo_igvie.Draw();
        graf_button.Draw();
        reset_button.Draw();
        setting_model_button.Draw();
        glDepthFunc(GL_LESS);


        //testt.Draw();

        glDepthFunc(GL_LEQUAL);
        view = glm::mat4(glm::mat3(camera.GetViewMatrix()));
        skybox.Draw();
        glDepthFunc(GL_LESS);
        view=camera.GetViewMatrix();
        gros.DraWMateriaL();
        canopy.DraWMateriaL();
        platform.DraW();
        platform_1.DraW();
        platform_2.DraW();
        platform_4.DraW();
       // platform_3.DraW();
        House_1.DraWMylt();
        CCT_object.DraWMylt();
        NTE_object.DraWMylt();

        inerf.Draw();


        glFinish();
        glfwSwapBuffers(test.window);
        for(auto &T:input){
            for(auto&J:T){
               J.string_in_float();
            }
        }


     if(graf_button_clic){
         glfwMakeContextCurrent(test2.window);
         glfwPollEvents();
         test2.new_fraem();
         keys_1[GLFW_MOUSE_BUTTON_MIDDLE]=glfwGetMouseButton(test2.window,GLFW_MOUSE_BUTTON_MIDDLE);
         keys_1[GLFW_MOUSE_BUTTON_LEFT]  =glfwGetMouseButton(test2.window,GLFW_MOUSE_BUTTON_LEFT);
         keys_1[GLFW_MOUSE_BUTTON_RIGHT] =glfwGetMouseButton(test2.window,GLFW_MOUSE_BUTTON_RIGHT);
         glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        // chart_1.unhide();
         if(input_field_graf ||input_field_graf_separate){
             for(auto &T:diapozon_set){
                 T.DrawIndef();
                // std::cout<<"fffffffffffffffffffffffffffffffffff"<<std::endl;
             }
            for(int i=0;i<querty_colors.size();i++){
                ourShader_1_color.use();
                ourShader_1_color.Uniform("new_color",color_chair[i].x,color_chair[i].y,color_chair[i].z);
                querty_colors[i].DrawIndef();
            }
            button_graf_diapozon_ok.DrawIndef();
            button_graf_diapozon_off.DrawIndef();

            input_field_windous_graf.DrawIndef();
          }


         for(int i=0;i<charts.size() && char_job[0];i++){
             if(!charts[i].connect){
                 for(int j=0;j<buttons.size()/charts.size();j++){
                 buttons[i*buttons.size()/charts.size()+j].DrawIndef();
                 }
             }
         }

         for(auto &T:buttons_separate){
             T.DrawIndef();
         }

         for(auto &T:menu_graf){
             T.DrawIndef();
         }







         glFinish();
         //glReadPixels(test.width*(1-0.25)/2,test.height*(1-0.05)/2,1,1,GL_RGB,GL_FLOAT,&pixcel);
         glReadPixels(test2.xpos,test2.height-test2.ypos,1,1,GL_RGB,GL_FLOAT,&pixcel_1);
         int r=static_cast<int>(pixcel_1.r*100+0.5);
         int g=static_cast<int>(pixcel_1.g*100+0.5);
//                std::cout<<"("<<static_cast<int>(pixcel_1.r*100+0.5)<<","
//                          <<static_cast<int>(pixcel_1.g*100+0.5)<<","
//                          <<static_cast<int>(pixcel_1.b*100+0.5)<<")"<<std::endl;

/////////////////////////////////////////////////////////////////////////////////////////////
        glClearColor(1.0f, 1.0f, 1.0f, 0.5f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);




         time_curent_model_graf.Print(std::to_string(time_curent.hours)+"h:"+std::to_string(time_curent.minutes)+"m:"+std::to_string(time_curent.seconds)+"c");
         time_curent_model_graf_yuers.Print(std::to_string(time_curent.year)+"."+std::to_string(time_curent.month+1)+"."+std::to_string(time_curent.day+1)+"day");

         V_graf[0].Print("|Э:"+std::to_string(static_cast<int>(E_VIES[time_curent.second_cyrent()]*0.001f))+"."+std::to_string(std::abs(static_cast<int>(E_VIES[time_curent.second_cyrent()]-static_cast<int>(E_VIES[time_curent.second_cyrent()]*0.001f)*1000))));
         V_graf[0].color_text=charts[0].setting.color;
         V_graf[1].Print("|Э:"+std::to_string(static_cast<int>(E_PMTS[time_curent.second_cyrent()]*0.001f))+"."+std::to_string(std::abs(static_cast<int>(E_PMTS[time_curent.second_cyrent()]-static_cast<int>(E_PMTS[time_curent.second_cyrent()]*0.001f)*1000))));
         V_graf[1].color_text=charts[1].setting.color;
         V_graf[2].Print("|Э:"+std::to_string(static_cast<int>(E_DGSS[time_curent.second_cyrent()]*0.001f))+"."+std::to_string(std::abs(static_cast<int>(E_DGSS[time_curent.second_cyrent()]-static_cast<int>(E_DGSS[time_curent.second_cyrent()]*0.001f)*1000))));
         V_graf[2].color_text=charts[2].setting.color;

         V_graf[5].Print("|Э:"+std::to_string(static_cast<int>(E_N_SCS[time_curent.second_cyrent()]*0.001f))+"."+std::to_string(std::abs(static_cast<int>(E_N_SCS[time_curent.second_cyrent()]-static_cast<int>(E_N_SCS[time_curent.second_cyrent()]*0.001f)*1000))));
         V_graf[5].color_text=charts[5].setting.color;
         V_graf[3].Print("|Э:"+std::to_string(static_cast<int>(E_N_Li_inS[time_curent.second_cyrent()]*0.001f))+"."+std::to_string(std::abs(static_cast<int>(E_N_Li_inS[time_curent.second_cyrent()]-static_cast<int>(E_N_Li_inS[time_curent.second_cyrent()]*0.001f)*1000))));
         V_graf[3].color_text=charts[3].setting.color;
         V_graf[4].Print("|Э:"+std::to_string(static_cast<int>(E_N_VSAES[time_curent.second_cyrent()]*0.001f))+"."+std::to_string(std::abs(static_cast<int>(E_N_VSAES[time_curent.second_cyrent()]-static_cast<int>(E_N_VSAES[time_curent.second_cyrent()]*0.001f)*1000))));
         V_graf[4].color_text=charts[4].setting.color;

         V_graf[6].Print("|Э:"+std::to_string(static_cast<int>(E_ССTS[time_curent.second_cyrent()]*0.001f))+"."+std::to_string(std::abs(static_cast<int>(E_ССTS[time_curent.second_cyrent()]-static_cast<int>(E_ССTS[time_curent.second_cyrent()]*0.001f)*1000))));
         V_graf[6].color_text=charts[6].setting.color;
         V_graf[7].Print("|Э:"+std::to_string(static_cast<int>(E_N_NTES[time_curent.second_cyrent()]*0.001f))+"."+std::to_string(std::abs(static_cast<int>(E_N_NTES[time_curent.second_cyrent()]-static_cast<int>(E_N_NTES[time_curent.second_cyrent()]*0.001f)*1000))));
         V_graf[7].color_text=charts[7].setting.color;

         V_graf[8].Print("|Э:"+std::to_string(static_cast<int>(E_P_PEES[time_curent.second_cyrent()]*0.001f))+"."+std::to_string(std::abs(static_cast<int>(E_P_PEES[time_curent.second_cyrent()]-static_cast<int>(E_P_PEES[time_curent.second_cyrent()]*0.001f)*1000))));
         V_graf[8].color_text=charts[8].setting.color;
         V_graf[9].Print("|Э:"+std::to_string(static_cast<int>(E_P_PTES[time_curent.second_cyrent()]*0.001f))+"."+std::to_string(std::abs(static_cast<int>(E_P_PTES[time_curent.second_cyrent()]-static_cast<int>(E_P_PTES[time_curent.second_cyrent()]*0.001f)*1000))));
         V_graf[9].color_text=charts[9].setting.color;

         name_menu_graf[2].Print("Все объекты");
         for(int i=2;i<12;i++){
         name_menu_graf[i].Print(charts[i-2].name);
         }
         name_menu_graf[12].Print(charts[13].name);

         for(auto &T:menu_graf){
             T.Draw();
         }
        if(keys_1[GLFW_MOUSE_BUTTON_LEFT] && !timer){
            timer=0;
            for(int i=2;i<12;i++){
                 if(static_cast<int>(menu_graf[i].id.r*100+0.5)==r &&
                    static_cast<int>(menu_graf[i].id.g*100+0.5)==g  ){
                     for(auto & T:char_job){
                         T=false;
                     }
                     char_job[i-2]=true;
                     current_char=i-3;
                     std::cout<<"{"<<i<<"}"<<current_char<<static_cast<int>(menu_graf[i].id.r*100)<<"***###########################################################"<<std::endl;

                 }
             }
        }

        if(!char_job[0]){
        charts_separate[current_char].Set_time(time_curent.second_cyrent());

        float x_dimension_separate=1.0f;
        float y_dimension_separate=1.0f;

        int tttt_x_separate=std::abs(static_cast<int>(charts_separate[current_char].setting.visible_scale_length_x/(5*100)*5)-static_cast<int>((charts_separate[current_char].setting.visible_scale_length_x/(100))*charts_separate[current_char].setting.move.x/2.0f));
        int tttt_y_separate=std::abs(static_cast<int>(charts_separate[current_char].setting.visible_scale_length_y/(5)*5)-static_cast<int>((charts_separate[current_char].setting.visible_scale_length_y/1.0f)*charts_separate[current_char].setting.move.y/2.0f));

        tttt_x_separate=tttt_x_separate/23;
        tttt_y_separate=tttt_y_separate/22;

        if(60*60*24*365<tttt_x_separate){
            dimension_x_separate.Print("год");
            x_dimension_separate=1.0f/(60.0f*60.0f*24.0f*365.0f);
        }else if(60*60*24<tttt_x_separate){
           dimension_x_separate.Print("д.");
            x_dimension_separate=1.0f/(60.0f*60.0f*24.0f);
        }else if(60*60<tttt_x_separate){
            dimension_x_separate.Print("ч");
            x_dimension_separate=1.0f/(60.0f*60.0f);
        }else if(60<tttt_x_separate){
            dimension_x_separate.Print("м");
            x_dimension_separate=1.0f/(60.0f);
        }else{
            x_dimension_separate=1.0f;
           dimension_x_separate.Print("c");
       }

        if(false){
            if(1000000<tttt_y_separate){
              dimension_y_separate.Print("МВт*ч");
                y_dimension_separate=1.0f/1000000.0f;
            }else if(1000<tttt_y_separate){
             dimension_y_separate.Print("кВт*ч");
               y_dimension_separate=1.0f/1000.0f;
           }else{
               y_dimension_separate=1.0f;
               dimension_y_separate.Print("Вт*ч");
           }
        }else{
            if(1000000<tttt_y_separate){
              dimension_y_separate.Print("МВт");
                y_dimension_separate=1.0f/1000000.0f;
            }else if(1000<tttt_y_separate){
             dimension_y_separate.Print("кВт");
               y_dimension_separate=1.0f/1000.0f;
           }else{
               y_dimension_separate=1.0f;
               dimension_y_separate.Print("Вт");
           }
       }

        dimension_x_separate.color_text=glm::vec3{0.3f,0.3f,1.0f};
        dimension_y_separate.color_text=glm::vec3{0.3f,0.3f,1.0f};


        for(int j=0;j<lines_x_separate.size();j++){
        //text_division_x[j+i*6].Print(std::to_string((charts[i].setting.visible_scale_length_x/(5*100)*j)-static_cast<int>((charts[i].setting.visible_scale_length_x/(100))*charts[i].setting.move.x/2.0f)));
        lines_x_separate[j].unhide();

        text_division_x_separate[j].Print(std::to_string(static_cast<int>(x_dimension_separate*((charts_separate[current_char].setting.visible_scale_length_x/static_cast<int>(lines_x_separate.size()*100)*j)-static_cast<int>((charts_separate[current_char].setting.visible_scale_length_x/(100.0f))*charts_separate[current_char].setting.move.x/2.0f)))));
        }

        for(int j=lines_y_separate.size()-1;j>0;j--){
        //text_division_y[j+i*6].Print(std::to_string((charts[i].setting.visible_scale_length_y/(5)*k)-static_cast<int>((charts[i].setting.visible_scale_length_y/1.0f)*charts[i].setting.move.y/2.0f)));
        lines_y_separate[j].unhide();
        text_division_y_separate[j].Print(std::to_string(static_cast<int>(y_dimension_separate*((charts_separate[current_char].setting.visible_scale_length_y/static_cast<int>(lines_y_separate.size())*(static_cast<int>(lines_y_separate.size())-1-j))-static_cast<int>((charts_separate[current_char].setting.visible_scale_length_y/(1.0f))*charts_separate[current_char].setting.move.y/2.0f)))));
        //text_division[j+i*6].color_text=glm::vec3{0.0f,0.0f,0.0f};
        //std::cout<<"|__"<<j<<"__|"<<static_cast<int>(charts_separate[current_char].setting.visible_scale_length_y/(lines_y_separate.size())*(lines_y_separate.size()-1-j))-static_cast<int>((charts_separate[current_char].setting.visible_scale_length_y/(1.0f))*charts_separate[current_char].setting.move.y/2.0f)<<std::endl;

        }

        for(auto &T:buttons_separate){
            T.Draw();
        }

        text_name_graf_separate.Print(charts_separate[current_char+1].name);
      //  glDepthFunc(GL_ALWAYS);
        charts_separate[current_char].unhide();
      //  glDepthFunc(GL_LESS);
if(keys_1[GLFW_MOUSE_BUTTON_LEFT] && !timer){
    timer=0;
        ////////////////////////////////arrow lift and right
        if(static_cast<int>(buttons_separate[0].id.r*100)==r &&
           static_cast<int>(buttons_separate[0].id.g*100)==g  ){
         charts_separate[current_char].setting.move.x-=0.02f;
        }
        if(static_cast<int>(buttons_separate[1].id.r*100)==r &&
           static_cast<int>(buttons_separate[1].id.g*100)==g  ){
        charts_separate[current_char].setting.move.x+=0.02f;
        }
        ////////////////////////////////arrow up and down
        if(static_cast<int>(buttons_separate[2].id.r*100)==r &&
           static_cast<int>(buttons_separate[2].id.g*100)==g  ){
        charts_separate[current_char].setting.move.y+=0.02f;
        }
        if(static_cast<int>(buttons_separate[3].id.r*100)==r &&
           static_cast<int>(buttons_separate[3].id.g*100)==g  ){
        charts_separate[current_char].setting.move.y-=0.02f;
        }

        ///////////////////////plus,plus_x and plus_y
        if(static_cast<int>(buttons_separate[4].id.r*100)==r &&
           static_cast<int>(buttons_separate[4].id.g*100)==g  ){
        charts_separate[current_char].setting.visible_scale_length_y=charts_separate[current_char].setting.visible_scale_length_y*0.9f;
        charts_separate[current_char].setting.visible_scale_length_x=charts_separate[current_char].setting.visible_scale_length_x*0.9f;
        }
        if(static_cast<int>(buttons_separate[5].id.r*100)==r &&
           static_cast<int>(buttons_separate[5].id.g*100)==g  ){
        charts_separate[current_char].setting.visible_scale_length_x=charts_separate[current_char].setting.visible_scale_length_x*0.9f;
        }
        if(static_cast<int>(buttons_separate[6].id.r*100)==r &&
           static_cast<int>(buttons_separate[6].id.g*100)==g  ){
        charts_separate[current_char].setting.visible_scale_length_y=charts_separate[current_char].setting.visible_scale_length_y*0.9f;
        }
        ///////////////////////////////////////////////////minus,minus_x and minus_y
        if(static_cast<int>(buttons_separate[7].id.r*100)==r &&
           static_cast<int>(buttons_separate[7].id.g*100)==g  ){
        charts_separate[current_char].setting.visible_scale_length_y=charts_separate[current_char].setting.visible_scale_length_y*1.1f;
        charts_separate[current_char].setting.visible_scale_length_x=charts_separate[current_char].setting.visible_scale_length_x*1.1f;

        }
        if(static_cast<int>(buttons_separate[8].id.r*100)==r &&
           static_cast<int>(buttons_separate[8].id.g*100)==g  ){
        charts_separate[current_char].setting.visible_scale_length_x=charts_separate[current_char].setting.visible_scale_length_x*1.1f;
        }
        if(static_cast<int>(buttons_separate[9].id.r*100)==r &&
           static_cast<int>(buttons_separate[9].id.g*100)==g  ){
        charts_separate[current_char].setting.visible_scale_length_y=charts_separate[current_char].setting.visible_scale_length_y*1.1f;
        }
        if(static_cast<int>(buttons_separate[10].id.r*100)==r &&
           static_cast<int>(buttons_separate[10].id.g*100)==g  ){
           input_field_graf_separate=true;
           nomer_graf=current_char;
        }
}
//  std::cout<<"<<<<0>>>>"<<std::endl;
glDepthFunc(GL_ALWAYS);
        if(input_field_graf_separate){

           input_field_windous_graf.Draw();

           for(int i=0;i<4;i++){
               if(input_diapozon_separate[nomer_graf].at(i).date.current_value_nomber==-999999){
                   input_diapozon_separate[nomer_graf].at(i).date.current_value_symbol="      0";
               }
           }

           for(int i=0;i<querty_colors.size();i++){
               ourShader_1_color.use();
               ourShader_1_color.Uniform("new_color",color_chair[i].x,color_chair[i].y,color_chair[i].z);
               querty_colors[i].Draw();
               if(cross_active_separate[nomer_graf][i]){
                 querty_colors_cross[i].Draw();
               }
               if(keys_1[GLFW_MOUSE_BUTTON_LEFT] && !timer){
                   if(static_cast<int>(querty_colors[i].id.r*100)==r && static_cast<int>(querty_colors[i].id.g*100)==g){
                       timer=5;
                       for(auto &T:cross_active_separate[nomer_graf]){
                           T=false;
                       }
                       cross_active_separate[nomer_graf][i]=true;
                       charts_separate[nomer_graf].setting.color=color_chair[i];
                       std::cout<<"___________"<<std::endl;
                   }
                 }
               }

                if(keys_1[GLFW_MOUSE_BUTTON_LEFT] && !timer){
                   if((static_cast<int>(button_graf_diapozon_off.id.r*100)==r && static_cast<int>(button_graf_diapozon_off.id.g*100)==g)){
                       input_field_graf_separate=false;
                   }
                   if((static_cast<int>(button_graf_diapozon_ok.id.r*100)==r && static_cast<int>(button_graf_diapozon_ok.id.g*100)==g)){
                    for(auto &T:input_diapozon_separate[nomer_graf]){
                        T.string_in_float();
                        T.active=false;
                        T.string_in_float();
                        T.imput.clear();
                    }
                     charts_separate[nomer_graf].setting.visible_scale_length_x=100.0f*std::abs(input_diapozon_separate[nomer_graf][1].date.current_value_nomber-input_diapozon_separate[nomer_graf][0].date.current_value_nomber);
                     charts_separate[nomer_graf].setting.move.x=-input_diapozon_separate[nomer_graf][0].date.current_value_nomber/static_cast<int>((charts_separate[nomer_graf].setting.visible_scale_length_x/100.0f)/2.0f);
                     charts_separate[nomer_graf].setting.visible_scale_length_y=std::abs(input_diapozon_separate[nomer_graf][3].date.current_value_nomber-input_diapozon_separate[nomer_graf][2].date.current_value_nomber);
                     charts_separate[nomer_graf].setting.move.y=-input_diapozon_separate[nomer_graf][2].date.current_value_nomber/static_cast<int>((charts_separate[nomer_graf].setting.visible_scale_length_y/1.0f)/2.0f);
                     input_field_graf_separate=false;
                     std::cout<<"&&&&&&&&&&&&&&^^^^^^^^^^^^^&&&&&&&&&&&&&&&&&&"<<std::endl;
                     std::cout<<charts_separate[nomer_graf].setting.visible_scale_length_x<<std::endl;
//                     std::cout<<charts[nomer_graf].setting.move.x<<"|"<<charts[nomer_graf].setting.move.y<<std::endl;
//                     for(auto &T:input_diapozon[nomer_graf]){
//                         T.active=false;
//                     }

                   }

               }




           header_input_field_windous_graf.Print("График:"+charts_separate[nomer_graf+1].name);
           for(int i=0;i<diapozon_set.size();i++){
               diapozon_set[i].Draw();
               input_diapozon_separate[nomer_graf][i].new_fraem(r,g);
               if(input_diapozon_separate[nomer_graf][i].active){
                  // std::cout<<input_diapozon[nomer_graf][0].imput<<std::endl;
               }
           }


           std::string diapozon_x="Диапозон X ";
           diapozon_x.push_back(static_cast<char>(186));
           diapozon_x+="[["+input_diapozon_separate[nomer_graf][0].date.current_value_symbol+" ; "+input_diapozon_separate[nomer_graf][1].date.current_value_symbol+"]";
           std::string diapozon_y="Диапозон Y ";
           diapozon_y.push_back(static_cast<char>(186));
           diapozon_y+="[["+input_diapozon_separate[nomer_graf][2].date.current_value_symbol+" ; "+input_diapozon_separate[nomer_graf][3].date.current_value_symbol+"]";
          // std::cout<<static_cast<int>(diapozon_x[0])<<"|"<<static_cast<int>(diapozon_x[1])<<std::endl;

           diapozon_x_installation.Print(diapozon_x);
           diapozon_y_installation.Print(diapozon_y);

           button_graf_diapozon_ok.Draw();
           button_graf_diapozon_off.Draw();

           button_graf_diapozon_ok_text.Print("Принять");
           button_graf_diapozon_off_text.Print("Отмена");

        }else {
             for(int i=0;i<16;i++){
              input_diapozon_separate[i].at(0).date.current_value_symbol=std::to_string((charts_separate[i].setting.visible_scale_length_x/(5*100)*0)-static_cast<int>((charts_separate[i].setting.visible_scale_length_x/(100))*charts_separate[i].setting.move.x/2.0f));
              input_diapozon_separate[i].at(1).date.current_value_symbol=std::to_string((charts_separate[i].setting.visible_scale_length_x/(5*100)*5)-static_cast<int>((charts_separate[i].setting.visible_scale_length_x/(100))*charts_separate[i].setting.move.x/2.0f));
              input_diapozon_separate[i].at(2).date.current_value_symbol=std::to_string((charts_separate[i].setting.visible_scale_length_y/(5)*0)-static_cast<int>((charts_separate[i].setting.visible_scale_length_y/1.0f)*charts_separate[i].setting.move.y/2.0f));
              input_diapozon_separate[i].at(3).date.current_value_symbol=std::to_string((charts_separate[i].setting.visible_scale_length_y/(5)*5)-static_cast<int>((charts_separate[i].setting.visible_scale_length_y/1.0f)*charts_separate[i].setting.move.y/2.0f));
             }

        }
glDepthFunc(GL_LESS);
        }



        // std::cout<<"$$$$$$$"<<test2.deltaTime<<"|"<<h<<std::endl;
         for(int i=0;i<(charts.size()-3) && char_job[0];i++){
         charts[i].Set_time(time_curent.second_cyrent());
         charts_separate[i].Set_time(time_curent.second_cyrent());

            if(!charts[i].connect){
       for(volatile int j=0;j<4;j++){
            ourShader_1_color.use();
            ourShader_1_color.Uniform("new_color",charts[i].color_arraws.x*1.5f,charts[i].color_arraws.y*1.5f,charts[i].color_arraws.z*1.5f);
            buttons[i*buttons.size()/charts.size()+j].Draw();
         }
            for(int j=4;j<buttons.size()/charts.size();j++){
            buttons[i*buttons.size()/charts.size()+j].Draw();
         }
        }


         if(keys_1[GLFW_MOUSE_BUTTON_LEFT] && !timer){
             timer=0;
                std::cout<<timer<<"{uuuuuuuuuuuuuuuuuuuuuuuuuuuuuuu}"<<std::endl;
         if(!charts[i].mode_overlay){
             ////////////////////////////////arrow lift and right
             if(static_cast<int>(buttons[0+buttons.size()/charts.size()*i].id.r*100)==r &&
                static_cast<int>(buttons[0+buttons.size()/charts.size()*i].id.g*100)==g  ){
              charts[i].setting.move.x-=0.02f;
             }
             if(static_cast<int>(buttons[1+buttons.size()/charts.size()*i].id.r*100)==r &&
                static_cast<int>(buttons[1+buttons.size()/charts.size()*i].id.g*100)==g  ){
              charts[i].setting.move.x+=0.02f;
             }
             ////////////////////////////////arrow up and down
             if(static_cast<int>(buttons[2+buttons.size()/charts.size()*i].id.r*100)==r &&
                static_cast<int>(buttons[2+buttons.size()/charts.size()*i].id.g*100)==g  ){
                charts[i].setting.move.y+=0.02f;
             }
             if(static_cast<int>(buttons[3+buttons.size()/charts.size()*i].id.r*100)==r &&
                static_cast<int>(buttons[3+buttons.size()/charts.size()*i].id.g*100)==g  ){
                charts[i].setting.move.y-=0.02f;
             }
         }else{
             ////////////////////////////////arrow lift and right
             if(static_cast<int>(buttons[0+buttons.size()/charts.size()*i].id.r*100)==r &&
                static_cast<int>(buttons[0+buttons.size()/charts.size()*i].id.g*100)==g &&
                 charts[i].grid_x!=0 ){

                 for(int j=0;j<buttons.size()/charts.size();j++){
                   buttons[i*buttons.size()/charts.size()+j].position.move(-glm::vec3(0.434,0.0f,0.0f));
                    }
                 text_name_graf[i].position.move(-glm::vec3(0.434,0.0f,0.0f));
                 for(int j=0,k=5;j<6 && k>-1;j++,k--){
                 text_division_x[j+i*6].position.move(-glm::vec3(0.434,0.0f,0.0f));
                 lines_x[j+i*6].position.move(-glm::vec3(0.434,0.0f,0.0f));
                 text_division_y[j+i*6].position.move(-glm::vec3(0.434,0.0f,0.0f));
                 lines_y[j+i*6].position.move(-glm::vec3(0.434,0.0f,0.0f));
                 }
                 //background[i].position.move(glm::vec3(0.434,0.0f,0.0f));
                 charts[i].position.move(-glm::vec3(0.434,0.0f,0.0f));
                 dimension_x[i].position.move(-glm::vec3(0.434,0.0f,0.0f));
                 dimension_x[i].position.move(-glm::vec3(0.434,0.0f,0.0f));
               //dimension_x[i].
                 dimension_y[i].position.move(-glm::vec3(0.434,0.0f,0.0f));
                 dimension_y[i].position.move(-glm::vec3(0.434,0.0f,0.0f));
               //dimension_y[i].
                 if( charts[charts[i].grid_y*4+charts[i].grid_x].chart_pointre.size()){
                 charts[charts[i].grid_y*4+charts[i].grid_x].disconnect_chart(&charts[i]);
                 }

                 charts[i].grid_x=charts[i].grid_x-1;
                if(charts[charts[i].grid_y*4+charts[i].grid_x].grid_x==charts[i].grid_x &&
                  charts[charts[i].grid_y*4+charts[i].grid_x].grid_y==charts[i].grid_y){
                std::cout<<i<<"lllllllllllllllllllllllllllllllll"<<charts[i].grid_y*4+charts[i].grid_x<<std::endl;

       /*правое*/         charts[charts[i].grid_y*4+charts[i].grid_x].connect_chart(&charts[i]);/*левое*/

                }else{
                std::cout<<i<<"{llllllllllllllllllllllllllllllll}"<<std::endl;
                }
//                charts[i].visible_scale_length_x=charts[i+1].visible_scale_length_x;
//                charts[i].visible_scale_length_y=charts[i+1].visible_scale_length_y;
             }
             if(static_cast<int>(buttons[1+buttons.size()/charts.size()*i].id.r*100)==r &&
                static_cast<int>(buttons[1+buttons.size()/charts.size()*i].id.g*100)==g &&
                charts[i].grid_x!=3  ){

                  for(int j=0;j<buttons.size()/charts.size();j++){
                    buttons[i*buttons.size()/charts.size()+j].position.move(glm::vec3(0.434,0.0f,0.0f));
                     }
                  text_name_graf[i].position.move(glm::vec3(0.434,0.0f,0.0f));
                  for(int j=0,k=5;j<6 && k>-1;j++,k--){
                  text_division_x[j+i*6].position.move(glm::vec3(0.434,0.0f,0.0f));
                  lines_x[j+i*6].position.move(glm::vec3(0.434,0.0f,0.0f));
                  text_division_y[j+i*6].position.move(glm::vec3(0.434,0.0f,0.0f));
                  lines_y[j+i*6].position.move(glm::vec3(0.434,0.0f,0.0f));
                  }
                  //background[i].position.move(glm::vec3(0.434,0.0f,0.0f));
                  charts[i].position.move(glm::vec3(0.434,0.0f,0.0f));
                  dimension_x[i].position.move(glm::vec3(0.434,0.0f,0.0f));
                  dimension_x[i].position.move(glm::vec3(0.434,0.0f,0.0f));
                //dimension_x[i].
                  dimension_y[i].position.move(glm::vec3(0.434,0.0f,0.0f));
                  dimension_y[i].position.move(glm::vec3(0.434,0.0f,0.0f));
                //dimension_y[i].

                  if( charts[charts[i].grid_y*4+charts[i].grid_x].chart_pointre.size()){
                  charts[charts[i].grid_y*4+charts[i].grid_x].disconnect_chart(&charts[i]);
                  }

                  charts[i].grid_x=charts[i].grid_x+1;

                 if(charts[charts[i].grid_y*4+charts[i].grid_x].grid_x==charts[i].grid_x &&
                   charts[charts[i].grid_y*4+charts[i].grid_x].grid_y==charts[i].grid_y){
                 std::cout<<i<<"rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr"<<charts[i].grid_y*4+charts[i].grid_x<<std::endl;
              charts[charts[i].grid_y*4+charts[i].grid_x].connect_chart(&charts[i]);
                 }else{
                 std::cout<<i<<"{rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr}"<<std::endl;
                 }
//                charts[i].visible_scale_length_x=charts[i+1].visible_scale_length_x;
//                charts[i].visible_scale_length_y=charts[i+1].visible_scale_length_y;

             }

             ////////////////////////////////arrow up and down
             if(static_cast<int>(buttons[2+buttons.size()/charts.size()*i].id.r*100)==r &&
                static_cast<int>(buttons[2+buttons.size()/charts.size()*i].id.g*100)==g &&
                 charts[i].grid_y!=0 ){

                 for(int j=0;j<buttons.size()/charts.size();j++){
                   buttons[i*buttons.size()/charts.size()+j].position.move(glm::vec3(0.0,0.666f,0.0f));
                    }
                 text_name_graf[i].position.move(glm::vec3(0.0,0.666f,0.0f));
                 for(int j=0,k=5;j<6 && k>-1;j++,k--){
                 text_division_x[j+i*6].position.move(glm::vec3(0.0,0.666f,0.0f));
                 lines_x[j+i*6].position.move(glm::vec3(0.0,0.666f,0.0f));
                 text_division_y[j+i*6].position.move(glm::vec3(0.0,0.666f,0.0f));
                 lines_y[j+i*6].position.move(glm::vec3(0.0,0.666f,0.0f));
                 }
                 //background[i].position.move(glm::vec3(0.434,0.0f,0.0f));
                 charts[i].position.move(glm::vec3(0.0,0.666f,0.0f));
                 dimension_x[i].position.move(glm::vec3(0.0,0.666f,0.0f));
                 dimension_x[i].position.move(glm::vec3(0.0,0.666f,0.0f));
               //dimension_x[i].
                 dimension_y[i].position.move(glm::vec3(0.0,0.666f,0.0f));
                 dimension_y[i].position.move(glm::vec3(0.0,0.666f,0.0f));
               //dimension_y[i].
                 if( charts[charts[i].grid_y*4+charts[i].grid_x].chart_pointre.size()){
                 charts[charts[i].grid_y*4+charts[i].grid_x].disconnect_chart(&charts[i]);
                 }

                 charts[i].grid_y=charts[i].grid_y-1;
                if(charts[charts[i].grid_y*4+charts[i].grid_x].grid_x==charts[i].grid_x &&
                  charts[charts[i].grid_y*4+charts[i].grid_x].grid_y==charts[i].grid_y){
                std::cout<<i<<"uuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuu"<<std::endl;
                 charts[charts[i].grid_y*4+charts[i].grid_x].connect_chart(&charts[i]);
                }else{
                std::cout<<i<<"{uuuuuuuuuuuuuuuuuuuuuuuuuuuuuuu}"<<std::endl;
                }
             }
             if(static_cast<int>(buttons[3+buttons.size()/charts.size()*i].id.r*100)==r &&
                static_cast<int>(buttons[3+buttons.size()/charts.size()*i].id.g*100)==g &&
                charts[i].grid_y!=2  ){

                  for(int j=0;j<buttons.size()/charts.size();j++){
                    buttons[i*buttons.size()/charts.size()+j].position.move(-glm::vec3(0.0,0.666f,0.0f));
                     }
                  text_name_graf[i].position.move(-glm::vec3(0.0,0.666f,0.0f));
                  for(int j=0,k=5;j<6 && k>-1;j++,k--){
                  text_division_x[j+i*6].position.move(-glm::vec3(0.0,0.666f,0.0f));
                  lines_x[j+i*6].position.move(-glm::vec3(0.0,0.666f,0.0f));
                  text_division_y[j+i*6].position.move(-glm::vec3(0.0,0.666f,0.0f));
                  lines_y[j+i*6].position.move(-glm::vec3(0.0,0.666f,0.0f));
                  }
                  //background[i].position.move(glm::vec3(0.434,0.0f,0.0f));
                  charts[i].position.move(-glm::vec3(0.0,0.666f,0.0f));
                  dimension_x[i].position.move(-glm::vec3(0.0,0.666f,0.0f));
                  dimension_x[i].position.move(-glm::vec3(0.0,0.666f,0.0f));
                //dimension_x[i].
                  dimension_y[i].position.move(-glm::vec3(0.0,0.666f,0.0f));
                  dimension_y[i].position.move(-glm::vec3(0.0,0.666f,0.0f));
                //dimension_y[i].
                  if( charts[charts[i].grid_y*4+charts[i].grid_x].chart_pointre.size()){
                  charts[charts[i].grid_y*4+charts[i].grid_x].disconnect_chart(&charts[i]);
                  }

                  charts[i].grid_y=charts[i].grid_y+1;
                 if(charts[charts[i].grid_y*4+charts[i].grid_x].grid_x==charts[i].grid_x &&
                   charts[charts[i].grid_y*4+charts[i].grid_x].grid_y==charts[i].grid_y){
                 std::cout<<i<<"rddddddddddddddddddddddddd"<<std::endl;
                  charts[charts[i].grid_y*4+charts[i].grid_x].connect_chart(&charts[i]);
                 }else{
                 std::cout<<i<<"{dddddddddddddddddddddddd}"<<std::endl;
                 }

             }
         }
         ///////////////////////plus,plus_x and plus_y
         if(static_cast<int>(buttons[4+buttons.size()/charts.size()*i].id.r*100)==r &&
            static_cast<int>(buttons[4+buttons.size()/charts.size()*i].id.g*100)==g  ){
            charts[i].setting.visible_scale_length_y=charts[i].setting.visible_scale_length_y*0.9f;
            charts[i].setting.visible_scale_length_x=charts[i].setting.visible_scale_length_x*0.9f;
         }
         if(static_cast<int>(buttons[5+buttons.size()/charts.size()*i].id.r*100)==r &&
            static_cast<int>(buttons[5+buttons.size()/charts.size()*i].id.g*100)==g  ){
            charts[i].setting.visible_scale_length_x=charts[i].setting.visible_scale_length_x*0.9f;
         }
         if(static_cast<int>(buttons[6+buttons.size()/charts.size()*i].id.r*100)==r &&
            static_cast<int>(buttons[6+buttons.size()/charts.size()*i].id.g*100)==g  ){
             charts[i].setting.visible_scale_length_y=charts[i].setting.visible_scale_length_y*0.9f;
         }
         ///////////////////////////////////////////////////minus,minus_x and minus_y
         if(static_cast<int>(buttons[7+buttons.size()/charts.size()*i].id.r*100)==r &&
            static_cast<int>(buttons[7+buttons.size()/charts.size()*i].id.g*100)==g  ){
            charts[i].setting.visible_scale_length_y=charts[i].setting.visible_scale_length_y*1.1f;
            charts[i].setting.visible_scale_length_x=charts[i].setting.visible_scale_length_x*1.1f;

         }
         if(static_cast<int>(buttons[8+buttons.size()/charts.size()*i].id.r*100)==r &&
            static_cast<int>(buttons[8+buttons.size()/charts.size()*i].id.g*100)==g  ){
            charts[i].setting.visible_scale_length_x=charts[i].setting.visible_scale_length_x*1.1f;
         }
         if(static_cast<int>(buttons[9+buttons.size()/charts.size()*i].id.r*100)==r &&
           static_cast<int>(buttons[9+buttons.size()/charts.size()*i].id.g*100)==g  ){
           charts[i].setting.visible_scale_length_y=charts[i].setting.visible_scale_length_y*1.1f;
         }
         if(static_cast<int>(buttons[10+buttons.size()/charts.size()*i].id.r*100)==r &&
           static_cast<int>(buttons[10+buttons.size()/charts.size()*i].id.g*100)==g  ){
            input_field_graf=true;
            nomer_graf=i;
         }
         if(static_cast<int>(buttons[11+buttons.size()/charts.size()*i].id.r*100)==r &&
           static_cast<int>(buttons[11+buttons.size()/charts.size()*i].id.g*100)==g  ){
             timer=10;
           if(charts[i].mode_overlay){
               charts[i].mode_overlay=false;
               charts[i].color_arraws=glm::vec3{1.0f,1.0f,1.0f};
           }else{
               charts[i].mode_overlay=true;
                charts[i].color_arraws=charts[i].setting.color;
           }

         }

     }

         if(charts[i].connect!=1){

         text_name_graf[i].Print(charts[i+1].name);
         }

         float x_dimension=1.0f;
         float y_dimension=1.0f;

         int tttt_x=std::abs(static_cast<int>(charts[i].setting.visible_scale_length_x/(5*100)*5)-static_cast<int>((charts[i].setting.visible_scale_length_x/(100))*charts[i].setting.move.x/2.0f));
         int tttt_y=std::abs(static_cast<int>(charts[i].setting.visible_scale_length_y/(5)*5)-static_cast<int>((charts[i].setting.visible_scale_length_y/1.0f)*charts[i].setting.move.y/2.0f));

         tttt_x=tttt_x/5;
         tttt_y=tttt_y/5;

         if(60*60*24*365<tttt_x){
             dimension_x[i].Print("год");
             x_dimension=1.0f/(60.0f*60.0f*24.0f*365.0f);
         }else if(60*60*24<tttt_x){
             dimension_x[i].Print("д.");
             x_dimension=1.0f/(60.0f*60.0f*24.0f);
         }else if(60*60<tttt_x){
             dimension_x[i].Print("ч");
             x_dimension=1.0f/(60.0f*60.0f);
         }else if(60<tttt_x){
             dimension_x[i].Print("м");
             x_dimension=1.0f/(60.0f);
         }else{
             x_dimension=1.0f;
             dimension_x[i].Print("c");
        }

         if(9<=i && i<=12){
             if(1000000<tttt_y){
               dimension_y[i].Print("МВт*ч");
                 y_dimension=1.0f/1000000.0f;
             }else if(1000<tttt_y){
              dimension_y[i].Print("кВт*ч");
                y_dimension=1.0f/1000.0f;
            }else{
                y_dimension=1.0f;
                dimension_y[i].Print("Вт*ч");
            }
         }else{
             if(1000000<tttt_y){
               dimension_y[i].Print("МВт");
                 y_dimension=1.0f/1000000.0f;
             }else if(1000<tttt_y){
              dimension_y[i].Print("кВт");
                y_dimension=1.0f/1000.0f;
            }else{
                y_dimension=1.0f;
                dimension_y[i].Print("Вт");
            }
        }


         dimension_x[i].color_text=glm::vec3{0.3f,0.3f,1.0f};
         dimension_y[i].color_text=glm::vec3{0.3f,0.3f,1.0f};

         for(int j=0,k=5;j<6 && k>-1;j++,k--){
         text_division_x[j+i*6].Print(std::to_string(static_cast<int>(x_dimension*((charts[i].setting.visible_scale_length_x/(5*100)*j)-static_cast<int>((charts[i].setting.visible_scale_length_x/(100))*charts[i].setting.move.x/2.0f)))));
         lines_x[j+i*6].unhide();
         text_division_y[j+i*6].Print(std::to_string(static_cast<int>(y_dimension*((charts[i].setting.visible_scale_length_y/(5)*k)-static_cast<int>((charts[i].setting.visible_scale_length_y/1.0f)*charts[i].setting.move.y/2.0f)))));
         lines_y[j+i*6].unhide();

         //text_division[j+i*6].color_text=glm::vec3{0.0f,0.0f,0.0f};
         }
         background[i].Draw();
         for(auto &T:charts[i].chart_pointre){
            T->setting.move=charts[i].chart_pointre.back()->setting.move;
            T->setting.visible_scale_length_x=charts[i].chart_pointre.back()->setting.visible_scale_length_x;
            T->setting.visible_scale_length_y=charts[i].chart_pointre.back()->setting.visible_scale_length_y;
            T->connect=true;
         }
            if(charts[i].chart_pointre.size()){
           // std::cout<<i<<"<>"<<charts[i].chart_pointre.back()->grid_x<<"|"<< charts[i].chart_pointre.back()->grid_y<<"|"<<charts[i].chart_pointre.back()->name<<std::endl;
            charts[i].chart_pointre.back()->connect=false;
            charts[i].setting.move=charts[i].chart_pointre.back()->setting.move;
            charts[i].setting.visible_scale_length_x=charts[i].chart_pointre.back()->setting.visible_scale_length_x;
            charts[i].setting.visible_scale_length_y=charts[i].chart_pointre.back()->setting.visible_scale_length_y;
            }






       //dimension_x[i].color_text=glm::vec3{0.07f,0.04f,0.56f};

       //dimension_y[i].color_text=glm::vec3{0.07f,0.04f,0.56f};

         glDepthFunc(GL_ALWAYS);
         charts[i].unhide();
         glDepthFunc(GL_LESS);



         }

        for(int i=0;i<charts.size();i++){
         background[i].Draw();
        }



        glDepthFunc(GL_ALWAYS);
     //   std::cout<<"<<<<0>>>>"<<std::endl;
        if(input_field_graf){

           input_field_windous_graf.Draw();

           for(int i=0;i<4;i++){
               if(input_diapozon[nomer_graf].at(i).date.current_value_nomber==-999999){
                   input_diapozon[nomer_graf].at(i).date.current_value_symbol="      0";
               }
           }

           for(int i=0;i<querty_colors.size();i++){
               ourShader_1_color.use();
               ourShader_1_color.Uniform("new_color",color_chair[i].x,color_chair[i].y,color_chair[i].z);
               querty_colors[i].Draw();
               if(cross_active[nomer_graf][i]){
                 querty_colors_cross[i].Draw();
               }
               if(keys_1[GLFW_MOUSE_BUTTON_LEFT] && !timer){
                   if(static_cast<int>(querty_colors[i].id.r*100)==r && static_cast<int>(querty_colors[i].id.g*100)==g){
                       timer=5;
                       for(auto &T:cross_active[nomer_graf]){
                           T=false;
                       }
                       cross_active[nomer_graf][i]=true;
                       charts[nomer_graf].setting.color=color_chair[i];
                       std::cout<<"___________"<<std::endl;
                   }
                 }
               }

                if(keys_1[GLFW_MOUSE_BUTTON_LEFT] && !timer){
                   if((static_cast<int>(button_graf_diapozon_off.id.r*100)==r && static_cast<int>(button_graf_diapozon_off.id.g*100)==g)){
                       input_field_graf=false;
                   }
                   if((static_cast<int>(button_graf_diapozon_ok.id.r*100)==r && static_cast<int>(button_graf_diapozon_ok.id.g*100)==g)){
                    for(auto &T:input_diapozon[nomer_graf]){
                        T.string_in_float();
                        T.active=false;
                        T.string_in_float();
                        T.imput.clear();
                    }
                     charts[nomer_graf].setting.visible_scale_length_x=100.0f*std::abs(input_diapozon[nomer_graf][1].date.current_value_nomber-input_diapozon[nomer_graf][0].date.current_value_nomber);
                     charts[nomer_graf].setting.move.x=-input_diapozon[nomer_graf][0].date.current_value_nomber/static_cast<int>((charts[nomer_graf].setting.visible_scale_length_x/100.0f)/2.0f);
                     charts[nomer_graf].setting.visible_scale_length_y=std::abs(input_diapozon[nomer_graf][3].date.current_value_nomber-input_diapozon[nomer_graf][2].date.current_value_nomber);
                     charts[nomer_graf].setting.move.y=-input_diapozon[nomer_graf][2].date.current_value_nomber/static_cast<int>((charts[nomer_graf].setting.visible_scale_length_y/1.0f)/2.0f);
                     input_field_graf=false;
                     std::cout<<"&&&&&&&&&&&&&&^^^^^^^^^^^^^&&&&&&&&&&&&&&&&&&"<<std::endl;
                     std::cout<<charts[nomer_graf].setting.visible_scale_length_x<<std::endl;
//                     std::cout<<charts[nomer_graf].setting.move.x<<"|"<<charts[nomer_graf].setting.move.y<<std::endl;
//                     for(auto &T:input_diapozon[nomer_graf]){
//                         T.active=false;
//                     }

                   }

               }




           header_input_field_windous_graf.Print("График:"+charts[nomer_graf+1].name);
           for(int i=0;i<diapozon_set.size();i++){
               diapozon_set[i].Draw();
               input_diapozon[nomer_graf][i].new_fraem(r,g);
               if(input_diapozon[nomer_graf][i].active){
                  // std::cout<<input_diapozon[nomer_graf][0].imput<<std::endl;
               }
           }


           std::string diapozon_x="Диапозон X ";
           diapozon_x.push_back(static_cast<char>(186));
           diapozon_x+="[["+input_diapozon[nomer_graf][0].date.current_value_symbol+" ; "+input_diapozon[nomer_graf][1].date.current_value_symbol+"]";
           std::string diapozon_y="Диапозон Y ";
           diapozon_y.push_back(static_cast<char>(186));
           diapozon_y+="[["+input_diapozon[nomer_graf][2].date.current_value_symbol+" ; "+input_diapozon[nomer_graf][3].date.current_value_symbol+"]";
          // std::cout<<static_cast<int>(diapozon_x[0])<<"|"<<static_cast<int>(diapozon_x[1])<<std::endl;

           diapozon_x_installation.Print(diapozon_x);
           diapozon_y_installation.Print(diapozon_y);

           button_graf_diapozon_ok.Draw();
           button_graf_diapozon_off.Draw();

           button_graf_diapozon_ok_text.Print("Принять");
           button_graf_diapozon_off_text.Print("Отмена");

        }else {
             for(int i=0;i<16;i++){
              input_diapozon[i].at(0).date.current_value_symbol=std::to_string((charts[i].setting.visible_scale_length_x/(5*100)*0)-static_cast<int>((charts[i].setting.visible_scale_length_x/(100))*charts[i].setting.move.x/2.0f));
              input_diapozon[i].at(1).date.current_value_symbol=std::to_string((charts[i].setting.visible_scale_length_x/(5*100)*5)-static_cast<int>((charts[i].setting.visible_scale_length_x/(100))*charts[i].setting.move.x/2.0f));
              input_diapozon[i].at(2).date.current_value_symbol=std::to_string((charts[i].setting.visible_scale_length_y/(5)*0)-static_cast<int>((charts[i].setting.visible_scale_length_y/1.0f)*charts[i].setting.move.y/2.0f));
              input_diapozon[i].at(3).date.current_value_symbol=std::to_string((charts[i].setting.visible_scale_length_y/(5)*5)-static_cast<int>((charts[i].setting.visible_scale_length_y/1.0f)*charts[i].setting.move.y/2.0f));
             }

        }
        glDepthFunc(GL_LESS);

         glFinish();
         glfwSwapBuffers(test2.window);
         for(auto &T:input_diapozon){
             for(auto&J:T){
                J.string_in_float();
             }
         }
         for(auto &T:input_diapozon_separate){
             for(auto&J:T){
                J.string_in_float();
                //std::cout<<":::::::::::::::"<<std::endl;
             }
         }

         ////
         ///
         ///
         glfwMakeContextCurrent(test.window);



     }
    }
    std::ofstream out("test");
    out.close();


    for(int i=0;i<input.size();i++){
        for(int j=0;j<input[i].size();j++){
           input_fields[i][j]=input[i][j].date;
        }
    }

    std::cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<std::endl;

    for(auto &T:input_fields){
            T.write_file("test");
    }



    std::ofstream out_3("graf",  std::ios::binary);
    for(auto &T:charts){
            T.write_file(out_3);
    }

    std::cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<std::endl;

    out_3.close();
    std::cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<std::endl;

    glfwTerminate();
    return 0;
}

// Is called whenever a key is pressed/released via GLFW
void Do_Movement( Window & window){
    // Camera controls
    if(keys[GLFW_KEY_W])
        camera.ProcessKeyboard(FORWARD, window.deltaTime);
        camera_two.ProcessKeyboard(FORWARD, window.deltaTime);
    if(keys[GLFW_KEY_S])
        camera.ProcessKeyboard(BACKWARD, window.deltaTime);
        camera_two.ProcessKeyboard(BACKWARD, window.deltaTime);
    if(keys[GLFW_KEY_A])
        camera.ProcessKeyboard(LEFT, window.deltaTime);
        camera_two.ProcessKeyboard(LEFT, window.deltaTime);
    if(keys[GLFW_KEY_D])
        camera.ProcessKeyboard(RIGHT, window.deltaTime);
        camera_two.ProcessKeyboard(RIGHT, window.deltaTime);
    if(keys[GLFW_KEY_0]){
        digit=0;
    }


    if(keys[GLFW_MOUSE_BUTTON_MIDDLE]){

     glfwSetInputMode(window.window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
     if(window.firstMouse)
     {
         window.lastX = window.xpos;
         window.lastY = window.ypos;
         window.firstMouse = false;
     }

     GLfloat xoffset = window.xpos - window.lastX;
     GLfloat yoffset = window.lastY - window.ypos;  // Reversed since y-coordinates go from bottom to left

     window.lastX = window.xpos;
     window.lastY = window.ypos;
     camera.ProcessMouseMovement(xoffset, yoffset);
 }else{
    glfwSetInputMode(window.window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);


     if(window.xpos<=49.5f){
     glfwSetCursorPos(window.window,50,window.ypos);
     camera.ProcessKeyboard(LEFT, window.deltaTime);
     camera_two.ProcessKeyboard(LEFT, window.deltaTime);
     }
     if(window.xpos>=window.width-49.5f){
     glfwSetCursorPos(window.window,window.width-50,window.ypos);
     camera.ProcessKeyboard(RIGHT, window.deltaTime);
     camera_two.ProcessKeyboard(RIGHT, window.deltaTime);
     }
     if(window.ypos>=window.height-49.5f){
     glfwSetCursorPos(window.window,window.xpos,window.height-50);
      camera.ProcessKeyboard(DOUWN, window.deltaTime);
      camera_two.ProcessKeyboard(DOUWN, window.deltaTime);
     }
     if(window.ypos<=49.5f){
     glfwSetCursorPos(window.window,window.xpos,50);
      camera.ProcessKeyboard(UP, window.deltaTime);
      camera_two.ProcessKeyboard(UP, window.deltaTime);
     }

}
}

// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    //cout << key << endl;
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    if (key >= 0 && key < 1024)
    {
        if(action == GLFW_PRESS)
            keys[key] = true;
        else if(action == GLFW_RELEASE)
            keys[key] = false;
    }

}



void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(yoffset);
}
void movent()
{




    GLfloat cameraSpeed = 0.1f;
    if(keys[GLFW_KEY_KP_8])
        trans1 += cameraSpeed ;
    if(keys[GLFW_KEY_KP_2])
        trans1  -= cameraSpeed;
    if(keys[GLFW_KEY_KP_4])
        trans2  -= cameraSpeed;
    if(keys[GLFW_KEY_KP_6])
        trans2  += cameraSpeed;
    if(keys[GLFW_KEY_KP_7])
        trans3  -= cameraSpeed*5;
    if(keys[GLFW_KEY_KP_9])
        trans3  += cameraSpeed*5;
    if(keys[GLFW_KEY_KP_0])
        trans4  -= cameraSpeed;
    if(keys[GLFW_KEY_KP_5])
        trans4  += cameraSpeed;
    if(keys[GLFW_KEY_KP_3])
        trans5  -= cameraSpeed*0.2;
    if(keys[GLFW_KEY_KP_1])
        trans5  += cameraSpeed*0.2;

}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

void close_callback(GLFWwindow* window){
    glfwHideWindow (window);
    graf_button_clic=false;
};

/*
        std::cout<<"####################################"<<std::endl;
        std::cout<<"|"<<cub.position.pos()[0][0]<<"|"<<cub.position.pos()[0][1]<<"|"<<cub.position.pos()[0][2]<<"|"<<cub.position.pos()[0][3]<<"|"<<std::endl;
        std::cout<<"|"<<cub.position.pos()[1][0]<<"|"<<cub.position.pos()[1][1]<<"|"<<cub.position.pos()[1][2]<<"|"<<cub.position.pos()[1][3]<<"|"<<std::endl;
        std::cout<<"|"<<cub.position.pos()[2][0]<<"|"<<cub.position.pos()[2][1]<<"|"<<cub.position.pos()[2][2]<<"|"<<cub.position.pos()[2][3]<<"|"<<std::endl;
        std::cout<<"|"<<cub.position.pos()[3][0]<<"|"<<cub.position.pos()[3][1]<<"|"<<cub.position.pos()[3][2]<<"|"<<cub.position.pos()[3][3]<<"|"<<std::endl;
        std::cout<<"#####################################"<<std::endl;
*/
