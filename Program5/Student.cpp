#include "Student.h"


Student::Student():Human()
{
    numer_ind=0;
    semestr=0;
    direction="";
    department="";
    size=0;
    mark= new string[size];
}
Student::Student(int age, char plec, string first_name, string surname, int size_human, int numer_ind,int semestr, string direction,string department, int size):
    Human(age,plec,first_name,surname,size_human),
    numer_ind(numer_ind),
    semestr(semestr),
    direction(direction),
    department(department),
    size(size)
{
    mark= new string[size];
}
Student::Student(string first_name, string surname, int size_human, int numer_ind, int size):
    Human(first_name,surname,size_human),
    numer_ind(numer_ind), size(size)
{
    mark= new string[size];
    semestr=0;
    direction="";
    department="";
}
Student::~Student()
{
    delete []mark;
}

void Student::birthday()
{
    cout<<"Student, semestr "<<semestr<<endl;
}
void Student::klasa()
{
    cout<<"Klasa Student"<<endl;
}
bool Student::operator <(Interface& d)const
{
    Student s=dynamic_cast<Student&>(d);
    return numer_ind<s.numer_ind;
}
int Student::counter()
{
    return Human::counter();
}

void Student::set_numer_ind(int number)
{
    numer_ind=number;
}
void Student::set_semestr(int zsemestr)
{
    semestr=zsemestr;
}
void Student::set_direction(string zdirection)
{
    direction=zdirection;
}
void Student::set_department(string zdepartment)
{
    department=zdepartment;
}

int Student::get_numer_ind()
{
    return numer_ind;
}
int Student::get_semestr()
{
    return semestr;
}
string Student::get_direction()
{
    return direction;
}
string Student::get_department()
{
    return department;
}

ostream& operator<< (ostream &output, Student const& student)
{
   output <<static_cast<const Human&>(student)<<endl<<"Numer indeksu: "<< student.numer_ind <<endl;
   output <<"semestr: "<<student.semestr<<endl<<"Kierunek: "<<student.direction<<endl<<"Wydzial: "<<student.department<<endl<<"oceny: ";
   for(int i=0;i<student.size;i++)
        output<<student.mark[i]<<" ";
   return output;
}
istream& operator>> (istream &input, Student& student)
{
   input >>static_cast<Human&>(student);
   cout<<endl<<"Numer Indeksu: ";
   input>>student.numer_ind;
   cout<<"Semestr: ";
   input>>student.semestr;
   cout<<"Kierunek: ";
   input>>student.direction;
   cout<<"Wydzial: ";
   input>>student.department;
   cout<<"ilosc ocen: ";
   input>>student.size;
   delete [] student.mark;
   student.mark=new string [student.size];
   for (int i=0;i<student.size;i++)
   {
        cout<<"ocena "<<i+1<<": ";
        input>>student.mark[i];
    }
   return input;
}
