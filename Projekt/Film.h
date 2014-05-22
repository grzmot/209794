#ifndef Film_h
#define Film_h
#include <string>
#include <fstream>
using namespace std;

class Film
{
	string title;
	int time;
	int restrictions;
	int id_film;
	static int number_of_film;
public:
	Film();
	Film(string title,int time,int restrictions, int id_film);
	Film(const Film &film);
	virtual ~Film();
	
	static int get_number_of_film();
	static void set_number_of_film();
	
	void set_title(string title);
	void set_time(int time);
	void set_restrictions(int restrictions);
	void set_id_film(int id_film);
	
	string get_title();
	int get_time();
	int get_restrictions();
	int get_id_film();
	friend istream& operator>> (istream&,Film&);
	friend ostream& operator<< (ostream&,Film const&);
	void save(ofstream &ofs);
	void read(ifstream &ifs);
};
#endif
