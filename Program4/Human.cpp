#include "Human.h"

int Human::couter=0;
int Human::counter()
{
    return couter;
}

Human::Human()
{
    age=0;
    plec='n';
    first_name="";
    surname="";
    couter++;
    size=0;
    favorite_books= new string[size];
}
Human::Human(int age, char plec, string first_name, string surname, int size):
    age(age),
    plec(plec),
    first_name(first_name),
    surname(surname),
    size(size)
{
    favorite_books= new string[size];
    couter++;
}
Human::Human(string first_name, string surname, int size):
    first_name(first_name),surname(surname),size(size)
{
    age=0;
    plec='n';
    couter++;
    favorite_books= new string[size];
}
Human::~Human()
{
    couter--;
    delete []favorite_books;
}

int Human::get_age()
{
    return age;
}
char Human::get_plec()
{
    return plec;
}
string Human::get_first_name()
{
    return first_name;
}
string Human::get_surname()
{
    return surname;
}
void Human::set_age(int age)
{
    this->age=age;
}
void Human::set_plec(char plec)
{
    this->plec=plec;
}
void Human::set_first_name(string first_name)
{
    this->first_name=first_name;
}
void Human::set_surname(string surname)
{
    this->surname=surname;
}

ostream& operator<< (ostream &output, Human const& human)
{
   output << "Imie: " << human.first_name <<endl<< "Nazwisko: " << human.surname << endl<<"Wiek: "<< human.age<<endl<<"plec: "<<human.plec<<endl<<"ulubione ksiazki: ";
   for(int i=0;i<human.size;i++)
        output<<human.favorite_books[i]<<" ";
   return output;
}
istream& operator>> (istream &input, Human& human)
{
    cout<<"podaj Imie:";
    input >> human.first_name;
    cout<<"podaj Nazwisko: ";
    input >> human.surname;
    cout<<"podaj Wiek:";
    input >> human.age;
    cout<<"plec: ";
    input>>human.plec;
    cout<<"podaj ilosc Ulubionych Ksiazek:";
   input >> human.size;
   delete []human.favorite_books;
   human.favorite_books= new string[human.size];
   for(int i=0;i<human.size;i++)
   {
        cout <<"podaj ksiazke "<<i+1<<": ";
        input >>human.favorite_books[i];
   }
   return input;
}
