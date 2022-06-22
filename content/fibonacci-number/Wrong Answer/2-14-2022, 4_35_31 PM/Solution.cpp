// https://leetcode.com/problems/fibonacci-number

class Solution {
public:
    int fib(int n) {
        if(n<=1){
            return n;
        }
        int a=0,b=1,c=1,c1=c;
        for(int i=2;i<=n;i++){
            c = a + b;
            a = b;
            b = c1;
            c1 = c;
        }
        return c;
    }
};