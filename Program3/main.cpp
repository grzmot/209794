#include <cstdlib>
#include <iostream>
#include "Student.h"
#include "Tutor.h"

using namespace std;

int main(int argc, char *argv[])
{
    Student *nowy;
    Tutor *nowy2;
    Human *nowy3;
    nowy=new Student("Maciej","xxx",209794);
    nowy2=new Tutor("Maciej","x","inz");
    nowy3= new Human("Maciej","Starosciak");
    delete nowy2;
    delete nowy;
    delete nowy3;
    system("PAUSE");
}
/*Odpowiedzi na putania:
    Sposoby dziediczenia ró¿ni¹ siê od siebie zasiengiem tzn:
        Dziedziczenie:: pulic 
            pola i metody:private- nie s¹ widzialne w klase pochodnej
            pola i metody:protecterd- przechodz¹ w protected
            pola i metody:public->public
        Dziedziczenie:: protected
            pola i metody:private- nie s¹ widzialne w klase pochodnej
            pola i metody:protecterd- przechodz¹ w private
            pola i metody:public->protected
        Dziedziczenie:: private
            pola i metody:private- nie s¹ widzialne w klase pochodnej
            pola i metody:protecterd- przechodz¹ w private
            pola i metody:public->private
    
    Konwersja pomiêdzy obiektami ró¿nych klas przynajmniejw moim przypadku koñczy siê zg³oszeniem bêdu przez kompilator
*/
