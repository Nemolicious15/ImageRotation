#ifndef PIXEL_H_INCLUDED
#define PIXEL_H_INCLUDED

class Pixel{

private:
    bool negru;
    int gri;
    int r;
    int g;
    int b;
    char type;
public:
    Pixel();
    Pixel(bool);
    Pixel(int);
    Pixel(int, int, int);
    Pixel(Pixel&);
    ~Pixel();
    Pixel operator=(Pixel);
    bool operator==(Pixel);
    char get_type();
    void set_type(char);
    void set_value(bool,int,int,int,int);
    bool get_negru();
    int get_gri();
    int get_r();
    int get_g();
    int get_b();
};

#endif // PIXEL_H_INCLUDED
