#include "view.h"

void View::present(const string& text)
{
    cout << text;
}

char View::getchar()
{
    char c;
    cin.get(c);
    return c;
}

pair<string, string> View::getdata()
{
    pair<string, string> input;
    string line;
    getline(cin, line);
    stringstream ss(line);
    ss >> input.first >> input.second;
    return input;
}

string View::getstring()
{
    string s;
    cin >> s;
    return s;
}
