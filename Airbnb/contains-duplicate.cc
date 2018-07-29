//  Contains Duplicate

// Time O(N), Space O(N)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int &n : nums) {
            if (map.count(n) > 0)
                return true;
            else
                map[n] = 1;
        }
        return false;
    }
};