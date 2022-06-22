// https://leetcode.com/problems/coin-change

class Solution {
public:
    int re(vector<int>& c, int remain,int item,vector<int>& dp,vector<bool>& vis){
        if(remain==0) return 0;
        if(item>=c.size() || remain<0) return 1000000;
        if(vis[remain]) return dp[remain];
        else{
            for(int i=0;i*c[item]<=remain;i++){
                dp[remain]=min(dp[remain],i+re(c,remain-(i*c[item]),item+1,dp,vis));
            }
        }
        vis[remain]=true;
        return dp[remain];
    }
    int coinChange(vector<int>& coins, int amount) {
        if(coins.size()==1 && amount%coins[0]!=0) return -1;
        if(amount==0) return 0;
        int min1=INT_MAX;
        vector<int> dp(amount+1,1000000);
        vector<bool> vis(amount+1,false);
        re(coins,amount,0,dp,vis);
        return dp[amount];
    }
};