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
    int ans;
    void dfs(TreeNode* r,TreeNode* f1,TreeNode* f2){
        if(r==nullptr) return;
        if(f2!=nullptr && f2->val%2==0){
            ans+=r->val;
        }
        dfs(r->left,r,f1);
        dfs(r->right,r,f1);
    }
    int sumEvenGrandparent(TreeNode* root) {
        dfs(root,nullptr,nullptr);
        return ans;
    }
};