#include "Circle.h"
int Circle::n=0;
int Circle::ilosc()
{
    return n;
}
Circle::Circle()
{
    location=(::location){0.0, 0.0};
    radius=0;
    n++;
}
Circle::Circle (::location location,double radius):location(location),radius(radius)
{
    n++;
}
Circle::~Circle()
{
    n--;
}
::location Circle::get_location()
{
    return location;
}
double Circle::get_radius()
{
    return radius;
}
void Circle::set_location(::location location)
{
    this->location=location;
}
void Circle::set_radius (double radius)
{
    this->radius=radius;
}
double Circle::circumference() 
{
    return 2*M_PI*radius;
}
double Circle::area()
{
    return M_PI*radius*radius;
}
Circle Circle::operator+(const Circle &c)const
{
    return Circle((::location){(location.x+c.location.x)/2.0,(location.y+c.location.y)/2.0},radius+c.radius);
}
Circle Circle::operator*(const double &s)const
{
    return Circle((::location){(location.x*s),(location.y*s)},radius*s);
}
