// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int,TreeNode*> par;
    vector<int> ans;
    int x;
    void dfs(TreeNode* now){
        if(now==nullptr) return;
        par[now->val]=now;
        dfs(now->left);
        dfs(now->right);
    }
    void dfs2(TreeNode* now,int dis){
        if(now==nullptr) return;
        if(dis>k) return;
        if(dis==x){
            ans.emplace_back(now->val);
        }
        dfs2(now->left,dis+1);
        dfs2(now->right,dis+1);
        dfs2(par[now->val],dis+1);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        x=k;
        dfs(root);
        dfs2(target,0);
        return ans;
    }
};