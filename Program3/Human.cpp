#include "Human.h"
int Human::licznik=0;
Human::Human(){wiek=0; plec='n'; imie=""; nazwisko="";licznik++;}
Human::Human(int w, char p, string i, string n, int *t){wiek=w; plec=p; imie=i; nazwisko=n;tab=t;licznik++;cout<<"konstruktor Human-obiektu:"<<Human::ilosc()<<endl;}
int Human::get_wiek(){return wiek;}
char Human::get_plec(){return plec;}
string Human::get_imie(){return imie;}
string Human::get_nazwisko(){return nazwisko;}
void Human::set_wiek(int w){wiek=w;}
void Human::set_plec(char p){plec=p;}
void Human::set_imie(string i){imie=i;}
void Human::set_nazwisko(string n){nazwisko=n;}
int Human::ilosc() {return licznik;}
Human::~Human(){cout<<"destr Human-obiektu:"<<Human::ilosc()<<endl;licznik--;}
