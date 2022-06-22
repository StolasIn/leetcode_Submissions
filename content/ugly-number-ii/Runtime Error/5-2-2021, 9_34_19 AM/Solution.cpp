// https://leetcode.com/problems/ugly-number-ii

class Solution {
public:
    int nthUglyNumber(int n) {
        bool dp[10000];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=6;i++) dp[i]=true;
        for(int i=7;i<10000;i++){
            if(i%2==0){
                dp[i]|=dp[i/2];
            }
            
            if(i%3==0){
                dp[i]|=dp[i/3];
            }
            if(i%5==0){
                dp[i]|=dp[i/5];
            }
        }
        int cnt=0,i;
        for(i=1;cnt<n;i++){
            if(dp[i]==true) cnt++;
        }
        return i-1;
    }
};