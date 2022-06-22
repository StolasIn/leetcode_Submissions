// https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent

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
    unordered_map<TreeNode*,TreeNode*> par;
    void dfs(TreeNode* r,TreeNode* from){
        if(r==nullptr) return;
        par[r]=from;
        dfs(r->left,r);
        dfs(r->right,r);
    }
    int sumEvenGrandparent(TreeNode* root) {
        dfs(root,nullptr);
        par[nullptr] = nullptr;
        int ans=0;
        for(auto i : par){
            if(par[i.second]!=nullptr && par[i.second]->val%2==0){
                ans+=i.first->val;
            }
        }
        return ans;
    }
};