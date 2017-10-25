#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED
#include "controller.h"

class UI{
private:
    Controller cont;
public:
    UI();
    UI(const UI&);
    ~UI();
    Controller get_controller();
    void set_controller(Controller);
    void citeste(char*);
    void afiseaza(int);
    void meniu_1();
    void validate_twh(char&,int&,int&);
    void validate_mat(char,int**,int,int);

};

#endif // UI_H_INCLUDED
