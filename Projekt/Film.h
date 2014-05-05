#ifndef Film_h
#define Film_h

#include <string>

class Film
{
    string titels;
    int times;
    char typ;
    int age;
    
public:
    Film();
    Film(string titels,int time,char typ, int age);
    virtual ~Film();
    
    void set_titels(string titels);
    void set_time(int times);
    void set_typ (char typ);
    void set_age (int age);
    string get_titels();
    int get_time();
    char get_typ();
    int get_age();
    
};
#endif
