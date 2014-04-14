#include <cstdlib>
#include <iostream>
#include "Student2.h"
#include "Tutor.h"
#include "Human.h"

using namespace std;

int main(int argc, char *argv[])
{
    Interface *nowy;
    Interface *nowyn;
    //Tutor *nowy2;
    //Human *nowy3;
    //Student2 *nowy4;
    //Student2 *nowy5;
    nowy=new Student("Maciej","xxx",3,209794,4);
    nowyn=new Student("Maciej","xxx",2,209798,3);
    //nowy2=new Tutor("Maciej","xxx",3,"inz");
    //nowy3= new Human("Maciej","Stxxxx",3);
    Mama1* f[4];
    f[0]= new Student();
    f[1]= new Student();
    f[2]=new Human();
    f[3]=new Tutor();
    for (int i=0;i<2;i++)
        {
            cout<<"obiekt nr: "<<i+1<<" ";
            f[i]->birthday();
        }
    cout<<endl;
    for (int i=0;i<4;i++)
        {
            cout<<"obiekt nr: "<<i+1<<" ";
            f[i]->klasa();
        }
    cout<<endl<<"Porownanie:"<<endl;
    if(*nowy<*nowyn)
        cout<<"Nowy ma mniejszy nr Indeksu niz nowyn"<<endl;
    else
        cout<<"Nowyn ma mniejszy nr Indeksu niz nowy"<<endl;
    cout<<endl<<endl;
    //nowy4= new Student2("Maciej","Stxxx",3,209794,4,"inz",5);
    //nowy5= new Student2();
    //double tab[]={3,1,5.5,2,5};
    //nowy4->set_average(tab);
    //double tab2[5];
    //nowy4->get_average(tab2);
    //for(int i=0;i<5;i++)
    //cout<<"tab2["<<i+1<<"]="<<tab2[i]<<endl;
    //cout<<*nowy3<<endl;
    //cout<<*nowy;
    //cout <<*nowy5<<endl<<endl;
    //cin>>*nowy5;//ok
    //cout<<endl<<*nowy4<<endl<<endl;
    //cout<<endl<<*nowy3<<endl;
    //cout<<"Podaj: Imie, Nazwisko i numer indeksu:"<<endl;
    //cin>>*nowy; //ok
    //cout<<endl<<*nowy4<<endl<<endl;
    //cin>>*nowy5; //ok
    //cout<<endl<<*nowy5<<endl<<endl;
    //cout<<endl<<"wiek:: "<<nowy5->get_age()<<endl;
    delete f[0];
    delete f[1];
    delete f[2];
    delete f[3];
    delete nowy;
    delete nowyn;
    //delete nowy2;
    //delete nowy3;
    //delete nowy4;
    //delete nowy5;
    system("PAUSE");
}

//nie mo¿na stworzyæ obiekty klasy abstrakcyjnej z funkcj¹ czysto wirtualn¹, poniewa¿ funkcja nie ma zdefinowanego cia³a.
//Ró¿nica pomêdzy klas¹ abstrakcyjn¹ a klas¹ bêd¹c¹ interfejsem polega na tym, ¿e klasa mo¿e dziedziczyæ tylko po jednej klase ale po wielu interfejsach i ty jest przewaga klas jako interfejsów
