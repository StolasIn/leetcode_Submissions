// https://leetcode.com/problems/sum-of-square-numbers

class Solution {
public:
    bool isseq(int x){
        if(((int)sqrt(x)*(int)sqrt(x))==x) return true;
        return false;
    }
    bool judgeSquareSum(int c) {
        if(c==0) return true;
        for(int i=1;i*i<=c;i++){
            if(isseq(c-i*i)){
                cout<<c<<" "<<i<<endl;
                return true;
            }
        }
        return false;
    }
};