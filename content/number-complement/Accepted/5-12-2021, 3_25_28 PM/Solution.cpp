// https://leetcode.com/problems/number-complement

class Solution {
public:
    int findComplement(int num) {
        int k=num;
        int bi=1;
        while(k){
            num=num^(bi);
            bi<<=1;
            k>>=1;
        }
        return num;
    }
};