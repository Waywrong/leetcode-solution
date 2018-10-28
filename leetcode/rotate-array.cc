//  Rotate Array

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        size_t n = nums.size();
        k %= static_cast<int>(n);
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};