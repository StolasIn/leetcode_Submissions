// https://leetcode.com/problems/palindrome-linked-list

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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==nullptr) return true;
        if(head->next==nullptr) return true;
        stack<int> st;
        st.push(head->val);
        head=head->next;
        for(;head!=nullptr;head==head->next){
            if(head->val==st.top()){
                break;
            }
            st.push(head->val);
        }
        for(;head!=nullptr;head=head->next){
            if(head->val==st.top()){
                st.pop();
            }
        }
        if(st.size()==0) return true;
        return false;
    }
};