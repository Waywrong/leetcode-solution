//  Next Permutation

// Time O(N), Space O(1)
class Solution {
    public void nextPermutation(int[] nums) {
        int size = nums.length;
        if (size < 2)
            return;
        int i, j, k;
        for (i=size-1; i>0; i--) {
            j = i - 1;
            if (nums[j] >= nums[i])
                continue;
            for (k=size-1; k>=i; k--)
                if (nums[k] > nums[j])
                    break;
            int t = nums[j]; nums[j] = nums[k]; nums[k] = t;
            reverse(nums, i, size-1);
            return;
        }
        reverse(nums, 0, size-1);
    }
    
    private void reverse(int[] nums, int start, int end) {
        while (start < end) {
            int t = nums[start];
            nums[start] = nums[end];
            nums[end] = t;
            start ++;
            end --;
        }
    }
}