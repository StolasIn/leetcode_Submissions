// https://leetcode.com/problems/find-mode-in-binary-search-tree

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
    unordered_map<int,int> map;
    void inorder(TreeNode* root){
        if(root==nullptr) return;
        inorder(root->left);
        map[root->val]++;
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        inorder(root);
        int ma=-1;
        for(auto& i : map){
            ma=max(ma,i.second);
        }
        for(auto& i : map){
            if(ma==i.second){
                ans.emplace_back(i.first);
            }
        }
        return ans;
    }
};