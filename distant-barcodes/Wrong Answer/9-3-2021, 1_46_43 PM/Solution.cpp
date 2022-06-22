// https://leetcode.com/problems/distant-barcodes

struct node{
    int v,f;
    bool operator<(const node a) const {
        return f<a.f;
    }
};
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& code) {
        if(code.size()==1) return code;
        priority_queue<node> pq;
        unordered_map<int,int> map;
        vector<int> ans;
        for(auto& i : code){
            map[i]++;
        }
        for(auto& i : map){
            pq.push(node{i.first,i.second});
        }
        while(pq.size()>1){
            auto a = pq.top();
            pq.pop();
            auto b = pq.top();
            pq.pop();
            ans.emplace_back(a.v);
            ans.emplace_back(b.v);
            if(a.f>1){
                pq.push(node{a.v,a.f-1});
            }
            if(b.f>1){
                pq.push(node{b.v,b.f-1});
            }
        }
        return ans;
    }
};