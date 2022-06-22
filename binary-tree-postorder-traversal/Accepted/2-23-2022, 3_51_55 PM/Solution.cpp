// https://leetcode.com/problems/binary-tree-postorder-traversal

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
    void post(TreeNode* r){
        if(r==nullptr){
            return;
        }
        post(r->left);
        post(r->right);
        ans.emplace_back(r->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        post(root);
        return ans;
    }
};