#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    map<string,string> databas;

    databas["Sverige"] = "Stockholm";
    databas["Kenya"] = "Nairobi";
    databas["Finland"] = "Helsingfors";
    databas["Norge"] = "Oslo";
    databas["Burkina Faso"] = "Ouagadougou";
    databas["Chile"] = "Santiago";

    cout << databas["Norge"] << endl;

    map<string,string>::iterator it;

    for (it=databas.begin(); it!=databas.end();++it)
    return 0;
}
