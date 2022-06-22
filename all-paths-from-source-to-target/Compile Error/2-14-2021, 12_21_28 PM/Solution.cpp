// https://leetcode.com/problems/all-paths-from-source-to-target

class Solution {
public:
    vector<vector<int>> ans;
    int s;
    void dfs(vector<vector<int>>& g,int x,vector<int>& now){
        if(x==s) ans.emplace_back(now);
        for(auto i : g[x]){
            now.emplace_back(i);
            dfs(g,i,now);
            now.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> now;
        s.graph.size()-1;
        now.emplace_back(0);
        dfs(graph,0,now);
        return ans;
    }
};