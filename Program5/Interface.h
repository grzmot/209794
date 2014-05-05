#ifndef Interface_h
#define Interface_h
#include <string>
using namespace std;
class Interface
{
public:
    virtual bool operator <(Interface& d)const=0;
    virtual bool operator ==(Interface& d)const=0;
};

#endif

