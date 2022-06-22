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
    int p=0;
    unordered_map<int,int> map;
    TreeNode* part(vector<int>& pre, vector<int>& ino,int left,int right){
        if(right<=left){
            return nullptr;
        }
        int k;
        k=map[pre[p]];
        p++;
        TreeNode* tp = new TreeNode(ino[k]);
        tp->left=part(pre,ino,left,k);
        tp->right=part(pre,ino,k+1,right);
        return tp;
    }
    TreeNode* buildTree(vector<int>& ino, vector<int>& post) {
        int m=ino.size();
        int cnt=0;
        vector<int> pre(m);
        for(int i=0;i<(m/2);i++){
            pre[cnt++]=post[m-i-1];
            pre[cnt++]=post[i];
        }
        if(m%2!=0){
            pre[m-1]=post[m/2];
        }
        for(int i=0;i<m;i++){
            map[ino[i]]=i;
        }
        TreeNode* root=new TreeNode(pre[0]);
        int k;
        k=map[pre[0]];
        p++;
        root->left=part(pre,ino,0,k);
        root->right=part(pre,ino,k+1,m);
        return root;
    }
};