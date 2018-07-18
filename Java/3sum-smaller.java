//  3Sum Smaller

// Time O(N^3), Space O(1)
class Solution {
    public int threeSumSmaller(int[] nums, int target) {
        int res = 0;
        for (int i=0; i<nums.length-2; i++) 
            for (int j=i+1; j<nums.length-1; j++) 
                for (int k=j+1; k<nums.length; k++) 
                    if (nums[i]+nums[j]+nums[k] < target)
                        res ++;
        return res;
    }
}

// Time O(N^2), Space O(1)
class Solution {
    public int threeSumSmaller(int[] nums, int target) {
        Arrays.sort(nums);
        int res = 0;
        for (int i=0; i<nums.length-2; i++) {
            int l = i+1, r = nums.length-1;
            while (l < r) {
                while (l<r && nums[i]+nums[l]+nums[r]>=target)
                    r --;
                if (l < r)
                    res += r - l;
                l ++;
            }
        }
        return res;
    }
}