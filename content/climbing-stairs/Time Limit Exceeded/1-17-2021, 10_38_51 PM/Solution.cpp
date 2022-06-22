// https://leetcode.com/problems/climbing-stairs

class Solution {
public:
    int ans=0;
    void dfs(int n){
        if(n==0){
            ans++;
            return;
        }
        if(n<0) return;
        dfs(n-1);
        dfs(n-2);
    }
    int climbStairs(int n) {
        dfs(n);
        return ans;
    }
};