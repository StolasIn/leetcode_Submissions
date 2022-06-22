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
    ListNode* reverseList(ListNode* h) {
        ListNode* pre = nullptr;
        ListNode* next = h->next;
        while(h!=nullptr){
            h->next = pre;
            pre = h;
            h = next;
            if(next!=nullptr){
                next = next->next;
            }
        }
        return pre;
    }
};