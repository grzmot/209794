#include "Seans.h"
#include <iostream>
int Seans::number_of_seans=0;
Seans::Seans():Film()
{
	number_of_seans++;
	hour.g=0;
	hour.m=0;
	day.d=0;
	day.m=0;
	day.y=0;
	type_seans="";
	sala=NULL;
}
Seans::Seans(string title,int time,int restrictions,int id_film, ::hour hour,::day day, Sala sala,string type_seans):Film(title,time,restrictions,id_film),hour(hour),day(day), type_seans(type_seans)
{
	number_of_seans++;
	this->sala=new Sala(sala);
}
Seans::Seans(const Film &film,::hour hour,::day day,Sala sala,string type_seans):Film(film),hour(hour),day(day),type_seans(type_seans)
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
void Seans::set_day(::day day)
{
	this->day=day;
}
::day Seans::get_day()
{
	return day;
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
	output<<seans.day.d<<"."<<seans.day.m<<"."<<seans.day.y<<" "<<seans.hour.g<<":"<<seans.hour.m<<"  "<<static_cast<const Film&>(seans)<<"   "<<seans.type_seans<<"  sala: "<<(seans.sala->get_number())+1<<endl;
	return output;
}
int Seans::get_number_of_seans()
{
	return number_of_seans;
}
void Seans::save(ofstream &ofs)
{
	Film::save(ofs);
	int x;
	x=type_seans.length();
	ofs.write((char*)(&x), sizeof(int));
	ofs.write((char*)(type_seans.c_str()), x);
	ofs.write((char*)(&hour.g), sizeof(int));
	ofs.write((char*)(&hour.m), sizeof(int));
	ofs.write((char*)(&day.d), sizeof(int));
	ofs.write((char*)(&day.m), sizeof(int));
	ofs.write((char*)(&day.y), sizeof(int));
	sala->save(ofs);
}
void Seans::read(ifstream &ifs)
{
	Film::read(ifs);
	int x;
	char* temp = new char[sizeof(int)];
	ifs.read(temp, sizeof(int));
	x=*(int*)(temp);
	delete temp;
	temp = new char[x];
	ifs.read(temp, x);
	for(int i=0;i<x;i++)
		type_seans=type_seans+(temp[i]);
	delete temp;
	temp=new char[sizeof(int)];
	ifs.read(temp, sizeof(int));
	hour.g=*(int*)(temp);
	ifs.read(temp, sizeof(int));
	hour.m=*(int*)(temp);
	ifs.read(temp, sizeof(int));
	day.d=*(int*)(temp);
	ifs.read(temp, sizeof(int));
	day.m=*(int*)(temp);
	ifs.read(temp, sizeof(int));
	day.y=*(int*)(temp);
	delete temp;
	if (sala==NULL)
		sala= new Sala();
	sala->read(ifs);
}
