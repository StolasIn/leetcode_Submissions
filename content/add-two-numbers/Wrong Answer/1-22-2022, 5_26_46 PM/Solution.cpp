// https://leetcode.com/problems/add-two-numbers

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l = new ListNode();
        auto head = l;
        int carry = 0;
        while(l1!=nullptr || l2!=nullptr){
            l->next = new ListNode();
            l=l->next;
            if(l1==nullptr){
                l->val = l2->val + carry;
                if(l->val>=10){
                    l->val-=10;
                    carry = 1;
                }
                l2 = l2->next;
            }
            else if(l2==nullptr){
                l->val = l1->val + carry;
                if(l->val>=10){
                    l->val-=10;
                    carry = 1;
                }
                l1 = l1->next;
            }
            else{
                l->val = l1->val + l2->val + carry;
                carry = 0;
                if(l->val>=10){
                    l->val-=10;
                    carry = 1;
                }
                l1 = l1->next;
                l2 = l2->next;
            }
        }
        if(carry == 1){
            l->next = new ListNode();
            l->next->val = 1;
        }
        return head->next;
    }
};