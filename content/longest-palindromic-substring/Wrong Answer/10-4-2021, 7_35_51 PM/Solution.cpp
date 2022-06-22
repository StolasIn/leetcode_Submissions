// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    int m,ma;
    vector<vector<int>> dp;
    int lon(int l,int r,string& s){
        if(l>r) return 2;
        if(l==r) return 1;
        else if(r==l+1){
            if(s[r]==s[l]) return 1; 
            else return 2;
        }
        
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        else{
            if(s[l]==s[r]){
                return dp[l][r]=lon(l+1,r-1,s);
            }
            else{
                return dp[l][r]=2;
            }
        }
        return 2;
    }
    string longestPalindrome(string s) {
        m=s.size();
        dp=vector<vector<int>>(m,vector<int>(m,-1));
        ma=-1;
        int l,r,t;
        string ans;
        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
                dp[i][j]=lon(i,j,s);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
                if(dp[i][j]==1 && ma<j-i){
                    ma=j-i;
                    l=i;
                    r=j;
                }
            }
        }
        for(int i=l;i<=r;i++){
            ans+=s[i];
        }
        return ans;
    }
};