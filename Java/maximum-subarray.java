//  Maximum Subarray

// Time O(N), Space O(1)
class Solution {
    public int maxSubArray(int[] nums) {
        int max_sum = Integer.MIN_VALUE, sub_sum = 0;
        for (int i=0; i<nums.length; i++) {
            sub_sum = Math.max(sub_sum+nums[i], nums[i]);
            max_sum = Math.max(max_sum, sub_sum);
        }
        return max_sum;
    }
}