// https://leetcode.com/problems/russian-doll-envelopes

class Solution {
public:
    //n^2的解，可以把想法改成LIS
    //先把array sort一次後，根據LIS的想法就能找到答案
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
        //直觀的dp，dp的內容是當前的這個娃娃能放多少個比他小的
        for(int i=0;i<m;i++){
            for(int j=0;j<i;j++){
                //如果目前可以放，且比之前放的更多就轉換狀態
                if(env[i][0]>env[j][0] && env[i][1]>env[j][1]){
                    dp[i]=max(dp[i],dp[j]+1);
                    ans=max(dp[i],ans);
                }
            }
        }
        return ans;
    }
};