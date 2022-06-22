// https://leetcode.com/problems/insert-into-a-binary-search-tree

class Solution {
public:
    
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // insert(root,val);
        if(!root){
            TreeNode* node=new TreeNode(val);
            
            return node;
        }
        if(root->val<val){
           root->right= insertIntoBST(root->right,val);
            return root;
        }
        if(root->val>val){
            
             root->left= insertIntoBST(root->left,val);
            return root;
        }
        return root;
    }
};