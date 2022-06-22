// https://leetcode.com/problems/perfect-squares

static vector<bool> vis=vector<bool>(100000,0);
static vector<int> dp=vector<int>(100000,100000);
class Solution {
public:
    bool isPerfectSquare(int x){
        int s = sqrt(x);
        return s*s == x ? true:false;
    }
    int backpack(vector<int>& item,int it,int remain){
        if(remain<=3) return remain;
        if(it>=item.size()) return 100000;
        for(int i=0;i*item[it]<=remain;i++){
            dp[remain]=min(dp[remain],i+backpack(item,it+1,remain-i*item[it]));
        }
        return dp[remain];
    }
    int numSquares(int n) {
        if(isPerfectSquare(n)) return 1;
        if(n<=3) return n;
        vector<int> item;
        int m=sqrt(n);
        for(int i=1;i<=m;i++){
            item.emplace_back(i*i);
        }
        backpack(item,0,n);
        if(vis[n]) return dp[n];
        return backpack(item,0,n);
    }    
};