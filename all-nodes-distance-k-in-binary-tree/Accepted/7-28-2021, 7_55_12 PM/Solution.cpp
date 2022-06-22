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
    int x,ta;
    void dfs1(TreeNode* now,TreeNode* from){
        if(now==nullptr) return;
        par[now->val]=from;
        dfs1(now->left,now);
        dfs1(now->right,now);
    }
    void dfs2(TreeNode* now,int dis,TreeNode* from){
        if(now==nullptr) return;
        if(dis==x){
            ans.emplace_back(now->val);
            return;
        }
        if(now->left!=from) dfs2(now->left,dis+1,now);
        if(now->right!=from) dfs2(now->right,dis+1,now);
        if(par[now->val]!=from) dfs2(par[now->val],dis+1,now);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        x=k;
        ta=target->val;
        dfs1(root,nullptr);
        dfs2(target,0,nullptr);
        return ans;
    }
};