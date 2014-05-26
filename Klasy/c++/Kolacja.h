#ifndef Kolacja_h
#define Kolacja_h
#include "Posilek.h"
using namespace std;
struct hour
{
	int h;
	int m;
};
class Kolacja : public Posilek
{
	::hour hour;
public:
	Kolacja();
	Kolacja(string name,int cal,::hour hour);
	~Kolacja();
	::hour get_hour();
	void set_hour(::hour hour);
};
#endif
