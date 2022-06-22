// https://leetcode.com/problems/last-stone-weight

class Solution {
public:
    int lastStoneWeight(vector<int>& st) {
        priority_queue<int> pq;
        int a,b;
        for(int i=0;i<st.size();i++){
            pq.push(st[i]);
        }
        while(pq.size()>1){
            a=pq.top();
            pq.pop();
            b=pq.top();
            pq.pop();
            if(a!=b){
                pq.push(a-b);
            }
        }
        if(pq.size()==0){
            return 0;
        }
        else{
            return pq.top();
        }
    }
};