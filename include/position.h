#ifndef POSITION_H
#define POSITION_H

#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <utility>



class Position{
private:
Position * position_parent=nullptr;
glm::mat4 (Position::*fun_pos)(){&Position::pos_fun};
glm::mat4 current_position;

public:
    glm::mat4 current_kord{1.0f};
    glm::mat4 current_rote{1.0f};
    glm::mat4 current_size{1.0f};
    glm::mat4 current_kord_angular{1.0f};


    Position()=default;
    Position(glm::vec3 && kord):
        current_kord((glm::translate(glm::mat4{1.0f}, kord))){};
    Position(float && ratate_corner,glm::vec3 && ratate_axis,glm::vec3 && kord=(glm::vec3(0.0,0.0,0.0f))):
        current_rote(glm::rotate(glm::mat4{1.0f},glm::radians(ratate_corner), ratate_axis)),
        current_kord((glm::translate(glm::mat4{1.0f},kord))){};
    Position(glm::mat4 cur_kord):current_kord(cur_kord) {};
    //премещения объекта
    void rotete(glm::vec3 for_mom,float rad);//порядок очень очень важен
    void scale(glm::vec3 scal);
    void move(glm::vec3 pos);
    void angular_move(glm::vec3 pos,glm::vec3 for_mom,float rad);

    //взаимодействие с родетелем
    glm::mat4 pos_fun();
    glm::mat4 pos_object_fun();
    bool conection_object(Position * pos );

    glm::mat4 pos();
    glm::vec3 position_world(){
        pos();
        return glm::vec3(current_position[3][0],current_position[3][1],current_position[3][2]);
    };
    glm::vec3 Get_scale(){
        return glm::vec3(current_size[0][0],current_size[1][1],current_size[2][2]);
    };
    void new_cicl();

    };

#endif // POSITION_H
