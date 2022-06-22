// https://leetcode.com/problems/linked-list-in-binary-tree

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
    unordered_set<TreeNode*> s;
    int tag;
    bool flag;
    void dfs(TreeNode* r){
        if(r==nullptr) return;
        if(r->val==tag){
            s.insert(r);
        }
        dfs(r->left);
        dfs(r->right);
    }
    void trase(ListNode* head, TreeNode* root){
        if(head==nullptr){
            flag=true;
            return;
        }
        if(root==nullptr) return;
        if(head->val==root->val){
            trase(head->next,root->left);
            trase(head->next,root->right);
        }
        else{
            return;
        }
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        tag=head->val;
        dfs(root);
        flag=false;
        for(auto i : s){
            if(flag) return true;
            trase(head,i);
        }
        return false;
    }
};