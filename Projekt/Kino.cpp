#include "Kino.h"
#include <iostream>
#include <stdio.h>
Kino::Kino()
{
	size_sala=6;
	size_film=10;
	size_seans=20;
	size_reservation=10;
	sala=new Sala *[size_sala];
	for(int i=0;i<size_sala;i++)
		sala[i]=NULL;
	film=new Film *[size_film];
	for(int i=0;i<size_film;i++)
		film[i]=NULL;
	seans=new Seans *[size_seans];
	for(int i=0;i<size_seans;i++)
		seans[i]=NULL;
	reservation=new Reservation *[size_reservation];
	for(int i=0;i<size_reservation;i++)
		reservation[i]=NULL;
	ticket=NULL;
}
Kino::~Kino()
{
	if(ticket!=NULL)
		delete ticket;
	for(int i=0;i<size_sala;i++)
		if(sala[i]!=NULL)
			delete sala[i];
	delete [] sala;
	for(int i=0;i<size_film;i++)
		if(film[i]!=NULL)
			delete film[i];
	delete [] film;
	for(int i=0;i<size_seans;i++)
		if(seans[i]!=NULL)
			delete seans[i];
	delete [] seans;
	for(int i=0;i<size_reservation;i++)
		if(reservation[i]!=NULL)
			delete reservation[i];
	delete [] reservation;
}

void Kino::resize_sala()
{
	Sala **tmp;
	tmp= new Sala *[size_sala];
	for(int i=0;i<size_sala;i++)
		tmp[i]=new Sala(*sala[i]);
	for(int i=0;i<size_sala;i++)
		delete sala[i];
	delete [] sala;
	size_sala*=2;
	sala= new Sala *[size_sala];
	for(int i=0;i<size_sala/2;i++)
		sala[i]=new Sala(*tmp[i]);
	for(int i=0;i<size_sala/2;i++)
			delete tmp[i];
	delete [] tmp;
	for(int i=size_sala/2;i<size_sala;i++)
		sala[i]=NULL;
	}
void Kino::resize_film()
{
	Film **tmp;
	tmp= new Film *[size_film];
	for(int i=0;i<size_film;i++)
		tmp[i]=new Film(*film[i]);
	for(int i=0;i<size_film;i++)
		delete film[i];
	delete [] film;
	size_film*=2;
	film= new Film *[size_film];
	for(int i=0;i<size_film/2;i++)
		film[i]=new Film(*tmp[i]);
	for(int i=0;i<size_film/2;i++)
			delete tmp[i];
	delete [] tmp;
	for(int i=size_film/2;i<size_film;i++)
		film[i]=NULL;
}
void Kino::resize_seans()
{
	Seans **tmp;
	tmp= new Seans *[size_seans];
	for(int i=0;i<size_seans;i++)
		tmp[i]=new Seans(*seans[i]);
	for(int i=0;i<size_seans;i++)
		delete seans[i];
	delete [] seans;
	size_seans*=2;
	seans= new Seans *[size_seans];
	for(int i=0;i<size_seans/2;i++)
		seans[i]=new Seans(*tmp[i]);
	for(int i=0;i<size_seans/2;i++)
			delete tmp[i];
	delete [] tmp;
	for(int i=size_seans/2;i<size_seans;i++)
		seans[i]=NULL;
}
void Kino::resize_reservation()
{
	Reservation **tmp;
	tmp= new Reservation *[size_reservation];
	for(int i=0;i<size_reservation;i++)
		tmp[i]=new Reservation(*reservation[i]);
	for(int i=0;i<size_reservation;i++)
		delete reservation[i];
	delete [] reservation;
	size_reservation*=2;
	reservation= new Reservation *[size_reservation];
	for(int i=0;i<size_reservation/2;i++)
		reservation[i]=new Reservation(*tmp[i]);
	for(int i=0;i<size_reservation/2;i++)
			delete tmp[i];
	delete [] tmp;
	for(int i=size_reservation/2;i<size_reservation;i++)
		reservation[i]=NULL;
}
Seans Kino::get_seans(int id_seans)
{
	return *seans[id_seans];
}
void Kino::view_sala()
{
	for (int j=0;j<size_sala;j++)
		if(sala[j]!=NULL)
			cout<<"Sala nr.: "<<j+1<<" "<<" ikosc miejsc: "<<sala[j]->get_number_of_seats()<<endl;
}

