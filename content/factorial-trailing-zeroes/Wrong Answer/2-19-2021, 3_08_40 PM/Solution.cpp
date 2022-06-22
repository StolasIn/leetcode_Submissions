// https://leetcode.com/problems/factorial-trailing-zeroes

class Solution {
public:
    int trailingZeroes(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            if(i%5==0){
                ans++;
            }
            if(i%25==0){
                ans++;
            }
            if(i%625==0){
                ans++;
            }
            if(i%3125==0){
                ans++;
            }
        }
        return ans;
    }
};