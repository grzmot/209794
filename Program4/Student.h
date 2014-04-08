#ifndef Student_h
#define Student_h
#include "Human.h"
using namespace std;
class Student : protected Human
{
    int numer_ind;
    int semestr;
    string direction;
    string department;
    string *mark;
    int size;
public:
    Student();
    Student(int age, char plec, string first_name, string surname, int size_human, int numer_ind,int semestr, string direction,string department, int size);
    Student(string first_name, string surname, int size, int numer_ind, int size);
    ~Student();
    
    static int counter(); 
    
    void set_age(int age);
    void set_first_name(string first_name);
    void set_surmane(string surname);
    void set_plec(char plec);
    void set_numer_ind(int number);
    void set_semestr(int semestr);
    void set_direction(string direction);
    void set_department(string department);
    int get_age();
    string get_first_name();
    string get_surmane();
    char get_plec();
    int get_numer_ind();
    int get_semestr();
    string get_direction();
    string get_department();
    friend ostream& operator<< (ostream&,Student const&);
    friend istream& operator>> (istream&,Student&);
};
#endif
