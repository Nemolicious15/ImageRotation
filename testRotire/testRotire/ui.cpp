#include <iostream>
#include <fstream>
#include "ui.h"
#include "mexception.h"

using namespace std;

UI::UI(){
    meniu_1();
}

//UI::UI(const UI& u){
//    cont=u.cont;
//}

UI::~UI(){

}

Controller UI::get_controller(){
    return cont;
}

void UI::set_controller(Controller c){
    cont=c;
}

void UI::citeste(char* f){
    ifstream imagini;
    imagini.open(f);
    if(!imagini) throw MException("Fisier corupt!");

    int num;
    imagini>>num;
    for(int k=0;k<num;k++){
        if(imagini.eof()) break;
        char t;
        int w;
        int h;
        int** p;
        imagini>>t>>w>>h;
        try{
            validate_twh(t,w,h);
        }catch(MException& e) {
        cout<<e.getMessage();
        }
            p = new int*[h];
            if(t!='c'){
                for(int i=0;i<h;i++) p[i]=new int[w];
                for(int i=0;i<h;i++)
                    for(int j=0;j<w;j++)
                        if(!imagini.eof()) imagini>>p[i][j];
                        else p[i][j]=0;
            } else {
                for(int i=0;i<h;i++) p[i]=new int[w*3];
                for(int i=0;i<h;i++)
                    for(int j=0;j<w*3;j++)
                        if(!imagini.eof()) imagini>>p[i][j];
                        else p[i][j]=0;
        }
        try{
            validate_mat(t,p,w,h);
        } catch(MException& e) {
        cout<<e.getMessage();
        }
        cont.add_img(t,p,w,h);

    }
    imagini.close();
    cout<<"Citirea matricilor din fisier a fost efectuata cu succes.";
}

void UI::afiseaza(int i){
    int w = cont.get_img(i).get_width();
    int h = cont.get_img(i).get_height();
    char t = cont.get_img(i).get_type();
    if(t=='n'){
        for(int j=0;j<h;j++){
        cout<<endl;
        for(int k=0;k<w;k++)
            cout<<cont.get_img(i).get_pixel(j,k).get_negru();
        }
    } else if(t=='g'){
        for(int j=0;j<h;j++){
        cout<<endl;
        for(int k=0;k<w;k++)
            cout<<cont.get_img(i).get_pixel(j,k).get_gri();
        }
    } else if(t=='c'){
        for(int j=0;j<h;j++){
        cout<<endl;
        for(int k=0;k<w;k++)
            cout<<"("<<cont.get_img(i).get_pixel(j,k).get_r()<<","<<
            cont.get_img(i).get_pixel(j,k).get_g()<<","<<
            cont.get_img(i).get_pixel(j,k).get_b()<<")";
        }
    }
    cout<<endl;

}

void UI::meniu_1(){
    try{
        citeste("test.txt");
    } catch(MException& e) {
        cout<<e.getMessage();
    }
    int x=-1;
    int i=0;
    double t=0;
    while (x!=0){
		cout << endl;
		cout << "___________________________________"<<endl;
        cout<<"Introduceti numarul operatiei dorite:"<<endl;
        cout<<"1: Afiseaza"<<endl;
        cout<<"2: Roteste"<<endl;
        cout<<"0: Exit"<<endl;
        cout<<"Operatia aleasa: ";
        cin>>x;
        //cout<<endl;
        if(x==1){
                cout<<"Introduceti numarul imaginii =(de la 0 la "<<cont.get_repo().get_current()-1<<")=: ";
                cin>>i;
                if(i<0 || i>cont.get_repo().get_current()-1)
                    cout<<"Numarul introdus este incorect!";
                else
                    afiseaza(i);
        } else
        if(x==2){
                cout<<"Introduceti numarul imaginii =(0-"<<cont.get_repo().get_current()-1<<")=: ";
                cin>>i;
                if(i<0 || i>cont.get_repo().get_current()-1)
                    cout<<"Numarul introdus este incorect!";
                else{
                    cout<<"Introduceti unghiul: ";
                    cin>>t;
                    cont.rotire(i,t);
                }
        } else
        if(x<0 || x>2) cout<<"Numarul introdus este incorect, optiune inexistenta!";
    }
}

void UI::validate_twh(char& t,int& w, int& h){
    if(t!='c' && t!='n' && t!='g') throw MException("Tip incorect!");
    if(w<0) throw MException("Numar de coloane incorect! (<0)");
    if(h<0) throw MException("Numar de randuri incorect! (<0)");
}


void UI::validate_mat(char t,int** p,int w,int h){
    if(t=='n'){
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++)
                if(p[i][j]!=0 && p[i][j]!=1) throw MException("Matrice incorecta, nu este de tip bool!");
    }
}
