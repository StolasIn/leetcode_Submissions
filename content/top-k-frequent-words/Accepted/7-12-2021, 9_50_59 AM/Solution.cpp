// https://leetcode.com/problems/top-k-frequent-words

struct node{
    string str;
    int f;
    bool operator<(const node& a) const{
        if(f!=a.f) return f<a.f;
        return str>a.str;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& w, int k) {
        unordered_map<string,int> map;
        priority_queue<node> pq;
        int m=w.size();
        for(int i=0;i<m;i++){
            map[w[i]]++;
        }
        for(auto i : map){
            pq.push(node{i.first,i.second});
        }
        vector<string> ans;
        for(int i=0;i<k;i++){
            ans.emplace_back(pq.top().str);
            pq.pop();
        }
        return ans;
    }
};