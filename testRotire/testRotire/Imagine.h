#ifndef IMAGINE_H_INCLUDED
#define IMAGINE_H_INCLUDED
#include "pixel.h"

class Imagine{

private:
    Pixel** pixels;
    int width;
    int height;
    char type;
public:
    Imagine();
    Imagine(char t,int**,int,int);
    Imagine(Imagine&);
    Imagine operator=(Imagine);
    int get_width();
    int get_height();
    char get_type();
    Pixel get_pixel(int,int);
    void set_pixel(int,int,Pixel);
    void rotire(double,double);
};

#endif // IMAGINE_H_INCLUDED
