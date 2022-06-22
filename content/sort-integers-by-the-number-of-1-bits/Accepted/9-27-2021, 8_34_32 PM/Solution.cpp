// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits

struct node{
    int val,bit;
    bool operator<(const node a) const {
        if(a.bit==bit){
            return a.val<val;
        }
        return a.bit<bit;
    }
};
class Solution {
public:
    int cnt(int x){
        int ans=0;
        while(x!=0){
            if(x&1){
                ans++;
            }
            x>>=1;
        }
        return ans;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> ans;
        priority_queue<node> pq;
        for(int i=0;i<arr.size();i++){
            pq.push(node{arr[i],cnt(arr[i])});
        }
        while(!pq.empty()){
            ans.emplace_back(pq.top().val);
            pq.pop();
        }
        return ans;
    }
};