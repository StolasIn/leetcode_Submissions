// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree

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
    vector<bool> v;
    vector<bool> ans;
    void dfs(TreeNode* r,TreeNode* tar){
        if(r==nullptr) return;
        if(r==tar){
            ans.assign(v.begin(),v.end());
            return;
        }
        v.emplace_back(true);
        dfs(r->left,tar);
        v.pop_back();
        v.emplace_back(false);
        dfs(r->right,tar);
        v.pop_back();
    }
    TreeNode* getTargetCopy(TreeNode* o, TreeNode* c, TreeNode* t) {
        dfs(o,t);
        for(int i=0;i<ans.size();i++){
            if(ans[i]){
                c=c->left;
            }
            else{
                c=c->right;
            }
        }
        return c;
    }
};