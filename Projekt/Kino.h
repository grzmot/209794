#ifndef Kino_h
#define Kino_h
#include "Sala.h"
#include "Film.h"
#include "Seans.h"
#include "Reservation.h"
#include "Ticket.h"
class Kino
{
	Sala **sala;
	Film **film;
	Seans **seans;
	Reservation **reservation;
	Ticket *ticket;
	int size_sala;
	int size_film;
	int size_seans;
	int size_reservation;
	void resize_sala();
	void resize_film();
	void resize_seans();
	void resize_reservation();
public:
	Kino();
	~Kino();
	Seans get_seans(int id_seans);
	void view_sala();
	void view_sala(int id_sala);
	void view_film();
	void view_film(int id_film);
	void view_seans();
	void view_seans(int id_seans);
	void view_seans_sala(int id_seans);
	void view_reservation();
	void set_tickets();
	void view_ticket_price();
	void buy_ticket(int number);
	
	
	void g_sala(int row,int space,int id);
	void g_film(string title,int time,int restrictions, int id);
	void g_seans(::hour hour, string type_seans,int id,int id_film,int id_sala);
	
	
	void add_sala();
	void add_film();
	void add_seans();
	void add_reservation();
	
	//id_xx- is a number in the array
	void delete_sala(int id_sala);
	void delete_film(int id_film);
	void delete_seans(int id_seans);
	void delete_reservation(int id_reservation);
};
#endif
