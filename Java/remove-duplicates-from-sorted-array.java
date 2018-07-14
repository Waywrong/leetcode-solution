//  Remove Duplicates from Sorted Array

// Time O(N), Space O(1)
class Solution {
    public int removeDuplicates(int[] nums) {
        int len = 1;
        if (nums.length == 1)
            return len;
        for (int i=1; i<nums.length; i++)
            if (nums[i] != nums[len-1])
                nums[len ++] = nums[i];
        return len;
    }
}