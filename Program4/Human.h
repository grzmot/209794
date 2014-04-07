#ifndef Human_h
#define Human_h
#include <string>
#include <iostream>
using namespace std;
class Human
{
    int wiek;
    char plec;
    string imie;
    string nazwisko;
    string *favorite_books;
    int size;
    static int couter;
public:
    Human();
    Human(int wiek, char plec, string imie, string nazwisko, int size);
    Human(string imie, string nazwisko);
    virtual ~Human();
        
    static int counter();
       
    int get_wiek();
    char get_plec();
    string get_imie();
    string get_nazwisko();
    void set_wiek(int w);
    void set_plec(char p);
    void set_imie(string i);
    void set_nazwisko(string n);
    friend ostream& operator<< (ostream&,Human const&);
    friend istream& operator>> (istream&,Human&);
};
#endif
