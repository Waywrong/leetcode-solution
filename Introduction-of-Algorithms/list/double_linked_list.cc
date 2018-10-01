/* Double Linked List */

#include <iostream>
#include <cstddef>
using namespace std;

template<typename T>
struct node 
{
    struct node *next;
    struct node *prev;
    T data;
    node(T &val) : data(val), next(0), prev(0) {}
};

template<typename T>
class DList 
{
    private:
        node<T> *head, *tail;
        size_t length;

    public:
        DList() : length(0), head(0), tail(0) {}

        void print_nodes()
        {
            if (head != 0)
            {
                for (node<T> *cur = head; cur != 0; cur = cur->next)
                    cout << cur->data << "\t";
                cout << endl;
            }
        }
        node<T> *search_node(T &x)
        {
            node<T> *res = 0;
            for (node<T> *cur = head; cur != tail; cur = cur->next)
                if (cur->data == x) { res = cur; break; }
            return res;
        }
        void insert_node(T &x) 
        {
            node<T> *p = new node<T>(x);
            if (head == 0)  head = p;
            else
            {
                p->prev = tail;
                tail->next = p;
            }
            tail = p;
            ++ length;
        }   
        void delete_node(node<T> *p)
        {
            if (p == head)
            {
                p->next->prev = 0;
                head = p->next;
            }
            else
            {
                p->prev->next = p->next;
                p->next->prev = p->prev;
            }
            delete p;
            -- length;
        }
        size_t get_length() { return length; }
};

int main(int argc, char **argv)
{
    DList<int> l;
    int N;
    for (int i = 0; i < 5; ++ i)
    {
        cin >> N;
        l.insert_node(N);
    }
    l.print_nodes();
    cout << l.get_length() << endl;
    while (cin >> N)
    {
        node<int> *p = l.search_node(N);
        if (p != 0) l.delete_node(p);
        l.print_nodes();
        cout << l.get_length() << endl;
    }
    return 0;
}