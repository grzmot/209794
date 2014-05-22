#include <cstdlib>
#include <iostream>
#include "Kino.h"
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
	Kino *kino;
	bool condition=true;
	kino= new Kino();
	ifstream plik2("..\\..\\plik.bin", ios::binary);
	if (plik2)
	{
		kino->read(plik2);
		plik2.close();
	}
	//system("pause");
	else
	{
		kino->g_sala(20,18,0);
		kino->g_sala(18,16,1);
		kino->g_film("AUTA 2",120,3,0);
		kino->g_film("Wiedzmin",160,12,1);
		kino->g_seans((::hour){17,20},(::day){12,05,2014},"2D",0,0,0);
		kino->g_seans((::hour){17,20},(::day){12,05,2014},"3D",1,0,1);
		kino->g_seans((::hour){13,20},(::day){12,05,2014},"3D",2,1,0);
		kino->g_ticket(20,25,15,20,14,18);
	}
	do {
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
								if(kino->check_sala())
								{
									int z;
									cout<<"wybierz sale do usuniecia"<<endl;
									kino->view_sala();
									cin>>z;
									z--;
									kino->delete_sala(z);
								}
								else
								{
									cout<<"Brak Sal"<<endl<<endl<<endl;
									system("PAUSE");
								}
								break;
							case 3:
								if(kino->check_sala())
									kino->view_sala();
								else
									cout<<"Brak Sal"<<endl;
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
								if(kino->check_film())
								{
									int z;
									cout<<"wybierz film do usuniecia"<<endl;
									kino->view_film();
									cin>>z;
									z--;
									kino->delete_film(z);
								}
								else
								{
									cout<<"Brak Filmow"<<endl;
									cout<<endl<<endl;
									system("PAUSE");
								}
								break;
							case 3:
								if(kino->check_film())
									kino->view_film();
								else
									cout<<"Brak filmow"<<endl;
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
								if(kino->check_seans())
								{
									int z;
									cout<<"wybierz seans do usuniecia"<<endl;
									kino->view_seans();
									cin>>z;
									z--;
									kino->delete_seans(z);
								}
								else
								{
									cout<<"Brak Seansow"<<endl;
									cout<<endl<<endl;
									system("PAUSE");
								}
								break;
							case 3:
								if(kino->check_seans())
									kino->view_seans();
								else
									cout<<"Brak Seansow"<<endl;
								cout<<endl<<endl;
								system("PAUSE");
								break;
							case 4:
								if(kino->check_seans())
								{
									int zx;
									cout<<"wybierz seans"<<endl;
									kino->view_seans();
									cin>>zx;
									zx--;
									kino->view_seans_sala(zx);
								}
								else
									cout<<"Brak Seansow"<<endl;
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
								if(kino->check_reservation())
								{
									int z;
									cout<<"wybierz rezerwacje do usuniecia"<<endl;
									kino->view_reservation();
									cin>>z;
									z--;
									kino->delete_reservation(z);
								}
								else
								{
									cout<<"Brak Rezerwacji"<<endl;
									cout<<endl<<endl;
									system("PAUSE");
								}
								break;
							case 3:
								if(kino->check_reservation())
									kino->view_reservation();
								else
									cout<<"Brak Rezerwacji"<<endl;
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
					int y,x;
					do
					{
						system("cls");
						cout<<endl<<endl;
						cout<<"1. Ceny biletow"<<endl;
						cout<<"2. Kup Bilet"<<endl;
						cout<<"0. Powrot"<<endl;
						cout<<"9. WYJSCIE"<<endl<<endl;
						cin>>x;
						cout<<endl<<endl;
						switch(x)
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
								menu=false;;
								break;
							case 9:
								condition=false;
								break;
							default:
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
	ofstream plik("..\\..\\plik.bin", ios::binary);
	{
		kino->save(plik);
		plik.close();
	}
	delete kino;
}
