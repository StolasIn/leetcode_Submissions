// https://leetcode.com/problems/binary-tree-inorder-traversal

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
    vector<int> ans;
    void in(TreeNode* r){
        if(r==nullptr){
            return;
        }
        in(r->left);
        ans.emplace_back(r->val);
        in(r->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        in(root);
        return ans;
    }
};