#include "Contact.h"

class Friend: public Contact
{
    string dob;
    string phone;
    string address;

    public:
    Friend(const string& name, const string& dob, const string& phone, const string& address);
    ContactType getType() const override;
}