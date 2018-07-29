//  Convert Sorted Array to Binary Search Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//  Time O(N), Space O(1)
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size()-1);
    }
    
    TreeNode *sortedArrayToBST(vector<int> &nums, int l, int r) {
        if (l > r)  return nullptr;
        int mid = l + (r - l) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, l, mid-1);
        root->right = sortedArrayToBST(nums, mid+1, r);
        return root;
    }
};