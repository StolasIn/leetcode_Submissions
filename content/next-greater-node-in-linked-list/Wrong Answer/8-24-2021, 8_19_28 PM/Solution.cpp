// https://leetcode.com/problems/next-greater-node-in-linked-list

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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> v;
        int t;
        auto tmp = head;
        while(tmp!=nullptr){
            v.emplace_back(tmp->val);
            tmp=tmp->next;
        }
        int ma=0;
        for(int i=v.size()-1;i>=0;i--){
            t=v[i];
            v[i]=ma;
            ma=max(ma,t);
        }
        return v;
    }
};