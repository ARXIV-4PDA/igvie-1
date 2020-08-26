#include "date_input.h"

Date_input_field::Date_input_field(){};

void Date_input_field::write_file(std::string name_file){
    if(on_imput){
    std::ofstream out(name_file, std::ios::app);
    out<<name<<"="<<current_value_symbol<< std::endl;
    out.close();
    }
}

void Date_input_field::calculate_vuoto(){
    std::string  vuoto="";
//        std::string  acut="";
//        int k=current_value_symbol.find('.');
//        if(k==-1){
//            acut+='.';
//            for(int i=0;i<accuracy;i++){
//                acut+='0';
//           }
//        }

    for(int i=0;i<max_size_input_symbol-static_cast<int>(current_value_symbol.size())/*-accuracy-1*/;i++){
        vuoto+=" ";

    }
    current_value_symbol=vuoto+current_value_symbol/*+acut*/;

}

void Date_input_field::calculate_namber(){
       current_value_symbol.clear();
       current_value_symbol=std::to_string(current_value_nomber);

        if(accuracy<6){
            for(int j=0;j<6-accuracy;j++){
            current_value_symbol.erase(current_value_symbol.size()-1);
            }
            if(accuracy==0){
             current_value_symbol.erase(current_value_symbol.size()-1);
            }
        }

        calculate_vuoto();
        //std::cout<<current_value_symbol<<std::endl;
}

void Date_input_field::calculate_max(){
        std::cout<<"]]]]"<<current_value_symbol<<std::endl;
        current_value_symbol.clear();
        current_value_symbol=std::to_string(max_nomber);

        if(accuracy<6){
        for(int j=0;j<6-accuracy;j++){
            current_value_symbol.erase(current_value_symbol.size()-1);
        }
        if(accuracy==0){
            current_value_symbol.erase(current_value_symbol.size()-1);
        }

        std::cout<<"[[[["<<current_value_symbol<<std::endl;
        }
};

void Date_input_field::calculate(){
       current_value_symbol.clear();
       current_value_symbol=std::to_string(min_nomber);

        if(accuracy<6){
            for(int j=0;j<6-accuracy;j++){
            current_value_symbol.erase(current_value_symbol.size()-1);
            }
            if(accuracy==0){
             current_value_symbol.erase(current_value_symbol.size()-1);
            }
        }

        calculate_vuoto();
        //std::cout<<current_value_symbol<<std::endl;
}

