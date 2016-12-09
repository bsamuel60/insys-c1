#include "model.h"

void Model::write(const pair<string, string>& data)
{
    database[data.first] = data.second;
}

bool Model::get(const string& key, string& value)
{
    bool exists;

    item = database.find(key);
    exists = item != database.end();
    if (exists)
        value = database[key];
    return exists;
}

bool Model::search(const string& value)
{
    item = database.begin();
    while ((item->second!=value)&&item!=database.end())
        item++;
    return item != database.end();
}

bool Model::next(pair<string, string>& data, const string& value)
{
    data.first=item->first;
    data.second=item->second;
    do
    {
        item++;
    }
    while ((item->second!=value)&&item!=database.end());

    return item != database.end();
}

bool Model::dump()
{
    item = database.begin();
    return item != database.end();
}

bool Model::next(pair<string, string>& data)
{
    data.first=item->first;
    data.second=item->second;
    item++;
    return item != database.end();
}

bool Model::erase(const string& key)
{
    item=database.find(key);
    if (item!=database.end())
    {
        database.erase(key);
        return true;
    }
    else
        return false;
}
