// https://leetcode.com/problems/min-cost-climbing-stairs

class Solution {
public:
    int dp[1000];
    int dfs(vector<int>& c,int ind){
        if(ind>=c.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int x=dfs(c,ind+1);
        int y=dfs(c,ind+2);
        return dp[ind]=min(x,y)+c[ind];
    }
    int minCostClimbingStairs(vector<int>& c) {
        for(int i=0;i<c.size();i++){
            dp[i]=-1;
        }
        return min(dfs(c,0),dfs(c,1));
    }
};