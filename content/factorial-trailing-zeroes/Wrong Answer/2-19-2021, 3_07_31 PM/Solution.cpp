// https://leetcode.com/problems/factorial-trailing-zeroes

class Solution {
public:
    int trailingZeroes(int n) {
        int ans=0;
        if(n==5) return 0;
        for(int i=1;i<=n;i++){
            if(n%5==0){
                ans++;
            }
            if(n%25==0){
                ans++;
            }
            if(n%625==0){
                ans++;
            }
            if(n%3125==0){
                ans++;
            }
        }
        return ans;
    }
};