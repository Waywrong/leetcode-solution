/* Merge Sort */

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

/* O(NlogN) */
void merge_sort(vector<double> &nums, int low, int high)
{
    if (low >= high)    return;
    int mid = low + (high - low)/ 2;
    merge_sort(nums, low, mid);
    merge_sort(nums, mid+1, high);
    int n1 = mid-low+1, n2 = high-mid;
    vector<double> left(n1), right(n2);
    for (int i = 0, j = low; j <= mid; ++i, ++j)
        left[i] = nums[j];
    for (int i = 0, j = mid+1; j <= high; ++i, ++j)
        right[i] = nums[j];
    int i = 0, j = 0, k = low;
    while (i<n1 && j<n2)
    {
        if (left[i] <= right[j])
            nums[k ++] = left[i ++];
        else
            nums[k ++] = right[j ++];
    }
    while (i < n1)  nums[k ++] = left[i ++];
    while (j < n2)  nums[k ++] = right[j ++];
}

/* find inversion pairs */
void find_inversions(vector<double> &nums, int low, int high, int &count)
{
    if (low >= high)    return;
    int mid = low + (high - low) / 2;
    find_inversions(nums, low, mid, count);
    find_inversions(nums, mid+1, high, count);
    int n1 = mid-low+1, n2 = high-mid;
    vector<double> left(n1), right(n2);
    for (int i = 0, j = low; j <= mid; ++i, ++j)
        left[i] = nums[j];
    for (int i = 0, j = mid+1; j <= high; ++i, ++j)
        right[i] = nums[j];
    int i = 0, j = 0, k = low;
    while (i<n1 && j<n2)
    {
        if (left[i] <= right[j])
            nums[k ++] = left[i ++];
        else
        {
            count += n1 - i;
            nums[k ++] = right[j ++];
        }
    }
    while (i < n1)  nums[k ++] = left[i ++];
    while (j < n2)  nums[k ++] = right[j ++];
}

int main(int argc, char **argv)
{
    /*
    int N;
    cin >> N;
    vector<double> nums(N);
    for (auto &x :nums) 
        x = (double)rand() / RAND_MAX * 2000 - 1000;
    merge_sort(nums, 0, nums.size()-1);
    for (auto &x : nums)    cout << x << "\t";
    cout <<endl;
    return 0;
    */

    vector<double> nums{3.0, 1.1, 4.6, 2.2, 1.2};
    int count = 0;
    find_inversions(nums, 0, nums.size()-1, count);
    cout << count << endl;
    return 0;
}