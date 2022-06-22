// https://leetcode.com/problems/time-needed-to-inform-all-employees

class Solution {
public:
    vector<int> par;
    vector<int> dp;
    vector<int> t;
    int dfs(int n){
        if(par[n]==-1){
            return t[n];
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=dfs(par[n])+t[n];
    }
    int numOfMinutes(int n, int h, vector<int>& m, vector<int>& in) {
        par.assign(n,-1);
        dp.assign(n,-1);
        t.assign(in.begin(),in.end());
        for(int i=0;i<m.size();i++){
            par[i]=m[i];
        }
        for(int i=0;i<n;i++){
            dfs(i);
        }
        int ans=*max_element(dp.begin(),dp.end());
        if(ans==-1) return 0;
        else return ans;
    }
};