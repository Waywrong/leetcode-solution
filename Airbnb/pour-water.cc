//  Pour Water

// Time O(NV), Space O(1)
class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        for (int cnt=0; cnt<V; cnt++) {
            int min_id = K;
            int min_h = heights[min_id];
            for (int i=K-1; i>=0 && heights[i]<=heights[i+1]; i--) {
                if (heights[i] < min_h) {
                    min_id = i;
                    min_h = heights[i];
                }
            }
            if (min_id != K) {
                heights[min_id] ++;
                continue;
            }
            for (int i=K+1; i<heights.size() && heights[i]<=heights[i-1]; i++) {
                if (heights[i] < min_h) {
                    min_id = i;
                    min_h = heights[i];
                }
            }
            heights[min_id] ++;
        }
        return heights;
    }
};
}
