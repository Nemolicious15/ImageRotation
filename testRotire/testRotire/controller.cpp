#include <math.h>
#include "controller.h"

Controller::Controller(){
}

Controller::Controller(Repository ri){
    repo=ri;
}

Controller::Controller(Controller& c){
    repo=c.repo;
}

Controller::~Controller(){
}

Controller Controller::operator=(Controller c){
    repo=c.repo;
	return *this;
}

Repository Controller::get_repo(){
    return repo;
}

void Controller::set_repo(Repository r){
    repo=r;
}

void Controller::add_img(char t,int** p,int w,int h){
    repo.adauga(t,p,w,h);
}

Imagine Controller::get_img(int i){
    return repo[i];
}

void Controller::rotire(int i, double tetha){
    double pi=3.1415;
    double s =sin(tetha*pi/180.0);
    double c =cos(tetha*pi/180.0);
    repo.rotire(i,s,c);

}
