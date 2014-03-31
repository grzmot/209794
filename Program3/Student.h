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
        Student(int w, char p, string i, string n, int *t, int numer_ind,int semestr, string kierunek,string wydzial);
        static int ilosc(); 
        void set_numer(int nr);
        void set_semestr(int sr);
        void set_kierunek(string kk);
        void set_wydzial(string wl);
        int get_numer();
        int get_semestr();
        string get_kierunek();
        string get_wydzial();
        ~Student();
};
#endif
