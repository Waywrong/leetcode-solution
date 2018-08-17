//  Unique Binary Search Tree

class Solution {
public:
    int numTrees(int n) {
        vector<int> nums(n+1, 0);
        nums[0] = 1; nums[1] = 1;
        for (int i=2; i<=n; i++)
            for (int k=1; k<=i; k++)
                nums[i] += nums[k-1] * nums[i-k];
        return nums[n];
    }
};
