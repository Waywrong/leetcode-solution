//  Jump Game

//  Solution 1
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size(), false);
        dp[0] = true;
        for (int i = 1; i < nums.size(); i ++) {
            for (int j = 0; j < i; j ++) {
                if (dp[j] && j+nums[j]>=i) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[nums.size()-1];
    }
};

//  Solution 2
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int far = 1;
        for (int i = 0; i<far && far<nums.size(); i ++)
            far = max(far, nums[i]+1+i);
        return far >= nums.size();
    }
};
