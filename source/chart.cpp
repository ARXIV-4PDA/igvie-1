#include "chart.h"
#include <glm/gtc/type_ptr.hpp>


void Chart::graf_new(Buffer_VAO VAO){
    draw=Display(VAO);
    draw.on_line();
};
void Chart::Set_time(int time_){
    draw.cout_line=time_;
};

void Chart::unhide(){
    shader.use();

    shader.Uniform<4,4>("model",      1, GL_FALSE, glm::value_ptr(position.pos()));
    shader.Uniform<4,4>("projection", 1, GL_FALSE, glm::value_ptr(*projection));
    shader.Uniform<4,4>("view",       1, GL_FALSE, glm::value_ptr(*view));
    shader.Uniform     ("current_time",time);
    shader.Uniform     ("visible_scale_length_x",setting.visible_scale_length_x);
    shader.Uniform     ("visible_scale_length_y",setting.visible_scale_length_y);
    shader.Uniform     ("color_chart",setting.color.r,setting.color.g,setting.color.b,1.0f);
    shader.Uniform     ("move",setting.move.x,setting.move.y);

    draw.start();

};

void read_vector_charts(std::string name_file,std::vector<Chart> &grafs){
    std::ifstream in(name_file,std::ios::binary);

    if(in.is_open()){
    for(int i=0;i<16;i++){
       in.read(reinterpret_cast<char*>(&grafs[i].setting),sizeof (Chart_setting));
//        std::cout<<grafs[i].visible_scale_length_x<<std::endl;
//        std::cout<<grafs[i].visible_scale_length_y<<std::endl;
//        std::cout<<grafs[i].move.x<<","<<grafs[i].move.y<<std::endl;
//        std::cout<<grafs[i].color.x<<","<<grafs[i].color.y<<","<<grafs[i].color.z<<std::endl;
//        grafs[i].visible_scale_length_x=grafs[i].visible_scale_length_x;
//        grafs[i].visible_scale_length_y=grafs[i].visible_scale_length_y;
//        grafs[i].move=grafs[i].move;
//        grafs[i].color=grafs[i].color;
    }
      in.close();
    }



};
