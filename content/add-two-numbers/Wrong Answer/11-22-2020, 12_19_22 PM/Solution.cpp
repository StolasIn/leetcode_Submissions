// https://leetcode.com/problems/add-two-numbers


//Definition for singly-linked list.
/*class ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* lsumptr = new ListNode;
        ListNode* lsum = new ListNode;
        lsumptr=lsum;
        ListNode* l1p=l1;
        ListNode* l2p=l2;
        int carry=0;
        int sum=0;
        while(l1p!=nullptr && l2p!=nullptr){
            sum=l1p->val+l2p->val+carry;
            if(sum>=10){
                carry=sum/10;
                sum%=10;
            }
            ListNode* node = new ListNode(sum);
            lsum->next = node;
            lsum = lsum->next;
            l1p = l1p->next;
            l2p = l2p->next;
        }
        if(l1p!=nullptr){
            while(l1p!=nullptr){
                l1p->val+=carry;
                if(l1p->val>=10){
                    carry=l1p->val/10;
                    l1p->val%=10;
                }
                ListNode* node = new ListNode(l1p->val);
                lsum->next = node;
                lsum = lsum->next;
                l1p = l1p->next;
            }
        }
        else{
            while(l2p!=nullptr){
                l2p->val+=carry;
                if(l2p->val>=10){
                    carry=l2p->val/10;
                    l2p->val%=10;
                }
                ListNode* node = new ListNode(l2p->val);
                lsum->next = node;
                lsum = lsum->next;
                l2p=l2p->next;
            }
        }
        if(carry!=0){
            ListNode* node = new ListNode(1);
            lsum->next = node;
        }
        auto tmp=lsumptr;
        lsumptr=lsumptr->next;
        delete tmp;
        return lsumptr;
    }
};