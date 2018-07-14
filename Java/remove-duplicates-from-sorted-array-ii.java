//  Remove Duplicates from Sorted Array II

// Time O(N), Space O(1)
class Solution {
    public int removeDuplicates(int[] nums) {
        int len = 2;
        if (nums.length <= 2)
            return nums.length;
        for (int i=2; i<nums.length; i++)
            if (nums[i] != nums[len-2])
                nums[len ++] = nums[i];
        return len;
    }
}