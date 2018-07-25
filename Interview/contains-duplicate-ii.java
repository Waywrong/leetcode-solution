//  Contains Duplicate II

// Time O(N), Space O(K)
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        List<Integer> store = new ArrayList<Integer>();
        int i = 0;
        for (i=0; i<=k && i<nums.length; i++) {
            if (store.indexOf(nums[i]) != -1)
                return true;
            else
                store.add(nums[i]);
        }
        for (i=k+1; i<nums.length; i++) {
            store.remove(0);
            if (store.indexOf(nums[i]) != -1)
                return true;
            else
                store.add(nums[i]);
        }
        return false;
    }
}