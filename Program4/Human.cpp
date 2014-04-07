#include "Human.h"

int Human::couter=0;
int Human::counter()
{
    return couter;
}

Human::Human()
{
    wiek=0;
    plec='n';
    imie="";
    nazwisko="";
    couter++;
    favorite_books= new string[0];
}
Human::Human(int wiek, char plec, string imie, string nazwisko, int size):
    wiek(wiek),
    plec(plec),
    imie(imie),
    nazwisko(nazwisko),
    size(size)
{
    favorite_books= new string[size];
    couter++;
}
Human::Human(string imie, string nazwisko):
    imie(imie),nazwisko(nazwisko)
{
    couter++;
    favorite_books= new string[0];
}
Human::~Human()
{
    couter--;
    delete []favorite_books;
}

int Human::get_wiek()
{
    return wiek;
}
char Human::get_plec()
{
    return plec;
}
string Human::get_imie()
{
    return imie;
}
string Human::get_nazwisko()
{
    return nazwisko;
}
void Human::set_wiek(int w)
{
    wiek=w;
}
void Human::set_plec(char p)
{
    plec=p;
}
void Human::set_imie(string i)
{
    imie=i;
}
void Human::set_nazwisko(string n)
{
    nazwisko=n;
}

ostream& operator<< (ostream &output, Human const& human)
{
   output << "Imie: " << human.imie <<endl<< "Nazwisko: " << human.nazwisko << endl;
   return output;
}
istream& operator>> (istream &input, Human& human)
{
   input >> human.imie >> human.nazwisko;
   return input;
}
