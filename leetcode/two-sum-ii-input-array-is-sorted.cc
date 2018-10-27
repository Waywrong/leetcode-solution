//  Two Sum II - Input array is sorted

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        size_t l = 0, r = numbers.size() - 1;
        while (l < r) {
            long sum = numbers[l] + numbers[r];
            if (sum > target)   -- r;
            else if (sum < target)  ++ l;
            else { res.push_back(l+1); res.push_back(r+1); return res; }
        }
        return res;
    }
};