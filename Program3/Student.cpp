#include "Student.h"


Student::Student():Human()
{
    cout<<"konstruktor Student"<<endl<<" obiektow:"<<Student::counter()<<endl;
}
Student::Student(int wiek, char plec, string imie, string nazwisko, int size, int numer_ind,int semestr, string kierunek,string wydzial):
    Human(wiek,plec,imie,nazwisko,size),
    numer_ind(numer_ind),
    semestr(semestr),
    kierunek(kierunek),
    wydzial(wydzial)
{
    cout<<"konstruktor Student"<<endl<<" obiektow:"<<Student::counter()<<endl;
}
Student::Student(string imie, string nazwisko,int numer_ind):
    Human(imie,nazwisko),
    numer_ind(numer_ind)
{
    cout<<"konstruktor Student"<<endl<<" obiektow:"<<Student::counter()<<endl;
}
Student::~Student()
{
    cout<<"destruktor Student"<<endl<<" obiektow:"<<Student::counter()<<endl;
}


int Student::counter()
{
    return Human::counter();
}


void Student::set_numer(int number)
{
    numer_ind=number;
}
void Student::set_semestr(int zsemestr)
{
    semestr=zsemestr;
}
void Student::set_kierunek(string zkierunek)
{
    kierunek=zkierunek;
}
void Student::set_wydzial(string zwydzial)
{
    wydzial=zwydzial;
}
int Student::get_numer()
{
    return numer_ind;
}
int Student::get_semestr()
{
    return semestr;
}
string Student::get_kierunek()
{
    return kierunek;
}
string Student::get_wydzial()
{
    return wydzial;
}
