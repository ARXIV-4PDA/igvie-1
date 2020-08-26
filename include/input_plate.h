#ifndef INPUT_PLATE_H
#define INPUT_PLATE_H
#include <window.h>
#include <model.h>
#include <vector>
#include <date_input.h>

constexpr int TIME_TIMER=9;
class Input_plate{
public:

    static std::vector<Input_plate *> input_plate_pointer;
    std::string imput=" ";
    Window * window=nullptr;
    std::vector<int> click_button;
    Model * indefecator;
    bool active =false;
    int timer=0;
    Date_input_field date;
    int nomber=-1;
    Input_plate(Window * window_,Model * model):window(window_),indefecator(model){};
    void on_input();
    void activeted();
    void new_fraem(int r,int g=0,int b=0);
    void string_in_float();

};


#endif // INPUT_PLATE_H
