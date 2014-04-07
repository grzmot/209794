#include <cstdlib>
#include <iostream>
#include "Student2.h"
#include "Tutor.h"

using namespace std;

int main(int argc, char *argv[])
{
    //Student *nowy;
    //Tutor *nowy2;
    //Human *nowy3;
    Student2 *nowy4;
    Student2 *nowy5;
    //nowy=new Student("Maciej","xxx",209794);
    //nowy2=new Tutor("Maciej","xxx","inz");
    //nowy3= new Human("Maciej","Stxxxx");
    nowy4= new Student2("Maciej","Stxxx",209794,"inz",5);
    nowy5= new Student2();
    //nowy5=new Student2();
    double tab[]={3,1,5.5,2,5};
    nowy4->set_average(tab);
    //double tab2[5];
    //nowy4->get_average(tab2);
    //for(int i=0;i<5;i++)
    //cout<<"tab2["<<i+1<<"]="<<tab2[i]<<endl;
    //cout<<*nowy3<<endl;
    //cout<<*nowy;
    //cout<<*nowy4<<endl<<endl;
    /*cout<<"Podaj: Imie, Nazwisko"<<endl;
    cin>>*nowy3;//ok
    cout<<endl<<*nowy3<<endl<<endl;*/
    cout<<endl<<*nowy4<<endl;
    /*cout<<"Podaj: Imie, Nazwisko i numer indeksu:"<<endl;
    cin>>*nowy; //ok
    cout<<endl<<*nowy<<endl<<endl;*/
    cout<<"Podaj: Imie, Nazwisko, numer indeksu i stopien:"<<endl;
    cin>>*nowy5; //ok
    cout<<endl<<*nowy5<<endl<<endl;
    //delete nowy;
    //delete nowy2;
    //delete nowy3;
    delete nowy4;
    delete nowy5;
    system("PAUSE");
}

//destruktor wirtualnu nale¿y stosowaæ w kalasch bazowych aby zepewniæ poprawne usowanie obiektów a tym samym poprawnie zwalniaæ pamiêæ któr¹ mi³y przydzielone obiekty.
