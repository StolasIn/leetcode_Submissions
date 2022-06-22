// https://leetcode.com/problems/minimum-bit-flips-to-convert-number

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0;
        while(start!=0 || goal!=0){
            ans+=(start&1)^(goal&1);
            start>>=1;
            goal>>=1;
        }
        return ans;
    }
};