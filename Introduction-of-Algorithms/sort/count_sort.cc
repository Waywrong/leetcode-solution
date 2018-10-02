/* Count Sort */

#include <iostream>
#include <vector>
using namespace std;

void count_sort(vector<int> &nums, int low, int high)
{
    vector<int> tmp(nums);
    int range = high - low + 1;
    vector<int> counter(range, 0);
    for (auto &x : nums)
        counter[x-low] += 1;
    for (int i = 1; i < range; ++ i)
        counter[i] += counter[i-1];
    for (int i = nums.size()-1; i >= 0; -- i)
    {
        tmp[counter[nums[i]-low]-1] = nums[i];
        counter[nums[i]-low] -= 1;
    }
    for (int i = 0; i < nums.size(); ++ i)
        nums[i] = tmp[i];
}

int main(int argc, char **argv)
{
    vector<int> nums{-1, 4, 2, 1, 0, 2, 2, -1, -2, 0, 4};
    count_sort(nums, -2, 4);
    for (auto &x : nums)    cout << x << "\t";
    cout << endl;
    return 0;
}