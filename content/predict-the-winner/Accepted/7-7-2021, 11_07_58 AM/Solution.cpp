// https://leetcode.com/problems/predict-the-winner

class Solution {
public:
    int dp[30][30];
    int re(vector<int>& n,int l,int r){
        if(l>r) return -9999999;
        if(dp[l][r]!=-1) return dp[l][r];
        int a=n[l]-re(n,l+1,r);
        int b=n[r]-re(n,l,r-1);
        return dp[l][r]=max(a,b);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int m=nums.size();
        if(m==1) return true;
        int sum=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<m;i++){
            dp[i][i]=nums[i];
            sum+=nums[i];
        }
        return re(nums,0,m-1)>=0;
    }
};