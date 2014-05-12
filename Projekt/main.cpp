#include <cstdlib>
#include <iostream>
#include "Kino.h"

using namespace std;

int main(int argc, char *argv[])
{
	Kino *kino;
	bool condition=true;
	kino= new Kino();
	kino->g_sala(20,18,0);
	kino->g_sala(18,16,1);
	kino->g_film("AUTA 2",120,3,0);
	kino->g_film("Wiedzmin",160,12,1);
	kino->g_seans((::hour){17,20},"2D",0,0,0);
	kino->g_seans((::hour){17,20},"3D",1,0,1);
	kino->g_seans((::hour){13,20},"3D",2,1,0);
	//kino->set_tickets();
	do
	{
		int x;
		system("cls");
		cout<<endl<<endl;
		cout<<"1. Zarzadzaj salami"<<endl;
		cout<<"2. Zarzadzaj filmami"<<endl;
		cout<<"3. Zarzadzaj seansami"<<endl;
		cout<<"4. Zmien ceny bitetow"<<endl;
		cout<<"5. Zarzadzaj rezerwacjami"<<endl;
		cout<<"6. Bilety"<<endl;
		cout<<"9. WYJSCIE"<<endl;
		cout<<endl;
		cin>>x;
		cout<<endl<<endl;
		switch(x)
		{
			case 1:
				{
					bool menu=true;
					int y;
					do
					{
						system("cls");
						cout<<endl<<endl;
						cout<<"1. dodaj sale"<<endl;
						cout<<"2. usun sale"<<endl;
						cout<<"3. zobacz sale"<<endl;
						cout<<"0. Powrot"<<endl;
						cout<<"9. WYJSCIE"<<endl<<endl;
						cin>>y;
						cout<<endl<<endl;
						switch(y)
						{
							case 1:
								kino->add_sala();
								break;
							case 2:
								int z;
								cout<<"wybierz sale do usuniecia"<<endl;
								kino->view_sala();
								cin>>z;
								z--;
								kino->delete_sala(z);
								break;
							case 3:
								kino->view_sala();
								cout<<endl<<endl;
								system("PAUSE");
								break;
							case 0:
								menu=false;
								break;
							case 9:
								condition=false;
								break;
						}
					}while(menu && condition);
				}
				break;
			case 2:
				{
					bool menu=true;
					int y;
					do
					{
						system("cls");
						cout<<endl<<endl;
						cout<<"1. dodaj film"<<endl;
						cout<<"2. usun film"<<endl;
						cout<<"3. zobacz filmy"<<endl;
						cout<<"0. Powrot"<<endl;
						cout<<"9. WYJSCIE"<<endl<<endl;
						cin>>y;
						cout<<endl<<endl;
						switch(y)
						{
							case 1:
								kino->add_film();
								break;
							case 2:
								int z;
								cout<<"wybierz film do usuniecia"<<endl;
								kino->view_film();
								cin>>z;
								z--;
								kino->delete_film(z);
								break;
							case 3:
								kino->view_film();
								cout<<endl<<endl;
								system("PAUSE");
								break;
							case 0:
								menu=false;
								break;
							case 9:
								condition=false;
								break;
						}
					}while(menu && condition);
				}
				break;
			case 3:
				{
					bool menu=true;
					int y;
					do
					{
						system("cls");
						cout<<endl<<endl;
						cout<<"1. dodaj seans"<<endl;
						cout<<"2. usun seans"<<endl;
						cout<<"3. zobacz seansy"<<endl;
						cout<<"4. zobacz rozklad miejsc na sali"<<endl;
						cout<<"0. Powrot"<<endl;
						cout<<"9. WYJSCIE"<<endl<<endl;
						cin>>y;
						cout<<endl<<endl;
						switch(y)
						{
							case 1:
								kino->add_seans();
								break;
							case 2:
								int z;
								cout<<"wybierz seans do usuniecia"<<endl;
								kino->view_seans();
								cin>>z;
								z--;
								kino->delete_seans(z);
								break;
							case 3:
								kino->view_seans();
								cout<<endl<<endl;
								system("PAUSE");
								break;
							case 4:
								int zx;
								cout<<"wybierz seans"<<endl;
								kino->view_seans();
								cin>>zx;
								zx--;
								kino->view_seans_sala(zx);
								cout<<endl<<endl;
								system("PAUSE");
								break;
							case 0:
								menu=false;
								break;
							case 9:
								condition=false;
								break;
						}
					}while(menu && condition);
				}
				break;
			case 4:
				kino->set_tickets();
				break;
			case 5:
				{	
					bool menu=true;
					int y;
					do
					{
						system("cls");
						cout<<endl<<endl;
						cout<<"1. dodaj rezerwacje"<<endl;
						cout<<"2. usun rezerwacje"<<endl;
						cout<<"3. zobacz rezerwacje"<<endl;
						cout<<"0. Powrot"<<endl;
						cout<<"9. WYJSCIE"<<endl<<endl;
						cin>>y;
						cout<<endl<<endl;
						switch(y)
						{
							case 1:
								kino->add_reservation();
								break;
							case 2:
								int z;
								cout<<"wybierz rezerwacje do usuniecia"<<endl;
								kino->view_reservation();
								cin>>z;
								z--;
								kino->delete_reservation(z);
								break;
							case 3:
								kino->view_reservation();
								cout<<endl<<endl;
								system("PAUSE");
								break;
							case 0:
								menu=false;
								break;
							case 9:
								condition=false;
								break;
						}
					}while(menu && condition);
				}
				break;
			case 6:
				{
					bool menu=true;
					int y,y1;
					do
					{
						system("cls");
						cout<<endl<<endl;
						cout<<"1. Ceny biletow"<<endl;
						cout<<"2. Kup Bilet"<<endl;
						cout<<"0. Powrot"<<endl;
						cout<<"9. WYJSCIE"<<endl<<endl;
						cin>>y1;
						cout<<endl<<endl;
						switch(y1)
						{
							case 1:
								kino->view_ticket_price();
								cout<<endl<<endl;
								system("PAUSE");
								break;
							case 2:
								cout<<"Ile bitetow chcesz kupic?"<<endl;
								cin>>y;
								kino->buy_ticket(y);
								break;
							case 0:
								menu=false;
								break;
							case 9:
								condition=false;
							break;
						}
					}while(menu && condition);
				}
				break;
			case 9:
				condition=false;
				break;
		}
	}while(condition);
	delete kino;
}
