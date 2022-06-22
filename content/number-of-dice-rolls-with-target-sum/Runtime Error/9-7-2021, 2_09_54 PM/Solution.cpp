// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum

class Solution {
public:
    vector<vector<int>> dp;
    int face;
    int re(int d,int remain){
        if(remain<0 || d<0) return 0;
        if(d==0 && remain==0) return 1;
        if(dp[d][remain]!=-1){
            return dp[d][remain];
        }
        int ans=0;
        for(int i=1;i<=face && i<=remain;i++){
            ans+=re(d-1,remain-i);
        }
        return dp[d][remain]=ans;
    }
    int numRollsToTarget(int d, int f, int target) {
        dp=vector<vector<int>>(d+1,vector<int>(target+1,-1));
        face=f;
        return re(d,target);
    }
};