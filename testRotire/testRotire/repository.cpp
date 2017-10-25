#include "repository.h"

Repository::Repository(){
    current=0;
    maxim=20;
    container = new Imagine[maxim];
}

Repository::Repository(const Repository &r){
    current=r.current;
    maxim=r.maxim;
    container=new Imagine[maxim];
    for(int i=0;i<current;i++)
        container[i]=r.container[i];
}

Repository::~Repository(){
    current=0;
    maxim=0;
    delete[] container;
}

int Repository::get_current(){
    return current;
}

int Repository::get_maxim(){
    return maxim;
}

Imagine& Repository::operator[](int n){
    return container[n];
}

Repository Repository::operator=(Repository r){
    current=r.get_current();
    maxim=r.get_maxim();
    container = new Imagine[maxim];
    for (int i=0;i<current;i++){
        container[i]=r.container[i];
    }
    return r;
}

/*bool Repository::operator==(Repository r){
    if(current!=r.current) return false;
    if(maxim!=r.maxim) return false;
    for(int i=0;i<current;i++){
        if(!(container[i]==r.container[i])) return false;
    }
    return true;
}*/

void Repository::adauga(char t,int** p,int w,int h){
    Imagine i(t,p,w,h);
    container[current]=i;
    current+=1;
}

void Repository::sterge(int n){
    for (int i=n-1;i<current-1;i++){
        container[i]=container[i+1];
    }
    current--;
}

void Repository::rotire(int i, double s, double c){
    container[i].rotire(s,c);
}
