#include <input_plate.h>


void Input_plate::on_input(){
    if(input_plate_pointer[0]==nullptr){
        input_plate_pointer.clear();
    }
    input_plate_pointer.emplace_back(this);
    this->nomber=input_plate_pointer.size();

    for(int i=0;i<input_plate_pointer.size();i++){
        input_plate_pointer[i]->active=false;
    }
}


void Input_plate::activeted(){
    for(int i=0;i<Input_plate::input_plate_pointer.size();i++){
        Input_plate::input_plate_pointer[i]->active=false;
    }
    this->active=true;
    imput.clear();
}


void  Input_plate::new_fraem(int r,int g,int b){
if(static_cast<int>((*indefecator).id.r*100)==r && static_cast<int>((*indefecator).id.g*100)==g && static_cast<int>((*indefecator).id.b*100)==b){
   for(int i=0;(i<click_button.size()) && !active;i++){
      if(glfwGetMouseButton((*window).window,click_button[i])==GLFW_PRESS){
          activeted();
          std::cout<<"active######################################################1"<<std::endl;
      }
    }
}
if(timer>0){
timer--;
}

   if(active && !timer){
       if(imput.size()<date.max_size_input_symbol){
           if(glfwGetKey((*window).window,GLFW_KEY_0)==GLFW_PRESS || glfwGetKey((*window).window,GLFW_KEY_KP_0)==GLFW_PRESS){
              imput+="0";
              timer=TIME_TIMER;
           }
           if(glfwGetKey((*window).window,GLFW_KEY_1)==GLFW_PRESS || glfwGetKey((*window).window,GLFW_KEY_KP_1)==GLFW_PRESS){
              imput+="1";
              timer=TIME_TIMER;
           }
           if(glfwGetKey((*window).window,GLFW_KEY_2)==GLFW_PRESS || glfwGetKey((*window).window,GLFW_KEY_KP_2)==GLFW_PRESS){
              imput+="2";
              timer=TIME_TIMER;
           }
           if(glfwGetKey((*window).window,GLFW_KEY_3)==GLFW_PRESS || glfwGetKey((*window).window,GLFW_KEY_KP_3)==GLFW_PRESS){
              imput+="3";
              timer=TIME_TIMER;
           }
           if(glfwGetKey((*window).window,GLFW_KEY_4)==GLFW_PRESS || glfwGetKey((*window).window,GLFW_KEY_KP_4)==GLFW_PRESS){
              imput+="4";
              timer=TIME_TIMER;
           }
           if(glfwGetKey((*window).window,GLFW_KEY_5)==GLFW_PRESS || glfwGetKey((*window).window,GLFW_KEY_KP_5)==GLFW_PRESS){
              imput+="5";
              timer=TIME_TIMER;
           }
           if(glfwGetKey((*window).window,GLFW_KEY_6)==GLFW_PRESS || glfwGetKey((*window).window,GLFW_KEY_KP_6)==GLFW_PRESS){
              imput+="6";
              timer=TIME_TIMER;
           }
           if(glfwGetKey((*window).window,GLFW_KEY_7)==GLFW_PRESS || glfwGetKey((*window).window,GLFW_KEY_KP_7)==GLFW_PRESS){
              imput+="7";
              timer=TIME_TIMER;
           }
           if(glfwGetKey((*window).window,GLFW_KEY_8)==GLFW_PRESS || glfwGetKey((*window).window,GLFW_KEY_KP_8)==GLFW_PRESS){
              imput+="8";
              timer=TIME_TIMER;
           }
           if(glfwGetKey((*window).window,GLFW_KEY_9)==GLFW_PRESS || glfwGetKey((*window).window,GLFW_KEY_KP_9)==GLFW_PRESS){
              imput+="9";
              timer=TIME_TIMER;
           }
           if(glfwGetKey((*window).window,GLFW_KEY_PERIOD)==GLFW_PRESS){
              imput+=".";
              timer=TIME_TIMER;
           }
           if(glfwGetKey((*window).window,GLFW_KEY_MINUS)==GLFW_PRESS){
              imput+="-";
              timer=TIME_TIMER;
           }

        }
       if(glfwGetKey((*window).window,GLFW_KEY_BACKSPACE)==GLFW_PRESS){
          if(imput.size())
          imput.erase(imput.size()-1);
          timer=TIME_TIMER;
       }
       if(glfwGetKey((*window).window,GLFW_KEY_ENTER)==GLFW_PRESS){
         active=false;
          timer=TIME_TIMER;

       }



//           if(glfwGetKey((*window).window,GLFW_KEY_DOWN)==GLFW_PRESS){
//               std::cout<<"DOWN"<<std::endl;
//               timer=TIME_TIMER*50;
//               std::cout<<nomber<<"{[|]}"<<active<<std::endl;
//               for(int i=0;i<Input_plate::input_plate_pointer.size();i++){
//                   Input_plate::input_plate_pointer[i]->active=false;

//               }
//               if(nomber!=1){
//               input_plate_pointer[nomber-1-1]->active=true;
//               std::cout<<nomber-1<<"{[<]}"<<active<<std::endl;
//               }else{
//                   input_plate_pointer[input_plate_pointer.size()-1]->active=true;
//                   std::cout<<input_plate_pointer.size()-1<<"{[=]}"<<active<<std::endl;
//               }
//           }
//           if(glfwGetKey((*window).window,GLFW_KEY_UP)==GLFW_PRESS){
//              std::cout<<"UP"<<std::endl;
//              timer=TIME_TIMER*50;
//              std::cout<<nomber<<"{[|]}"<<active<<std::endl;
//              for(int i=0;i<Input_plate::input_plate_pointer.size();i++){
//                  Input_plate::input_plate_pointer[i]->active=false;
//              }


//              if(nomber!=input_plate_pointer.size()){
//              input_plate_pointer[nomber+1-1]->active=true;
//              std::cout<<nomber+1<<"{[>]}"<<active<<std::endl;
//              }else{
//                  input_plate_pointer[1-1]->active=true;
//                  std::cout<<1-1<<"{[=]}"<<active<<std::endl;
//              }
//           }

}
}

