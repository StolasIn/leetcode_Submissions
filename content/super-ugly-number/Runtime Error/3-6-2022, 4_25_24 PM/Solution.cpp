// https://leetcode.com/problems/super-ugly-number

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& p) {
        vector<bool> dp(p.back()+1,false);
        int m = p.size();
        dp[1] = true;
        for(int i=0;i<m;i++){
            dp[p[i]] = true;
        }
        int cnt = 1;
        for(int i=1;;i++){
            for(int j=0;j<m;j++){
                if(i%p[j]==0){
                    dp[i] = dp[i/p[j]];
                    if(dp[i]==true){
                        cnt++;
                    }
                    break;
                }
            }
            if(cnt>=n){
                return i;
            }
        }
        return -1;
    }
};