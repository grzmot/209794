#ifndef Student_h
#define Student_h
#include "Human.h"
#include <string>
#include "Interface.h"
using namespace std;
class Student : public Human, public Interface
{
    int numer_ind;
    int semestr;
    string direction;
    string department;
    string *mark;
    int size;
public:
    Student();
    Student(int age, char sex, string first_name, string surname, int size_human, int numer_ind,int semestr, string direction,string department, int size);
    Student(string first_name, string surname, int size, int numer_ind, int size);
    ~Student();
    
    static int counter();

    virtual void birthday();
    virtual void klasa();
    virtual bool operator <(Interface& d)const;
    
    void set_numer_ind(int number);
    void set_semestr(int zsemestr);
    void set_direction(string direction);
    void set_department(string department);
    int get_numer_ind();
    int get_semestr();
    string get_direction();
    string get_department();
    friend ostream& operator<< (ostream&,Student const&);
    friend istream& operator>> (istream&,Student&);
};
#endif
