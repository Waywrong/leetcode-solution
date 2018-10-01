/* Binary Search */

#include <iostream>
#include <vector>
#include <cstddef>
using namespace std;

/* Iterative */
template<typename T>
int binary_search_iter(vector<T> &nums, int low, int high, T value)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == value) return mid;
        if (nums[mid] < value)  low = mid + 1;
        else    high = mid - 1;
    }
    return -1; 
}

/* Recursive */
template<typename T>
int binary_search_recu(vector<T> &nums, int low, int high, T value)
{
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    if (nums[mid] == value) return mid;
    int idx = binary_search_recu(nums, low, mid-1, value);
    return (idx!=-1 ? idx : binary_search_recu(nums, mid+1, high, value));
}

int main(int argc, char **argv)
{
    vector<int> nums{1,2,3,4,5,6,7,8,9};
    //cout << binary_search_iter(nums, 0, nums.size()-1, 5) << endl;
    cout << binary_search_recu(nums, 0, nums.size()-1, 10) << endl;
    return 0;
}