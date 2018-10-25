//  Jump Game II

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        for (int i = 0; i < nums.size(); i ++) 
            dp[i] = i;
        for (int i = 1; i < nums.size(); i ++)
            for (int j = 0; j < i; j ++)
                if (j+nums[j] >= i)
                    dp[i] = min(dp[i], dp[j]+1);
        return dp[nums.size()-1];
    }
};
