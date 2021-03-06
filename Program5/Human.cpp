#include "Human.h"

int Human::couter=0;
int Human::counter()
{
    return couter;
}

Human::Human()
{
    age=0;
    sex='n';
    first_name="";
    surname="";
    couter++;
    size=0;
    favorite_books= new string[size];
}
Human::Human(int age, char sex, string first_name, string surname, int size):
    age(age),
    sex(sex),
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
    sex='n';
    couter++;
    favorite_books= new string[size];
}
Human::~Human()
{
    couter--;
    delete []favorite_books;
}

void Human::birthday()
{
    cout<<"Human"<<endl;
}
void Human::klasa()
{
    cout<<"klasa Human"<<endl;
}
void Human::pola()
{
    cout<<"Pola wlasne klasy Human:"<<endl<<" Imie,Nazwisko,Wiek,sex,Ulubione ksiazki"<<endl;
}

int Human::get_age()
{
    return age;
}
char Human::get_sex()
{
    return sex;
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
void Human::set_sex(char sex)
{
    this->sex=sex;
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
   output << "Imie: " << human.first_name <<endl<< "Nazwisko: " << human.surname << endl<<"Wiek: "<< human.age<<endl<<"sex: "<<human.sex<<endl<<"ulubione ksiazki: ";
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
    cout<<"sex: ";
    input>>human.sex;
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
