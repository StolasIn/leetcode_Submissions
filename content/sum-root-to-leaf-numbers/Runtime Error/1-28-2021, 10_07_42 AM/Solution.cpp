// https://leetcode.com/problems/sum-root-to-leaf-numbers

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
    vector<vector<int>> ans;
    void dfs(TreeNode* root,vector<int>& str){
        if(root==nullptr) return;
        if(root->left==nullptr && root->right==nullptr) {
            str.emplace_back(root->val);
            ans.emplace_back(str);
            str.pop_back();
            return;
        }
        str.emplace_back(root->val);
        dfs(root->left,str);
        dfs(root->right,str);
        str.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        if(root==nullptr) return 0;
        
        int sum=0;
        int pro=1;
        vector<int> o;
        dfs(root,o);
        for(int i=0;i<ans.size();i++){
            pro=1;
            for(int j=ans[i].size()-1;j>=0;j--){
                sum+=pro*ans[i][j];
                pro*=10;
            }
        }
        return sum;
    }
};