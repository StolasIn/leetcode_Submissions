// https://leetcode.com/problems/path-sum-iii

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
    int cnt=0;
    unordered_map<int,int> map;
    void re(TreeNode* root, int sum,int now){
        if(root==nullptr) return;
        now+=root->val;
        cnt+=map[now-sum];
        map[now]++;
        re(root->left,sum,now);
        re(root->right,sum,now);
        map[now]--;
    }
    int pathSum(TreeNode* root, int sum) {
        map[0]=1;
        re(root,sum,0);
        return cnt;
    }
};