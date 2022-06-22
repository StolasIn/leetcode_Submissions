// https://leetcode.com/problems/fibonacci-number

class Solution {
public:
    int dp[35];
    int re(int n){
        if(dp[n]!=-1){
            return dp[n];
        }
        if(n<=1) return n;
        return dp[n]=re(n-1)+re(n-2);
    }
    int fib(int n) {
        memset(dp,-1,sizeof(dp));
        return re(n);
    }
};