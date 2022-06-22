// https://leetcode.com/problems/coin-change

class Solution {
public:
    int re(vector<int>& c, int remain,int item,vector<int>& dp,vector<bool>& vis){
        if(remain==0) return 0;
        if(item>=c.size()) return 1000000;
        if(vis[remain]) return dp[remain];
        for(int i=0;i*c[item]<=remain;i++){
            dp[remain]=min(dp[remain],i+re(c,remain-(i*c[item]),item+1,dp,vis));
        }
        vis[remain]=true;
        return dp[remain];
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        if(coins.size()==1 && amount%coins[0]!=0) return -1;
        if(amount==0) return 0;
        vector<int> dp(amount+1,1000000);
        vector<bool> vis(amount+1,false);
        re(coins,amount,0,dp,vis);
        if(dp[amount]==1000000) return -1;
        return dp[amount];
    }
};