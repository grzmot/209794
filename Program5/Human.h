#ifndef Human_h
#define Human_h
#include <string>
#include <iostream>
#include "Mama1.h"

using namespace std;
class Human : public Mama1
{
    int age;
    char sex;
    string first_name;
    string surname;
    string *favorite_books;
    int size;
    static int couter;
public:
    Human();
    Human(int age, char sex, string first_name, string surname, int size);
    Human(string first_name, string surname,int size);
    virtual ~Human();
        
    static int counter();
    
    virtual void birthday();
    virtual void klasa();
    
    void pola();
    int get_age();
    char get_sex();
    string get_first_name();
    string get_surname();
    void set_age(int age);
    void set_sex(char sex);
    void set_first_name(string first_name);
    void set_surname(string surname);
    friend ostream& operator<< (ostream&,Human const&);
    friend istream& operator>> (istream&,Human&);
};
#endif
