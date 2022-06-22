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
    TreeNode* re(vector<int>& v,int l,int r){
        int mid=(r-l)/2+l;
        TreeNode* t = new TreeNode(v[mid]);
        if(r==l){
            return t;
        }
        if(r<l){
            return nullptr;
        }
        t->left=re(v,l,mid-1);
        t->right=re(v,mid+1,r);
        return t;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==nullptr) return nullptr;
        vector<int> v;
        while(head!=nullptr){
            v.emplace_back(head->val);
            head=head->next;
        }
        auto t=re(v,0,v.size()-1);
        return t;
    }
};