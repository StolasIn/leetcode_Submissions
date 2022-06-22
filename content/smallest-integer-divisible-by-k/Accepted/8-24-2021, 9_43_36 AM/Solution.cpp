// https://leetcode.com/problems/smallest-integer-divisible-by-k

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int mod=0;
        if(k%2==0 || k%5==0) return -1;
        for(int i=1;i<=k;i++){
            mod=(mod*10+1)%k;
            if(mod==0) return i;
        }
        return -1;
    }
};