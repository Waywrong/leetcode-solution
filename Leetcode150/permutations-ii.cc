//  Permutations II

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        do {
            res.push_back(nums);
        } while (get_next_permutation(nums));
        return res;
    }
    
    bool get_next_permutation(vector<int> &nums) {
        int i, j, k;
        for (i=nums.size()-1; i>0; i--) {
            j = i - 1;
            if (nums[j] >= nums[i]) continue;
            for (k=nums.size()-1; k>=i; k--)
                if (nums[k] > nums[j])
                    break;
            swap(nums[k], nums[j]);
            reverse(nums.begin()+i, nums.end());
            return true;
        }
        return false;
    }
};