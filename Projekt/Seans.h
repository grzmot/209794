#ifndef Seans_h
#define Seans_h
#include "Film.h"
#include "Sala.h"
class Seans : public Film
{
    int nr_sala;
    static int couter;
public:
    Seans();
    Seans(string titels, int times,char typ,int age,int nr_sala);
    ~Seans();
    
    static int get_couter();
    
    void set_nr_sala(int nr_sala);
    int get_nr_sala();
};
#endif
