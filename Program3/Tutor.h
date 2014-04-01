#ifndef Tutor_h
#define Tutor_h
#include "Human.h"

class Tutor:protected Human
{
    string tytul_naukowy;
    int liczba_poblikacji;
public:
    Tutor();
    Tutor(int wiek, char plec, string imie, string nazwisko, int size, string tytul_naukowy, int liczba_poblikacji);
    Tutor(string imie, string nazwisko, string tytul_naukowy);
    ~Tutor();
        
    static int counter();
        
    void set_tytul(string ztytul);
    void set_liczba(int zpublikacje);
    string get_tytyl();
    int get_liczba();       
};
#endif
