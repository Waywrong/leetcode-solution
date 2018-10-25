//  Next Permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        get_next_permutation(nums);
    }
    
    void get_next_permutation(vector<int> &nums) {
        int i, j, k;
        for (i=nums.size()-1; i>0; i--) {
            j = i - 1;
            if (nums[j] >= nums[i]) continue;
            for (k=nums.size()-1; k>=i; k--)
                if (nums[k] > nums[j])
                    break;
            swap(nums[j], nums[k]);
            reverse(nums.begin() + i, nums.end());
            return;
        }
        reverse(nums.begin(), nums.end());
    }
};