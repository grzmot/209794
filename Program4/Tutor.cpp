#include "Tutor.h"

Tutor::Tutor():Human()
{
    tytul_naukowy="";
    liczba_poblikacji=0;
}
Tutor::Tutor(int wiek, char plec, string imie, string nazwisko, int size, string tytul_naukowy, int liczba_poblikacji):
    Human(wiek,plec,imie,nazwisko,size),
    tytul_naukowy(tytul_naukowy),
    liczba_poblikacji(liczba_poblikacji)
{}
Tutor::Tutor(string imie, string nazwisko, string tytul_naukowy):
    Human(imie,nazwisko),
    tytul_naukowy(tytul_naukowy)
{}
Tutor::~Tutor()
{}


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

ostream& operator<< (ostream &output, Tutor const& tutor)
{
   output <<static_cast<const Human&>( tutor )<< "Tytul naukowy: " << tutor.tytul_naukowy <<endl;
   return output;
}
istream& operator>> (istream &input, Tutor& tutor)
{
   input >>static_cast<Human&>( tutor )>>tutor.tytul_naukowy;
   return input;
}
