#include "Contact.h"

class Colleague: public Contact
{
    string phone;
    string company;
    string address;

    public:
    Colleague(const string& name, const string& phone, const string& company, const string& address);
    ContactType getType() const override;
}