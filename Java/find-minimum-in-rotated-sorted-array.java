//  Find Minimum in Rotate

// Time O(logN), Space O(1)
class Solution {
    public int findMin(int[] nums) {
        int l = 0, r = nums.length-1;
        while (l <= r) {
            if (nums[l] <= nums[r])
                break;
            int mid = l + (r-l) / 2;
            if (nums[mid] < nums[r])
                r = mid;
            else
                l = mid + 1;
        }
        return nums[l];
    }
}