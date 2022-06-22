// https://leetcode.com/problems/coin-change

class Solution {
public:
    int dp[10010];
    int re(vector<int>& c, int remain,int item){
        if(remain==0) return 0;
        if(item>=c.size()) return 1000000;
        if(dp[remain]<1000000) return dp[remain];
        int sum=1000000;
        for(int i=0;i*c[item]<=remain;i++){
            sum=min(sum,i+re(c,remain-(i*c[item]),item+1));
        }
        dp[remain]=sum;
        return dp[remain];
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        if(coins.size()==1 && amount%coins[0]!=0) return -1;
        if(amount==0) return 0;
        memset(dp,1000000,sizeof(dp));
        re(coins,amount,0);
        if(dp[amount]>=1000000) return -1;
        return dp[amount];
    }
};