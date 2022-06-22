// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal

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
    int p;
    unordered_map<int,int> map;
    TreeNode* part(vector<int>& post, vector<int>& ino,int left,int right){
        if(right<=left){
            return nullptr;
        }
        int k;
        k=map[post[p]];
        p--;
        TreeNode* tp = new TreeNode(ino[k]);
        tp->left=part(post,ino,left,k);
        tp->right=part(post,ino,k+1,right);
        return tp;
    }
    TreeNode* buildTree(vector<int>& ino, vector<int>& post) {
        int m=ino.size();
        p=m-1;
        int cnt=0;
        for(int i=0;i<m;i++){
            map[ino[i]]=i;
        }
        TreeNode* root=new TreeNode(post[m-1]);
        int k;
        k=map[post[m-1]];
        p--;
        root->left=part(post,ino,0,k);
        root->right=part(post,ino,k+1,m);
        return root;
    }
};