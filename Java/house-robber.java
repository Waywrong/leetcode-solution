//  House Robber

// Time O(N), Space O(1)
class Solution {
    public int rob(int[] nums) {
        int size = nums.length;
        if (size == 0)  return 0;
        if (size == 1)  return nums[0];
        if (size == 2)  return (nums[0]>nums[1]) ? nums[0] : nums[1];
        int[] arr = new int[size];
        int a = nums[0], b = (nums[0]>nums[1]) ? nums[0] : nums[1], c = 0;
        for (int i=2; i<size; i++) {
            c = Math.max(a + nums[i], b);
            a = b;
            b = c;
        }
        return c;
    }
}