void Input_plate::string_in_float(){
    if(date.on_imput && active){
    date.current_value_symbol=imput;
    imput=date.current_value_symbol;
    }

    //std::cout<<"<1>"<<T[i].name<<":"<<i<<"|"<<std::endl;
    date.calculate_vuoto();
    //std::cout<<"<2>"<<T[i].name<<":"<<i<<"|"<<std::endl;
    if(date.current_value_symbol.size()!=0 && !active){


    if(date.current_value_symbol.back()==' '  ){
      date.calculate();
    }
    //std::cout<<"<3>"<<T[i].name<<":"<<i<<"|"<<std::endl;
      double nomber=0.0f;
     int k=date.current_value_symbol.find_last_of(' ');
     int t=date.current_value_symbol.find_last_of('.');
     if(t==-1){
         //std::cout<<T[i].name<<":"<<i<<"|"<<static_cast<int>(T[i].current_value_symbol.size())<<"}}"<<std::endl;
         t=static_cast<int>(date.current_value_symbol.size())-1;
     }
     //std::cout<<T[i].name<<":"<<i<<"|"<<nomber<<"}}"<<-(static_cast<int>(T[i].current_value_symbol.size())-t-1)<<std::endl;

     for(int j=date.current_value_symbol.size()-1,l=-(static_cast<int>(date.current_value_symbol.size())-t-1);j>k;j--,l++){
         switch (date.current_value_symbol[j]) {
        case '1':nomber+=1.0f*pow(10.0f,l);break;
        case '2':nomber+=2.0f*pow(10.0f,l);break;
        case '3':nomber+=3.0f*pow(10.0f,l);break;
        case '4':nomber+=4.0f*pow(10.0f,l);break;
        case '5':nomber+=5.0f*pow(10.0f,l);break;
        case '6':nomber+=6.0f*pow(10.0f,l);break;
        case '7':nomber+=7.0f*pow(10.0f,l);break;
        case '8':nomber+=8.0f*pow(10.0f,l);break;
        case '9':nomber+=9.0f*pow(10.0f,l);break;
        case '0':nomber+=0.0f*pow(10.0f,l);break;
        case '.':l=l-1;break;
        case '-':nomber=-nomber;break;
         }
     }

     if(nomber>date.max_nomber){
        nomber=date.max_nomber;
        date.calculate_max();
        date.calculate_vuoto();
     }
     if(nomber<date.min_nomber){
        nomber=date.min_nomber;
        date.calculate();
        date.calculate_vuoto();
     }

     date.current_value_nomber=nomber;
     date.calculate_namber();

}
}

std::vector<Input_plate *> Input_plate::input_plate_pointer{nullptr};
