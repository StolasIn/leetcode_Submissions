// https://leetcode.com/problems/factorial-trailing-zeroes

class Solution {
public:
    int trailingZeroes(int n) {
        int ans1=0;
        for(int i=1;i<=n;i++){
            ans1+=n/=5;
        }
        return ans1;
    }
};