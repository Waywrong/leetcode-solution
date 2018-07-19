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
        int major = 0, cnt = 0;
        for (int n : nums) {
            if (n == major)
                cnt ++;
            else if (cnt == 0) {
                cnt ++;
                major = n;
            }
            else
                cnt --;
        }
        return major;
    }
}