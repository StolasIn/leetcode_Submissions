// https://leetcode.com/problems/intersection-of-two-linked-lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,bool> map1;
        unordered_map<ListNode*,bool> map2;
        for(;headA!=nullptr;headA=headA->next){
            map1[headA]=1;
        }
        for(;headB!=nullptr;headB=headB->next){
            if(map1.find(headB)!=map1.end()){
                return headB;
            }
        }
        return nullptr;
    }
};