/* Queue */

#include <iostream>
#include <cstddef>
using namespace std;

template<typename T>
class Queue
{
    private:
        struct node 
        {
            node *next;
            T data;
            node(T val=T()) : next(0), data(val) {}
        };

        node *head;
        node *tail;
        size_t length;

    public:
        Queue() : tail(0), length(0) { head = new node(T()); }

        size_t size() { return length; }
        bool empty() { return (length == 0); }
        void push(T &x);
        void pop();
        T front() const;
};

template<typename T>
void Queue<T>::push(T &x)
{
    if (head->next == 0)
    {
        head->next = new node(x);
        tail = head->next;
    }
    else
    {
        tail->next = new node(x);
        tail = tail->next;
    }
    ++ length;
}

template<typename T>
void Queue<T>::pop()
{
    if (size() == 0)
    {
        cout << "Queue empty..." << endl;
        return;
    }
    node *tmp = head->next;
    head->next = head->next->next;
    delete tmp;
    -- length;
}

template<typename T>
T Queue<T>::front() const
{
    return (head->next->data);
}

int main(int argc, char **argv)
{
    Queue<int> q;
    int x;
    for (int i = 0; i < 3; ++ i)
    {
        cin >> x;
        q.push(x);
    }
    cout << q.size() << endl;
    for (int i = 0; i < 3; ++ i)
    {
        cout << q.front() << "\t";
        q.pop();
        cout << q.size() << endl;
    }
    cin >> x;
    q.push(x);
    cout << q.front() << "\t" << q.size() << endl;
    return 0;
}