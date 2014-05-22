#ifndef Ticket_h
#define Ticket_h
#include <iostream>
#include <fstream>
using namespace std;
class Ticket
{
	double ticket[2][3];
public:
	Ticket();
	Ticket(double normal_2D, double normal_3D, double reduced_2D, double reduced_3D, double group_2D,double group_3D);
	~Ticket();
	
	void set_normal_2D(double normal_2D);
	void set_normal_3D(double normal_3D);
	void set_reduced_2D(double reduced_2D);
	void set_reduced_3D(double reduced_3D);
	void set_group_2D(double group_2D);
	void set_group_3D(double group_3D);
	double get_normal_2D();
	double get_normal_3D();
	double get_reduced_2D();
	double get_reduced_3D();
	double get_group_2D();
	double get_group_3D();
	friend istream& operator>> (istream&,Ticket&);
	friend ostream& operator<< (ostream&,Ticket const&);
	void save(ofstream &ofs);
	void read(ifstream &ifs);
};
#endif
