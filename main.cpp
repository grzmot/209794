#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <Math.h>
#include "Circle.h"
using namespace std;


int main(int argc, char *argv[])
{
    Circle circle((location){4.2,2.4},5.1);
    Circle c1((location){6.0,4.0},6.0),c2,c3;
c3=c1*3.0;
c2=circle+c1;
Circle::dilosc(4);
printf("Circle location is %.1fx%.1f.\n", 
    circle.get_location().x, circle.get_location().y);
printf("Circle radius is %.1f.\n", 
    circle.get_radius());
printf("Circle circumference is %.2f.\n", 
    circle.circumference());
printf("Circle area is %.2f.\n\n", 
    circle.area());
    
printf("Circle location is %.1fx%.1f.\n",
    c2.get_location().x, circle.get_location().y);
printf("Circle radius is %.1f.\n\n",
    c2.get_radius());
    
printf("Circle location is %.1fx%.1f.\n",
    c3.get_location().x, circle.get_location().y);
printf("Circle radius is %.1f.\n\n",
    c3.get_radius());
printf("ilosc obiektow: %d\n",Circle::ilosc());
   
    system("PAUSE");
    return EXIT_SUCCESS;
}
// klasa potrzebuje destruktor aby zwolniæ pamiêæ poswoich obiektach
//W zmiennych i funkcjach statycznych mo¿eby przechowywaæ dane wspólne dla wszystkich obiektów danej klasy
//Statyczne zmienne mog¹ zast¹piæ zmienne globalne
