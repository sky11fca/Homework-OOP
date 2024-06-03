#include "Contact.h"

class AdressBook
{
    vector<Contact*> list;

    public:

    ~AdressBook();
    void addContact(Contact* cont);
    Contact* searchContact(const string& name);
    vector<Friend*> getFriend();
    void deleteContact(const string& name);
}