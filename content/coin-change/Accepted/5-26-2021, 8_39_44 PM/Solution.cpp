// https://leetcode.com/problems/coin-change

class Solution {
public:
    
    // memoization
    
    vector<vector<int>> dp;
    
    int fun(vector<int> &v, int sum, int i)
    {
        if(sum==0)
            return 0;
        
        if(i<0)
            return INT_MAX-1;
        
        if(dp[i][sum]!=-1)
            return dp[i][sum];
        
        if(sum-v[i]>=0)
        {
            int num1 = fun(v,sum-v[i],i) + 1;
            int num2 = fun(v,sum,i-1);
            
            return dp[i][sum] = min(num1,num2);
        }
        else
            return dp[i][sum] = fun(v,sum,i-1);
    }
    
    int coinChange(vector<int>& v, int sum) 
    {
        int n = v.size();
        
        dp.clear();
        dp.resize(n+1,vector<int> (sum+1,-1));
        
        int ans = fun(v,sum,n-1);
        
        if(ans==INT_MAX-1)
            return -1;
        else
            return ans;
    }
};