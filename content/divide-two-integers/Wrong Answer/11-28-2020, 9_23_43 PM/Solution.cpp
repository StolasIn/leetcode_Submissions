// https://leetcode.com/problems/divide-two-integers

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool bool1=false;
        bool bool2=false;
        if(dividend==-2147483648) return 2147483647;
        if(dividend<0){
            bool1=true;
        }
        if(divisor<0){
            bool2=true;
        }
        if(!bool1 && !bool2){
            return (int)dividend/divisor;
        }
        else if(bool1 && bool2){
            return (int) abs(dividend)/abs(divisor);
        }
        else{
            return -1*(int) abs(dividend)/abs(divisor);
        }
        return 0;
    }
};