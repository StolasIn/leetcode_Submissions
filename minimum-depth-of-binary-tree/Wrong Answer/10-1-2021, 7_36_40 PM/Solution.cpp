// https://leetcode.com/problems/minimum-depth-of-binary-tree

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
    TreeNode* p;
    int d;
};
class Solution {
public:
    int minDepth(TreeNode* root) {
        int l;
        queue<node> q;
        q.push(node{root,0});
        node tmp;
        while(!q.empty()){
            tmp = q.front();
            q.pop();
            if(tmp.p->left==nullptr || tmp.p->right==nullptr){
                return tmp.d+1;
            }
            else{
                q.push(node{tmp.p->left,tmp.d+1});
                q.push(node{tmp.p->right,tmp.d+1});
            }
        }
        return 0;
    }
};