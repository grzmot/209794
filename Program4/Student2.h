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
    Student2(int age, char plec, string first_name, string surname, int size_human, int numer_ind,int semestr, string direction,string department, int size_student, string degree);
    Student2(string imie, string surname, int size_human, int numer_ind, int size_student, string degree,int size);
    ~Student2();
    
    void set_degree(string zdegree);
    void set_average(double taverage[]);
    void set_age(int age);
    void set_first_name(string first_name);
    void set_surmane(string surname);
    void set_plec(char plec);
    void set_numer_ind(int numer_ind);
    void set_semestr(int semestr);
    void set_direction(string direction);
    void set_department(string department);
    void get_average(double taverage[]);
    int get_age();
    string get_first_name();
    string get_surmane();
    char get_plec();
    int get_numer_ind();
    int get_semestr();
    string get_direction();
    string get_department();
    string get_degree();
    friend ostream& operator<< (ostream&,Student2 const&);
    friend istream& operator>> (istream&,Student2&);    
};
#endif
