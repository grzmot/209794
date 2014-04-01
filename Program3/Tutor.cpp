#include "Tutor.h"

Tutor::Tutor():Human()
{
    cout<<"konstruktor Tutor"<<endl<<" obiektow:"<<Tutor::counter()<<endl;
}
Tutor::Tutor(int wiek, char plec, string imie, string nazwisko, int size, string tytul_naukowy, int liczba_poblikacji):
    Human(wiek,plec,imie,nazwisko,size),
    tytul_naukowy(tytul_naukowy),
    liczba_poblikacji(liczba_poblikacji)
{
    cout<<"konstruktor Tutor"<<endl<<" obiektow:"<<Tutor::counter()<<endl;
}
Tutor::Tutor(string imie, string nazwisko, string tytul_naukowy):
    Human(imie,nazwisko),
    tytul_naukowy(tytul_naukowy)
{
    cout<<"konstruktor Tutor"<<endl<<" obiektow:"<<Tutor::counter()<<endl;
}
Tutor::~Tutor()
{
    cout<<"destruktor Tutor"<<endl<<" obiektow:"<<Tutor::counter()<<endl;
}


int Tutor::counter()
{
    return Human::counter();
}


void Tutor::set_tytul(string ztytul)
{
    tytul_naukowy=ztytul;
}
void Tutor::set_liczba(int zpublikacje)
{
    liczba_poblikacji=zpublikacje;
}
string Tutor::get_tytyl()
{
    return tytul_naukowy;
}
int Tutor::get_liczba()
{
    return liczba_poblikacji;
}
