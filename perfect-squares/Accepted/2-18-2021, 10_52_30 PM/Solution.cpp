// https://leetcode.com/problems/perfect-squares

class Solution {
public:
    bool isPerfectSquare(int x){
        int s = sqrt(x);
        return s*s == x ? true:false;
    }
    int backpack(vector<int>& item,vector<bool>& vis,vector<int>& dp,int it,int remain){
        if(vis[remain]) return dp[remain];
        if(it>=item.size()) return 100000;
        for(int i=0;i*item[it]<=remain;i++){
            dp[remain]=min(dp[remain],i+backpack(item,vis,dp,it+1,remain-i*item[it]));
        }
        vis[remain]=true;
        return dp[remain];
    }
    int numSquares(int n) {
        if(isPerfectSquare(n)) return 1;
        if(n<=3) return n;
        vector<int> item;
        vector<bool> vis(100000,false);
        vector<int> dp(100000,100000);
        vis[0]=vis[1]=vis[2]=vis[3]=true;
        dp[0]=0; dp[1]=1; dp[2]=2; dp[3]=3;
        int m=sqrt(n);
        for(int i=1;i<=m;i++){
            item.emplace_back(i*i);
        }
        if(vis[n]) return dp[n];
        else return backpack(item,vis,dp,0,n);
    }
};