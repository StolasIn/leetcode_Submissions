// https://leetcode.com/problems/binary-tree-preorder-traversal

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
    void pre(TreeNode* r){
        if(r==nullptr){
            return;
        }
        ans.emplace_back(r->val);
        pre(r->left);
        pre(r->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        pre(root);
        return ans;
    }
};