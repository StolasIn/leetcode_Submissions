// https://leetcode.com/problems/complement-of-base-10-integer

class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        else if(n==1) return 0;
        int m=pow(2,ceil(log2(n)));
        if(m==n) return n-1;
        return m-n-1;
    }
};