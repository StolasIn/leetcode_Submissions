// https://leetcode.com/problems/n-th-tribonacci-number

class Solution {
public:
    vector<int> dp;
    int tri(int n){
        if(n<=1){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return tri(n-3)+tri(n-2)+tri(n-1);
    }
    int tribonacci(int n) {
        dp = vector<int>(40,-1);
        dp[2]=1;
        return tri(n);
    }
};