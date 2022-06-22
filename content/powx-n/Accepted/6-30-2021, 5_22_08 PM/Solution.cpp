// https://leetcode.com/problems/powx-n

class Solution {
public:
    double one;
    double mul(double a,double b){
        return a*b;
    }
    double qmul(long int n){
        if(n==1){
            return one;
        }
        double tmp=qmul(n/2);
        tmp=mul(tmp,tmp);
        if(n%2==1){
            tmp=mul(one,tmp);
        }
        return tmp;
    }
    double myPow(double x, int n) {
        long int m=n;
        one=x;
        if(m==0) return 1;
        if(m<0){
            return 1/qmul(-m);
        }
        else return qmul(m);
    }
};