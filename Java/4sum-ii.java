//  4Sum II

// Time O(N^2), Space O(N)
class Solution {
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        int res = 0;
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int a : A) {
            for (int b : B) {
                if (map.containsKey(a+b))
                    map.put(a+b, map.get(a+b)+1);
                else
                    map.put(a+b, 1);
            }
        }
        for (int c : C) 
            for (int d : D) 
                if (map.containsKey(-c-d))
                    res += map.get(-c-d);
        return res;
    }
}