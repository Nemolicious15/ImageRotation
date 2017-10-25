#ifndef REPOSITORY_H_INCLUDED
#define REPOSITORY_H_INCLUDED
#include "Imagine.h"

class Repository{
private:
    Imagine* container;
    int current;
    int maxim;
public:
    Repository();
    Repository(const Repository&);
    ~Repository();
    int get_current();
    int get_maxim();
    Imagine& operator[](int);
    Repository operator=(Repository);
    bool operator==(Repository);
    void adauga(char,int**,int,int);
    void sterge(int);
    void rotire(int,double,double);
};

#endif // REPOSITORY_H_INCLUDED
