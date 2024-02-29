#include <bits/stdc++.h>
using namespace std;
struct data
{
    string firstName;
    string lastName;
    string email;
    long long phoneNumber;
};
class ContactM
{
public:
    ContactM();

    // member functions - add , edit , list , delete

    void addContact(string, string, long long, string);
    void addContact(); // accept details from the user

    void listAllContacts();

    // edit details

    void edit(int index);
    void editPhoneNumber(long long phoneNumber);
    void editName(string firstName, string lastName);
    void editEmail(string email);

    // delete user

    void removeUser(int index);
    void removeUserName(string);
    void removeUserNumber(long long);
    void removeUserEmail(string);

    // search user
    void searchName(string name);
    void searchNumber(long long phoneNumber);
    void searchEmail(string email);

    void backUp(long long phoneNumber);

    // array of struct data
    vector<struct data> info;
};