#ifndef Student_h
#define Student_h
#include "Human.h"
using namespace std;
class Student : protected Human
{
    int numer_ind;
    int semestr;
    string kierunek;
    string wydzial;
public:
    Student();
    Student(int wiek, char plec, string imie, string nazwisko, int size, int numer_ind,int semestr, string kierunek,string wydzial);
    Student(string imie, string nazwisko,int numer_ind);
    ~Student();
    
    static int counter(); 
    
    void set_numer(int number);
    void set_semestr(int semestr);
    void set_kierunek(string kierunek);
    void set_wydzial(string wydzial);
    int get_numer();
    int get_semestr();
    string get_kierunek();
    string get_wydzial();
};
#endif
