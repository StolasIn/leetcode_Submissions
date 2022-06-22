// https://leetcode.com/problems/average-of-levels-in-binary-tree

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
    vector<int> v[1000];
    int level=0;
    void dfs(TreeNode* root,int dis){
        if(root==nullptr) return;
        level=max(level,dis);
        v[dis].emplace_back(root->val);
        dfs(root->left,dis+1);
        dfs(root->right,dis+1);
    }
    double avg(vector<int>& v){
        double m=v.size();
        long long int sum=0;
        for(int i=0;i<m;i++){
            sum+=v[i];
        }
        return sum/m;
    }
    vector<double> averageOfLevels(TreeNode* root) {
        dfs(root,0);
        vector<double> ans;
        for(int i=0;i<=level;i++){
            ans.emplace_back(avg(v[i]));
        }
        return ans;
    }
};