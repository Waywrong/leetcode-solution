//  House Robber

//  Time O(N), Space O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 0)  return 0;
        if (size == 1)  return nums[0];
        if (size == 2)  return (nums[0]>nums[1] ? nums[0] : nums[1]);
        nums[1] = (nums[0]>nums[1] ? nums[0] : nums[1]);
        for (int i=2; i<size; i++)
            nums[i] = max(nums[i-2] + nums[i], nums[i-1]);
        return nums[size-1];
    }
};