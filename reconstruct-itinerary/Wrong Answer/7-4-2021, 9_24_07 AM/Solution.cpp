// https://leetcode.com/problems/reconstruct-itinerary

class Solution {
public:
    unordered_map<string,vector<string>> map;
    vector<string> ans;
    void dfs(string& now){
        string str;
        ans.emplace_back(now);
        for(int i=map[now].size()-1;i>=0;i--){
            str=map[now][i];
            if(map[now].size()!=0){
                map[now].pop_back();
                dfs(str);
            }
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