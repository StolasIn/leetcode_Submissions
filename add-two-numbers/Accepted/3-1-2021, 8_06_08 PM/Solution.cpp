// https://leetcode.com/problems/add-two-numbers

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto head=new ListNode(0);
        auto head1=head;
        int carry=0;
        int sum;
        while(l1!=nullptr || l2!=nullptr || carry!=0){
            sum=0;
            if(l1!=nullptr){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=nullptr){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            if(sum>=10){
                carry=1;
                sum-=10;
            }
            else{
                carry=0;
            }
            auto tmp=new ListNode(sum);
            head1->next=tmp;
            head1=head1->next;
        }
        return head->next;
    }
};