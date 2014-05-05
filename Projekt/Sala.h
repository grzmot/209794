#ifndef Sala_h
#define Sala_h
struct place
{
    int x;
    int y;
};
class Sala
{
    ::place places;
    int ilosc;
public:
    Sala();
    Sala(::place place);
    ~Sala();
    void set_place(::place place);
    int get_ilosc();
};
#endif
