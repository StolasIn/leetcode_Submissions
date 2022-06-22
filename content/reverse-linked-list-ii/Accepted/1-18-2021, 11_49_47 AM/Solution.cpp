// https://leetcode.com/problems/reverse-linked-list-ii

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        auto ptr=head;
        int right=n;
        vector<ListNode*> arr;
        for(;ptr!=nullptr;ptr=ptr->next){
            arr.push_back(ptr);
        }
        m--;
        n--;
       while(m<n){
           swap(arr[m]->val,arr[n]->val);
           m++;
           n--;
       }
        return head;
    }
};