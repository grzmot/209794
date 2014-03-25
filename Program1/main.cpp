#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <Math.h>

using namespace std;

struct location{
    double x,y;
};
class Circle
{
    location Location;
    double radius;
    public:
        location get_location(){return Location;}
        double get_radius (){return radius;}
        void set_location (location w) {Location=w;}
        void set_radius (double r){radius=r;}
        double circumference() {return 2*M_PI*radius;}
        double area(){return M_PI*radius*radius;}
};
int main(int argc, char *argv[])
{
    Circle circle;
circle.set_location((location){ 4.0, 2.0 });
circle.set_radius(15.0);

printf("Circle location is %.1fx%.1f.\n", 
    circle.get_location().x, circle.get_location().y);
printf("Circle radius is %.1f.\n", 
    circle.get_radius());
printf("Circle circumference is %.2f.\n", 
    circle.circumference());
printf("Circle area is %.2f.\n", 
    circle.area());
    system("PAUSE");
    return EXIT_SUCCESS;
}
