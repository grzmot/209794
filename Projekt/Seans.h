#ifndef Seans_h
#define Seans_h
#include "Film.h"
#include "Sala.h"
#include <string>
#include <fstream>
using namespace std;
struct day
{
	int d;
	int m;
	int y;
};
struct hour
{
	int g;
	int m;
};
class Seans : public Film
{
	::hour hour;
	Sala *sala;
	:: day day;
	string type_seans;
	static int number_of_seans;
public:
	Seans();
	Seans(string title,int time,int restrictions,int id_film, ::hour hour,::day day,Sala sala,string type_seans);
	Seans(const Film &film,::hour hour,::day day,Sala sala, string type_seans);
	~Seans();
	
	static int get_number_of_seans();
	
	void set_hour(::hour hour);
	void set_sala(Sala sala);
	void set_type_seans(string type_seans);
	void set_day(::day day);
	::day get_day();
	::hour get_hour();
	int get_number_of_hall();
	Sala get_sala();
	Sala& get_sala2();
	string get_type_seans();
	friend ostream& operator<< (ostream&,Seans const&);
	void save(ofstream &ofs);
	void read(ifstream &ifs);
};
#endif
