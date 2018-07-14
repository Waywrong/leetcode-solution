//  Permutations II

// Time O(N^2*N!), Space O(1)
class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        do {
            List<Integer> l = list2arr(nums);
            ans.add(l);
        } while (nextPermutation(nums));
        return ans;
    }
    
    private Boolean nextPermutation(int[] nums) {
        int len = nums.length;
        if (len < 2)
            return false;
        int i, j, k;
        for (i=len-1; i>0; i--) {
            j = i-1;
            if (nums[j] >= nums[i])
                continue;
            for (k=len-1; k>=i; k--)
                if (nums[k] > nums[j])
                    break;
            int t = nums[j]; nums[j] = nums[k]; nums[k] = t;
            reverse(nums, i, len-1);
            return true;
        }
        return false;
    }
    
    private void reverse(int[] nums, int start, int end) {
        if (start >= end)
            return;
        int mid = start + (end-start) / 2;
        for (int i=0; i+start<=mid; i++) {
            int t = nums[start+i];
            nums[start+i] = nums[end-i];
            nums[end-i] = t;
        }
    }
    
    private List<Integer> list2arr(int[] nums) {
        List<Integer> ans = new ArrayList<Integer>();
        for (int i=0; i<nums.length; i++)
            ans.add(nums[i]);
        return ans;
    }
}