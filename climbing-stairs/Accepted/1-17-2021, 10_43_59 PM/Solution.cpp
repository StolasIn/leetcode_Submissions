// https://leetcode.com/problems/climbing-stairs

class Solution {
public:
    int dfs(int n,vector<int>& num,vector<bool>& vis){
        if(n<0) return 0;
        if(n==0) return 1;
        if(vis[n]) return num[n];
        else{
            num[n]=dfs(n-1,num,vis)+dfs(n-2,num,vis);
            vis[n]=true;
            return num[n];
        }
    }
    int climbStairs(int n) {
        vector<bool> vis(50,0);
        vector<int> num(50,1);
        dfs(n,num,vis);
        return num[n];
    }
};