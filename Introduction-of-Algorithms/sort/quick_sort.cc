/* Quick Sort */

#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>
#include <ctime>
using namespace std;

/* Partition functions */
int partition1(vector<double> &nums, int low, int high)
{
    double tmp = nums[low];
    while (low < high) 
    {
        while (low<high && nums[high]>tmp)  -- high;
        if (low < high) nums[low ++] = nums[high];
        while (low<high && nums[low]<tmp)   ++ low;
        if (low < high) nums[high --] = nums[low];
    }
    nums[low] = tmp;
    return low;
}

int partition2(vector<double> &nums, int low, int high)
{
    double tmp = nums[high];
    int i = low - 1;
    for (int j = low; j < high; ++ j)
        if (nums[j] <= tmp)
            swap(nums[++ i], nums[j]);
    swap(nums[++ i], nums[high]);
    return i;
}

/* Main Process */
/* O(NlogN) */
void quick_sort_1(vector<double> &nums, int low, int high)
{
    if (low >= high)    return;
    int p = partition1(nums, low, high);
    quick_sort_1(nums, low, p-1);
    quick_sort_1(nums, p+1, high);
}

/* O(N) */
void quick_sort_2(vector<double> &nums, int low, int high)
{
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        int p = partition2(nums, low, high);
        if (p <= mid)
        {
            quick_sort_2(nums, low, p-1);
            low = p + 1;
        }
        else
        {
            quick_sort_2(nums, p+1, high);
            high = p - 1;
        }
    }
}

/* O(NlogN) */
void quick_sort_iter(vector<double> &nums, int low, int high)
{
    stack<int> st;
    int l = low, r = high;
    int p = partition1(nums, low, high);
    if (p > l + 1)
    {
        st.push(l);
        st.push(p-1);
    }
    if (p < r - 1)
    {
        st.push(p+1);
        st.push(r);
    }
    while (!st.empty())
    {
        r = st.top();   st.pop();
        l = st.top();   st.pop();
        p = partition1(nums, l, r);
        if (p > l + 1)
        {
            st.push(l);
            st.push(p-1);
        }
        if (p < r - 1)
        {
            st.push(p+1);
            st.push(r);
        }
    }
}

int main(int argc, char **argv)
{
    int N;
    cin >> N;
    vector<double> nums(N);
    for (auto &x : nums)
        x = (double)rand() / RAND_MAX * 2000 - 1000;
    //quick_sort_1(nums, 0, nums.size()-1);
    //quick_sort_2(nums, 0, nums.size()-1);
    quick_sort_iter(nums, 0, nums.size()-1);
    for (auto &x : nums)    cout << x << "\t";
    cout << endl;
    return 0;
}