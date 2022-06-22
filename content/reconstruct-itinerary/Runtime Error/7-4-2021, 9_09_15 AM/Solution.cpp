// https://leetcode.com/problems/reconstruct-itinerary

class Solution {
public:
    unordered_map<string,vector<string>> map;
    vector<string> ans;
    void dfs(string& now){
        ans.emplace_back(now);
        for(int i=0;i<map[now].size();i++){
            dfs(map[now][i]);
            map[now].pop_back();
        }
    }
    vector<string> findItinerary(vector<vector<string>>& t) {
        int m=t.size();
        string s="JFK";
        for(int i=0;i<m;i++){
            map[t[i][0]].emplace_back(t[i][1]);
        }
        for(int i=0;i<m;i++){
            sort(map[t[i][0]].rbegin(),map[t[i][0]].rend());
        }
        dfs(s);
        return ans;
    }
};