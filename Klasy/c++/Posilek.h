#ifndef Posilek_h
#define Posilek_h
#include <string>
using namespace std;
class Posilek
{
	string name;
	int cal;
	static int couter;
public:
	Posilek();
	Posilek(string name,int cal);
	~Posilek();
	static int get_couter();
	string get_name();
	int get_cal();
	void set_name(string name);
	void set_cal(int cal);
};
#endif
