#ifndef CHART_H
#define CHART_H
#include <iostream>
#include <model.h>
#include <fstream>

struct Chart_setting{
    int visible_scale_length_x=24*60*60*100;//мс
    int visible_scale_length_y=2;//Квт
    glm::vec3 color{0.0f,0.0f,0.0f};
    glm::vec2 move=glm::vec2{0.0f,0.0f};
};


class Chart{
public:

    int grid_x=0;
    int grid_y=0;

    std::vector<Chart *> chart_pointre;
    Shader shader;
    Shader shaderIndef=shader;
    std::string name="";
    std::string current_characters="";
    Position position;
    bool mode_overlay=false;
    bool connect=false;
    bool name_unhide=true;
    glm::vec3 color_arraws{1.0f,1.0f,1.0f};
    Chart_setting setting;
    int time=2;
    glm::mat4 * projection=nullptr;
    glm::mat4 * view=nullptr;
    Buffer_VAO VAOl=line_VAO();
    Display draw{VAOl};
    Chart(Shader shader_,glm::mat4 *proj,glm::mat4 *viw,Position position_,glm::vec3 color_)
        :shader(shader_),position(position_),projection(proj),view(viw){
        draw.on_line();
        setting.color=color_;
    };
    void connect_chart(Chart *plus){
        chart_pointre.push_back(plus);
    }
    void disconnect_chart(Chart *minus){
        chart_pointre.pop_back();
    }

    void write_file(std::ofstream &out){
        out.write(reinterpret_cast<char*>(&setting),sizeof (Chart_setting));
    }



    void disconnect_chart(){
       for(auto &T:chart_pointre){
           T->connect=false;
           T->name_unhide=true;
       }

       std::vector<Chart *> chart_pointre_1;
       chart_pointre=chart_pointre_1;
       chart_pointre.push_back(this);
       //this->connect=false;
       //connect_chart(this);
    }

    void graf_new(Buffer_VAO VAO);
    void Set_time(int time_);
    void unhide();

    //gl_VertexID
};
void read_vector_charts(std::string name_file,std::vector<Chart> &grafs);
#endif // CHART_H
