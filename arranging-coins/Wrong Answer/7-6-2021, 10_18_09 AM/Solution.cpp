// https://leetcode.com/problems/arranging-coins

class Solution {
public:
    int arrangeCoins(int n) {
        long long u=n;
        long long i=ceil(sqrt(u*2));
        if((i*(i+1))/2==u){
            return i;
        }
        else{
            return i-1;
        }
    }
};