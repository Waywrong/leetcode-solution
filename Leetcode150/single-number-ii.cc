//  Single Number II

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> table;
        for (auto &n : nums)
            table[n] ++;
        for (auto &x : table)
            if (x.second == 1)
                return x.first;
        return -1;
    }
};