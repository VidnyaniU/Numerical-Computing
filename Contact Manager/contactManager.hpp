#include <bits/stdc++.h>
using namespace std;
struct data
{
    string firstName;
    string lastName;
    string email;
    ulong phoneNumber;
};
class ContactM
{
public:
    ContactM();
    ContactM(string, string, ulong, string);

    // member functions - add , edit , list , delete
    void AddContact(string, string, ulong, string);
    void ListAllContacts();
    void DeleteContact(ulong phoneNumber);

    // array of struct data
    vector<struct data> info;
};