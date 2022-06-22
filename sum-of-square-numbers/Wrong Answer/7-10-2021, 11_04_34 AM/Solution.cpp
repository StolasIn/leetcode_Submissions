// https://leetcode.com/problems/sum-of-square-numbers

class Solution {
public:
    bool isseq(int x){
        if(sqrt(x)*sqrt(x)==x) return true;
        return false;
    }
    bool judgeSquareSum(int c) {
        for(int i=1;i*i<=c;i++){
            if(isseq(c-i*i)){
                return true;
            }
        }
        return false;
    }
};