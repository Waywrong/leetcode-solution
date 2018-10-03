/* Max Heap */

#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class MaxHeap
{
    private:
        vector<T> heap;

        void max_heapify(int low, int high)
        {
            int root = low, left = 2*low + 1, right;
            while (left <= high)
            {
                int idx = heap[root]>heap[left] ? root : left;
                right = left + 1;
                if (right<=high && heap[right]>heap[idx])   
                    idx = right;
                if (idx != root)
                {
                    swap(heap[root], heap[idx]);
                    root = left;
                    left = 2 * root + 1;
                }
                else    break;
            }
        }

    public:
        void insert(T &x)
        {
            heap.push_back(x);
            int child = heap.size()-1, parent = (child - 1) / 2;
            while (parent >= 0)
            {
                if (heap[child] > heap[parent])
                {
                    swap(heap[child], heap[parent]);
                    child = parent;
                    parent = (child - 1) / 2;
                }
                else    break;
            }
        }
        T pop()
        {
            T res = heap[0];
            swap(heap[0], heap[heap.size()-1]);
            heap.pop_back();
            max_heapify(0, heap.size()-1);
            return res;
        }
};

int main(int argc, char **argv)
{
    MaxHeap<int> max_heap;
    int x;
    for (int i = 0; i < 5; ++ i)
    {
        cin >> x;
        max_heap.insert(x);
    }
    cout << max_heap.pop() << endl;
    cout << max_heap.pop() << endl;
}