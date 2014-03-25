#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include "Circle.h"
using namespace std;


int main(int argc, char *argv[])
{
    Circle circle[10];
    circle[0].set_location((location){4.2,2.4});
    circle[0].set_radius(5.2);
    Circle::dilosc();
    circle[1]=circle[0]*5.6;
    Circle::dilosc();
    for (int i=2;i<5;i++)
    {
        circle[i]=circle[i-1]+circle[i-2];
        Circle::dilosc();
    }


    for (int i=0;i<Circle::ilosc();i++)
    {
        cout<<"Obiekt "<<i+1<<endl;
        printf("Circle location is %.1fx%.1f\n",circle[i].get_location().x, circle[i].get_location().y);
        printf("Circle radius is %.1f\n",circle[i].get_radius());
        printf("Circle cirmference is %.2f\n",circle[i].circumference());
        printf("Circle area is %.2f\n\n",circle[i].area());
    }

    printf("ilosc obiektow: %d\n",Circle::ilosc());
   
    system("PAUSE");
    return EXIT_SUCCESS;
}
// klasa potrzebuje destruktor aby zwolniæ pamiêæ poswoich obiektach
//W zmiennych i funkcjach statycznych mo¿eby przechowywaæ dane wspólne dla wszystkich obiektów danej klasy
//Statyczne zmienne mog¹ zast¹piæ zmienne globalne
