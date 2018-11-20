//  House Robber

class Solution {
public:
    int rob(vector<int>& nums) {
        size_t n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return (nums[0]>nums[1] ? nums[0] : nums[1]);
        int pp = nums[0], p = (nums[0]>nums[1] ? nums[0] : nums[1]);
        int res;
        for (size_t i = 2; i < n; ++ i) {
            res = max(pp + nums[i], p);
            pp = p;
            p = res;
        }
        return res;
    }
};