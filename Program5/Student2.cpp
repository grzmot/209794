#include "Student2.h"

Student2::Student2():Student()
{
    degree="";
    size=0;
    average=new double[size];
}
Student2::Student2(int age, char plec, string first_name, string surname, int size_human, int numer_ind,int semestr, string direction,string department, int size_student, string degree):
    Student(age,plec,first_name,surname,size_human,numer_ind,semestr,direction,department,size_student),
    degree(degree), size(semestr-1)
{
    average=new double[size];
}
Student2::Student2(string first_name, string surname, int size_human, int numer_ind, int size_student, string degree, int size):
    Student(first_name,surname,size_human,numer_ind,size_student),
    degree(degree),
    size(size)
{
    average=new double[size];
}

Student2::~Student2()
{
    delete []average;
}

void Student2::pola()
{
    cout<<"Pola wlasne klasy Student2:"<<endl<<" Tytul, srednie z minionych semestrow"<<endl;
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
   output <<static_cast<const Student&>( student2 )<<endl<< "Stopien: "<< student2.degree <<endl<<"Srednie: ";
   for(int i=0;i<student2.size;i++)
        output<<student2.average[i]<<" ";
   return output;
}
istream& operator>> (istream &input, Student2& student2)
{
   input>>static_cast<Student&>(student2);
   cout<<endl<<"Stopien: ";
   input>>student2.degree;
   student2.size=student2.get_semestr()-1;
   delete [] student2.average;
   student2.average= new double[student2.size];
   for (int i=0;i<student2.size;i++)
   {
        cout<<"Srednia za semestr "<<i+1<<": ";
        input>>student2.average[i];
    }
   return input;
}
