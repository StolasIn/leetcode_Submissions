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
    int s;
    unordered_map<int,int> map;
    void re(TreeNode* root,int now){
        if(root==nullptr) return;
        now+=root->val;
        if(map.find(now-s)!=map.end())cnt+=map[now-s];
        map[now]++;
        re(root->left,now);
        re(root->right,now);
        map[now]--;
    }
    int pathSum(TreeNode* root, int sum) {
        s=sum;
        map[0]=1;
        re(root,0);
        return cnt;
    }
};