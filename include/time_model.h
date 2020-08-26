#ifndef TIME_MODEL_H
#define TIME_MODEL_H
#include <iostream>
#include <vector>

struct Time{
    int seconds=0;
    int minutes=0;
    int delenie_hours=0;
    int hours=0;
    int day=0;
    int day_curent=0;
    int month=0;
    int year=2020;
    std::vector<int> day_on_mounthe{
        31,
        28,
        31,

        30,
        31,
        30,

        31,
        31,
        30,

        31,
        30,
        31
    };

    //void operator=
    void operator=(int t){
       seconds=t;
       minutes=0;
       hours=0;
       day=0;
       day_curent=0;
       month=0;
       year=0;
        for(;seconds>=60;){
           seconds-=60;
           minutes++;
        }
        for(;minutes>=60;){
           minutes-=60;
           hours++;
        }
        for(;hours>=24;){
           hours-=24;
           day++;
           day_curent++;
        }
        for(;day>=day_on_mounthe[month];){
            day-=day_on_mounthe[month];
            month++;
        }
        for(;month>=12;){
            month-=12;
            year++;
            day_curent=0;
        }
        switch (minutes) {
        case 0: delenie_hours=1;break;
        case 10:delenie_hours=3;break;
        case 20:delenie_hours=3;break;
        case 30:delenie_hours=4;break;
        case 40:delenie_hours=3;break;
        case 50:delenie_hours=5;break;
        }
    }

    void operator+=(int t){
       seconds+=t;

       for(;seconds>=60;){
           seconds-=60;
           minutes++;
       }
       for(;minutes>=60;){
           minutes-=60;
           hours++;
       }
        for(;hours>=24;){
           hours-=24;
           day++;
           day_curent++;
      }
        for(;day>=day_on_mounthe[month];){
            day-=day_on_mounthe[month];
            month++;
        }
        for(;month>=12;){
            month-=12;
            year++;
            day_curent=0;
        }
        switch (minutes) {
        case 0: delenie_hours=1;break;
        case 10:delenie_hours=3;break;
        case 20:delenie_hours=3;break;
        case 30:delenie_hours=4;break;
        case 40:delenie_hours=3;break;
        case 50:delenie_hours=5;break;
        }
    }

    long second_cyrent(){
        return static_cast<long>( seconds+minutes*60+hours*60*60+day_curent*60*60*24);
    }
};

class Time_Model
{
public:
    Time_Model();
    Time time;

};

#endif // TIME_MODEL_H
