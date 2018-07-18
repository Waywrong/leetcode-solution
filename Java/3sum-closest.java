//  3Sum Closest

// Time O(N^2), Space O(1)
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int min_diff = Integer.MAX_VALUE, res = 0;
        if (nums.length < 3)
            return res;
        Arrays.sort(nums);
        for (int i=0; i<nums.length-2; i++) {
            if (i>0 && nums[i]==nums[i-1])
                continue;
            int l = i+1, r = nums.length-1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == target)
                    return target;
                if (Math.abs(sum - target) < min_diff) {
                    min_diff = Math.abs(sum - target);
                    res = sum;
                }
                if (sum > target)
                    r --;
                if (sum < target)
                    l ++;
            }
        }
        return res;
    }
}