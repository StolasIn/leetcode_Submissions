// https://leetcode.com/problems/sort-characters-by-frequency

struct node{
    char c;
    int f;
    bool operator<(const node& a) const {
        return a.f>f;
    }
};
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> map;
        priority_queue<node> pq;
        string ans;
        for(int i=0;i<s.size();i++){
            map[s[i]]++;
        }
        for(auto i : map){
            pq.push(node{i.first,i.second});
        }
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            for(int i=0;i<t.f;i++){
                ans+=t.c;
            }
        }
        return ans;
    }
};