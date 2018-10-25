//  Trapping Rain Water

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1, level = 0, res = 0;
        while (l < r) {
            int lower = height[height[l]<height[r] ? l ++ : r --];
            level = max(level, lower);
            res += level - lower;
        }
        return res;
    }
};
