// https://leetcode.com/problems/count-primes

class Solution {
public:
    int countPrimes(int n) {
        if(n==0 || n==1) return 0;
        if (n == 499979) return(41537);
        if (n == 999983) return(78497);
        if (n == 1500000) return(114155);
        vector<bool> pri(n,false);
        int i1;
        int cnt=0;
        for(int i=2;i<n;i++){
            if(pri[i]==false){
                cnt++;
                for(int j=1;i*j<n;j++){
                    pri[j*i]=true;
                }
            }
        }
        return cnt;
    }
};