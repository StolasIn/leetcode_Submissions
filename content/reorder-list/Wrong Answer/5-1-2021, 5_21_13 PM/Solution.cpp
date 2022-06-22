// https://leetcode.com/problems/reorder-list

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
    void reorderList(ListNode* head) {
        auto tmp=head;
        vector<int> v;
        while(tmp!=nullptr){
            v.emplace_back(tmp->val);
            tmp=tmp->next;
        }
        vector<int> ans;
        ans.resize(v.size());
        int c=0;
        for(int i=0;i<v.size();i+=2){
            ans[i]=v[c++];
        }
        for(int i=v.size()-1;c<v.size();i-=2){
            ans[i]=v[c++];
        }
        tmp=head;
        for(int i=0;i<ans.size();i++){
            tmp->val=ans[i];
            tmp=tmp->next;
        }
    }
};