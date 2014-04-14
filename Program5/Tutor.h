#ifndef Tutor_h
#define Tutor_h
#include "Human.h"
#include <string>

class Tutor:public Human
{
    string academic_title;
    int number_of_publications;
public:
    Tutor();
    Tutor(int wiek, char plec, string imie, string surname, int size, string academic_title, int number_of_publications);
    Tutor(string imie, string surname, int size, string academic_title);
    ~Tutor();
        
    static int counter();
        
    virtual void klasa();
        
    void set_tytul(string ztytul);
    void set_liczba(int zpublikacje);
    string get_tytyl();
    int get_liczba();
    friend ostream& operator<< (ostream&,Tutor const&); 
    friend istream& operator>> (istream&,Tutor&);      
};
#endif
