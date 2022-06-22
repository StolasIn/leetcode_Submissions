// https://leetcode.com/problems/partition-list

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
    ListNode* partition(ListNode* head, int x) {
        vector<int> v;
        auto tmp = head;
        while(tmp!=nullptr){
            if(tmp->val<x)v.emplace_back(tmp->val);
            tmp=tmp->next;
        }
        tmp = head;
        while(tmp!=nullptr){
            if(tmp->val>=x)v.emplace_back(tmp->val);
            tmp=tmp->next;
        }
        tmp = head;
        int c=0;
        while(tmp!=nullptr){
            tmp->val=v[c++];
            tmp=tmp->next;
        }
        return head;
    }
};