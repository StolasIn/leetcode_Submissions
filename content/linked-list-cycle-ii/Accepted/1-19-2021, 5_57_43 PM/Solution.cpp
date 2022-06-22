// https://leetcode.com/problems/linked-list-cycle-ii

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
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,bool> map;
        ListNode* ans;
        bool flag=0;
        for(;head!=nullptr;head=head->next){
            if(map.find(head)==map.end()){
                map[head]=1;
            }
            else{
                flag=1;
                ans=head;
                break;
            }
        }
        if(flag==1)
            return ans;
        else{
            return nullptr;
        }
    }
};