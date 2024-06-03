#include "Contact.h"
#include "Friend.h"
#include "Aqcuaintance.h"
#include "Colleague.h"
#include "AdressBook.h"

int main() {
    AddressBook addressBook;

    addressBook.addContact(new Friend("John Doe", "1990-01-01", "123-456-7890", "123 Elm Street"));
    addressBook.addContact(new Acquaintance("Jane Smith", "234-567-8901"));
    addressBook.addContact(new Colleague("Jim Brown", "345-678-9012", "Tech Corp", "456 Maple Avenue"));

    // Search by name
    Contact* contact = addressBook.searchContact("John Doe");
    if (contact) 
    {
        cout << "Found contact: " << contact->getName() << std::endl;
    } 
    else 
    {
        cout << "Contact not found" << std::endl;
    }

    // Get all friends
    vector<Friend*> friends = addressBook.getFriends();
    cout << "Friends in the address book:" << std::endl;
    for (const Friend* friendContact : friends) 
    {
        std::cout << friendContact->getName() << std::endl;
    }

    // Delete a contact
    addressBook.deleteContact("Jane Smith");
    contact = addressBook.searchContact("Jane Smith");
    if (contact) 
    {
        std::cout << "Found contact: " << contact->getName() << std::endl;
    } 
    else 
    {
        std::cout << "Contact not found" << std::endl;
    }

    return 0;
}