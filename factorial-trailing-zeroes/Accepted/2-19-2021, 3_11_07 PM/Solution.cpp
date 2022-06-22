// https://leetcode.com/problems/factorial-trailing-zeroes

class Solution {
public:
    int trailingZeroes(int n) {
        int ans1=0,ans2=0;
        for(int i=1;i<=n;i++){
            for(int j=5;j<10000;j*=5){
                if(i%j==0) ans1++;
            }
            for(int j=2;j<10000;j*=2){
                if(i%j==0) ans2++;
            }
        }
        return min(ans1,ans2);
    }
};