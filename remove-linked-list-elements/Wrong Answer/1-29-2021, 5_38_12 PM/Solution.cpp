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
        while(tmp!=nullptr && tmp->next!=nullptr){
            if(tmp->next->val==val){
                tmp->next=tmp->next->next;
            }
            tmp=tmp->next;
        }
        if(head->val==val) return head->next;
        else return head;
    }
};