// https://leetcode.com/problems/combination-sum-iv

class Solution {
public:
    int re(vector<int>& dp,vector<int>& num,int remain){
        if(dp[remain]!=-1) return dp[remain];
        if(remain==0) return 1;
        int tmp=0;
        for(int i=0;i<num.size();i++){
            if(remain-num[i]>=0) tmp+=re(dp,num,remain-num[i]);
        }
        dp[remain]=tmp;
        return tmp;
    }
    int combinationSum4(vector<int>& num, int t) {
        vector<int> dp;
        dp.assign(t+1,-1);
        return re(dp,num,t);
    }
};