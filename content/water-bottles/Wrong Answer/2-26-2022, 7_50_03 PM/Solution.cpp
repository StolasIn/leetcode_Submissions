// https://leetcode.com/problems/water-bottles

class Solution {
public:
    int numWaterBottles(int b, int e) {
        int mod = 0;
        int ans = 0;
        while(b>0){
            ans+=b;
            b=(b+mod)/e;
            mod = b%e;
        }
        return ans;
    }
};