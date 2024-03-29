#include "contactManager.hpp"

using namespace std;

ContactM::ContactM()
{
}

void ContactM::addContact(string firstName, string lastName, long long phoneNumber, string email)
{
    struct data temp;
    temp.firstName = firstName;
    temp.lastName = lastName;
    temp.phoneNumber = phoneNumber;
    temp.email = email;

    info.push_back(temp);
}
void ContactM ::addContact()
{
    struct data temp;
    cout << "Enter first name: ";
    cin >> temp.firstName;
    cout << "Enter last name: ";
    cin >> temp.lastName;
    cout << "Enter phone number: ";
    cin >> temp.phoneNumber;
    cout << "Enter email: ";
    cin >> temp.email;

    info.push_back(temp);
}

void ContactM::listAllContacts()
{
    for (int i = 0; i < info.size(); i++)
    {
        cout << "\nFirst Name :: " << info[i].firstName << "\nLast Name :: " << info[i].lastName << "\nPhone Number :: " << info[i].phoneNumber << "\nEmail :: " << info[i].email << endl;
    }
}

void ContactM::edit(int index)
{
    cout << "Edited first name: ";
    cin >> info[index].firstName;
    cout << "Edited last name: ";
    cin >> info[index].lastName;
    cout << "Edited phone number: ";
    cin >> info[index].phoneNumber;
    cout << "Edited email: ";
    cin >> info[index].email;
}
void ContactM::editPhoneNumber(long long phoneNumber)
{
    // find the index of the number
    int index = 0;
    for (int i = 0; i < info.size(); i++)
    {
        if (info[i].phoneNumber == phoneNumber)
        {
            index = i;
            break;
        }
    }
    cout << "Edited phone number: ";
    cin >> info[index].phoneNumber;
}
void ContactM::editName(string firstName, string lastName)
{
    // find the index of the name
    int index = 0;
    for (int i = 0; i < info.size(); i++)
    {
        if (info[i].firstName == firstName && info[i].lastName == lastName)
        {
            index = i;
            break;
        }
    }
    cout << "Edited first name: ";
    cin >> info[index].firstName;
    cout << "Edited last name: ";
    cin >> info[index].lastName;
}
void ContactM::editEmail(string email)
{
    // find the index of the email
    int index = 0;
    for (int i = 0; i < info.size(); i++)
    {
        if (info[i].email == email)
        {
            index = i;
            break;
        }
    }
    cout << "Edited email: ";
    cin >> info[index].email;
}

void ContactM::removeUser(int index)
{
    // erase contact from that index
    info.erase(info.begin() + index);
}
void ContactM::removeUserName(string firstName)
{
    // find the index of the name
    int index = 0;
    for (int i = 0; i < info.size(); i++)
    {
        if (info[i].firstName == firstName)
        {
            index = i;
            break;
        }
    }

    // remove username
    info[index].firstName = "";
}
void ContactM::removeUserNumber(long long phoneNumber)
{
    // find the index of the phoneNumber
    int index = 0;
    for (int i = 0; i < info.size(); i++)
    {
        if (info[i].phoneNumber == phoneNumber)
        {
            index = i;
            break;
        }
    }
    // remove phoneNumber
    info[index].phoneNumber = 0;
}
void ContactM::removeUserEmail(string email)
{
    // find the index of the email
    int index = 0;
    for (int i = 0; i < info.size(); i++)
    {
        if (info[i].email == email)
        {
            index = i;
            break;
        }
    }
    // remove email
    info[index].email = "";
}

void ContactM::searchName(string firstName)
{
    // find the index of the name
    int index = 0;
    for (int i = 0; i < info.size(); i++)
    {
        if (info[i].firstName == firstName)
        {
            index = i;
            break;
        }
    }
    cout << "\nFirst Name :: " << info[index].firstName << "\nLast Name :: " << info[index].lastName << "\nPhone Number :: " << info[index].phoneNumber << "\nEmail :: " << info[index].email << endl;
}
void ContactM::searchNumber(long long phoneNumber)
{
    // find the index of the number
    int index = 0;
    for (int i = 0; i < info.size(); i++)
    {
        if (info[i].phoneNumber == phoneNumber)
        {
            index = i;
            break;
        }
    }
    cout << "\nFirst Name :: " << info[index].firstName << "\nLast Name :: " << info[index].lastName << "\nPhone Number :: " << info[index].phoneNumber << "\nEmail :: " << info[index].email << endl;
}
void ContactM::searchEmail(string email)
{
    // find the index of the email
    int index = 0;
    for (int i = 0; i < info.size(); i++)
    {
        if (info[i].email == email)
        {
            index = i;
            break;
        }
    }
    cout << "\nFirst Name :: " << info[index].firstName << "\nLast Name :: " << info[index].lastName << "\nPhone Number :: " << info[index].phoneNumber << "\nEmail :: " << info[index].email << endl;
}

void ContactM::backUp()
{

    // backup file
    ofstream backupFile("backup.txt", ios::out);

    // write the contact details to the backup file

    for (int i = 0; i < info.size(); i++)
    {
        backupFile << "First Name: " << info[i].firstName << endl;
        backupFile << "Last Name: " << info[i].lastName << endl;
        backupFile << "Phone Number: " << info[i].phoneNumber << endl;
        backupFile << "Email: " << info[i].email << endl;
        backupFile << endl;
    }

    // close the backup file
    backupFile.close();

    cout << "\nBackup created successfully!\n\n";
}

void ContactM::restore()
{
    string details;

    ifstream restoreFile("backup.txt");
    while (getline(restoreFile, details))
    {
        cout << details;
        cout << endl;
    }
    restoreFile.close();
}