//  Find Minimum in Rotated Sorted Array II

class Solution {
public:
    int findMin(vector<int>& nums) {
        size_t l = 0, r = nums.size()-1;
        while (l != r) {
            size_t mid = l + (r - l) / 2;
            if (nums[mid] > nums[r])
                l = mid + 1;
            else if (nums[mid] < nums[r])
                r = mid;
            else
                -- r;
        }
        return nums[l];
    }
};