// https://leetcode.com/problems/is-graph-bipartite

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int m=graph.size()-1;
        for(int i=0;i<=m;i++){
            if(graph[i].size()==m) return false;
        }
        return true;
    }
};