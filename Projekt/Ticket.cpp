#include "Ticket.h"
#include <windows.h>
Ticket::Ticket()
{
	ticket[0][0]=0;
	ticket[1][0]=0;
	ticket[0][1]=0;
	ticket[1][1]=0;
	ticket[0][2]=0;
	ticket[1][2]=0;
}
Ticket::Ticket(double normal_2D, double normal_3D, double reduced_2D, double reduced_3D, double group_2D,double group_3D)
{
	ticket[0][0]=normal_2D;
	ticket[1][0]=normal_3D;
	ticket[0][1]=reduced_2D;
	ticket[1][1]=reduced_3D;
	ticket[0][2]=group_2D;
	ticket[1][2]=group_3D;
}
Ticket::~Ticket()
{
}

void Ticket::set_normal_2D(double normal_2D)
{
	ticket[0][0]=normal_2D;
}
void Ticket::set_normal_3D(double normal_3D)
{
	ticket[1][0]=normal_3D;
}
void Ticket::set_reduced_2D(double reduced_2D)
{
	ticket[0][1]=reduced_2D;
}
void Ticket::set_reduced_3D(double reduced_3D)
{
	ticket[1][1]=reduced_3D;
}
void Ticket::set_group_2D(double group_2D)
{
	ticket[0][2]=group_2D;
}
void Ticket::set_group_3D(double group_3D)
{
	ticket[1][2]=group_3D;
}
double Ticket::get_normal_2D()
{
	return ticket[0][0];
}
double Ticket::get_normal_3D()
{
	return ticket[1][0];
}
double Ticket::get_reduced_2D()
{
	return ticket[0][1];
}
double Ticket::get_reduced_3D()
{
	return ticket[1][1];
}
double Ticket::get_group_2D()
{
	return ticket[0][2];
}
double Ticket::get_group_3D()
{
	return ticket[1][2];
}
istream& operator>> (istream &input, Ticket& ticketes)
{
	cout<<endl<<"Podaj ceny biletow"<<endl;
	cout<<endl<<"Cena biletu Normalnego(2D)[zl]: ";
	input>>ticketes.ticket[0][0];
	cout<<endl<<"Cena biletu Narmalnego(3D)[zl]: ";
	input>>ticketes.ticket[1][0];
	cout<<endl<<"Cena biletu Ulgowego(2D)[zl]: ";
	input>>ticketes.ticket[0][1];
	cout<<endl<<"Cena biletu Ulgowegogo(3D)[zl]: ";
	input>>ticketes.ticket[1][1];
	cout<<endl<<"Cena biletu Grupowego(2D)[zl]: ";
	input>>ticketes.ticket[0][2];
	cout<<endl<<"Cena biletu Grupowego(3D)[zl]: ";
	input>>ticketes.ticket[1][2];
	return input;
}
ostream& operator<< (ostream &output, Ticket const& ticketes)
{
	cout.width(10);
	output <<endl<<endl<<left<<"Bilet:";
	cout.width(6);
	output<<left<<"  2D"<<left<<"  3D"<<endl;
	cout.width(10);
	output<<"Normalny";
	cout.width(3);
	output<<left<<ticketes.ticket[0][0]<<"zl  "<<left<<ticketes.ticket[1][0]<<"zl"<<endl;
	cout.width(10);
	output<<"Ulgowy";
	cout.width(3);
	output<<left<<ticketes.ticket[0][1]<<"zl  "<<left<<ticketes.ticket[1][1]<<"zl"<<endl;
	cout.width(10);
	output<<"Grupowy";
	cout.width(3);
	output<<left<<ticketes.ticket[0][2]<<"zl  "<<left<<ticketes.ticket[1][2]<<"zl"<<endl<<endl;
	return output;
}
void Ticket::save(ofstream &ofs)
{
	ofs.write((char*)(&ticket[0][0]), sizeof(double));
	ofs.write((char*)(&ticket[0][1]), sizeof(double));
	ofs.write((char*)(&ticket[0][2]), sizeof(double));
	ofs.write((char*)(&ticket[1][0]), sizeof(double));
	ofs.write((char*)(&ticket[1][1]), sizeof(double));
	ofs.write((char*)(&ticket[1][2]), sizeof(double));
}
void Ticket::read(ifstream &ifs)
{
	char* temp = new char[sizeof(double)];
	ifs.read(temp, sizeof(double));
	ticket[0][0]=*(double*)(temp);
	ifs.read(temp, sizeof(double));
	ticket[0][1]=*(double*)(temp);
	ifs.read(temp, sizeof(double));
	ticket[0][2]=*(double*)(temp);
	ifs.read(temp, sizeof(double));
	ticket[1][0]=*(double*)(temp);
	ifs.read(temp, sizeof(double));
	ticket[1][1]=*(double*)(temp);
	ifs.read(temp, sizeof(double));
	ticket[1][2]=*(double*)(temp);
	delete temp;
}
