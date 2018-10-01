/* Stack */

#include <iostream>
#include <cstddef>
#include <cstdlib>
using namespace std;

template<typename T>
class stack
{
    private:
        struct node 
        {
            struct node *next;
            struct node *prev;
            T data;
            node(T &val) : data(val), next(0), prev(0) {}
        };

        node *top;
        size_t size;

    public:
        stack() : top(0), size(0) {}

        bool empty() { return (size == 0); }
        size_t length() { return size; }
        void push(T x)
        {
            node *p = new node(x);
            if (empty())
                top = p;
            else
            {
                p->prev = top;
                top->next = p;
                top = p;
            }
            ++ size;
        }
        T pop()
        {
            if (empty())
            {
                cout << "No element in Stack..." << endl;
                exit(1);
            }
            node *tmp = top;
            T res = tmp->data;
            top = top->prev;
            if (top != 0)   top->next = 0;
            delete tmp;
            -- size;
            return res;
        }
};

int main(int argc, char **argv)
{
    stack<double> s;
    s.push(1.0);
    s.push(23.1);
    s.push(33.2);
    cout << s.length() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.length() << endl;
    s.push(3.3);
    cout << s.length() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.length() << endl;
    cout << s.pop() <<endl;
    return 0;
}