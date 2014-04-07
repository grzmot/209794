#include "Student2.h"

Student2::Student2():Student()
{
    degree="";
    average=new double[1];
}
Student2::Student2(int wiek, char plec, string imie, string nazwisko, int size_human, int numer_ind,int semestr, string kierunek,string wydzial, int size_student, string degree, int size):
    Student(wiek,plec,imie,nazwisko,size_human,numer_ind,semestr,kierunek,wydzial,size_student),
    degree(degree),
    size(size)
{
    average=new double[size];
}
Student2::Student2(string imie, string nazwisko, int numer_ind, string degree,int size):
    Student(imie,nazwisko,numer_ind),
    degree(degree),
    size(size)
{
    average=new double[size];
}

Student2::~Student2()
{
    delete []average;
}


void Student2::set_degree(string zdegree)
{
    degree=zdegree;
}
void Student2::set_average(double taverage[])
{
    for (int i=0;i<size;i++)
        average[i]=taverage[i];
}
void Student2::get_average(double taverage[])
{
    for (int i=0;i<size;i++)
        taverage[i]=average[i];
}
string Student2::get_degree()
{
    return degree;
}


ostream& operator<< (ostream &output, Student2 const& student2)
{
   output <<static_cast<const Student&>( student2 )<< "Stopien: " << student2.degree <<endl;
   return output;
}
istream& operator>> (istream &input, Student2& student2)
{
   input >>static_cast<Student&>( student2 )>>student2.degree;
   return input;
}
