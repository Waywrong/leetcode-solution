#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

/* O(N^2) */
void bubble_sort(vector<double> &nums)
{
    for (int i = 0; i < nums.size()-1; ++ i)
        for (int j = nums.size()-1; j > i; -- j)
            if (nums[j] < nums[j-1])
                swap(nums[j], nums[j-1]);
}

void bubble_sort_improved(vector<double> &nums)
{
    int i = 0;
    while (i < nums.size()-1)
    {
        bool stop = true;
        int idx = i + 1;
        for (int j = nums.size()-1; j > i; -- j)
        {
            if (nums[j] < nums[j-1])
            {
                swap(nums[j], nums[j-1]);
                idx = j - 1;
                stop = false;
            }
        }
        if (stop)   break;
        i = idx;
    }
}

int main(int argc, char **argv)
{
    int N;
    cin >> N;
    vector<double> nums(N);
    for (auto &x : nums)
        x = (double)rand() / RAND_MAX * 2000 - 1000;
    //bubble_sort(nums);
    bubble_sort_improved(nums);
    for (auto &x : nums)    cout << x << "\t";
    cout << endl;
    return 0;
}