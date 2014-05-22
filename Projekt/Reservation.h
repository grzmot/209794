#ifndef Reservation_h
#define Reservation_h
#include <fstream>
using namespace std;
class Reservation
{
	int reservation_number;
	int seans_id;
	int *row;
	int *space;
	int number;
	static int number_of_reservation;
public:
	Reservation();
	Reservation(int seans_id,int reservation_number,int number, int t_row[],int t_space[]);
	~Reservation();
	
	static int get_number_of_reservation();
	
	void set_seans_id(int seans_id);
	int get_number();
	int get_reservation_number();
	int get_seans_id();
	int* get_row();
	int* get_space();
	int get_row(int r);
	int get_space(int s);
	void save(ofstream &ofs);
	void read(ifstream &ifs);
};
#endif
