/* Find Kth Element */

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

/* Using Min Heap, O(KlogN) */
template<typename T>
void min_heapify(vector<T> &nums, int low, int high)
{
    int root = low, left = 2*root + 1, right;
    while (left <= high)
    {
        int idx = nums[root]<nums[left] ? root : left;
        right = left + 1;
        if (right<=high && nums[right]<nums[idx])
            idx = right;
        if (idx != root)
        {
            swap(nums[root], nums[idx]);
            root = idx; 
            left = 2 * root + 1;
        }
        else    break;
    }
}

template<typename T>
void build_min_heap(vector<T> &nums)
{
    for (int i = (nums.size()-2)/2; i >= 0; -- i)
        min_heapify(nums, i, nums.size()-1);
}

template<typename T>
T find_kth_element(vector<T> &nums, int k)
{
    if (k > nums.size())    
    {
        cout << "Invalid K..." << endl;
        exit(1);
    }
    build_min_heap(nums);
    for (int i = 1; i < k; ++ i)
    {
        swap(nums[0], nums[nums.size()-i]);
        min_heapify(nums, 0, nums.size()-i-1);
    }
    return nums[0];
}

/* Using Partition similiar with Quick Sort, O(N) */
template<typename T>
int partition(vector<T> &nums, int low, int high)
{
    T tmp = nums[low];
    int i = low, j = high;
    while (i < j)
    {
        while (i<j && nums[j]>tmp)  -- j;
        if (i < j)  nums[i ++] = nums[j];
        while (i<j && nums[i]<tmp)  ++ i;
        if (i < j)  nums[j --] = nums[i];
    }
    nums[i] = tmp;
    return i;
}

template<typename T>
T find_kth_element_1(vector<T> &nums, int low, int high, int k)
{
    if (low>high || high-low+1<k)
    {
        cout << "Invalid K.." << endl;
        exit(1);
    }
    int pos = partition(nums, low, high);
    int idx = pos - low + 1;
    if (idx == k)   return nums[pos];
    else if (idx < k)
        return find_kth_element_1(nums, pos+1, high, k-idx);
    else
        return find_kth_element_1(nums, low, pos-1, k);
}

int main(int argc, char **argv)
{
    vector<int> nums{23,34,12,45,25,67,17,89,39,21};
    //cout << find_kth_element(nums, 5) << endl;
    cout << find_kth_element_1(nums, 0, nums.size()-1, 5) << endl;
    cout << find_kth_element_1(nums, 0, nums.size()-1, 2) << endl;
    cout << find_kth_element_1(nums, 0, nums.size()-1, 9) << endl;
    return 0;
}