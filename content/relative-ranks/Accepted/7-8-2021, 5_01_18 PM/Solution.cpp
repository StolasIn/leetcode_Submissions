// https://leetcode.com/problems/relative-ranks

struct node{
    int val;
    int id;
    bool operator<(const node b) const{
        return val<b.val;
    }
};
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<node> pq;
        vector<string> ans(score.size());
        for(int i=0;i<score.size();i++){
            pq.push(node{score[i],i});
        }
        ans[pq.top().id]="Gold Medal";
        pq.pop();
        if(score.size()==1) return ans;
        ans[pq.top().id]="Silver Medal";
        pq.pop();
        if(score.size()==2) return ans;
        ans[pq.top().id]="Bronze Medal";
        pq.pop();
        if(score.size()==3) return ans;
        int cnt=4;
        while(!pq.empty()){
            ans[pq.top().id]=to_string(cnt++);
            pq.pop();
        }
        return ans;
    }
};