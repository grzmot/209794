#ifndef Sala_h
#define Sala_h

class Sala
{
	int row;
	int space;
	int number;
	int number_of_seats;
	bool **spaces;
	static int number_of_hall;
	
public:
	Sala();
	Sala(int row, int space, int number);
	Sala(const Sala &hall);
	~Sala();
	
	static int get_number_of_hall();
	static void set_number_of_hall();
	
	void set_number(int number);
	void set_spaces(int row, int space);
	int get_number();
	int get_number_of_seats();
	void view_spaces();
	void take_seat(int row[], int space[],int number_seats);//zajmij miejsca
	void relase_seat(int row[], int space[], int number_seats);//zwolnij miejsca
	bool place_free(int row,int place);
	
};
#endif
