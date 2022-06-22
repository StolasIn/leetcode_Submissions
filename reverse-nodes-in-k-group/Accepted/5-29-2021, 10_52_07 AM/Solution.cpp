// https://leetcode.com/problems/reverse-nodes-in-k-group

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
    int v[5050];
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k==1)
        {
            return head;
        }
        auto tmp = head;
        int s=0;
        while(tmp!=nullptr){
            v[s++]=tmp->val;
            tmp=tmp->next;
        }
        for(int i=0;i+k<=s;i+=k){
            reverse(v+i,v+i+k);
        }
        tmp = head;
        int c=0;
        while(tmp!=nullptr){
            tmp->val = v[c++];
            tmp=tmp->next;
        }
        return head;
    }
};