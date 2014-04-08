#ifndef Human_h
#define Human_h
#include <string>
#include <iostream>
using namespace std;
class Human
{
    int age;
    char plec;
    string first_name;
    string surname;
    string *favorite_books;
    int size;
    static int couter;
public:
    Human();
    Human(int age, char plec, string first_name, string surname, int size);
    Human(string first_name, string surname,int size);
    virtual ~Human();
        
    static int counter();
    
    int get_age();
    char get_plec();
    string get_first_name();
    string get_surname();
    void set_age(int age);
    void set_plec(char plec);
    void set_first_name(string first_name);
    void set_surname(string surname);
    friend ostream& operator<< (ostream&,Human const&);
    friend istream& operator>> (istream&,Human&);
};
#endif