void Kino::view_film()
{
	for (int j=0;j<size_film;j++)
		if(film[j]!=NULL)
			cout<<j+1<<". "<<*film[j]<<endl;
}
void Kino::view_film(int id_film)
{
	cout<<endl<<film[id_film]<<endl;
}
void Kino::view_seans()
{
	for (int j=0;j<size_seans;j++)
		if(seans[j]!=NULL)
			cout<<j+1<<". "<<*seans[j];
}

void Kino::view_seans(int id_seans)
{
	cout<<endl<<seans[id_seans]<<endl;
}
void Kino::view_seans_sala(int id_seans)
{
	seans[id_seans]->get_sala().view_spaces();
}
void Kino::view_reservation()
{
	for (int j=0;j<size_reservation;j++)
		if(reservation[j]!=NULL)
		{
			cout<<j+1<<". "<<"Film: "<<seans[reservation[j]->get_seans_id()]->get_title();
			cout<<" godz: "<<seans[reservation[j]->get_seans_id()]->get_hour().g<<":"<<seans[reservation[j]->get_seans_id()]->get_hour().m;
			cout<<" sala: "<<(seans[reservation[j]->get_seans_id()]->get_sala().get_number())+1;
			for(int i=0;i<(reservation[j]->get_number());i++)
				cout<<" Miejsce "<<i+1<<": "<<(reservation[j]->get_row(i))+1<<"/"<<(reservation[j]->get_space(i))+1<<" ";
			cout<<endl;
		}
}
void Kino::set_tickets()
{
	if(ticket==NULL)
	{
		ticket= new Ticket();
		cin>>*ticket;
	}
	else
	{
		int i=0;
		cout<<*ticket;
		cout<<"ile cen biletow chcesz znienic?"<<endl;
		cin>>i;
		if(i>6)
			i=6;
		for(int j=0;j<i;j++)
		{
			cout<<endl<<"ktora cene biletu chcesz zmienic?"<<endl;
			cout<<"1 -Normalny 2D"<<endl;
			cout<<"2 -Normalny 3D"<<endl;
			cout<<"3 -Ulgowy 2D"<<endl;
			cout<<"4 -Ulgowy 3D"<<endl;
			cout<<"5 -Grupowy 2D"<<endl;
			cout<<"6 -Grupowy 3D"<<endl;
			int x;
			double y;
			cin>>x;
			cout<<"podaj nowa cene: "<<endl;
			cin>>y;
			switch(x)
			{
				case 1: 
					ticket->set_normal_2D(y);
					break;
				case 2: 
					ticket->set_normal_3D(y);
					break;
				case 3: 
					ticket->set_reduced_2D(y);
					break;
				case 4: 
					ticket->set_reduced_3D(y);
					break;
				case 5: 
					ticket->set_group_2D(y);
					break;
				case 6: 
					ticket->set_group_3D(y);
					break;
			}
		}
	}
}
void Kino::view_ticket_price()
{
	if(ticket!=NULL)
		cout<<*ticket<<endl;
}
void Kino::buy_ticket(int number)
{
	bool confirmation;
	int *tickets,q;
	tickets= new int [number];
	int x,*space[2];
	space[0]=new int [number];
	space[1]=new int [number];
	cout<<endl<<"wybierz seans"<<endl;
	view_seans();
	cin>>x;
	x--;
	if(number==1)
		cout<<"wybierz miejsce"<<endl;
	else 
		cout<<"wybierz miejsca"<<endl;
	seans[x]->get_sala().view_spaces();
	if (number==1)
	{
		do
		{
			cout<<"RZAD/MIEJSCE: ";
			scanf("%i/%i",&space[0][0],&space[1][0]);
			if (!(seans[x]->get_sala().place_free(space[0][0],space[1][0])))
				cout<<"miejsce zajete"<<endl;
		}while (!(seans[x]->get_sala().place_free(space[0][0],space[1][0])));
		cout<<"wybiez bilet"<<endl;
		cout<<"1. Normalny "<<endl<<"2. Ulgowy"<<endl;
		cin>>tickets[0];
		cout<<endl<<endl<<seans[x]->get_title()<<endl;
		cout<<"godzina: "<<seans[x]->get_hour().g<<":"<<seans[x]->get_hour().m<<endl;
		cout<<"RZAD: "<<space[0][0]<<" / MIEJSCE: "<<space[1][0]<<endl;
		if ((seans[x]->get_type_seans()=="2D")&& tickets[0]==1)
			cout<<"Film 2D"<<endl<<"Cena: "<<ticket->get_normal_2D()<<"zl"<<endl;
		else if((seans[x]->get_type_seans()=="3D")&& tickets[0]==1)
			cout<<"Film 3D"<<endl<<"Cena: "<<ticket->get_normal_3D()<<"zl"<<endl;
		else if((seans[x]->get_type_seans()=="2D")&& tickets[0]==2)
			cout<<"Film 2D"<<endl<<"Cena: "<<ticket->get_reduced_2D()<<"zl"<<endl;
		else
			cout<<"Film 3D"<<endl<<"Cena: "<<ticket->get_reduced_3D()<<"zl"<<endl;
		cout<<"potwierdz zakup"<<endl<<"1-POTWIERDZ"<<endl<<"2-ANULUJ";
		cin>>q;
		if(q==1)
			confirmation=true;
		else
			confirmation=false;
	}
	else
	{
		for (int i=0; i<number;i++)
		{
			do
			{
				cout<<"miejsce "<<i+1<<" (RAZD/MIEJSCE): ";
				scanf("%i/%i",&space[0][i-1],&space[1][i-1]);
				if (!(seans[x]->get_sala().place_free(space[0][i-1],space[1][i-1])))
					cout<<"miejsce zajete"<<endl;
			}while (!(seans[x]->get_sala().place_free(space[0][i-1],space[1][i-1])));
		}
		cout<<"wybiez bilet"<<endl;
		cout<<"1. Normalny "<<endl<<"2. Ulgowy"<<endl;
		for (int i=0;i<number;i++)
		{
			
			cout<<"bilet "<<i+1<<": ";
			cin>>tickets[i];
		}
		double price=0;
		for (int i=0;i<number;i++)
		{
			cout<<"BILET "<<i+1;
			cout<<endl<<endl<<seans[x]->get_title()<<endl;
			cout<<"godzina: "<<seans[x]->get_hour().g<<":"<<seans[x]->get_hour().m<<endl;
			cout<<"RZAD: "<<space[0][i]<<" / MIEJSCE: "<<space[1][i]<<endl;
			if ((seans[x]->get_type_seans()=="2D")&& tickets[i]==1)
			{
				cout<<"Film 2D"<<endl<<"Cena: "<<ticket->get_normal_2D()<<"zl"<<endl;
				price+=ticket->get_normal_2D();
			}
			else if((seans[x]->get_type_seans()=="3D")&& tickets[i]==1)
			{
				cout<<"Film 3D"<<endl<<"Cena: "<<ticket->get_normal_3D()<<"zl"<<endl;
				price+=ticket->get_normal_3D();
			}
			else if((seans[x]->get_type_seans()=="2D")&& tickets[i]==2)
			{
				cout<<"Film 2D"<<endl<<"Cena: "<<ticket->get_reduced_2D()<<"zl"<<endl;
				price+=ticket->get_reduced_2D();
			}
			else
			{
				cout<<"Film 3D"<<endl<<"Cena: "<<ticket->get_reduced_3D()<<"zl"<<endl;
				price+=ticket->get_reduced_3D();
			}
		}
		cout<<"Razam do zaplaty: "<<price<<"zl"<<endl;
		cout<<"potwierdz zakup"<<endl<<"1-POTWIERDZ"<<endl<<"2-ANULUJ";
		cin>>q;
		if(q==1)
			confirmation=true;
		else
			confirmation=false;
	}
	if(confirmation)
			seans[x]->get_sala().take_seat(space[0],space[1],number);
	delete [] space[1];
	delete [] space[0];
	delete [] tickets;
}


