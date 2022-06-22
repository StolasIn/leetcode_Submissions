// https://leetcode.com/problems/longest-palindromic-subsequence

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s1=s;
        reverse(s1.begin(),s1.end());
        int m=s.size();
        string dp[m+1][m+1];
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==s1[j-1]){
                    dp[i][j]=dp[i-1][j-1]+s[i-1];
                }
                else{
                    if(dp[i-1][j].size()>dp[i][j-1].size()){
                        dp[i][j]=dp[i-1][j];
                    }
                    else{
                        dp[i][j]=dp[i][j-1];
                    }
                }
            }
        }
        cout<<dp[m][m]<<endl;
        string str="";
        for(int i=0;i<(dp[m][m].size()+1)/2;i++){
            str+=dp[m][m][i];
        }
        cout<<str<<endl;
        for(int i=(dp[m][m].size())/2-1;i>=0;i--){
            str+=dp[m][m][i];
        }
        return str.size();
    }
};