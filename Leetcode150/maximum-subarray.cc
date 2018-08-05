//  Maximum Subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, sub_sum = 0;
        for (int &x : nums) {
            sub_sum = max(sub_sum + x, x);
            res = max(sub_sum, res);
        }
        return res;
    }
};