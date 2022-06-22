// https://leetcode.com/problems/water-bottles

class Solution {
public:
    int numWaterBottles(int b, int e) {
        int mod = 0,mod1 = 0;
        int ans = 0;
        while(b>0){
            ans+=b;
            mod = (b + mod1)%e;
            b = (b+mod1)/e;
            mod1 = mod;
        }
        return ans;
    }
};