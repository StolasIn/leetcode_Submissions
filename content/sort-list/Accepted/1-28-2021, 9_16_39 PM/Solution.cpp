// https://leetcode.com/problems/sort-list

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
    ListNode* sortList(ListNode* head) {
        auto ptr=head;
        vector<int> ans;
        while(ptr!=nullptr){
            ans.emplace_back(ptr->val);
            ptr=ptr->next;
        }
        sort(ans.begin(),ans.end());
        ptr=head;
        for(int i=0;ptr!=nullptr;i++){
            ptr->val=ans[i];
            ptr=ptr->next;
        }
        return head;
    }
};