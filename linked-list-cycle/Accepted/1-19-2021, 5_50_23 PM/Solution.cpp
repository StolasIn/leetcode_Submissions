// https://leetcode.com/problems/linked-list-cycle

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
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,bool> map;
        for(;head!=nullptr;head=head->next){
            if(map.find(head)==map.end()){
                map[head]=1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};