// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    string longestPalindrome(string s) {
        int m=s.size();
        bool dp[m][m];
        memset(dp,false,sizeof(dp));
        int ma=-1,l,r;
        string ans;
        for(int i=0;i<m;i++){
            dp[i][i]=true;
            if(i+1<m && s[i]==s[i+1]){
                dp[i][i+1]=true;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
                if(dp[i+1][j-1]==true && s[i]==s[j]){
                    dp[i][j]=true;
                    if(ma<j-i){
                        ma=j-i;
                        l=i;
                        r=j;
                    }
                }
            }
        }
        for(int i=l;i<=r;i++){
            ans+=s[i];
        }
        return ans;
    }
};