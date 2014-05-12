#include "Film.h"
#include <iostream>

int Film::number_of_film=0;
Film::Film()
{
	number_of_film++;
	title="";
	time=0;
	restrictions=0;
}
Film::Film(string title,int time,int restrictions):title(title),time(time),restrictions(restrictions)
{
	number_of_film++;
}
Film::Film(const Film &film)
{
	number_of_film++;
	title=film.title;
	time=film.time;
	restrictions=film.restrictions;
}
Film::~Film()
{
	number_of_film--;
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
istream& operator>> (istream &input, Film& film)
{
	cout<<"Podaj tylul filmu:   ";
	input>>film.title;
	cout<<endl<<"Podaj dlugosc filmu [min]:   ";
	input>>film.time;
	cout<<"Podaj ograniczenia wiekowe (do lat):   ";
	input>>film.restrictions;
	return input;
}
ostream& operator<< (ostream &output, Film const& film)
{
	output<<film.title<<"  "<<"dlugosc: "<<film.time<<" min  "<<"ograniczenia wiekowe: +"<<film.restrictions;
	return output;
}
int Film::get_number_of_film()
{
	return number_of_film;
}
