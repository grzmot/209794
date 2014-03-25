#include "Circle.h"
location Circle::get_location(){return olocation;}
double Circle::get_radius (){return radius;}
void Circle::set_location (location w) {olocation=w;}
void Circle::set_radius (double r){radius=r;}
double Circle::circumference() {return 2*M_PI*radius;}
double Circle::area(){return M_PI*radius*radius;}
Circle::Circle(){olocation=(location){0.0, 0.0}; radius=0;}
Circle::Circle (location l,double r){olocation=l; radius=r;}
Circle::~Circle(){}
Circle Circle::operator+(const Circle & c)const
{
    return Circle((location){(olocation.x+c.olocation.x)/2.0,(olocation.y+c.olocation.y)/2.0},radius+c.radius);
    }
Circle Circle::operator*(const double & s)const
{
    return Circle((location){(olocation.x*s),(olocation.y*s)},radius*s);
}
int Circle::n=0;
void Circle::dilosc(){n++;}
void Circle::dilosc(int z){n=n+z;}
int Circle::ilosc(){return n;}


