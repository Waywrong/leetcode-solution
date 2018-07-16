//  Longest Increasing Subsequence

// Time O(N^2), Space O(N)
class Solution {
    public int lengthOfLIS(int[] nums) {
        if (nums.length < 2)
            return nums.length;
        int max_len = Integer.MIN_VALUE;
        int[] record = new int[nums.length];
        for (int i=0; i<nums.length; i++)
            record[i] = 1;
        for (int i=0; i<nums.length; i++) 
            for (int j=0; j<i; j++)
                if (nums[i]>nums[j] && record[j]+1>record[i])
                    record[i] = record[j] + 1;
        for (int i=0; i<nums.length; i++) 
            max_len = Math.max(max_len, record[i]);
        return max_len;
    }
}