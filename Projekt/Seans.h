#ifndef Seans_h
#define Seans_h
#include "Film.h"
#include "Sala.h"
#include <string>
using namespace std;
struct hour
{
	int g;
	int m;
};
class Seans : public Film
{
	::hour hour;
	Sala *sala;
	string type_seans;
	static int number_of_seans;
public:
	Seans();
	Seans(string title,int time,int restrictions, ::hour hour,Sala sala,string type_seans);
	Seans(const Film &film,::hour hour,Sala sala, string type_seans);
	~Seans();
	
	static int get_number_of_seans();
	
	void set_hour(::hour hour);
	void set_sala(Sala sala);
	void set_type_seans(string type_seans);
	::hour get_hour();
	int get_number_of_hall();
	Sala get_sala();
	Sala& get_sala2();
	string get_type_seans();
	friend ostream& operator<< (ostream&,Seans const&);
};
#endif
