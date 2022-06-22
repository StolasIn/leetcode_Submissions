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
    void re(TreeNode* r,int dis){
        if(r==nullptr) return;
        if(dis==d){
            ans+=r->val;
        }
        else if(dis>d){
            d=dis;
            ans=r->val;
        }
        re(r->left,dis+1);
        re(r->right,dis+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        ans=0;
        re(root,0);
        return ans;
    }
};