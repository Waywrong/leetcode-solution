//  Pour Water

// Time O(NV), Space O(1)
class Solution {
    public int[] pourWater(int[] heights, int V, int K) {
        if (heights==null || heights.length==0 || V<0
            || K<0 || K>=heights.length)    return heights;
        while (V-- > 0) {
            int minIdx = K;
            int minHeight = heights[K];
            for (int i=K-1; i>=0 && heights[i]<=heights[i+1]; i--) {
                if (heights[i] < minHeight) {
                    minIdx = i;
                    minHeight = heights[i];
                }
            }
            if (minIdx != K) {
                heights[minIdx] ++;
                continue;
            }
            for (int i=K+1; i<heights.length && heights[i]<=heights[i-1]; i++) {
                if (heights[i] < minHeight) {
                    minIdx = i;
                    minHeight = heights[i];
                }
            }
            heights[minIdx] ++;
        }
        return heights;
    }
}
