// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* re(TreeNode* now,vector<int>& v,int l,int r){
        cout<<l<<" "<<r<<endl;
        if(r<l) return nullptr;
        if(r==l){
            now=new TreeNode();
            now->val=v[l];
            return now;
        }
        int mid=(r-l)/2+l;
        if(now==nullptr){
            now=new TreeNode();
        }
        now->val=v[mid];
        now->left=re(now->left,v,l,mid-1);
        now->right=re(now->right,v,mid+1,r);
        return now;
     }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v;
        auto tmp = head;
        while(tmp!=nullptr){
            v.emplace_back(tmp->val);
            tmp=tmp->next;
        }
        TreeNode* t=new TreeNode();
        return re(t,v,0,v.size()-1);
    }
};