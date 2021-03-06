#include "Sala.h"
#include <windows.h>
#include <cstdlib>
#include <iostream>
using namespace std;

int Sala::number_of_hall=0;
Sala::Sala()
{
	row=0;
	space=0;
	number_of_hall++;
	number=number_of_hall;
	number_of_seats=0;
	spaces=NULL;
}

Sala::Sala(int row, int space, int number):row(row),space(space),number(number)
{
	number_of_hall++;
	number_of_seats=row*space;
	spaces=new int*[this->row];
	for(int i=0;i<row;i++)
		spaces[i]=new int[this->space];
	for(int i=0;i<row;i++)
		for(int j=0;j<space;j++)
			spaces[i][j]=0;
}
Sala::Sala(const Sala &hall)
{
	row=hall.row;
	space=hall.space;
	number=hall.number;
	number_of_seats=hall.number_of_seats;
	spaces=new int*[row];
	for(int i=0;i<row;i++)
		spaces[i]=new int[space];
	for(int i=0;i<row;i++)
		for(int j=0;j<space;j++)
			spaces[i][j]=hall.spaces[i][j];
}
Sala::~Sala()
{
	for(int i=0;i<row;i++)
		delete [] spaces[i];
	delete [] spaces;
}

int Sala::get_number_of_hall()
{
	return number_of_hall;
}

void Sala::set_number(int number)
{
	this->number=number;
}
void Sala::set_spaces(int row, int space)
{
	this->row=row;
	this->space=space;
	if(spaces!=NULL)
	{
		for(int i=0;i<row;i++)
			delete [] spaces[i];
		delete [] spaces;
	}
	spaces=new int*[this->row];
	for(int i=0;i<row;i++)
		spaces[i]=new int[this->space];
	for(int i=0;i<row;i++)
		for(int j=0;j<space;j++)
			spaces[i][j]=0;
	number_of_seats=row*space;
}
int Sala::get_number()
{
	return number;
}
int Sala::get_number_of_seats()
{
	return number_of_seats;
}
void Sala::view_spaces()//poka� miejsca na sali
{
	HANDLE hOut;
	hOut = GetStdHandle( STD_OUTPUT_HANDLE );
	if(space<25)
	{
		cout<<"RZAD";
		for(int i=0;i<space/2+1;i++)
			if(i==space/2)
				cout<<"EKRAN";
			else
				cout<<"  ";
		for(int i=0;i<row;i++)
		{
			cout.width(6);
			cout<<endl<<left<<i+1;
			cout.width(0);
			for(int j=0;j<space;j++)
			{
				cout<<" ";
				if(spaces[i][j]==1)
					SetConsoleTextAttribute(hOut, BACKGROUND_RED);
				cout<<j+1;
				SetConsoleTextAttribute(hOut, !(BACKGROUND_GREEN|BACKGROUND_BLUE|BACKGROUND_RED));
				SetConsoleTextAttribute(hOut, (FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED));
			}
		}
		cout<<endl<<endl<<endl;
	}
	else
	{
		cout<<"RZAD";
		for(int i=0;i<(space/2+4);i++)
			if(i==(space/2+3))
				cout<<"EKRAN";
			else
				cout<<"  ";
		for(int i=0;i<row;i++)
		{
			cout.width(6);
			cout<<endl<<left<<i+1;
			cout.width(0);
			for(int j=0;j<space;j++)
			{
				if((j==7)||(j==space-6))
				cout<<"  ";
				cout<<" ";
				if(spaces[i][j]==1)
					SetConsoleTextAttribute(hOut, BACKGROUND_RED);
				cout<<j+1;
				SetConsoleTextAttribute(hOut, !(BACKGROUND_GREEN|BACKGROUND_BLUE|BACKGROUND_RED));
				SetConsoleTextAttribute(hOut, (FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED));
			}
		}
		cout<<endl<<endl<<endl;
	}
}
void Sala::take_seat(int row[], int space[],int number_seats)//zajmij miejsca
{
	for(int i=0;i<number_seats;i++)
		spaces[row[i]][space[i]]=1;
}
void Sala::relase_seat(int row[], int space[],int number_seats)//zwolnij miejsca
{
	for(int i=0;i<number_seats;i++)
		spaces[row[i]][space[i]]=0;
}
bool Sala::place_free(int row_s,int place_s)
{
	return (spaces[row_s][place_s]==0);
}
void Sala::set_number_of_hall()
{
	number_of_hall--;
}

void Sala::save(ofstream &ofs)
{
	ofs.write((char*)(&row), sizeof(int));
	ofs.write((char*)(&space), sizeof(int));
	ofs.write((char*)(&number), sizeof(int));
	for (int i=0;i<row;i++)
		{
			for(int j=0;j<space;j++)
			{
				ofs.write((char*)(&spaces[i][j]), sizeof(int));
			}
		}
}
void Sala::savex(fstream &ofs)
{
	ofs.write((char*)(&row), sizeof(int));
	ofs.write((char*)(&space), sizeof(int));
	ofs.write((char*)(&number), sizeof(int));
	for (int i=0;i<row;i++)
		{
			for(int j=0;j<space;j++)
				ofs.write((char*)(&spaces[i][j]), sizeof(int));
		}
}
void Sala::read(ifstream &ifs)
{
	char *temp=new char [sizeof(int)];
	ifs.read(temp, sizeof(int));
	row=*(int*)temp;
	ifs.read(temp, sizeof(int));
	space=*(int*)(temp);
	ifs.read(temp, sizeof(int));
	number=*(int*)(temp);
	number_of_seats=row*space;
	spaces=new int*[row];
	for(int i=0;i<row;i++)
		spaces[i]=new int[space];
	//for(int i=0;i<row;i++)
	//	for(int j=0;j<space;j++)
		//	spaces[i][j]=0;
	for (int i=0;i<row;i++)
		for(int j=0;j<space;j++)
		{
			ifs.read(temp, sizeof(int));
			spaces[i][j]=*(int*)(temp);
			
		}
	delete temp;
}
