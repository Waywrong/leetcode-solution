//  Find Minimum in Rotated Sorted Array

class Solution {
public:
    int findMin(vector<int>& nums) {
        size_t l = 0, r = nums.size()-1;
        size_t mid = 0;
        while (l != r) {
            mid = l + (r - l) / 2;
            if (nums[mid] > nums[r])
                l = mid + 1;
            else
                r = mid;
        }
        return nums[l];
    }
};