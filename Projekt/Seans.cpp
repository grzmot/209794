#include "Seans.h"

int Seans::couter=0;

Seans::Seans():Film()
{
    nr_sala=0;
}
Seans::Seans(string titels,int times,char typ,int age,int nr_sala):Film(titels,time,typ,age),nr_sala(nr_sala)
{
}
Seans::~Seans()
{
    delete sala;
}

int Seans::get_couter()
{
    return couter;
}

void Seans::set_nr_sala(int nr_sala)
{
    this->nr_sala=nr_sala;
}
int Seans::get_nr_sala()
{
    return nr_sala;
}

