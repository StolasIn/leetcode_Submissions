// https://leetcode.com/problems/binary-number-with-alternating-bits

class Solution {
public:
    bool hasAlternatingBits(int n) {
        if((n&(n>>1))==0 && ((n&(n>>2))==(n>>2))) return true;
        return false;
    }
};