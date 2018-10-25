//  Maximum Subarray

//  O(NlogN)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty())   return 0;
        return maxSubArray(nums, 0, nums.size()-1);
    }
    
    int maxSubArray(vector<int>& nums, int l, int r) {
        if (l == r) return nums[l];
        int mid = l + (r-l) / 2;
        int l_max_sum = maxSubArray(nums, l, mid);
        int r_max_sum = maxSubArray(nums, mid+1, r);
        int lsum = INT_MIN, rsum = INT_MIN, sum = 0;
        for (int i = mid; i >= l; i --) {
            sum += nums[i];
            if (sum > lsum) lsum = sum;
        }
        sum = 0;
        for (int i = mid+1; i <= r; i ++) {
            sum += nums[i];
            if (sum > rsum) rsum = sum;
        }
        return max(lsum+rsum, max(l_max_sum, r_max_sum));
    }
};

//  O(N)
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
