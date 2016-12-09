#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class View
{
public:
	void present(const string& text);
	char getchar();
	pair<string, string> getdata();
	string getstring();
};
