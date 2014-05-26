#include <cstdlib>
#include <iostream>
#include "Kolacja.h"
using namespace std;

int main(int argc, char *argv[])
{
	Kolacja *kolacja;
	kolacja = new Kolacja("Kielbasa",500,(::hour){18,23});
	cout<<"Posilek: "<<kolacja->get_name();
	cout<<endl<<"kalorie: "<<kolacja->get_cal()<<endl;
	cout<<"godz.: "<<kolacja->get_hour().h<<":"<<kolacja->get_hour().m<<endl<<endl;
    system("PAUSE");
}
