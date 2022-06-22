// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree

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
    vector<int> v;
    int ans;
    int partition1(vector<int> &arr,int left,int right){
        int pivot_index=rand()%(right-left+1)+left;
        int pivot=arr[pivot_index];
        swap(arr[pivot_index],arr[right]);
        int front1=left;
        for(int cur=left;cur<=right;cur++){
            if(arr[cur]>pivot){
                swap(arr[cur],arr[front1]);
                front1++;
            }
        }
        swap(arr[front1],arr[right]);
        return front1;
    }
    void quick_select(vector<int>& nums,int left,int right,int k){
        if(left==right) {ans=nums[left]; return;}
        if(right>left){
            int pivot=partition1(nums,left,right);
            if(k==pivot){
                ans=nums[pivot];
                return;
            }
            if(k>pivot){
                quick_select(nums,pivot+1,right,k);
            }
            else if(k<pivot){
                quick_select(nums,left,pivot-1,k);
            }
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size()==1) return nums[0];
        quick_select(nums,0,nums.size()-1,k-1);
        return ans;
    }
    void inorder(TreeNode* root){
        if(root==nullptr) return;
        inorder(root->left);
        v.emplace_back(root->val);
        inorder(root->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        inorder(root);
        return findKthLargest(v,v.size()-2);
    }
};