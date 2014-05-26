#include "Posilek.h"
int Posilek::couter=0;
Posilek::Posilek()
{
	name="";
	cal=0;
	couter++;
}
Posilek::Posilek(string name,int cal)
{
	couter++;
	this->name=name;
	this->cal=cal;
}
Posilek::~Posilek()
{
	couter--;
}
int Posilek::get_couter()
{
	return couter;
}
string Posilek::get_name()
{
	return name;
}
int Posilek::get_cal()
{
	return cal;
}
void Posilek::set_name(string name)
{
	this->name=name;
}
void Posilek::set_cal(int cal)
{
	this->cal=cal;
}
