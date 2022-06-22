// https://leetcode.com/problems/all-paths-from-source-to-target

class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<vector<int>>& g,int x,vector<int>& now){
        if(x==g.size()-1) ans.emplace_back(now);
        for(auto i : g[x]){
            now.emplace_back(i);
            dfs(g,i,now);
            now.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> now;
        now.emplace_back(0);
        dfs(graph,0,now);
        return ans;
    }
};