#include "Tutor.h"

Tutor::Tutor():Human()
{
    academic_title="";
    number_of_publications=0;
}
Tutor::Tutor(int age, char sex, string first_name, string surname, int size, string academic_title, int number_of_publications):
    Human(age,sex,first_name,surname,size),
    academic_title(academic_title),
    number_of_publications(number_of_publications)
{}
Tutor::Tutor(string first_name, string surname, int size, string academic_title):
    Human(first_name,surname,size),
    academic_title(academic_title)
{}
Tutor::~Tutor()
{}


int Tutor::counter()
{
    return Human::counter();
}

void Tutor::klasa()
{
    cout<<"klasa Tutor"<<endl;
}
void Tutor::set_tytul(string ztytul)
{
    academic_title=ztytul;
}
void Tutor::set_liczba(int zpublikacje)
{
    number_of_publications=zpublikacje;
}
string Tutor::get_tytyl()
{
    return academic_title;
}
int Tutor::get_liczba()
{
    return number_of_publications;
}

ostream& operator<< (ostream &output, Tutor const& tutor)
{
   output <<static_cast<const Human&>( tutor )<< "Tytul naukowy: " << tutor.academic_title <<endl<<"Liczba Publikacji:"<<tutor.number_of_publications<<endl;
   return output;
}
istream& operator>> (istream &input, Tutor& tutor)
{
   input >>static_cast<Human&>( tutor );
   cout<<"Tytul naukowy: ";
   input>>tutor.academic_title;
   cout<<"liczba publikacji: ";
   input>>tutor.number_of_publications;
   return input;
}
