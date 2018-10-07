/* Hash Table with Linked List */

#include <iostream>
#include <string>
using namespace std;

#define M 10

struct HashTable
{
    private:
        struct node
        {
            node *prev;
            node *next;
            string name;
            node(string &val) : name(val), prev(0), next(0) {}
        };

        static node *table[M];
        static unsigned int SDBMHash(string &s);

    public:
        static bool find(string &s);
        static void insert(string &s);
        static bool remove(string &s);
};

HashTable::node *HashTable::table[M] = {0,0,0,0,0,0,0,0,0,0};

unsigned int HashTable::SDBMHash(string &s)
{
    unsigned int hash = 0, i = 0;
    for (; i < s.length(); ++ i)
    {
        hash = s[i] + (hash << 6) + (hash << 16) - hash;
    }
    return hash%M;
}

bool HashTable::find(string &s)
{
    unsigned int idx = SDBMHash(s);
    if (table[idx] == 0)    return false;
    for (auto p = table[idx]->next; p != 0; p = p->next)
        if (p->name == s)    return true;
    return false;
}

void HashTable::insert(string &s)
{
    unsigned int idx = SDBMHash(s);
    string val = s;
    if (table[idx] == 0)  table[idx] = new node(val);
    node *p = new node(s);
    node *head = table[idx];
    p->next = head->next;
    head->next = p;
    if (p->next != 0)   p->next->prev = p;
    p->prev = head;
}

bool HashTable::remove(string &s)
{
    unsigned int idx = SDBMHash(s);
    node *head = table[idx];
    if (head == 0)  return false;
    for (auto p = head->next; p != 0; p = p->next)
    {
        if (p->name == s)
        {
            p->prev->next = p->next;
            if (p->next != 0)
                p->next->prev = p->prev;
            delete p;
            return true;
        }
    }
    return false;
}

int main(int argc, char **argv)
{
    string s;
    for (int i = 0; i < 2; ++ i)
    {
        cin >> s;
        HashTable::insert(s);
    }
    while (cin >> s)
    {
        if (HashTable::find(s))
        {
            cout << "Found" << endl;
            HashTable::remove(s);
        }
        else    cout << "Not Found" << endl;
    }
    return 0;
}