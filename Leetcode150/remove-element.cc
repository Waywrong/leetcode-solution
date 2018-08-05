//  Remove Element

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res = 0;
        for (auto &x : nums) 
            if (x != val)
                nums[res ++] = x;
        return res;
    }
};