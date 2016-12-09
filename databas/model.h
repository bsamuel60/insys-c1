#include <string>
#include <map>

using namespace std;

class Model
{
	map<string, string> database;
	map<string, string>::iterator item;
public:
	void write(const pair<string,string>& data);
	bool get(const string& key,string& value);
	bool search(const string& value);
	bool next(pair<string, string>& data, const string& value);
	bool dump();
	bool next(pair<string, string>& data);
	bool erase(const string& key);
};
