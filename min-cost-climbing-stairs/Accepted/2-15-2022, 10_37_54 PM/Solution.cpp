// https://leetcode.com/problems/min-cost-climbing-stairs

class Solution {
public:
    unordered_map<int,int> map;
    int dfs(vector<int>& cost,int n){
        if(n<=1){
            return 0;
        }
        if(map.find(n)!=map.end()){
            return map[n];
        }
        return map[n] = min(dfs(cost,n-1) + cost[n-1],dfs(cost,n-2) + cost[n-2]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        cost.emplace_back(0);
        return dfs(cost,cost.size());
    }
};