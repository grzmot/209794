#ifndef Film_h
#define Film_h
#include <string>
using namespace std;

class Film
{
	string title;
	int time;
	int restrictions;
	static int number_of_film;
public:
	Film();
	Film(string title,int time,int restrictions);
	Film(const Film &film);
	virtual ~Film();
	
	void set_title(string title);
	void set_time(int time);
	void set_restrictions(int restrictions);
	
	string get_title();
	int get_time();
	int get_restrictions();
	friend istream& operator>> (istream&,Film&);
	friend ostream& operator<< (ostream&,Film const&);
	static int get_number_of_film();
};
#endif
