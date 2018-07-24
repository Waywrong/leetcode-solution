//  Single Number

// Time O(N), Space O(N)
class Solution {
    public int singleNumber(int[] nums) {
        int res = 0;
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int n : nums) {
            if (map.containsKey(n))
                map.remove(n);
            else
                map.put(n, 1);
        }
        for (Integer key : map.keySet()) {
            res = key;
            break;
        }
        return res;
    }
}

// Time O(N), Space O(1)
class Solution {
    public int singleNumber(int[] nums) {
        int res = 0;
        for (int n : nums) 
            res ^= n;
        return res;
    }
}