//  First Missing Positive

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        for (i = 0; i < nums.size(); i ++) 
            while (nums[i]>0 && nums[i]<=nums.size() && nums[nums[i]-1]!=nums[i])
                swap(nums[i], nums[nums[i]-1]);
        for (i = 0; i < nums.size(); i ++)
            if (nums[i] != i+1)
                break;
        return i+1;
    }
};
