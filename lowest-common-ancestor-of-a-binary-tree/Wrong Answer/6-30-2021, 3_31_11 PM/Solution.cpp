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
    TreeNode* check;
    bool f;
    vector<TreeNode*> t;
    void dfs(vector<TreeNode*>& v,TreeNode* now){
        if(f || now==nullptr) return;
        v.emplace_back(now);
        if(now->val==check->val){
            t.assign(v.begin(),v.end());
            f=true;
            return;
        }
        dfs(v,now->left);
        dfs(v,now->right);
        v.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> t1;
        vector<TreeNode*> t2;
        vector<TreeNode*> v;
        TreeNode* ans;
        f=false;
        check=p;
        t.clear();
        dfs(v,root);
        t1.assign(t.begin(),t.end());
        f=false;
        check=q;
        t.clear();
        v.clear();
        dfs(v,root);
        t2.assign(t.begin(),t.end());
        for(int i=0;i<min(t1.size(),t2.size());i++){
            cout<<t1[i]->val<<" "<<t2[i]->val<<endl;
            if(t1[i]->val!=t2[i]->val){
                ans=t1[i-1];
            }
        }
        return ans;
    }
};