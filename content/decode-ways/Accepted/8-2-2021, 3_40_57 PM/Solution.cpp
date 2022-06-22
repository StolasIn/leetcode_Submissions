// https://leetcode.com/problems/decode-ways

class Solution {
public:
    vector<int> dp;
    int m;
    string s;
    int dfs(int ind){
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int tmp=0;
        if(s[ind-1]!='0')tmp+=dfs(ind-1);
        if(ind-2>=0){
            if(s[ind-2]!='0' && (s[ind-2]-'0')*10+(s[ind-1]-'0')<=26){
                tmp+=dfs(ind-2);
            }
        }
        return dp[ind]=tmp;
    }
    int numDecodings(string str) {
        m=str.size();
        dp.assign(m+1,-1);
        dp[0]=1;
        s=str;
        return dfs(m);
    }
};