// https://leetcode.com/problems/russian-doll-envelopes

class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        if(a[0]>b[0]){
            return true;
        }
        else if(a[0]==b[0]){
            if(a[1]>b[1]){
                return true;
            }
            return false;
        }
        return false;
    }
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(),env.end());
        int m=env.size();
        int ans=1;
        vector<int> dp(m,1);
        for(int i=0;i<m;i++){
            for(int j=0;j<i;j++){
                if(env[i][0]>env[j][0] && env[i][1]>env[j][1]){
                    dp[i]=max(dp[i],dp[j]+1);
                    ans=max(dp[i],ans);
                }
            }
        }
        return ans;
    }
};