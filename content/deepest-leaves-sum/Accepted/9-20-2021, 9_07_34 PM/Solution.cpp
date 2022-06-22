// https://leetcode.com/problems/deepest-leaves-sum

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
    int d,ans;
    int dep(TreeNode* r){
        if(r==nullptr){
            return 0;
        }
        int x = dep(r->left);
        int y = dep(r->right);
        return max(x,y)+1;
    }
    void re(TreeNode* r,int dis){
        if(r==nullptr) return;
        if(dis==d-1){
            ans+=r->val;
            return;
        }
        re(r->left,dis+1);
        re(r->right,dis+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        d=dep(root);
        ans=0;
        re(root,0);
        return ans;
    }
};