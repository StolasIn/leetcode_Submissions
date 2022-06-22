// https://leetcode.com/problems/fibonacci-number

class Solution {
public:
    int fib(int n) {
        if(n<=1){
            return n;
        }
        int a=0,b=1,c=1,a1;
        for(int i=2;i<n;i++){
            c += b;
            a1 = b;
            b += a;
            a = a1;
        }
        return c;
    }
};