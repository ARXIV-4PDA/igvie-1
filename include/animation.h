#ifndef ANIMATION_H
#define ANIMATION_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <glm/vec3.hpp> // glm::vec3
#include<GL/glew.h>
#include <glm/vec4.hpp>

#include <GL/gl.h>
#include "texture.h"

class Animation: public Texture{
private:
int total_frame;
int current_frame;
int collum;
int row;
int zadergka;
int speed;
std::vector<glm::vec4> cycle_animation{total_frame};
public:
glm::vec4 result;
Animation(std::string path,int type_image__,int type_texture__,int number_kadrov,int collum_,int row_,int sp):
Texture(path, type_image__, type_texture__),total_frame(number_kadrov),current_frame(-1),collum(collum_),row(row_),speed(sp){




   for (int current_frame1=0;!(current_frame1==total_frame);current_frame1++) {


    cycle_animation[current_frame1][0]=(current_frame1%collum)-1;
    cycle_animation[current_frame1][1]=static_cast<int>(current_frame1-cycle_animation[current_frame1][0])/collum;
    cycle_animation[current_frame1][1]++;
    cycle_animation[current_frame1][0]=collum-cycle_animation[current_frame1][0]-1;
    //cycle_animation[current_frame1][0]++;
    cycle_animation[current_frame1][2]=1.0f/collum;
    cycle_animation[current_frame1][3]=1.0f/row;
    std::cout<<"current_frame:"<<current_frame1<<std::endl;
    std::cout<<"cycle_animation[current_frame1][0]:"<<cycle_animation[current_frame1][0]<<std::endl;
    std::cout<<"cycle_animation[current_frame1][1]:"<<cycle_animation[current_frame1][1]<<std::endl;
    std::cout<<"cycle_animation[current_frame1][2]:"<<cycle_animation[current_frame1][2]<<std::endl;
    std::cout<<"cycle_animation[current_frame1][3]:"<<cycle_animation[current_frame1][3]<<std::endl;


}


zadergka=0;

result[2]=1.0f/collum;
result[3]=1.0f/row;

if(speed<0){

result[0]=0;
result[1]=0;
result[2]=1;
result[3]=1;
}

if(type_image==D21){
current_frame=1;
}

};

Animation(std::vector<std::string> path,int type_image__,int type_texture__,int number_kadrov,int collum_,int row_,int sp):
Texture(path, type_image__, type_texture__),total_frame(number_kadrov),current_frame(-1),collum(collum_),row(row_),speed(sp){




   for (int current_frame1=0;!(current_frame1==total_frame);current_frame1++) {


    cycle_animation[current_frame1][0]=(current_frame1%collum);
    cycle_animation[current_frame1][1]=(current_frame1-cycle_animation[current_frame1][0])/row;
    cycle_animation[current_frame1][1]++;
    cycle_animation[current_frame1][0]++;
    cycle_animation[current_frame1][2]=1.0f/collum;//смещают область теск=туры до одного рямоугольника
    cycle_animation[current_frame1][3]=1.0f/row;
//    std::cout<<"current_frame:"<<current_frame1<<std::endl;
//    std::cout<<"cycle_animation[current_frame1][0]:"<<cycle_animation[current_frame1][0]<<std::endl;
//    std::cout<<"cycle_animation[current_frame1][1]:"<<cycle_animation[current_frame1][1]<<std::endl;
//    std::cout<<"cycle_animation[current_frame1][2]:"<<cycle_animation[current_frame1][2]<<std::endl;
//    std::cout<<"cycle_animation[current_frame1][3]:"<<cycle_animation[current_frame1][3]<<std::endl;


}
//по x
///0.1.2.3.4.5.6.7.8.9.10.11.12.13.14.15.16.17.18.19.20.21.22.23.24.25.26.27.28.29.30.31
///0.1.2.3.4.5.6.7.8.9.10.11.12.13.14.15.16.17.18.19.20.21.22.23.24.25.26.27.28.29.30.31
///0.1.2.3.4.5.6.7.8.9.10.11.12.13.14.15.16.17.18.19.20.21.22.23.24.25.26.27.28.29.30.31
///0.1.2.3.4.5.6.7.8.9.10.11.12.13.14.15.16.17.18.19.20.21.22.23.24.25.26.27.28.29.30.31
///0.1.2.3.4.5.6.7.8.9.10.11.12.13.14.15.16.17.18.19.20.21.22.23.24.25.26.27.28.29.30.31
///0.1.2.3.4.5.6.7.8.9.10.11.12.13.14.15.16.17.18.19.20.21.22.23.24.25.26.27.28.29.30.31
///0.1.2.3.4.5.6.7.8.9.10.11.12.13.14.15.16.17.18.19.20.21.22.23.24.25.26.27.28.29.30.31
///0.1.2.3.4.5.6.7.8.9.10.11.12.13.14.15.16.17.18.19.20.21.22.23.24.25.26.27.28.29.30.31
///0.1.2.3.4.5.6.7.8.9.10.11.12.13.14.15.16.17.18.19.20.21.22.23.24.25.26.27.28.29.30.31
//по y
///0.0.0.0.0.0.0.0.0.0.00.00.00.00.00.00.00.00.00.00.00.00.00.00.00.00.00.00.00.00.00.00
///
///
///
///
///
///
///
///
///
zadergka=0;

result[2]=1.0f/collum;
result[3]=1.0f/row;

if(speed<0){

result[0]=0;
result[1]=0;
result[2]=1;
result[3]=1;
}

if(type_image==D21){
current_frame=1;
}

};


virtual void new_cicl()  override  {

zadergka++;
if(zadergka==speed){
current_frame++;
zadergka=0;
if(current_frame==(total_frame)){
current_frame=0;
};
};
}

void new_fream(){
if(zadergka==0 && speed>=0){
//result[1]=(current_frame%collum);
//result[0]=(current_frame-result[1])/row;
//result[1]++;
//result[0]++;

result[1]=cycle_animation[current_frame][1];
result[0]=cycle_animation[current_frame][0];


//std::cout<<"current_frame:"<<current_frame<<std::endl;
//std::cout<<"result[0]:"<<result[0]<<std::endl;
//std::cout<<"result[1]:"<<result[1]<<std::endl;
//std::cout<<"result[2]:"<<result[2]<<std::endl;
//std::cout<<"result[3]:"<<result[3]<<std::endl;

};
};

void speed_change(int new_speed){
speed=new_speed;
};

glm::vec4 Get_frame_namber(int i){
  return cycle_animation[i];
};


/*
 пример бхода картинки для анимации
|->->->|
|->->->|
|->    |
 ------
*/


};






#endif // ANIMATION_H
