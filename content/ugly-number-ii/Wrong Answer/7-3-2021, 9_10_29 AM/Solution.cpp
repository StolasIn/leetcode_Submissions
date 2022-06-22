// https://leetcode.com/problems/ugly-number-ii

class Solution {
public:
    int nthUglyNumber(int n) {
        bool dp[100000];
        memset(dp,false,sizeof(dp));
        int cnt=0;
        dp[0]=false;
        dp[1]=true;
        int i=0;
        for(i=2;cnt<n;i++){
            if(dp[i/2]==true || dp[i/3]==true || dp[i/5]==true){
                dp[i]=true;
                cnt++;
            }
        }
        return i;
    }
};