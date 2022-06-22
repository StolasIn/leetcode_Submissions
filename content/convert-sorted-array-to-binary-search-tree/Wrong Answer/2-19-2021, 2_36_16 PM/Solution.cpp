// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* part(vector<int>& n,int l,int r){
        if(l>r) return nullptr;
        TreeNode* root=new TreeNode(n[(l+r)/2]);
        root->left=part(n,l,(l+r)/2-1);
        root->right=part(n,(l+r)/2+1,r);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0) return nullptr;
        if(nums.size()==1){
            return new TreeNode(nums[0]);
        }
        int m=nums.size();
        TreeNode* root=new TreeNode(nums[(m+1)/2]);
        root->left=part(nums,0,(m+1)/2-1);
        root->right=part(nums,(m+1)/2+1,m-1);
        return root;
    }
};