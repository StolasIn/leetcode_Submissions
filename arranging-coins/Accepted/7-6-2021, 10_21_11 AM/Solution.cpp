// https://leetcode.com/problems/arranging-coins

class Solution {
public:
    int arrangeCoins(int n) {
        long long u=n;
        u=floor(sqrt(u*2)+0.5);
        if((u*(u+1))/2==n){
            return u;
        }
        else{
            return u-1;
        }
    }
};