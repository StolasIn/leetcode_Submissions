// https://leetcode.com/problems/integer-break

class Solution {
public:
    int dp[60];
    int re(int n,int d){
        if(dp[n]!=-1) return dp[n];
        int ma=-1;
        for(int i=1;i<n;i++){
            ma=max(ma,i*re(n-i,d+1));
            //printf("%d %d %d\n",n,i,ma);
        }
        if(d!=0) ma=max(ma,n);
        return dp[n]=ma;
    }
    int integerBreak(int n) {
        memset(dp,-1,sizeof(dp));
        dp[2]=1;
        dp[0]=0;
        dp[1]=1;
        return re(n,0);
    }
};