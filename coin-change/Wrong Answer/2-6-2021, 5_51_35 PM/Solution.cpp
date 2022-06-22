// https://leetcode.com/problems/coin-change

class Solution {
public:
    int re(vector<int>& c, int remain,int item,vector<vector<int>>& dp,int sum){
        if(remain==0) return sum;
        if(item>=c.size() || remain<0) return INT_MAX;
        if(dp[item][remain]!=INT_MAX) return dp[item][remain];
        else{
            for(int i=0;i*c[item]<=remain;i++){
                //cout<<item<<" "<<remain-(i*c[item])<<" "<<sum+i<<endl;
                dp[item][remain]=min(dp[item][remain],re(c,remain-(i*c[item]),item+1,dp,sum+i));
            }
        }
        return dp[item][remain];
    }
    int coinChange(vector<int>& coins, int amount) {
        if(coins.size()==1 && amount%coins[0]!=0) return -1;
        if(amount==0) return 0;
        int min1=INT_MAX;
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,INT_MAX));
        re(coins,amount,0,dp,0);
        /*for(int i=0;i<coins.size();i++){
            for(int j=0;j<=amount;j++){
                cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }
        }*/
        for(int i=0;i<coins.size();i++){
            min1=min(min1,dp[i][amount]);
        }
        return min1;
    }
};