// https://leetcode.com/problems/bitwise-and-of-numbers-range

class Solution {
public:
    int rangeBitwiseAnd(int l, int r) {
        int b=log2(r-l);
        return (l&((1<<30)-(1<<b)));
    }
};