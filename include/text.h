#ifndef TEXT_H
#define TEXT_H
#include <iostream>
#include <model.h>
#include <font.h>

class Text
{
public:
    Shader shader;
    Shader shaderIndef=shader;
    std::string current_characters="";
    Position position;
    Font font;
    glm::vec3 color_text=glm::vec3{1.0f,1.0f,1.0f};
    int text_alignment=1; /*1:
                        * lift
                        * -1:
                        * right                       *
                        * .-начало
                        */


    glm::mat4 * projection=nullptr;
    glm::mat4 * view=nullptr;
    Buffer_VAO VAOp=plate_VAO();
    Display draw{VAOp};
    Text(Shader shader_,glm::mat4 *proj,glm::mat4 *viw,Position position_,Font font_,std::string current_characters_="")
        :shader(shader_),current_characters(current_characters_),position(position_),font(font_),projection(proj),view(viw){
        draw.Instanced_on();
        draw.instance=current_characters.size();
    };
    void Print(std::string new_characters="");
    void Print(int new_characters);


    Text & operator=(const Text & text)=delete;
    Text & operator=(Text && text)=delete;
    Text (Text && text)
        :shader(std::move(text.shader)),current_characters(std::move(text.current_characters)),
        position(std::move(text.position)),font(std::move(text.font)),
        projection(std::move(text.projection)),view(std::move(text.view)){
        this->draw.Instanced_on();
        this->draw.instance=current_characters.size();
        this->color_text=color_text;
    };
    Text (const Text & text) :shader(text.shader),current_characters(text.current_characters),position(text.position),font(text.font),projection(text.projection),view(text.view){
        this->draw.Instanced_on();
        this->draw.instance=current_characters.size();
         this->color_text=color_text;
    };
};

#endif // TEXT_H
