#ifndef Circle_h
#define Circle_h
#include <Math.h>
struct location{
    double x,y;
};
class Circle
{
    ::location location;
    double radius;
    static int n;
    
    public:
    Circle();
    Circle (::location location,double radius);
    ~Circle();
    
    ::location get_location();
    double get_radius ();
    void set_location (::location location);
    void set_radius (double radius);
    double circumference();
    double area();
    Circle operator+(const Circle &c);
    Circle operator*(const double &s);

    static int ilosc();
};
#endif
