//   Majority Element

// Time O(N), Space O(N)
class Solution {
    public int majorityElement(int[] nums) {
        int size = nums.length;
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int n : nums) {
            if (map.containsKey(n))
                map.put(n, map.get(n) + 1);
            else
                map.put(n, 1);
            if (map.get(n) > size/2)
                return n;
        }
        return Integer.MAX_VALUE;
    }
}

// Time O(N), Space O(1)
class Solution {
    public int majorityElement(int[] nums) {
        int count = 1, major = nums[0];
        for (int i=1; i<nums.length; i++) {
            if (count == 0) {
                count ++;
                major = nums[i];
            }
            else if (nums[i] == major)
                count ++;
            else
                count --;
        }
        return major;
    }
}