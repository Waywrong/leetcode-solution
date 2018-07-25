//  Contains Duplicate

// Time O(N), Space O(N)
class Solution {
    public boolean containsDuplicate(int[] nums) {
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int n : nums) {
            if (map.containsKey(n))
                return true;
            else
                map.put(n, 1);
        }
        return false;
    }
}