//  Majority Element II

// Time O(N), Space O(N)
class Solution {
    public List<Integer> majorityElement(int[] nums) {
        List<Integer> res = new ArrayList<Integer>();
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        int size = nums.length;
        for (int n : nums) {
            if (map.containsKey(n))
                map.put(n, map.get(n) + 1);
            else
                map.put(n, 1);
            if (map.get(n) > size/3)
                if (res.indexOf(n) == -1)
                    res.add(n);
        }
        return res;
    }
}

// Time O(N), Space O(1)
class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int cnt1 = 0, cnt2 = 0, major1 = 0, major2 = 1;
        for (int n : nums) {
            if (n == major1)    cnt1 ++;
            else if (n == major2)   cnt2 ++;
            else if (cnt1 == 0) {
                cnt1 ++;
                major1 = n;
            }
            else if (cnt2 == 0) {
                cnt2 ++;
                major2 = n;
            }
            else {
                cnt1 --;
                cnt2 --;
            }
        }
        cnt1 = cnt2 = 0;
        for (int n : nums) {
            if (n == major1)    cnt1 ++;
            if (n == major2)    cnt2 ++;
        }
        List<Integer> res = new ArrayList<Integer>();
        if (cnt1 > nums.length/3)   res.add(major1);
        if (cnt2 > nums.length/3)   res.add(major2);
        return res;
    }
}