// https://leetcode.com/problems/merge-two-sorted-lists

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode;
        auto tmp = head;
        while(l1!=nullptr && l2!=nullptr){
            ListNode* tmp2 = new ListNode;
            tmp->next=tmp2;
            tmp=tmp->next;
            if(l1->val>l2->val){
                tmp->val=l2->val;
                l2=l2->next;
            }
            else{
                tmp->val=l1->val;
                l1=l1->next;
            }
        }
        auto t = head;
        head=head->next;
        delete t;
        if(l1!=nullptr){
            while(l1!=nullptr){
                ListNode* tmp2 = new ListNode;
                tmp->next=tmp2;
                tmp=tmp->next;
                tmp->val=l1->val;
                l1=l1->next;
            }
        }
        else if(l2!=nullptr){
            while(l2!=nullptr){
                ListNode* tmp2 = new ListNode;
                tmp->next=tmp2;
                tmp=tmp->next;
                tmp->val=l2->val;
                l2=l2->next;
            }
        }
        return head;
    }
};