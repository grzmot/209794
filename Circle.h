#ifndef Circle_h
#define Circle_h
#include <Math.h>
struct location{
    double x,y;
};
class Circle
{
    location Location;
    double radius;
    static int n;
    public:
        Circle();
        Circle (location l,double r);
        ~Circle();
        location get_location();
        double get_radius ();
        void set_location (location w);
        void set_radius (double r);
        double circumference();
        double area();
        Circle operator+(const Circle & c)const;
        Circle operator*(const double & s)const;
        static void dilosc();
        static void dilosc(int z);
        static int ilosc();
};
#endif
