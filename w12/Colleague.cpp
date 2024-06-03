#include "Colleague.h"

Colleague::Colleague(const string& name, const string& phone, const string& company, const string& address): Contact(name), phone(phone), company(company), address(address)
{

}

ContactType Colleague::getType() const 
{
    return ContactType::COLLEAGUE;
}