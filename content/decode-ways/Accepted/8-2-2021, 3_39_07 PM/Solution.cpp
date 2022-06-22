// https://leetcode.com/problems/decode-ways

class Solution {
public:
    vector<int> dp;
    int m;
    string s;
    int dfs(int ind){
        cout<<ind<<endl;
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int tmp=0;
        if(s[ind-1]!='0')tmp+=dfs(ind-1);
        string t="";
        if(ind-2>=0){
            t+=s[ind-2];
            t+=s[ind-1];
            if(s[ind-2]!='0' && atoi(t.c_str())<=26){
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