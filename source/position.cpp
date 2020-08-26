#include <position.h>

#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <utility>
#include <iostream>

    void Position::rotete(glm::vec3 for_mom,float rad){//порядок очень очень важен
    current_rote=glm::rotate(current_rote,glm::radians(rad), for_mom);
    };

    void Position::scale(glm::vec3 scal){//неважен порядок
    current_size=glm::scale(current_size, scal);
    }


    void Position::move(glm::vec3 pos){//неважен порядок
    current_kord=glm::translate(current_kord,pos);
    };

    void Position::angular_move(glm::vec3 pos,glm::vec3 for_mom,float rad){//неважен порядок
    current_kord_angular=glm::translate(current_kord_angular,pos);
    current_kord_angular=glm::rotate(current_kord_angular,glm::radians(rad), for_mom+glm::vec3(this->pos()[3][0],this->pos()[3][1],this->pos()[3][2]));
    };

    glm::mat4 Position::pos_fun(){
    current_position=current_kord*current_kord_angular*current_size*current_rote;
    return this->current_position;
    };

    glm::mat4 Position::pos_object_fun(){
        this-> current_position=
                 this->current_kord*(*(this->position_parent)).current_kord*
                 this->current_kord_angular*(*(this->position_parent)).current_kord_angular*
                 this->current_size*(*(this->position_parent)).current_size*
                 this->current_rote*(*(this->position_parent)).current_rote;
    return this->current_position;
    };


     glm::mat4 Position::pos(){
    return (this->*fun_pos)();
    };

    bool Position::conection_object(Position * pos ){
        if(pos){
        position_parent=pos;
        fun_pos=&Position::pos_object_fun;
        return true;
        }else {
         return false;
        }
    }


    void Position::new_cicl(){
    };




