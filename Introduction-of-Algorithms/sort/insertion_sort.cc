/* Insertion Sort */

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void insertion_sort(vector<double> &nums)
{
    for (int i = 1; i < nums.size(); ++ i)
    {
        double tmp = nums[i];
        int j = i - 1;
        while (j>=0 && nums[j]>tmp)
        {
            swap(nums[j+1], nums[j]);
            -- j;
        }
        nums[j+1] = tmp;
    }
}

int main(int argc, char **argv)
{
    int N;
    cin >> N;
    vector<double> nums(N);
    for (auto &x : nums)
        x = (double)rand() / RAND_MAX * 2000 - 1000;
    insertion_sort(nums);
    for (auto &x : nums)    cout << x << "\t";
    cout << endl;
    return 0;
}