#include "Student.h"

Student::Student():Human(){};
Student::Student(int w, char p, string i, string n, int *t, int numer_ind,int semestr, string kierunek,string wydzial):Human(w,p,i,n,t), numer_ind(numer_ind), semestr(semestr), kierunek(kierunek), wydzial(wydzial){cout<<"konstruktor Student-obiektu:"<<Student::ilosc()<<endl;};
void Student::set_numer(int nr){numer_ind=nr;};
void Student::set_semestr(int sr){semestr=sr;};
void Student::set_kierunek(string kk){kierunek=kk;};
void Student::set_wydzial(string wl){wydzial=wl;};
int Student::get_numer(){return numer_ind;};
int Student::get_semestr(){return semestr;};
string Student::get_kierunek(){return kierunek;};
string Student::get_wydzial(){return wydzial;};
Student::~Student(){cout<<"destr Student-obiektu:"<<Student::ilosc()<<endl;};
int Student::ilosc() {return Human::ilosc();}
