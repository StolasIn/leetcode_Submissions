// https://leetcode.com/problems/delete-leaves-with-a-given-value

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
    TreeNode* ptr;
    bool is;
};
class Solution {
public:
    int tar;
    node rm(TreeNode* r){
        if(r==nullptr){
            return node{nullptr,true};
        }
        node a=rm(r->left);
        node b=rm(r->right);
        r->left=a.ptr;
        r->right=b.ptr;
        if(r->val==tar){
            if(a.is==true && b.is==true){
                return node{nullptr,true};
            }
        }
        return node{r,false};
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        tar=target;
        rm(root);
        return root;
    }
};