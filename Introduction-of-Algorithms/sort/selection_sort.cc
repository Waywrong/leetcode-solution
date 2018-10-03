/* Selection Sort */

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

/* O(N^2) */
void selection_sort(vector<double> &nums)
{
    for (int i = 0; i < nums.size()-1; ++ i)
    {
        int idx = i;
        for (int j = i+1; j < nums.size(); ++ j)
            if (nums[j] < nums[idx])
                idx = j;
        if (idx != i)   swap(nums[idx], nums[i]);
    }
}

int main(int argc, char **argv)
{
    int N;
    cin >> N;
    vector<double> nums(N);
    for (auto &x : nums)
        x = (double)rand() / RAND_MAX * 2000 - 1000;
    selection_sort(nums);
    for (auto &x : nums)    cout << x << "\t";
    cout << endl;
    return 0;
}