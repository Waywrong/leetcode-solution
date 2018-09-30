/* Insertion Sort */

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

/* O(N^2) */
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

/* O(NlogN) */
void insertion_sort_improved(vector<double> &nums)
{
    for (int i = 1; i < nums.size(); ++ i)
    {
        double tmp = nums[i];
        int l = 0, r = i;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] < tmp)    l = mid + 1;
            else    r = mid;
        }        
        nums.erase(nums.begin() + i);
        nums.insert(nums.begin()+l, tmp);
    }
}

int main(int argc, char **argv)
{
    int N;
    cin >> N;
    vector<double> nums(N);
    for (auto &x : nums)
        x = (double)rand() / RAND_MAX * 2000 - 1000;
    //insertion_sort(nums);
    insertion_sort_improved(nums);
    for (auto &x : nums)    cout << x << "\t";
    cout << endl;
    return 0;
}