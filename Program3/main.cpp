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
    Sposoby dziediczenia r�ni� si� od siebie zasiengiem tzn:
        Dziedziczenie:: pulic 
            pola i metody:private- nie s� widzialne w klase pochodnej
            pola i metody:protecterd- przechodz� w protected
            pola i metody:public->public
        Dziedziczenie:: protected
            pola i metody:private- nie s� widzialne w klase pochodnej
            pola i metody:protecterd- przechodz� w private
            pola i metody:public->protected
        Dziedziczenie:: private
            pola i metody:private- nie s� widzialne w klase pochodnej
            pola i metody:protecterd- przechodz� w private
            pola i metody:public->private
    
    Konwersja pomi�dzy obiektami r�nych klas przynajmniejw moim przypadku ko�czy si� zg�oszeniem b�du przez kompilator
*/
