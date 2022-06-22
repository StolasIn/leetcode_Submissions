// https://leetcode.com/problems/powx-n

class Solution {
public:
    double myPow(double x, int n) {
        if(x==0) return 0;
        if(x==1) return 1;
        if(n<-10000) return 0.0;
        double y=1.0;
        double pro;
        pro=x;
        if(n<0){
            n=abs(n);
            pro=1/x;
        }
        for(int i=0;i<n;i++){
            y*=pro;
        }
        return y;
    }
};