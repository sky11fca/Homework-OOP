#include "Contact.h"

class Acquaintance: public Contact
{
    string phone;

    public:
    Acquaintance(const string& name, const string& phone);
    ContactType getType() const override;
}