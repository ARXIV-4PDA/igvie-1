#ifndef DATE_INPUT_H
#define DATE_INPUT_H
#include <iostream>
#include <fstream>
#include <array>


class Date_input_field{
public:
std::string name="Параметр";
std::string dimension="В";
int max_size_input_symbol=8;
int accuracy=2;
int max_decades=5;
double max_nomber=10000;
double min_nomber=0;
float current_value_nomber=00000.00f;
std::string current_value_symbol="";
bool on_imput=false;
Date_input_field();

void write_file(std::string name_file);
void calculate_vuoto();
void calculate_namber();
void calculate_max();
void calculate();

};

#endif // DATE_INPUT_H
