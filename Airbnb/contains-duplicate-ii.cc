//  Contains Duplicate II

// Time O(N), Space O(K)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<int> slide;
        for (int i=0; i<nums.size(); i++) {
            if (i > k) slide.erase(slide.begin());
            if (find(slide.begin(), slide.end(), nums[i]) != slide.end())
                return true;
            else
                slide.push_back(nums[i]);
        }
        return false;
    }
};