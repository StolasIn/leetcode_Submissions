// https://leetcode.com/problems/binary-tree-level-order-traversal

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
struct node{
    TreeNode* n;
    int v;
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<node> q;
        vector<vector<int>> ans;
        q.push(node{root,0});
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            if(t.n==nullptr) continue;
            if(t.v>=ans.size()){
                ans.emplace_back(vector<int>());
            }
            ans[t.v].emplace_back(t.n->val);
            q.push(node{t.n->left,t.v+1});
            q.push(node{t.n->right,t.v+1});
        }
        return ans;
    }
};