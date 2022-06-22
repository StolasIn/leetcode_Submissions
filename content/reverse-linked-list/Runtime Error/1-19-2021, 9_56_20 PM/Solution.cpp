// https://leetcode.com/problems/reverse-linked-list

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
    ListNode* reverseList(ListNode* head) {
        ListNode* ptr=nullptr;
        ListNode* ptr1;
        ListNode* ptr2;
        ListNode* tmp=head;
        for(;tmp->next!=nullptr;){
            ptr1=tmp->next->next;
            ptr2=tmp->next;
            tmp->next=ptr;
            ptr=tmp;
            tmp=ptr2;
            ptr2=ptr1;
        }
        tmp->next=ptr;
        return tmp;
    }
};