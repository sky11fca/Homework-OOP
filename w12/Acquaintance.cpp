#include "Acquaintance.h"

Acquaintance::Acquaintance(const string& name, const string& phone): Contact(name), phone(phone)
{

}

ContactType Acquaintance::getType() const 
{
    return ContactType::ACQUAINTANCE;
}