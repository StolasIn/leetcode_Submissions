// https://leetcode.com/problems/flatten-binary-tree-to-linked-list

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
    vector<TreeNode*> ans;
    void pre_order(TreeNode* root){
        if(root==nullptr) return;
        ans.emplace_back(root);
        pre_order(root->left);
        pre_order(root->right);
    }
    void flatten(TreeNode* root) {
        if(root=nullptr) return;
        pre_order(root);
        for(int i=0;i<ans.size()-1;i++){
            ans[i]->left=nullptr;
            ans[i]->right=ans[i+1];
        }
    }
};