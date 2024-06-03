#include "ContactType.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Contact
{
    protected:
    string name;

    public:
    Contact(const string& name): name(name) {}
    virtual ~Contact()=default;
    string getName() const {return name;}
    virtual ContactType getType() const=0;
};