//  Remove Element

// Time O(N), Space O(1)
class Solution {
    public int removeElement(int[] nums, int val) {
        int len = 0;
        for (int i=0; i<nums.length; i++)
            if (nums[i] != val)
                nums[len ++] = nums[i];
        return len;
    }
}