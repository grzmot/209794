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
}
Student::~Student()
{
    delete []mark;
}


int Student::counter()
{
    return Human::counter();
}

void Student::set_age(int age)
{
    Human::set_age(age);
}
void Student::set_first_name(string first_name)
{
    Human::set_first_name(first_name);
}
void Student::set_surmane(string surname)
{
    Human::set_surname(surname);
}
void Student::set_plec(char plec)
{
    Human::set_plec(plec);
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

int Student::get_age()
{
    return Human::get_age();
}
string Student::get_first_name()
{
    return Human::get_first_name();
}
string Student::get_surmane()
{
    return Human::get_surname();
}
char Student::get_plec()
{
    return Human::get_plec();
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
   output <<static_cast<const Human&>(student)<<"Numer indeksu: "<< student.numer_ind <<endl;
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
