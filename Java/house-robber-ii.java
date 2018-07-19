//  House Robber II

// Time O(N), Space O(1)
class Solution {
    public int rob(int[] nums) {
        if (nums.length == 1) return nums[0];
        return Math.max(rob(nums, 1, nums.length - 1), rob(nums, 0, nums.length - 2));
    }
    
    public int rob(int[] nums, int from, int to) {
        int prev = 0; 
        int gprev = 0; 
        for (int i = from; i <= to; i++) {
            int cur = Math.max(gprev + nums[i], prev);
            gprev = prev;
            prev = cur;
        }
        return prev;
    }
}