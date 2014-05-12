#include "Seans.h"
#include <iostream>
int Seans::number_of_seans=0;
Seans::Seans():Film()
{
	number_of_seans++;
	hour.g=0;
	hour.m=0;
	type_seans="";
	sala=NULL;
}
Seans::Seans(string title,int time,int restrictions,int id_film, ::hour hour,Sala sala,string type_seans):Film(title,time,restrictions,id_film),hour(hour), type_seans(type_seans)
{
	number_of_seans++;
	this->sala=new Sala(sala);
}
Seans::Seans(const Film &film,::hour hour,Sala sala,string type_seans):Film(film),hour(hour),type_seans(type_seans)
{
	number_of_seans++;
	this->sala=new Sala(sala);
}
Seans::~Seans()
{
	number_of_seans--;
	if (sala!=NULL)
		delete sala;
}
void Seans::set_hour(::hour hour)
{
	this->hour=hour;
}
void Seans::set_sala(Sala sala)
{
	if(!(this->sala==NULL))
		delete this->sala;
	this->sala=new Sala(sala);
}
void Seans::set_type_seans(string type_seans)
{
	this->type_seans=type_seans;
}
::hour Seans::get_hour()
{
	return hour;
}
int Seans::get_number_of_hall()
{
	return sala->get_number();
}
Sala Seans::get_sala()
{
	return *sala;
}
Sala& Seans::get_sala2()
{
	return *this->sala;
}
string Seans::get_type_seans()
{
	return type_seans;
}
ostream& operator<< (ostream &output, Seans const& seans)
{
	output<<seans.hour.g<<":"<<seans.hour.m<<"  "<<static_cast<const Film&>(seans)<<"   "<<seans.type_seans<<"  sala: "<<(seans.sala->get_number())+1<<endl;
	return output;
}
int Seans::get_number_of_seans()
{
	return number_of_seans;
}
