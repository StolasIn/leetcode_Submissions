// https://leetcode.com/problems/remove-nth-node-from-end-of-list

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* next_ptr = head;
        ListNode* nextn_ptr = head;
        while(n--){
            nextn_ptr = nextn_ptr->next;   
        }
        if(nextn_ptr==nullptr){
            return head->next;
        }
        while(nextn_ptr->next!=nullptr){
            next_ptr = next_ptr->next;
            nextn_ptr = nextn_ptr->next;
        }
        if(next_ptr->next == nullptr){
            return nullptr;
        }
        next_ptr->next = next_ptr->next->next;
        return head;
    }
};