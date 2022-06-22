// https://leetcode.com/problems/nim-game

class Solution {
public:
    vector<bool> dp;
    vector<bool> vis;
    bool dfs(int n){
        if(n<=0) return false;
        if(vis[n]==true) return dp[n];
        dp[n]=false;
        for(int i=1;i<=3;i++){
            if(dfs(n-i)==false){
                dp[n]=true;
                break;
            }
        }
        vis[n]=true;
        return dp[n];
    }
    bool canWinNim(int n) {
        dp.resize(n+1);
        vis.resize(n+1);
        dp[0]=false;
        vis[0]=true;
        return dfs(n);
    }
};