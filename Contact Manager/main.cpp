#include <bits/stdc++.h>
#include "contactManager.hpp"

using namespace std;

int main()
{
    ContactM cm;
    cm.addContact("Vid", "Umathe", 4641646654, "vid@gmail.com");
    cm.addContact("Bun", "Bun", 6466466541, "bun@gmail.com");
    cm.addContact("Gru", "Min", 6879466540, "gru@gmail.com");

    // cm.listAllContacts();

    // cm.DeleteContact(4641646654);
    // cm.addContact();
    // cm.removeUserEmail("vid@gmail.com");
    // cm.removeUserName("Vid");
    // cm.searchEmail("gru@gmail.com");
    cm.listAllContacts();
    // cm.backUp(4641646654);
    cout << endl;
    return 0;
}
