#include "contactManager.hpp"

using namespace std;

ContactM::ContactM()
{
}
void ContactM::AddContact(string firstName, string lastName, ulong phoneNumber, string email)
{
    struct data temp;
    temp.firstName = firstName;
    temp.lastName = lastName;
    temp.phoneNumber = phoneNumber;
    temp.email = email;

    info.push_back(temp);
}

void ContactM::ListAllContacts()
{
    for (int i = 0; i < info.size(); i++)
    {
        cout << "\nFirst Name :: " << info[i].firstName << "\nLast Name :: " << info[i].lastName << "\nPhone Number :: " << info[i].phoneNumber << "\nEmail :: " << info[i].email << endl;
    }
}

void ContactM::DeleteContact(ulong phoneNumber){
    

}