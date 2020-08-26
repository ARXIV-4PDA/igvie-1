#include "text.h"
#include <glm/gtc/type_ptr.hpp>

void Text::Print(std::string new_characters){
shader.use();

draw.instance=new_characters.size();
 current_characters=new_characters;



int k=0;
if(text_alignment==-1){


}

//33333-3-34-3-32
if(text_alignment==1){
for(int i=0;i< current_characters.size();i++){
int nomer_symbol=0;
if(static_cast<int>(current_characters[i])<0){
    nomer_symbol=font.namber_symbol( current_characters[i],current_characters[i+1]);
    i++;
    k++;
}else{
    nomer_symbol=font.namber_symbol( current_characters[i]);
}

glm::vec4 frame=font.texture.Get_frame_namber(nomer_symbol);

shader.Uniform("symbol["+std::to_string(i-k)+"]",frame[0], frame[1],frame[2],frame[3]);
//std::cout<<"["<<i<<"|"<<nomer_symbol<<"|"<<current_characters.size()<<"]"<<std::endl;
//std::cout<<frame[0]<<"|"<<frame[1]<<"|"<<frame[2]<<"|"<<frame[3]<<std::endl;
};
}

if(!(new_characters.size()==0)){
draw.instance-=k;
 current_characters=new_characters;
}


glActiveTexture(GL_TEXTURE0);
shader.Uniform("map_font", 0);
glBindTexture(GL_TEXTURE_2D,font.texture.texture());


shader.Uniform<4,4>("model",      1, GL_FALSE, glm::value_ptr(position.pos()));
shader.Uniform<4,4>("projection", 1, GL_FALSE, glm::value_ptr(*projection));
shader.Uniform<4,4>("view",       1, GL_FALSE, glm::value_ptr(*view));
shader.Uniform     ("size_symbol",text_alignment*position.Get_scale().x,position.Get_scale().y);
shader.Uniform     ("color_text", color_text.r,color_text.g,color_text.b,1.0f);


draw.start();

glActiveTexture(GL_TEXTURE0);
};
