// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree

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
    vector<int> arr;
    void re(TreeNode* r,int l){
        if(r==nullptr){
            return;
        }
        if(l==arr.size()){
            arr.emplace_back(r->val);
        }
        else{
            arr[l]+=r->val;
        }
        re(r->left,l+1);
        re(r->right,l+1);
    }
    int maxLevelSum(TreeNode* root) {
        re(root,0);
        return max_element(arr.begin(),arr.end())-arr.begin()+1;
    }
};