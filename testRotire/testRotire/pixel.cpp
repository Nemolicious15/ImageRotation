#include "pixel.h"

Pixel::Pixel(){
    type = '0';//none
    negru=0;
    gri=0;
    r=0;
    g=0;
    b=0;
}

Pixel::Pixel(bool b){
    negru=b;
    type = 'n';//negru
    gri=0;
    r=0;
    g=0;
    b=0;
}

Pixel::Pixel(int i){
    gri=i;
    type = 'g';//gri
    negru=0;
    r=0;
    g=0;
    b=0;
}

Pixel::Pixel(int i, int ii, int iii){
    r=i;
    g=ii;
    b=iii;
    type='c';//color
    negru=0;
    gri=0;
}

Pixel::Pixel(Pixel& p){
    negru=p.negru;
    gri=p.gri;
    r=p.r;
    g=p.g;
    b=p.b;
}

Pixel::~Pixel(){
    negru=false;
    gri=0;
    r=0;
    g=0;
    b=0;
}

Pixel Pixel::operator=(Pixel p){
    negru=p.negru;
    gri=p.gri;
    r=p.r;
    g=p.g;
    b=p.b;
    return p;
}

bool Pixel::operator==(Pixel p){
    if(type!=p.type) return false;
    if(negru!=p.negru) return false;
    if(gri!=p.gri) return false;
    if(r!=p.r) return false;
    if(g!=p.g) return false;
    if(b!=p.b) return false;
    return true;
}

char Pixel::get_type(){
    return type;
}

void Pixel::set_type(char c){
    type=c;
}

void Pixel::set_value(bool n,int gr,int i,int ii,int iii){
    negru=n;
    gri=gr;
    r=i;
    g=ii;
    b=iii;
}

bool Pixel::get_negru(){
    return negru;
}

int Pixel::get_gri(){
    return gri;
}

int Pixel::get_r(){
    return r;
}

int Pixel::get_g(){
    return g;
}

int Pixel::get_b(){
    return b;
}

