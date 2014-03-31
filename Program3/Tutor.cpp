#include "Tutor.h"

Tutor::Tutor():Human(){};
Tutor::Tutor(int w, char p, string i, string n, int *t, string tytul_naukowy, int liczba_poblikacji):Human(w,p,i,n,t), tytul_naukowy(tytul_naukowy), liczba_poblikacji(liczba_poblikacji){cout<<"konstruktor Tutor-obiektu:"<<Tutor::ilosc()<<endl;};
void Tutor::set_tytul(string tl){tytul_naukowy=tl;};
void Tutor::set_liczba(int sm){liczba_poblikacji=sm;};
string Tutor::get_tytyl(){return tytul_naukowy;};
int Tutor::get_liczba(){return liczba_poblikacji;};
Tutor::~Tutor(){cout<<"destr Tutor-obiektu:"<<Tutor::ilosc()<<endl;};
int Tutor::ilosc() {return Human::ilosc();}
