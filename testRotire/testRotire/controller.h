#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include "repository.h"
#include "imagine.h"

class Controller{

private:
    Repository repo;
public:
    Controller();
    Controller(Repository ri);
    Controller(Controller&);
    ~Controller();
    Controller operator=(Controller);
    Repository get_repo();
    void set_repo(Repository);
    void add_img(char,int**,int,int);
    Imagine get_img(int);
    void rotire(int, double);

};

#endif // CONTROLLER_H_INCLUDED
