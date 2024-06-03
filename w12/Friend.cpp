#include "Friend.h"

Friend::Friend(const string& name, const string& dob, const string& phone, const string& address): Contact(name), dob(dob), phone(phone), address(address)
{

}

ContactType Friend:: getType() const 
{
    return ContactType::FRIEND;
}