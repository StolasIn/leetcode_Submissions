// https://leetcode.com/problems/perfect-squares

class Solution {
public:
    bool isPerfectSquare(int x){
        int s = sqrt(x);
        return s*s == x ? true:false;
    }
    int backpack(vector<int>& item,vector<bool>& vis,vector<int>& dp,int it,int remain){
        if(remain<=3){
            return remain;
        }
        if(vis[remain]) return dp[remain];
        if(it<0) return 100000;
        for(int i=0;i*item[it]<=remain;i++){
            dp[remain]=min(dp[remain],i+backpack(item,vis,dp,it-1,remain-i*item[it]));
        }
        vis[remain]=true;
        return dp[remain];
    } 
    int numSquares(int n) {
        if(isPerfectSquare(n)) return 1;  
        vector<int> item;
        vector<bool> vis(n+1,false);
        vector<int> dp(n+1,100000);
        int m=sqrt(n);
        for(int i=1;i<=m;i++){
            item.emplace_back(i*i);
        }
        return backpack(item,vis,dp,m-1,n);
    }
};