/* Priority Queue */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <cstdlib>
using namespace std;

template<typename Task, typename Priority>
class priority_queue
{
    private:
        unordered_map<Task, Priority> task_index;
        unordered_map<Task, Priority> task_info;
        vector<Task> task_heap;
    
        Task extract_max() const;
        void increase_task_priority(Task &t, Priority &p);
        void decrease_task_priority(Task &t, Priority &p);

    public:
        bool search_task(Task &t);
        void insert_task(Task &t, Priority &p);
        void delete_task(Task &t);
        Task get_top_task() const;
        void print_queue() const;
        void print_index() const;
        void print_info() const;
};

template<typename Task, typename Priority>
Task priority_queue<Task, Priority>::extract_max() const
{
    if (!task_heap.empty()) 
        return task_heap[0];
    else
    {
        cout << "Queue is empty..." << endl;
        exit(1);
    }
}

template<typename Task, typename Priority>
void priority_queue<Task, Priority>::increase_task_priority(Task &t, Priority &p)
{
    int idx = task_index[t];
    task_info[t] = p;
    int child = idx, parent = (child - 1) / 2;
    while (parent >= 0)
    {
        if (task_info[task_heap[child]] > task_info[task_heap[parent]])
        {
            task_index[task_heap[child]] = parent;
            task_index[task_heap[parent]] = child;
            swap(task_heap[child], task_heap[parent]);
            child = parent;
            parent = (child - 1) / 2;
        }
        else    break;
    }
}

template<typename Task, typename Priority>
void priority_queue<Task, Priority>::decrease_task_priority(Task &t, Priority &p)
{
    int idx = task_index[t];
    task_info[t] = p;
    int root = idx, left = 2*idx+1, right;
    while (left <= task_heap.size()-1)
    {
        int max_i = task_info[task_heap[root]]>task_info[task_heap[left]] ? root : left;
        right = left + 1;
        if (right<=task_heap.size()-1 && task_info[task_heap[right]]>task_info[task_heap[max_i]])
            max_i = right;
        if (max_i != root)
        {
            task_index[task_heap[max_i]] = root;
            task_index[task_heap[root]] = max_i;
            swap(task_heap[max_i], task_heap[root]);
            root = max_i;
            left = 2 * root + 1;
        }
        else    break;
    }
}

template<typename Task, typename Priority>
bool priority_queue<Task, Priority>::search_task(Task &t)
{
    return (task_index.count(t) > 0);
}

template<typename Task, typename Priority>
void priority_queue<Task, Priority>::insert_task(Task &t, Priority &p)
{
    if (search_task(t))
    {
        if (task_info[t] < p)
            increase_task_priority(t, p);
        else if (task_info[t] > p)
            decrease_task_priority(t, p);
        else    return;
    }
    else
    {
        task_heap.push_back(t);
        task_index[t] = task_heap.size()-1;
        increase_task_priority(t, p);
    }
}

template<typename Task, typename Priority>
void priority_queue<Task, Priority>::delete_task(Task &t)
{
    if (search_task(t))
    {
        int idx = task_index[t];
        task_heap.erase(task_heap.begin() + idx);
        for (int i = (task_heap.size()-2)/2; i >= 0; -- i)
            decrease_task_priority(t, task_info[t]);
    }
    else
        cout << "No task found..." << endl;
}

template<typename Task, typename Priority>
Task priority_queue<Task, Priority>::get_top_task() const
{
    return extract_max();
}

template<typename Task, typename Priority> 
void priority_queue<Task, Priority>::print_queue() const
{
    for (auto &x : task_heap)
        cout << x << "\t";
    cout << endl;
}

template<typename Task, typename Priority>
void priority_queue<Task, Priority>::print_index() const
{
    for (auto &p : task_index)
        cout << p.first << ":" << p.second << "\t";
    cout << endl;
}

template<typename Task, typename Priority>
void priority_queue<Task, Priority>::print_info() const
{
    for (auto &p : task_info)
        cout << p.first << ":" << p.second << "\t";
    cout << endl;
}

/***********************************************************/

int main(int argc, char **argv)
{
    priority_queue<string, int> q;
    string t;
    int p;
    /*
    for (int i = 0; i < 6; ++ i)
    {
        cin >> t >> p;
        q.insert_task(t, p);
    }
    q.print_queue();
    while (cin >> t >> p)
    {
        q.insert_task(t, p);
        q.print_queue();
    }*/
    while (cin >> t >> p)
    {
        q.insert_task(t, p);
        q.print_queue();
        //q.print_index();
        //q.print_info();
    }
    return 0;
}