//  Two Sum

// Time O(N), Space O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i=0; i<nums.size(); i++) {
            if (map.count(target - nums[i]) > 0)
                return vector<int> { map[target - nums[i]], i };
            else
                map[nums[i]] = i;
        }
        return vector<int> { -1, -1 };
    }
};