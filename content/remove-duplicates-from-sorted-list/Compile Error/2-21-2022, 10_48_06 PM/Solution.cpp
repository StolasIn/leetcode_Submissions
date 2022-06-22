// https://leetcode.com/problems/remove-duplicates-from-sorted-list

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr){
            retunr head;
        }
        ListNode* first = head;
        ListNode* next = head;
        while(next!=nullptr){
            if(first->val == next->val){
                next = next->next;
            }
            else{
                first->next = next;
                first = next;
            }
        }
        first->next = nullptr;
        return head;
    }
};