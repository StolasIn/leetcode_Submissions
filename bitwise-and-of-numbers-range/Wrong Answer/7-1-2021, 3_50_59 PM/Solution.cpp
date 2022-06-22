// https://leetcode.com/problems/bitwise-and-of-numbers-range

class Solution {
public:
    int rangeBitwiseAnd(int l, int r) {
        if(r-l==0) return l;
        int b=log2(r-l);
        return (l&((1<<30)-(1<<b)));
    }
};