void Kino::g_sala(int row,int space, int id)
{
	if(sala[id]==NULL)
		sala[id]=new Sala(row,space,id);
}
void Kino::g_film(string title,int time,int restrictions,int id)
{
	if(film[id]==NULL)
		film[id]=new Film(title,time,restrictions);
}
void Kino::g_seans(::hour hour, string type_seans,int id,int id_film,int id_sala)
{
	if(seans[id]==NULL)
		seans[id]=new Seans(*film[id_film],hour,*sala[id_sala],type_seans);
}

void Kino::add_sala()
{
	int i=0;
	i--;
	bool x=true;
	do
	{
		i++;
		if(sala[i]==NULL)
			x=false;
	}while((i<size_sala)&& x);
	if(x)
		resize_sala();
	int row,space;
	cout<<"podaj ilosc rzedow: ";
	cin>>row;
	cout<<"podaj ilosc miejsc w rzedzie: ";
	cin>>space;
	sala[i]=new Sala();
	sala[i]->set_spaces(row,space);
	sala[i]->set_number(i);
}
void Kino::add_film()
{
	int i=0;
	i--;
	bool x=true;
	do
	{
		i++;
		if(film[i]==NULL)
			x=false;
	}while((i<size_film)&& x);
	if(x)
		resize_film();
	film[i]=new Film();
	cin>>*film[i];
}
void Kino::add_seans()
{
	int i=0,s,f;//s- number od sala, f- number of film
	string t="";//t-type of film 2D/3D
	i--;
	bool x=true;
	do
	{
		i++;
		if(seans[i]==NULL)
			x=false;
	}while((i<size_seans)&& x);
	if(x)
		resize_seans();
	cout<<"wybierz film:"<<endl;
	view_film();
	cin>>f;
	f--;
	cout<<"wybierz Sale:"<<endl;
	for (int j=0;j<size_sala;j++)
		if(sala[j]!=NULL)
			cout<<"Sala nr: "<<j+1<<" ilosc miejsc: "<<sala[j]->get_number_of_seats()<<endl;
	cin>>s;
	s--;
	cout<<"podaj godzine seansu(format->gg:mm): ";
	int g=0,m=0;
	scanf("%i:%i",&g,&m);
	cout<<"podaj typ filmu(2D/3D): ";
	cin>>t;
	seans[i]=new Seans(*film[f],(::hour){g,m},*sala[s],t);
}
void Kino::add_reservation()
{
	int i=0;
	int n,*row,*space,xy[1],y[1];
	int id_seans;
	i--;
	bool x=true;
	do
	{
		i++;
		if(reservation[i]==NULL)
			x=false;
	}while((i<size_reservation)&& x);
	if(x)
		resize_reservation();
	cout<<"wybierz seans"<<endl;
	view_seans();
	cin>>id_seans;
	id_seans--;
	cout<<"ile miejsc chcesz zarezerwowac?"<<endl;
	cin>>n;
	row=new int[n];
	space=new int[n];
	cout<<"wybierz miejsce: "<<endl;
			seans[id_seans]->get_sala().view_spaces();
	for(int j=0;j<n;j++)
	{
		do
		{
			cout<<"Miejsce "<<j+1<<"  rzad/miejsce: ";
			scanf("%i/%i",&row[j],&space[j]);
			row[j]--;
			space[j]--;
			if(!(seans[id_seans]->get_sala2().place_free(row[j],space[j])))
				cout<<"miejsce zajete"<<endl;
		} while(!(seans[id_seans]->get_sala2().place_free(row[j],space[j])));
		xy[0]=row[j];
		y[0]=space[j];
		seans[id_seans]->get_sala2().take_seat(xy,y,1);
	}
	reservation[i]=new Reservation(id_seans,i,n,row,space);
	delete []row;
	delete []space;
}
void Kino::delete_sala(int id_sala)
{
	if(sala[id_sala]!=NULL)
		delete sala[id_sala];
	sala[id_sala]=NULL;
}
void Kino::delete_film(int id_film)
{
	if(film[id_film]!=NULL)
		delete film[id_film];
	film[id_film]=NULL;
}
void Kino::delete_seans(int id_seans)
{
	if(seans[id_seans]!=NULL)
		delete seans[id_seans];
	seans[id_seans]=NULL;
}
void Kino::delete_reservation(int id_reservation)
{
	if(reservation[id_reservation]!=NULL)
		{
			seans[reservation[id_reservation]->get_seans_id()]->get_sala2().relase_seat(reservation[id_reservation]->get_row(),reservation[id_reservation]->get_space(),reservation[id_reservation]->get_number());
			delete reservation[id_reservation];
		}
	reservation[id_reservation]=NULL;
}
void Kino::view_sala(int id_sala)
{
	sala[id_sala]->view_spaces();
}

