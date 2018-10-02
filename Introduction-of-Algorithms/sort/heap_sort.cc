/* Heap Sort */

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void max_heapify(vector<double> &nums, int low, int high)
{
    int root = low, left = 2*low + 1, right;
    while (left <= high)
    {
        int idx = nums[root]>nums[left] ? root : left;
        right = left + 1;
        if (right<=high && nums[right]>nums[idx])
            idx = right;
        if (idx != root)
        {
            swap(nums[root], nums[idx]);
            root = idx;
            left = 2* root + 1;
        }
        else    break;
    }
}

void build_max_heap(vector<double> &nums)
{
    int n = nums.size();
    for (int i = (n-2)/2; i>=0; --i)
        max_heapify(nums, i, n-1);
}

void heap_sort(vector<double> &nums)
{
    build_max_heap(nums);
    for (int i = nums.size()-1; i > 0; -- i)
    {
        swap(nums[0], nums[i]);
        max_heapify(nums, 0, i-1);
    }
}

int main(int argc, char **argv)
{
    int N;
    cin >> N;
    vector<double> nums(N);
    for (auto &x :nums)
        x = (double)rand() / RAND_MAX * 2000 - 1000;
    heap_sort(nums);
    for (auto &x : nums)    cout <<x <<"\t";
    cout << endl;
    return 0;
}