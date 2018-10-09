/* HashMap with Open Addressing */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstddef>
using namespace std;

#define NIL "NIL"
#define DELETED "DELETED"

class HashMap
{
    private:
        vector<string> table;

        unsigned int SDBMHash(string &s) const;

    public:
        HashMap(size_t capability);

        bool find(string &s) const;
        void insert(string &s);
        bool remove(string &s);
};

unsigned int HashMap::SDBMHash(string &s) const
{
    unsigned int hash = 0, i = 0;
    for (; i < s.length(); ++ i)
    {
        hash = s[i] + (hash << 6) + (hash << 16) - hash;
    }
    return (hash % table.size());
}

HashMap::HashMap(size_t capability)
{
    table.resize(capability);
    fill_n(table.begin(), capability, NIL);
}

bool HashMap::find(string &s) const
{
    unsigned int hash = SDBMHash(s);
    for (size_t i = 0; i < table.size(); ++ i)
    {
        unsigned int idx = (hash + i) % table.size();
        if (table[idx] == NIL)  return false;
        if (table[idx]==DELETED)    continue;
        if (table[idx] == s)    return true;
    }
    return false;
}

void HashMap::insert(string &s)
{
    unsigned int hash = SDBMHash(s);
    if (find(s))    
    {
        cout << "The element has already stored..." << endl;
        return;
    }
    for (size_t i = 0; i < table.size(); ++ i)
    {
        unsigned int idx = (hash + i) % table.size();
        if (table[idx] == NIL || table[idx] == DELETED)
        {
            table[idx] = s;
            break;
        }
    }
}

bool HashMap::remove(string &s)
{
    unsigned int hash = SDBMHash(s);
    if (!find(s))
    {
        cout << "No matching result found...";
        return false;
    }
    for (size_t i = 0; i < table.size(); ++ i)
    {
        unsigned int idx = (hash + i) % table.size();
        if (table[idx] == NIL)  return false;
        if (table[idx] == DELETED)  continue;
        table[idx] = DELETED;
        break;
    }
    return true;
}

int main(int argc, char **argv)
{
    HashMap hm(10);
    string s;
    for (int i = 0; i < 5; ++ i)
    {
        cin >> s;
        hm.insert(s);
    }
    while (cin >> s)
    {
        if (hm.find(s))
        {
            cout << "Found..." << endl;
            hm.remove(s);
        }
        else    cout << "Not Found..." << endl;
    }
    return 0;
}