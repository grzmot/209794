#include "Reservation.h"
#include <iostream>
int Reservation::number_of_reservation=0;
Reservation::Reservation()
{
	row=NULL;
	space=NULL;
	seans_id=0;
	reservation_number=0;
	number=0;
	number_of_reservation++;
}
Reservation::Reservation(int seans_id,int reservation_number,int number, int t_row[],int t_space[]):number(number),
	seans_id(seans_id),
	reservation_number(reservation_number)
{
	number_of_reservation++;
	row =new int[number];
	space=new int[number];
	for(int i=0;i<number;i++)
	{
		row[i]=t_row[i];
		space[i]=t_space[i];
	}
}
Reservation::~Reservation()
{
	number_of_reservation--;
	if (row!=NULL)
		delete []row;
	if (space!=NULL)
		delete []space;
}
void Reservation::set_seans_id(int seans_id)
{
	this->seans_id=seans_id;
}
int Reservation::get_number()
{
	return number;
}
int Reservation::get_reservation_number()
{
	return reservation_number;
}
int Reservation::get_seans_id()
{
	return seans_id;
}
int* Reservation::get_row()
{
	return row;
}
int* Reservation::get_space()
{
	return space;
}
int Reservation::get_row(int r)
{
	return row[r];
}
int Reservation::get_space(int s)
{
	return space[s];
}
int Reservation::get_number_of_reservation()
{
	return number_of_reservation;
}
