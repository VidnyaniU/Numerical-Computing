#include <bits/stdc++.h>
#include "contactManager.hpp"

using namespace std;

int main()
{
    ContactM cm;
    cm.AddContact("Vid", "Umathe", 4641646654, "vid@gmail.com");
    cm.AddContact("Bun", "Bun", 6466466541, "bun@gmail.com");
    cm.AddContact("Gru", "Min", 6879466540, "gru@gmail.com");

    cm.ListAllContacts();

    return 0;
}
