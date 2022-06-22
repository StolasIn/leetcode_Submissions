// https://leetcode.com/problems/remove-nth-node-from-end-of-list

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //ListNode* tmp = new ListNode;
        vector<ListNode*> v;
        auto tmp = head;
        int cnt=0;
        if(head->next==nullptr){
            return nullptr;
        }
        
        while(tmp!=nullptr){
            cnt++;
            v.push_back(tmp);
            tmp=tmp->next;
        }
        if(cnt==n){
            auto tmp3 = head;
            head=head->next;
            delete tmp3;
        }
        else{
            auto tmp2=v[cnt-n];
            v[cnt-n-1]->next=v[cnt-n]->next;
            delete tmp2;
        }
        return head;
    }
};