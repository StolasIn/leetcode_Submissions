// https://leetcode.com/problems/remove-linked-list-elements

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
    void del(){
        
    }
    ListNode* removeElements(ListNode* h, int val) {
        ListNode* pre = new ListNode();
        pre->next = h;
        auto ans = pre;
        while(h!=nullptr){
            //cout<<pre<<endl;
            if(h->val == val){
                pre->next = h->next;
            }
            else{
                pre = h;
            }
            h = h->next;
        }
        return ans->next;
    }
};