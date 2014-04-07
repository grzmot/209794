#ifndef Student2_h
#define Student2_h
#include "Student.h"
using namespace std;
class Student2 : protected Student
{
    string degree;
    double *average;
    int size;
public:
    Student2();
    Student2(int wiek, char plec, string imie, string nazwisko, int size_human, int numer_ind,int semestr, string kierunek,string wydzial, int size_student, string degree,int size);
    Student2(string imie, string nazwisko, int numer_ind, string degree,int size);
    ~Student2();
    
    void set_degree(string zdegree);
    void set_average(double taverage[]);
    void get_average(double taverage[]);
    string get_degree();
    friend ostream& operator<< (ostream&,Student2 const&);
    friend istream& operator>> (istream&,Student2&);    
};
#endif
