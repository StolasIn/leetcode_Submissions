// https://leetcode.com/problems/coin-change

class Solution {
public:
    int dp[10010];
    int re(vector<int>& c, int remain){
        if(remain==0) return 0;
        if(remain<0) return 10000000;
        if(dp[remain]!=-1) return dp[remain];
        int sum=10000000;
        int res;
        for(auto& i : c){
            res=re(c,remain-i);
            if(res>=10000000) continue;
            sum = min(sum,res+1);
        }
        return dp[remain]=sum;
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.rbegin(),coins.rend());
        if(coins.size()==1 && amount%coins[0]!=0) return -1;
        if(amount==0) return 0;
        for(int i=0;i<=amount;i++){
            dp[i]=-1;
        }
        re(coins,amount);
        return dp[amount];
    }
};