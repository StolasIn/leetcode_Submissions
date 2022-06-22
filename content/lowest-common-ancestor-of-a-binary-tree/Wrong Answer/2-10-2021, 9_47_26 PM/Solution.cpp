// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree

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
    vector<vector<TreeNode*>> ans; 
    void find(TreeNode* root, TreeNode* p,vector<TreeNode*>& now){
        if(root==nullptr) return;
        if(root==p){
            now.emplace_back(root);
            ans.emplace_back(now);
            now.pop_back();
        }
        now.emplace_back(root);
        find(root->left,p,now);
        find(root->right,p,now);
        now.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p==root || q==root) return root;
        vector<TreeNode*> now;
        find(root,p,now);
        now.clear();
        find(root,q,now);
        int m=min(ans[0].size(),ans[1].size());
        for(int i=0;i<m;i++){
            if(ans[0][i]->val!=ans[1][i]->val){
                p=ans[0][i-1];
                break;
            }
        }
        return p;
    }
};