#include "Film.h"
#include <iostream>

int Film::number_of_film=0;
Film::Film()
{
	number_of_film++;
	title="";
	time=0;
	restrictions=0;
	id_film=0;
}
Film::Film(string title,int time,int restrictions,int id_film):title(title),time(time),restrictions(restrictions),id_film(id_film)
{
	number_of_film++;
}
Film::Film(const Film &film)
{
	title=film.title;
	time=film.time;
	restrictions=film.restrictions;
	id_film=film.id_film;
}
Film::~Film()
{
}

void Film::set_title(string title)
{
	this->title=title;
}
void Film::set_time(int time)
{
	this->time=time;
}
void Film::set_restrictions(int restrictions)
{
	this->restrictions=restrictions;
}
void Film::set_id_film(int id_film)
{
	this->id_film=id_film;
}
string Film::get_title()
{
	return title;
}
int Film::get_time()
{
	return time;
}
int Film::get_restrictions()
{
	return restrictions;
}
int Film::get_id_film()
{
	return id_film;
}
istream& operator>> (istream &input, Film& film)
{
	fflush( stdin );
	cout<<"Podaj tylul filmu:   ";
	getline(cin,film.title);
	cout<<endl<<"Podaj dlugosc filmu [min]:   ";
	input>>film.time;
	cout<<"Podaj ograniczenia wiekowe (od lat):   ";
	input>>film.restrictions;
	return input;
}
ostream& operator<< (ostream &output, Film const& film)
{
	output<<film.title<<"  "<<film.time<<" min  "<< "+"<<film.restrictions;
	return output;
}
int Film::get_number_of_film()
{
	return number_of_film;
}
void Film::set_number_of_film()
{
	number_of_film--;
}
void Film::save(ofstream &ofs)
{
	int x=title.length();
	char *c;
	c= new char[x];
	for(int i=0;i<x;i++)
		c[i]=title[i];
	ofs.write((char*)(&x), sizeof(int));
	ofs.write((char*)(c), x);
	ofs.write((char*)(&time), sizeof(int));
	ofs.write((char*)(&restrictions), sizeof(int));
	ofs.write((char*)(&id_film), sizeof(int));
}
void Film::read(ifstream &ifs)
{
	int x;
	char* temp = new char[sizeof(int)];
	ifs.read(temp, sizeof(int));
	x=*(int*)(temp);
	delete temp;
	temp = new char[x];
	ifs.read(temp, x);
	for(int i=0;i<x;i++)
	{
		title=title+(temp[i]);
	}
	delete temp;
	temp=new char[sizeof(int)];
	ifs.read(temp, sizeof(int));
	time=*(int*)(temp);
	ifs.read(temp, sizeof(int));
	restrictions=*(int*)(temp);
	ifs.read(temp, sizeof(int));
	id_film=*(int*)(temp);
	delete temp;
}
