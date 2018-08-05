//  Remove Duplicates from Sorted Array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2)    return nums.size();
        int res = 1;
        for (auto &x : nums) 
            if (x != nums[res-1])
                nums[res ++] = x;
        return res;
    }
};