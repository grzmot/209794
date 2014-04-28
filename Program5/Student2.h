#ifndef Student2_h
#define Student2_h
#include "Student.h"
#include <string>
using namespace std;
class Student2 : public Student
{
    string degree;
    double *average;
    int size;
public:
    Student2();
    Student2(int age, char sex, string first_name, string surname, int size_human, int numer_ind,int semestr, string direction,string department, int size_student, string degree);
    Student2(string imie, string surname, int size_human, int numer_ind, int size_student, string degree,int size);
    ~Student2();
    
    void pola();
    void set_degree(string zdegree);
    void set_average(double taverage[]);
    void get_average(double taverage[]);
    string get_degree();
    friend ostream& operator<< (ostream&,Student2 const&);
    friend istream& operator>> (istream&,Student2&);    
};
#endif
