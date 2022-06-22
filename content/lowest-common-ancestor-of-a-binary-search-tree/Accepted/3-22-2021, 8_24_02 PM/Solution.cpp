// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree

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
    int st1,st2;
    int cnt;
    vector<vector<TreeNode*>> cmp;
    void dfs(TreeNode* root,vector<TreeNode*>& now){
        if(root==nullptr || cnt>=2) return;
        if(root->val==st1 || root->val==st2){
            cnt++;
            now.emplace_back(root);
            cmp.emplace_back(now);
            now.pop_back();
            if(cnt>=2) return;
        }
        now.emplace_back(root);
        dfs(root->left,now);
        dfs(root->right,now);
        now.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> now;
        st1=p->val;
        st2=q->val;
        cnt=0;
        bool flag=true;
        dfs(root,now);
        int i;
        int m=min(cmp[0].size(),cmp[1].size());
        for(i=0;i<m;i++){
            if(cmp[0][i]->val!=cmp[1][i]->val){
                flag=false;
                break;
            }
        }
        return cmp[0][i-1];
    }
};