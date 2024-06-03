#include "AdressBook.h"

AdressBook::~AdressBook()
{
    for(auto i:list)
    {
        delete i;
    }
}

void AdressBook::addContact(Contact* cont)
{
    list.push_back(cont);
}

Contact* AdressBook::searchContact(const string& name)
{
    for(auto i:list)
    {
        if(i->getName()==name)
        {
            return const_cast<Contact*>(i);
        }
    }
    return nullptr;
 
}

vector<Friend*> AdressBook::getFriends()
{
    vector<Friend*> friends;
    for(auto i : list)
    {
        if(i->getType()==ContactType::FRIEND)
        {
            friends.push_back(dynamic_cast<Friend*>(const_cast<Contact*>(i)));
        }
    }
    return friends;
}

void AdressBook::deleteContact(const string& name) 
{
    for(int i=0; i<list.size(); i++)
    {
        if(list[i]->getName()==name)
        {
            delete list[i];
            list.erase(list.begin()+i);
            break;
        }
    }
}
