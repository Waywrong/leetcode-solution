//  Longest Consecutive Sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int max_len = 1;
        set<int> s(nums.begin(), nums.end());
        nums.assign(s.begin(), s.end());
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> lens(n, 1);
        for (int i = 1; i < n; i ++) {
            if (nums[i] - nums[i-1] == 1) {
                lens[i] = lens[i-1] + 1;
                max_len = max(lens[i], max_len);
            }
        }
        return max_len;
    }
};
