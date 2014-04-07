#include "Student.h"


Student::Student():Human()
{
    numer_ind=0;
    semestr=0;
    kierunek="";
    wydzial="";
    size=0;
    tab= new string[1];
}
Student::Student(int wiek, char plec, string imie, string nazwisko, int size_human, int numer_ind,int semestr, string kierunek,string wydzial, int size):
    Human(wiek,plec,imie,nazwisko,size_human),
    numer_ind(numer_ind),
    semestr(semestr),
    kierunek(kierunek),
    wydzial(wydzial),
    size(size)
{
    tab= new string[size];
}
Student::Student(string imie, string nazwisko,int numer_ind):
    Human(imie,nazwisko),
    numer_ind(numer_ind)
{
    tab= new string[0];
}
Student::~Student()
{
    delete []tab;
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

ostream& operator<< (ostream &output, Student const& student)
{
   output <<static_cast<const Human&>( student )<< "Numer indeksu: " << student.numer_ind <<endl;
   return output;
}
istream& operator>> (istream &input, Student& student)
{
   input >>static_cast<Human&>(student)>>student.numer_ind;
   return input;
}
