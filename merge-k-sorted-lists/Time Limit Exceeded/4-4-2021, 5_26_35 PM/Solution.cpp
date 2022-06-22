// https://leetcode.com/problems/merge-k-sorted-lists

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
/*bool operator<(ListNode* a,ListNode* b){
    return a->val>b->val;
}*/
class Solution {
public:
    int len(ListNode* l){
        int cnt=0;
        while(l){
            cnt++;
            l=l->next;
        }
        return cnt;
    }
    ListNode* mergel(ListNode* a,ListNode* b){
        auto head=new ListNode(0);
        auto tmp=head;
        while(a!=nullptr || b!=nullptr){
            if(a==nullptr){
                head->next=b;
                break;
            }
            if(b==nullptr){
                head->next=a;
                break;
            }
            if(a->val<b->val){
                head->next=new ListNode(a->val);
                a=a->next;
                head=head->next;
            }
            else{
                head->next=new ListNode(b->val);
                b=b->next;
                head=head->next;
            }
        }
        return tmp->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& l) {
        if(l.size()==0) return nullptr;
        int m=l.size();
        priority_queue<ListNode*> pq;
        for(int i=0;i<m;i++){
            pq.push(l[i]);
        }
        while(pq.size()>1){
            auto a=pq.top();
            pq.pop();
            auto b=pq.top();
            pq.pop();
            pq.push(mergel(a,b));
        }
        return pq.top();
    }
};