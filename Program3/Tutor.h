#ifndef Tutor_h
#define Tutor_h
#include "Human.h"

class Tutor:protected Human
{
    string tytul_naukowy;
    int liczba_poblikacji;
    public:
        Tutor();
        Tutor(int w, char p, string i, string n, int *t, string tytul_naukowy, int liczba_poblikacji);
        void set_tytul(string tl);
        void set_liczba(int sm);
        string get_tytyl();
        int get_liczba();
        static int ilosc(); 
        ~Tutor();
};
#endif
