// https://leetcode.com/problems/power-of-four

class Solution {
public:
    bool isPowerOfFour(int num) {
        long long n = abs(num);
        while(n>1){
            if(n%4!=0) return false;
            n/=4;
        }
        return true;
    }
};