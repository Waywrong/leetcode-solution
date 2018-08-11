Find First and Last Position of Element in Sorted Array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = find_lower_bound(nums, target);
        int ub = find_upper_bound(nums, target);
        if (lb==nums.size() || nums[lb]!=target)
            return vector<int> { -1, -1 };
        else
            return vector<int> { lb, ub-1 };
    }
    
    int find_upper_bound(vector<int> &nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = l + (r-l) / 2;
            if (nums[mid] <= target)    
                l = mid + 1;
            else    r = mid;
        }
        return l;
    }
    
    int find_lower_bound(vector<int> &nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = l + (r-l) / 2;
            if (nums[mid] < target) 
                l = mid + 1;
            else    r = mid;
        }
        return l;
    }
};
