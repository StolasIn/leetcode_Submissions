// https://leetcode.com/problems/maximum-binary-tree

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
    int fmax(vector<int>& v,int l,int r){
        int ma=-1;
        int ans;
        for(int i=l;i<=r;i++){
            if(ma<v[i]){
                ans=i;
                ma=v[i];
            }
        }
        return ans;
    }
    TreeNode* re(vector<int>& v,int now,int l,int r){
        if(r<l) return nullptr;
        TreeNode* node=new TreeNode(v[now]);
        node->left=re(v,fmax(v,l,now-1),l,now-1);
        node->right=re(v,fmax(v,now+1,r),now+1,r);
        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int m=nums.size();
        return re(nums,fmax(nums,0,m-1),0,m-1);
    }
};