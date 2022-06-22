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
        ListNode* ans=new ListNode();
        auto ptr=head;
        int a[210]={0};
        for(;ptr!=nullptr;ptr=ptr->next){
            a[ptr->val+100]++;
        }
        auto beg=ans;
        for(int i=0;i<210;i++){
            if(a[i]>=1){
                ListNode* tmp=new ListNode();
                beg->next=tmp;
                beg=beg->next;
                beg->val=i-100;
            }
        }
        beg->next=nullptr;
        return ans->next;
    }
};