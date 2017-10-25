#include <iostream>
#include "Imagine.h"

using namespace std;

Imagine::Imagine(){
    pixels = new Pixel*[10];
    for(int i=0;i<10;i++)
        pixels[i] = new Pixel[10];
    width=0;
    height=0;
}

Imagine::Imagine(char t,int** p,int w,int h){
    pixels = new Pixel*[h];
    for(int i=0;i<h;i++)
        pixels[i] = new Pixel[w];
    if(t=='n'){
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++){
            pixels[i][j].set_value(p[i][j],0,0,0,0);
        }
    }
    if(t=='g'){
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
            pixels[i][j].set_value(0,p[i][j],0,0,0);
    }
    if(t=='c'){
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++){
            pixels[i][j].set_value(0,0,p[i][j],p[i][j+w],p[i][j+2*w]);}
    }
    width=w;
    height=h;
    type=t;
}

Imagine::Imagine(Imagine& im){
    type=im.type;
    width=im.width;
    height=im.height;
    pixels = new Pixel*[height];
    for(int i=0;i<height;i++) pixels[i] = new Pixel[width];
    for(int i=0;i<im.height;i++)
        for(int j=0;j<im.width;j++)
            pixels[i][j]=im.pixels[i][j];
}

Imagine Imagine::operator=(Imagine im){
    type=im.type;
    width=im.width;
    height=im.height;
    pixels = new Pixel*[height];
    for(int i=0;i<height;i++) pixels[i] = new Pixel[width];

    for(int i=0;i<im.height;i++)
        for(int j=0;j<im.width;j++)
            pixels[i][j]=im.pixels[i][j];

    return* this;
}


int Imagine::get_width(){
    return width;
}

int Imagine::get_height(){
    return height;
}

char Imagine::get_type(){
    return type;
}

Pixel Imagine::get_pixel(int i,int j){
    return pixels[i][j];
}

void Imagine::set_pixel(int x,int y,Pixel p){
    pixels[y][x]=p;
}

void Imagine::rotire(double s, double c){
    int maxi;
    if(height>width) maxi=height; else maxi=width;
    Pixel** aux = new Pixel*[maxi];
    for(int i=0;i<height;i++) aux[i]=new Pixel[maxi];
    Pixel nul;
    nul.set_type(type);
    nul.set_value(0,0,0,0,0);
    int midx;
    int midy;
    midx = width/2;
    midy = height/2;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
                if((int)(midy+(j-midx)*s+(i-midy)*c + 0.5)>0 && (int)(midy+(j-midx)*s+(i-midy)*c + 0.5)<height)
                if((int)(midx+(j-midx)*c-(i-midy)*s + 0.5)-1>0 && (int)(midx+(j-midx)*c-(i-midy)*s + 0.5)-1<width)
                    aux[i][j]=pixels[(int)(midy+(j-midx)*s+(i-midy)*c + 0.5)]
                    [(int)(midx+(j-midx)*c-(i-midy)*s + 0.5)-1 ];

            }
        }
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            pixels[i][j]=aux[i][j];
        }}
}
