// https://leetcode.com/problems/middle-of-the-linked-list

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
    ListNode* middleNode(ListNode* head) {
        ListNode* next_ptr = head;
        ListNode* next2_ptr = head;
        while(next2_ptr!=nullptr && next2_ptr->next!=nullptr){
            next_ptr = next_ptr->next;
            next2_ptr = next2_ptr->next->next;
        }
        return next_ptr;
    }
};