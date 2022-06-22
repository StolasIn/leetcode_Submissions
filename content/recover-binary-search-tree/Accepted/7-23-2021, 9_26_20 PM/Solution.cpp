// https://leetcode.com/problems/recover-binary-search-tree

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
    vector<int> v;
    int cnt;
    void inorder(TreeNode* root){
        if(root==nullptr) return;
        inorder(root->left);
        v.emplace_back(root->val);
        inorder(root->right);
    }
    void inorderb(TreeNode* root){
        if(root==nullptr) return;
        inorderb(root->left);
        root->val=v[cnt++];
        inorderb(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        sort(v.begin(),v.end());
        cnt=0;
        inorderb(root);
    }
};