// https://leetcode.com/problems/ugly-number-ii

bool dp[10000000];
class Solution {
public:
    int nthUglyNumber(int n) {
        memset(dp,false,sizeof(dp));
        int cnt=1;
        dp[0]=false;
        dp[1]=true;
        int i=0;
        for(i=2;cnt<n;i++){
            if((i%2==0 && dp[i/2]==true) || (i%3==0 && dp[i/3]==true) || (i%5==0 && dp[i/5]==true)){
                dp[i]=true;
                cnt++;
            }
        }
        return i-1;
    }
};