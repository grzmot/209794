#include "Kolacja.h"
Kolacja::Kolacja():Posilek()
{
	hour.h=0;
	hour.m=0;
}
Kolacja::Kolacja(string name,int cal,::hour hour):Posilek(name,cal)
{
	this->hour=hour;
}
Kolacja::~Kolacja()
{
}
::hour Kolacja::get_hour()
{
	return hour;
}
void Kolacja::set_hour(::hour hour)
{
	this->hour=hour;
}
