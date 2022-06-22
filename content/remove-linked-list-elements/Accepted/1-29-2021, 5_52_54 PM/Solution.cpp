// https://leetcode.com/problems/remove-linked-list-elements

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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr) return head;
        auto tmp=head;
        auto tmp1=tmp->next;
        while(tmp1!=nullptr){
            if(tmp1->val==val){
                while(tmp1->next!=nullptr && tmp1->next->val==val){
                    tmp1=tmp1->next;
                }
                tmp->next=tmp1->next;
            }
            tmp=tmp1;
            tmp1=tmp1->next;
        }
        if(head->val==val) return head->next;
        else return head;
    }
};