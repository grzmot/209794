#ifndef Human_h
#define Human_h
#include <string>
#include <iostream>
using namespace std;
class Human
{
    int wiek;
    char plec;
    string imie, nazwisko;
    int *tab;
    static int licznik;
    public:
        Human();
        Human(int w, char p, string i, string n, int *t);
        int get_wiek();
        char get_plec();
        string get_imie();
        string get_nazwisko();
        void set_wiek(int w);
        void set_plec(char p);
        void set_imie(string i);
        void set_nazwisko(string n); 
        static int ilosc();
        ~Human();
    
};
#endif
