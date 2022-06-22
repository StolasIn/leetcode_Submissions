// https://leetcode.com/problems/count-primes

class Solution {
public:
    int countPrimes(int n) {
        bool ch[n+1];
        int cnt=0;
        for(int i=0;i<=n;i++) ch[i]=false;
        int m=sqrt(n)+1;
        for(int i=2;i<m;i++){
            if(ch[i]==false){
                for(int j=i*i;j<=n;j+=i){
                    ch[j]=true;
                }
            }
        }
        for(int i=2;i<=n;i++){
            if(ch[i]) cnt++;
        }
        return n-cnt-1;
    }
};