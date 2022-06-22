// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        string dp[m+1][n+1];
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                dp[i][j]="";
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+s1[i-1];
                }
                else{
                    if(dp[i-1][j].size()==dp[i][j-1].size()){
                        if(dp[i-1][j]>dp[i][j-1]){
                            dp[i][j]=dp[i-1][j];
                        }
                        else{
                            dp[i][j]=dp[i][j-1];
                        }
                    }
                    else if(dp[i-1][j].size()>dp[i][j-1].size()){
                        dp[i][j]=dp[i-1][j];
                    }
                    else{
                        dp[i][j]=dp[i][j-1];
                    }
                }
            }
        }
        //cout<<dp[m][n]<<endl;
        int a=0,b=0,c=0;
        for(int i=0;i<m;i++){
            a+=s1[i];
        }
        for(int i=0;i<n;i++){
            b+=s2[i];
        }
        for(int i=0;i<dp[m][n].size();i++){
            c+=dp[m][n][i];
        }
        return a+b-2*c;
    }
};