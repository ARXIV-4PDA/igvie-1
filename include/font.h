#ifndef FONT_H
#define FONT_H
#include <animation.h>


class Font{
public:
    Animation texture;
    int wight=0;
    int hight=0;
    int size=1;
    int dinamic=0;
    Font(Animation texture_):texture(texture_){};
int namber_symbol(char symbol){
        return symbol;
    };
int namber_symbol(char symbol_1,int symbol_2){
   int symbol1=static_cast<int>(symbol_1);
   int symbol2=static_cast<int>(symbol_2);
   if(symbol1==-70 && symbol2==91){return 186;};

   if(symbol1==-47 && symbol2==-113){return 255-0;};
   if(symbol1==-47 && symbol2==-114){return 255-1;};
   if(symbol1==-47 && symbol2==-115){return 255-2;};
   if(symbol1==-47 && symbol2==-116){return 255-3;};
   if(symbol1==-47 && symbol2==-117){return 255-4;};
   if(symbol1==-47 && symbol2==-118){return 255-5;};
   if(symbol1==-47 && symbol2==-119){return 255-6;};
   if(symbol1==-47 && symbol2==-120){return 255-7;};
   if(symbol1==-47 && symbol2==-121){return 255-8;};
   if(symbol1==-47 && symbol2==-122){return 255-9;};
   if(symbol1==-47 && symbol2==-123){return 255-10;};
   if(symbol1==-47 && symbol2==-124){return 255-11;};
   if(symbol1==-47 && symbol2==-125){return 255-12;};
   if(symbol1==-47 && symbol2==-126){return 255-13;};
   if(symbol1==-47 && symbol2==-127){return 255-14;};
   if(symbol1==-47 && symbol2==-128){return 255-15;};
   if(symbol1==-48 && symbol2==-65){return 255-16;};
   if(symbol1==-48 && symbol2==-66){return 255-17;};
   if(symbol1==-48 && symbol2==-67){return 255-18;};
   if(symbol1==-48 && symbol2==-68){return 255-19;};
   if(symbol1==-48 && symbol2==-69){return 255-20;};
   if(symbol1==-48 && symbol2==-70){return 255-21;};
   if(symbol1==-48 && symbol2==-71){return 255-22;};
   if(symbol1==-48 && symbol2==-72){return 255-23;};
   if(symbol1==-48 && symbol2==-73){return 255-24;};
   if(symbol1==-48 && symbol2==-74){return 255-25;};
   if(symbol1==-48 && symbol2==-75){return 255-26;};
   if(symbol1==-48 && symbol2==-76){return 255-27;};
   if(symbol1==-48 && symbol2==-77){return 255-28;};
   if(symbol1==-48 && symbol2==-78){return 255-29;};
   if(symbol1==-48 && symbol2==-79){return 255-30;};
   if(symbol1==-48 && symbol2==-80){return 255-31;};
   if(symbol1==-48 && symbol2==-81){return 255-32;};
   if(symbol1==-48 && symbol2==-82){return 255-33;};
   if(symbol1==-48 && symbol2==-83){return 255-34;};
   if(symbol1==-48 && symbol2==-84){return 255-35;};
   if(symbol1==-48 && symbol2==-85){return 255-36;};
   if(symbol1==-48 && symbol2==-86){return 255-37;};
   if(symbol1==-48 && symbol2==-87){return 255-38;};
   if(symbol1==-48 && symbol2==-88){return 255-39;};
   if(symbol1==-48 && symbol2==-89){return 255-40;};
   if(symbol1==-48 && symbol2==-90){return 255-41;};
   if(symbol1==-48 && symbol2==-91){return 255-42;};
   if(symbol1==-48 && symbol2==-92){return 255-43;};
   if(symbol1==-48 && symbol2==-93){return 255-44;};
   if(symbol1==-48 && symbol2==-94){return 255-45;};
   if(symbol1==-48 && symbol2==-95){return 255-46;};
   if(symbol1==-48 && symbol2==-96){return 255-47;};
   if(symbol1==-48 && symbol2==-97){return 255-48;};
   if(symbol1==-48 && symbol2==-98){return 255-49;};
   if(symbol1==-48 && symbol2==-99){return 255-50;};
   if(symbol1==-48 && symbol2==-100){return 255-51;};
   if(symbol1==-48 && symbol2==-101){return 255-52;};
   if(symbol1==-48 && symbol2==-102){return 255-53;};
   if(symbol1==-48 && symbol2==-103){return 255-54;};
   if(symbol1==-48 && symbol2==-104){return 255-55;};
   if(symbol1==-48 && symbol2==-105){return 255-56;};
   if(symbol1==-48 && symbol2==-106){return 255-57;};
   if(symbol1==-48 && symbol2==-107){return 255-58;};
   if(symbol1==-48 && symbol2==-108){return 255-59;};
   if(symbol1==-48 && symbol2==-109){return 255-60;};
   if(symbol1==-48 && symbol2==-110){return 255-61;};
   if(symbol1==-48 && symbol2==-111){return 255-62;};
   if(symbol1==-48 && symbol2==-112){return 255-63;};

   return 0;

}

};

#endif // FONT_H
