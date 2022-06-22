// https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation

class Solution {
public:
    bool isp(int x){
        int n=sqrt(x)+1;
        if(x==1) return false;
        for(int i=2;i<n;i++){
            if(x%i==0){
                return false;
            }
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for(int i=left;i<=right;i++){
            if(isp(__builtin_popcount(i))){
                ans++;
            }
        }
        return ans;
    }
};