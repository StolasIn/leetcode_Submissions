// https://leetcode.com/problems/rotate-list

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
    ListNode* rotateRight(ListNode* head, int k) {
        auto tmp = head;
        int cnt=0;
        for(;tmp->next!=nullptr;tmp=tmp->next){
            cnt++;
        }
        tmp->next=head;
        cnt++;
        k%=cnt;
        tmp=head;
        for(int i=0;i<cnt-k-1;i++){
            tmp=tmp->next;
        }
        head=tmp->next;
        tmp->next=nullptr;
        return head;
    }
};